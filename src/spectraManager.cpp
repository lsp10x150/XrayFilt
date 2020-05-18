//
// Created by lsp10 on 09.05.2020.
//
#include<fstream>
#include<iostream>
#include<vector>
#include<G4SystemOfUnits.hh>
#include <pwdefs.hh>
#include "spectraManager.hh"

/// Конструктор класса менеджера спектров, пока содержит только исходный спектр.
spectraManager::spectraManager(){
    gottenSpectra.reserve(200); //Резервируем в памяти 200 ячеек для хранения std::pair<G4double, G4double>
    cntr = 1;
    for (int i = 0; i < 161; ++i){
        gottenSpectra.emplace_back(i,0); // то же, что и push_back только более безопасный
        // позволяет не указывать std::pair(i, 0), emplace_back сам понимает какого типа
        // члены вектора - рассмотреть вопрос подробнее
    }
}

bool spectraManager::SetInitialSpectraFile(G4String path){

    std::fstream InitialSpectraFile(path); // файл с исходным спектром
    if (InitialSpectraFile.good()) {
        std::cout << "Initial spectra file opened successfully!" << std::endl;

        /// Чтение спектра из файла
        std::vector<std::pair<G4double, G4double>> tempSpectra;
        while (InitialSpectraFile.good()){
            std::pair<G4double, G4double> pair;
            InitialSpectraFile >> pair.second;
            InitialSpectraFile >> pair.first;
            tempSpectra.push_back(pair);
            //std::cout << pair.first << " " << pair.second << std::endl;
        }
        InitialSpectraFile.close();

        /// Интегрирование спектра
        G4double buffer = 0;
        for (auto & it : tempSpectra){
            it.first += buffer;
            buffer = it.first;
        }

        /// Нормирование спектра
        for (auto & it : tempSpectra){
            it.first /= buffer; // Делим каждый элемент на buffer, в котором после предыдущего
            // цикла хранится максимальное значение коллекции
        }

        for (auto & it : tempSpectra){
            initialSpectra.insert(it);
        }

        return true;
    }
    else {
        std::cout << "Failed to open initial spectra file.\n"
                     "Initializing monoenergetic beam of 50 keV" << std::endl;
        initialSpectra.insert(std::make_pair(1, 50));
        return false;
    }
}

void spectraManager::ShowSpectra() {
    std::cout << "Initial spectra holds: " << std::endl;
    for (auto & it : initialSpectra){
        std::cout << it.first << " " << it.second << std::endl;
    }
}

std::map<G4double, G4double> spectraManager::getInitialSpectra(){ // Публичная функция доступа к исходному спектру
    return initialSpectra;
}

void spectraManager::CollectSpectra(G4Step* step, G4TouchableHistory* history) {
    double energy = step->GetPreStepPoint()->GetKineticEnergy() / keV;
    if (step->GetTrack()->GetDefinition()->GetParticleName() == "gamma") {
        int index = int(floor(energy));
        if (index >= 0 && index < 161)
            gottenSpectra[index].second++;
    }
}

void spectraManager::PushGottenSpectraToFile() {
    std::string name = "./spectrums/spectrum";
    std::string width = std::to_string(config.GetCertainParameter("FILTER_WIDTH") -
                                               (cntr-1)*config.GetCertainParameter("STEP_REDUCING_FILTER_WIDTH")) + "Al.dat";
    std::ofstream file(name+width);
    for(int i = 0; i<161; ++i)
    {
        file << std::setw(15) << gottenSpectra[i].first << " "
             << std::setw(15) << gottenSpectra[i].second << std::endl;
    }
    file.close();
    cntr++;
}

void spectraManager::RenewGottenSpectra() {
    for (int i = 0; i < 161; ++i){
        gottenSpectra.emplace_back(std::make_pair(i,0));
    }
}

int spectraManager::GetCntr() const {
    return cntr;
}
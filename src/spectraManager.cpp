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

    cntr = 0;
    for (int i = 0; i < 161; ++i){
        gottenSpectra.push_back(std::make_pair(i,0));
    }

    std::fstream InitialSpectraFile("initialSpectra.dat"); // файл с исходным спектром
    if (InitialSpectraFile.good()) {
        std::cout << "Initial spectra file opened successfully!" << std::endl;

        /// Чтение спектра из файла
        std::vector<std::pair<G4double, G4double>> tempSpectra;
        while (InitialSpectraFile.good()){
            std::pair<G4double, G4double> pair;
            InitialSpectraFile >> pair.second;
            InitialSpectraFile >> pair.first;
            tempSpectra.push_back(pair);
            std::cout << pair.first << " " << pair.second << std::endl;
        }
        InitialSpectraFile.close();

        std::cout << "Initial spectra file has been read successfully!" << std::endl;

        /// Интегрирование спектра
        G4double buffer = 0;
        for (auto it = tempSpectra.begin(); it != tempSpectra.end(); ++it){
            it->first += buffer;
            buffer = it->first;
        }

        /// Нормирование спектра
        for (auto it = tempSpectra.begin(); it != tempSpectra.end(); ++it){
            it->first /= buffer; // Делим каждый элемент на buffer, в котором после предыдущего
            // цикла хранится максимальное значение коллекции
        }

        for (auto it = tempSpectra.begin(); it != tempSpectra.end(); ++it){
            initialSpectra.insert(*it);
        }

        std::cout << "Initial spectra holds: " << std::endl;
        for (auto it = initialSpectra.begin(); it != initialSpectra.end(); ++it){
            std::cout << it->first << " " << it->second;
            std::cout << std::endl;
        }
    }
    else std::cout << "Failed to open initial spectra file" << std::endl;
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
    std::string date = std::to_string(cntr)+".dat";
    std::ofstream file(name+date);
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
        gottenSpectra.push_back(std::make_pair(i,0));
    }
}

int spectraManager::GetCntr() {
    return cntr;
}
#include <fstream>
#include <iostream>
#include <vector>
#include <G4SystemOfUnits.hh>
#include "SpectraManager.hh"
/// Конструктор класса менеджера спектров
SpectraManager::SpectraManager(){
    //Резервируем в памяти 200 ячеек для хранения std::pair<G4double, G4double>
    gottenSpectra.reserve(200);
    cntr = 1;
    for (int i = 0; i < 161; ++i){
        gottenSpectra.emplace_back(i,0); } }
bool SpectraManager::SetInitialSpectraFile(G4String path){
    // инициализировали поток из файла с исходным спектром
    std::fstream InitialSpectraFile(path);
    // Если файл открылся успешно
    if (InitialSpectraFile.good()) {
        std::cout << "Initial spectra file opened successfully!"
                                                    << std::endl;
        /// Чтение спектра из файла
        std::vector<std::pair<G4double, G4double>> tempSpectra;
        while (InitialSpectraFile.good()){
            std::pair<G4double, G4double> pair;
            InitialSpectraFile >> pair.second;
            InitialSpectraFile >> pair.first;
            tempSpectra.push_back(pair); }
        InitialSpectraFile.close();
        /// Интегрирование спектра
        G4double buffer = 0;
        for (auto & it : tempSpectra){
            it.first += buffer;
            buffer = it.first;       }
        /// Нормирование спектра
        for (auto & it : tempSpectra){
            // Делим каждый элемент на buffer, в котором после предыдущего
            // цикла хранится максимальное значение коллекции
            it.first /= buffer;      }
        /// Передача данных в отображение
        for (auto & it : tempSpectra){
            initialSpectra.insert(it); }
        return true; }
    else { // Если файл не открылся
        std::cout << "Failed to open initial spectra file.\n"
                     "Initializing monoenergetic beam of 50 keV" << std::endl;
        initialSpectra.insert(std::make_pair(1, 50));
        return false; } }
/// Метод для дебага
void SpectraManager::ShowSpectra() {
    std::cout << "Initial spectra holds: " << std::endl;
    for (auto & it : initialSpectra){
        std::cout << it.first << " " << it.second << std::endl; } }
/// Метод для доступа к исходному спектру
std::map<G4double, G4double> SpectraManager::getInitialSpectra(){
    return initialSpectra; }
/// Метод набора спектра
void SpectraManager::CollectSpectra(G4Step* step, G4TouchableHistory* history) {
    double energy = step->GetPreStepPoint()->GetKineticEnergy() / keV;
    if (step->GetTrack()->GetDefinition()->GetParticleName() == "gamma") {
        int index = int(floor(energy));
        if (index >= 0 && index < 161)
            gottenSpectra[index].second++; } }
/// Метод для сохранения симулированного спектра в файл
void SpectraManager::PushGottenSpectraToFile() {
    G4String name = "./spectrums/";
    name += config.GetMaterial();
    name += "_";
    std::string width = std::to_string
            (config.GetCertainParameter("FILTER_WIDTH") -
            (cntr-1)*config.GetCertainParameter("STEP_REDUCING_FILTER_WIDTH")) +
            "_mm.dat";
    std::ofstream file(name+width);
    for(int i = 0; i<161; ++i){
         file << std::setw(15) << gottenSpectra[i].first << " "
         << std::setw(15) << gottenSpectra[i].second << std::endl; }
    file.close();
    cntr++; }
/// Метод для обнуления контейнера с симспектром
void SpectraManager::RenewGottenSpectra() {
    for (int i = 0; i < 161; ++i)
        gottenSpectra.emplace_back(std::make_pair(i,0)); }
/// Метод для получения значения счетчика
int SpectraManager::GetCntr() const {
    return cntr; }
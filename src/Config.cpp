#include "Config.hh"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <G4String.hh>
/// Пустой конструктор
Config::Config() {}
/// Метод для установки пути к файлу настроек
void Config::SetConfigFile(G4String path){
    // Файл с параметрами
    std::ifstream configFile(path);
    // Если config.dat открылся, читаем его, иначе настройки по-умолчанию
    if (configFile.good()) {
        std::cout << "Config file opened successfully!" << std::endl;
        getline(configFile, pathToInitialSpectra);
        while (configFile.good()) {
            std::pair<std::string, G4double> pair;
            configFile >> pair.first;
            configFile >> pair.second;
            parameters.insert(pair); }
    } else { std::cout << "Could not open config.dat. \n"
                          "Make sure it is within the main "
                          "directory of the project and try again.\n\n"
                    "Initializing configs with default parameters."
                    << std::endl;
        pathToInitialSpectra = "initialSpectra.dat";
        parameters.insert(
                std::make_pair("N_PARTICLES", 100000));
        parameters.insert(
                std::make_pair("FILTER_WIDTH", 2.5));
        parameters.insert(
                std::make_pair("N_ITERATIONS", 1));
        parameters.insert(
                std::make_pair("STEP_REDUCING_FILTER_WIDTH", 0.5));
        parameters.insert(
                std::make_pair("INHERENT_FILTRATION", 1));
        parameters.insert(
                std::make_pair("FILTER_MATERIAL", 0)); } }
/// Метод-геттер для получения текущего значения параметра по ключу
G4double Config::GetCertainParameter(std::string paramKey) {
    return parameters.at(paramKey); }
void Config::ShowParameters() {
    std::cout << "Config parameters are: \n";
    std::cout << pathToInitialSpectra << std::endl;
    for (auto it = parameters.begin(); it != parameters.end(); ++it)
        std::cout << std::setw(30) <<
            it->first << " " << it->second << std::endl; }
/// Метод-геттер пути до файла спектра источника
G4String Config::GetPathToInitialSpectra(){
    return pathToInitialSpectra; }
/// Метод-геттер текущего материала доп.фильтра
G4String Config::GetMaterial() {
    switch(int(this->GetCertainParameter("FILTER_MATERIAL"))){
        case 0: return "Al";
        case 1: return "Cu";
        case 2: return "Sn";
        case 3: return "Zn";
        default: return "Al"; } }
//
// Created by lsp10 on 09.05.2020.
//

#include "GetConfig.hh"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <G4String.hh>

Config::Config() {}

void Config::SetConfigFile(G4String path){
    std::ifstream configFile(path); // файл с параметрами
    if (configFile.good()) {
        std::cout << "Config file opened successfully!" << std::endl;
        getline(configFile, pathToInitialSpectra); /// Get Initial Spectra
        while (configFile.good()) {
            std::pair<std::string, G4double> pair;
            configFile >> pair.first;
            configFile >> pair.second;
            parameters.insert(pair);
            //std::cout << pair.first << " " << pair.second << std::endl;
        }
    }
    else{
        std::cout << "Could not open config.dat. \nMake sure it is "
                     "within the main directory of the project and try again.\n\n"
                     "Initializing configs with default parameters." << std::endl;
        pathToInitialSpectra = "initialSpectra.dat";
        parameters.insert(std::make_pair("N_PARTICLES", 100000));
        parameters.insert(std::make_pair("FILTER_WIDTH", 2.5));
        parameters.insert(std::make_pair("N_ITERATIONS", 1));
        parameters.insert(std::make_pair("STEP_REDUCING_FILTER_WIDTH", 0.5));
        parameters.insert(std::make_pair("INHERENT_FILTRATION", 1));
    }
}

G4double Config::GetCertainParameter(std::string paramKey) {
    return parameters.at(paramKey);
}

void Config::ShowParameters() {
    std::cout << "Config parameters are: \n";
    std::cout << pathToInitialSpectra << std::endl;
    for (auto it = parameters.begin(); it != parameters.end(); ++it){
        std::cout << std::setw(30) << it->first << " " << it->second << std::endl;
    }
}

G4String Config::GetPathToInitialSpectra(){
    return pathToInitialSpectra;
}
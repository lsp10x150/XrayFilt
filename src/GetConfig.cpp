//
// Created by lsp10 on 09.05.2020.
//

#include "GetConfig.hh"
#include <fstream>
#include <iostream>
#include <iomanip>

Config::Config(){
    std::ifstream configFile("config.dat"); // файл с исходным спектром
    if (configFile.good()) {
        std::cout << "Config file opened successfully!" << std::endl;
        while (configFile.good()) {
            std::pair<std::string, G4double> pair;
            configFile >> pair.first;
            configFile >> pair.second;
            parameters.insert(pair);
            //std::cout << pair.first << " " << pair.second << std::endl;
        }
    }
    else{
        std::cout << "Could not open config.dat. \n Make sure it is "
                     "within the main directory of the project and try again." << std::endl;
    }
}

G4double Config::GetCertainParameter(std::string paramKey) {
    return parameters.at(paramKey);
}

void Config::ShowParameters() {
    std::cout << "Config parameters are: \n";
    for (auto it = parameters.begin(); it != parameters.end(); ++it){
        std::cout << std::setw(30) << it->first << " " << it->second << std::endl;
    }
}
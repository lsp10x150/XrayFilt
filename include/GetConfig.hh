//
// Created by lsp10 on 09.05.2020.
//

#include <map>
#include <pwdefs.hh>
#include <G4String.hh>

#ifndef XRAYFILT_GETCONFIG_HH
#define XRAYFILT_GETCONFIG_HH


class Config{
    std::map<std::string, const G4double> parameters;
    G4String pathToInitialSpectra;
public:
    G4double GetCertainParameter(std::string paramKey);
    void ShowParameters();
    G4String GetPathToInitialSpectra();
    void SetConfigFile(G4String);
    G4String GetMaterial();
    Config();
};


#endif //XRAYFILT_GETCONFIG_HH

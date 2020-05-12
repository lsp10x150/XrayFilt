//
// Created by lsp10 on 09.05.2020.
//

#include <map>
#include <pwdefs.hh>

#ifndef XRAYFILT_GETCONFIG_HH
#define XRAYFILT_GETCONFIG_HH


class Config{
    std::map<std::string, const G4double> parameters;
public:
    G4double GetCertainParameter(std::string paramKey);
    void ShowParameters();
    Config();
};


#endif //XRAYFILT_GETCONFIG_HH

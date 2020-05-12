//
// Created by lsp10 on 09.05.2020.
//
#include<map>
#include <G4TouchableHistory.hh>
#include <G4Step.hh>

#ifndef XRAYFILT_SPECTRAMANAGER_HH
#define XRAYFILT_SPECTRAMANAGER_HH
class spectraManager {
    std::map<G4double, G4double> initialSpectra;
    std::vector<std::pair<G4double, G4double>> gottenSpectra;
    int cntr;
public:
    spectraManager();
    std::map<G4double, G4double> getInitialSpectra();
    void CollectSpectra(G4Step* step, G4TouchableHistory* history);
    void PushGottenSpectraToFile();
    void RenewGottenSpectra();
    void ShowSpectra();
    int GetCntr() const;
};

#endif //XRAYFILT_SPECTRAMANAGER_HH

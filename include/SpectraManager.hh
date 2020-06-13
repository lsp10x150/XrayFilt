#include<map>
#include <G4TouchableHistory.hh>
#include <G4Step.hh>
#include "Config.hh"
#ifndef XRAYFILT_SPECTRAMANAGER_HH
#define XRAYFILT_SPECTRAMANAGER_HH
extern Config config;
class SpectraManager {
    std::map<G4double, G4double> initialSpectra;
    std::vector<std::pair<G4double, G4double>> gottenSpectra;
    int cntr;
public:
    SpectraManager();
    std::map<G4double, G4double> getInitialSpectra();
    void CollectSpectra(G4Step* step, G4TouchableHistory* history);
    void PushGottenSpectraToFile();
    void RenewGottenSpectra();
    void ShowSpectra();
    int GetCntr() const;
    bool SetInitialSpectraFile(G4String); };
#endif //XRAYFILT_SPECTRAMANAGER_HH
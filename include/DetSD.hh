#include<G4VSensitiveDetector.hh>
#ifndef ExG4DetectorSD_h
#define ExG4DetectorSD_h 1
class G4Step;
class G4TouchableHistory;
class DetSD: public G4VSensitiveDetector {
public:
    DetSD(G4String name);
    ~DetSD();
    G4bool ProcessHits(G4Step* step, G4TouchableHistory* history); };
#endif
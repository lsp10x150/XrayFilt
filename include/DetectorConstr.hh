#ifndef ExG4DetectorConstruction01_h
#define ExG4DetectorConstruction01_h 1
#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "G4Tubs.hh"
class G4VPhysicalVolume;
class G4LogicalVolume;
class DetectorConstr : public G4VUserDetectorConstruction {
  public:
    G4double FILTER_WIDTH;
    DetectorConstr(G4double F_W);
    virtual ~DetectorConstr();
    virtual G4VPhysicalVolume* Construct();
    virtual void ConstructSDandField(); };
#endif
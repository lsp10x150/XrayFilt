#ifndef ExG4DetectorConstruction01_h
#define ExG4DetectorConstruction01_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "G4Tubs.hh"
class G4VPhysicalVolume;
class G4LogicalVolume;
extern G4double HIST_MAX;

class ExG4DetectorConstruction01 : public G4VUserDetectorConstruction
{
  public:
    G4double FILTER_WIDTH;
    ExG4DetectorConstruction01(G4double F_W);
    virtual ~ExG4DetectorConstruction01();
    virtual G4VPhysicalVolume* Construct();
    virtual void ConstructSDandField();
  protected:
};
#endif


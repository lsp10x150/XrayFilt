#include <G4VisAttributes.hh>
#include <ExG4PrimaryGeneratorAction01.hh>
#include "ExG4DetectorConstruction01.hh"
#include "ExG4DetectorSD.hh"
#include "G4RunManager.hh"
#include "G4SDManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

ExG4DetectorConstruction01::ExG4DetectorConstruction01(G4double F_W)
: G4VUserDetectorConstruction()
{FILTER_WIDTH = F_W;} // В конструкторе инициализируется переданная из мэйна толщина фильтра

ExG4DetectorConstruction01::~ExG4DetectorConstruction01()
{ }

G4VPhysicalVolume* ExG4DetectorConstruction01::Construct() {
    G4NistManager *nist = G4NistManager::Instance();
    G4bool checkOverlaps = true;

    /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
    ///                     Материалы
    /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo

    G4Material *air = nist->FindOrBuildMaterial("G4_AIR");
    G4Material *vacuum = nist->FindOrBuildMaterial("G4_Galactic");
    //G4Material* W = nist->FindOrBuildMaterial("G4_W");
    G4Material *Al = nist->FindOrBuildMaterial("G4_Al");
    G4Material *Cu = nist->FindOrBuildMaterial("G4_Cu");
    G4Material *Sn = nist->FindOrBuildMaterial("G4_Sn");
    G4Material *Zn = nist->FindOrBuildMaterial("G4_Zn");
    G4Material *Si = nist->FindOrBuildMaterial("G4_Si");


    /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
    ///                        Мир
    /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo

    const G4double WORLD_SIZE_XY = 10 * cm;
    const G4double WORLD_SIZE_Z = 75 * cm;

    G4Box *solidWorld = new G4Box("World", WORLD_SIZE_XY, WORLD_SIZE_XY, WORLD_SIZE_Z);
    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, air, "World");
    G4VPhysicalVolume *physWorld =
            new G4PVPlacement(0, G4ThreeVector(), logicWorld, "World",
                              0, false, 0, checkOverlaps);

    /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
    ///                       Трубка
    /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo

    G4Box *solidTube = new G4Box("Tube", 10 * cm, 10 * cm, 4 * cm);
    G4LogicalVolume *logicTube = new G4LogicalVolume(solidTube, vacuum, "Tube");
    logicTube->SetVisAttributes(G4VisAttributes::Invisible);
    new G4PVPlacement(0, G4ThreeVector(0, 0, -50 * cm), logicTube, "Tube",
                      logicWorld, false, 0, checkOverlaps);


    if (config.GetCertainParameter("INHERENT_FILTRATION")){
        /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
        ///          Собственная фильтрация трубки - включается только при параметре INHERENT_FILTRATION == 1
        /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
        G4Box *inherentFiltSolid = new G4Box("inherentFilt", 3 * cm, 3 * cm, 1.25 * mm);
        // Согласно ISO 9236-1, собственная фильтрация кожуха рентгеновской трубки - 2,5 +- 0.2 мм Al
        G4LogicalVolume *inherentFiltLogic = new G4LogicalVolume(inherentFiltSolid, Al, "inherentFilt");
        new G4PVPlacement(0, G4ThreeVector(0, 0, 4 * cm), inherentFiltLogic, "inherentFilt",
                          logicTube, false, 0, checkOverlaps);
    }

    /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
    ///                     Фильтр
    /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo

    G4Material *filterMat = Al;
    /// enum
    /// Al - 0
    /// Cu - 1
    /// Sn - 2
    /// Zn - 3

    switch (int(config.GetCertainParameter("FILTER_MATERIAL")))
    {
        case 0:
            filterMat = Al;
            break;
        case 1:
            filterMat = Cu;
            break;
        case 2:
            filterMat = Sn;
            break;
        case 3:
            filterMat = Zn;
            break;
        default:
            filterMat = Al;
            break;
    }
    std::cout << "Filter Material is: ";
    std::cout << *filterMat;

    G4Box* solidFilt = new G4Box("Filter", 5.*cm, 5.*cm, (FILTER_WIDTH/2)*mm);
    G4LogicalVolume* logicFilt = new G4LogicalVolume(solidFilt, filterMat,"Filter");
    new G4PVPlacement(0,G4ThreeVector(0,0,-40*cm), logicFilt,
                      "Filter", logicWorld, false, 0, checkOverlaps);

    /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
    ///                      Детектор
    /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo

    G4Box* solidDet = new G4Box("Detector", 10*cm, 10*cm, 1*mm);
    G4LogicalVolume* logicDet = new G4LogicalVolume(solidDet, Si,"Detector");
    new G4PVPlacement(0,G4ThreeVector(0,0,50*cm),logicDet,"Detector",
            logicWorld,false,0,checkOverlaps);

  return physWorld;
}

void ExG4DetectorConstruction01::ConstructSDandField()
{
  G4String trackerChamberSDname = "DetectorSD";
  ExG4DetectorSD* aTrackerSD = new ExG4DetectorSD(trackerChamberSDname);
  G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD);
  SetSensitiveDetector("Detector", aTrackerSD, true);
  // Добавляем чувствительный объем ко всем логическим областям с именем Detector
}
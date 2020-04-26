#include <G4VisAttributes.hh>
#include "ExG4DetectorConstruction01.hh"
#include "ExG4DetectorSD.hh"
#include "G4RunManager.hh"
#include "G4SDManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

ExG4DetectorConstruction01::ExG4DetectorConstruction01()
: G4VUserDetectorConstruction()
{ }

ExG4DetectorConstruction01::~ExG4DetectorConstruction01()
{ }

G4VPhysicalVolume* ExG4DetectorConstruction01::Construct()
{
    G4NistManager* nist = G4NistManager::Instance();
    G4int det_sizeZ = 1*mm;
    G4bool checkOverlaps = true;

    /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
    ///                     Материалы
    /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo

    G4Material* air = nist->FindOrBuildMaterial("G4_AIR");
    G4Material* vacuum = nist->FindOrBuildMaterial("G4_Galactic");
    G4Material* W = nist->FindOrBuildMaterial("G4_W");
    G4Material* Al = nist->FindOrBuildMaterial("G4_Al");
    G4Material* Si = nist->FindOrBuildMaterial("G4_Si");

    /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
    ///                        Мир
    /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo

    G4double world_sizeXY = 10*cm;//Размер по x и y здесь будут одинаковы - ширина и высота
    G4double world_sizeZ  = 75*cm;//Размер по z - толщина

    G4Box* solidWorld = new G4Box("World", world_sizeXY, world_sizeXY, world_sizeZ);
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, air,"World");
    G4VPhysicalVolume* physWorld =
            new G4PVPlacement(0,G4ThreeVector(),logicWorld,"World",0,false,0, checkOverlaps);

    /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
    ///                       Трубка
    /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo

    G4Box* solidTube = new G4Box("Tube", 10*cm, 10*cm, 4*cm);
    G4LogicalVolume* logicTube = new G4LogicalVolume(solidTube, vacuum, "Tube");
    logicTube->SetVisAttributes(G4VisAttributes::Invisible);
    new G4PVPlacement(0, G4ThreeVector(0,0,-50*cm), logicTube, "Tube", logicWorld, false, 0, checkOverlaps);

    /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
    ///                       Анод
    /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo

    G4Box* solidAnode = new G4Box("Anode", 2*cm, 2*cm, 2*cm);
    G4LogicalVolume* logicAnode = new G4LogicalVolume(solidAnode, W, "Anode");
    G4RotationMatrix* yRot = new G4RotationMatrix;
    yRot->rotateY(2*M_PI/9.*rad);
    new G4PVPlacement(yRot, G4ThreeVector(1,0,-1*cm), logicAnode, "Anode",
            logicTube, false, 0, checkOverlaps);

    /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
    ///                       Фильтр
    /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo

    G4Box* solidFilt = new G4Box("Filter", 5*cm, 5*cm, 2*mm);
    G4LogicalVolume* logicTar = new G4LogicalVolume(solidFilt, Al,"Target");
    new G4PVPlacement(0,G4ThreeVector(0,0,-45*cm), logicTar,
                      "Target", logicWorld, false, 0, checkOverlaps);

    /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
    ///                      Детектор
    /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo

    G4Box* solidDet = new G4Box("Detector", 10*cm, 10*cm, det_sizeZ);
    G4LogicalVolume* logicDet = new G4LogicalVolume(solidDet, Si,"Detector");
    new G4PVPlacement(0,G4ThreeVector(0,0,-40*cm),logicDet,"Detector",logicWorld,false,0,checkOverlaps);          //overlaps checking, флаг проверки перекрытия объемов
    /*
     /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
     ///              Ловушка для электронов
     /// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo

  // Solid
     G4double innerRadiusOfTheTube = 5.0*mm;
     G4double outerRadiusOfTheTube = 6.0*mm;
     G4double heightOfTheTube = 100.0*mm;
     G4double startAngleOfTheTube = 0.*deg;
     G4double spanningAngleOfTheTube = 360.0*deg;

     G4Tubs* trapTube = new G4Tubs("trapName",
     innerRadiusOfTheTube,
     outerRadiusOfTheTube,
     heightOfTheTube,
     startAngleOfTheTube,
     spanningAngleOfTheTube);

     // Логический объем
     G4LogicalVolume* logicTrap =
             new G4LogicalVolume(trapTube,            //its solid, объем
                                 det_mat,             //its material, указываем материал детектора
                                 "Trap");         //its name, его имя
     new G4PVPlacement(0,                       //no rotation, так же без вращения
                       G4ThreeVector(0,0,-49*cm), //at (0,0,50 см) положение центра детектора, он смещен на 5 см от центра объема World
                       logicTrap,                //its logical volume, подключаем логический объем
                       "Trap",              //its name, имя физического объема
                       logicWorld,              //its mother  volume, родительский логический объем, помещаем в world!
                       false,                   //no boolean operation, без булевых операций
                       0,                       //copy number, номер копии
                       checkOverlaps);          //overlaps checking, флаг проверки перекрытия объемов
 */
  return physWorld;
}

void ExG4DetectorConstruction01::ConstructSDandField()
{
  G4String trackerChamberSDname = "DetectorSD";
  ExG4DetectorSD* aTrackerSD = new ExG4DetectorSD(trackerChamberSDname);
  G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD);
  SetSensitiveDetector("Detector", aTrackerSD, true);  // Добавляем чувствительный объем ко всем логическим областям с именем Detector
}
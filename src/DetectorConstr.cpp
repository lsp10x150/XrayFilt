#include <G4VisAttributes.hh>
#include <PrimaryGenAction.hh>
#include "DetectorConstr.hh"
#include "DetSD.hh"
#include "G4RunManager.hh"
#include "G4SDManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
/// Конструктор
DetectorConstr::DetectorConstr(G4double F_W)
    : G4VUserDetectorConstruction()
// Инициализируется переданная из мэйна толщина фильтра
    {FILTER_WIDTH = F_W;}
/// Деструктор
DetectorConstr::~DetectorConstr(){}
/// Создание геометрии
G4VPhysicalVolume* DetectorConstr::Construct() {
// Вызов нистМенеджера для обращения за данными материалов
G4NistManager *nist = G4NistManager::Instance();
/// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
///                     Материалы
/// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
    G4Material *air = nist->FindOrBuildMaterial("G4_AIR");
    G4Material *vacuum = nist->FindOrBuildMaterial("G4_Galactic");
    G4Material *Al = nist->FindOrBuildMaterial("G4_Al");
    G4Material *Cu = nist->FindOrBuildMaterial("G4_Cu");
    G4Material *Sn = nist->FindOrBuildMaterial("G4_Sn");
    G4Material *Zn = nist->FindOrBuildMaterial("G4_Zn");
    G4Material *Si = nist->FindOrBuildMaterial("G4_Si");
/// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
///                        Мир
/// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
    // Полвинные размеры мира
    const G4double wSizeXY= 10 * cm;
    const G4double wSizeZ = 75 * cm;
    G4Box *solidWorld = new G4Box("World", wSizeXY, wSizeXY, wSizeZ);
    G4LogicalVolume *logicWorld =
            new G4LogicalVolume(solidWorld, air, "World");
    G4VPhysicalVolume *physWorld =
            new G4PVPlacement(0, G4ThreeVector(), logicWorld, "World",
            0, false, 0, true);
/// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
///               Вакуум возле источника
/// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
    G4Box *solidTube = new G4Box("Tube", 10 * cm, 10 * cm, 4 * cm);
    G4LogicalVolume *logicTube = new G4LogicalVolume(solidTube, vacuum, "Tube");
    logicTube->SetVisAttributes(G4VisAttributes::Invisible);
    new G4PVPlacement(0, G4ThreeVector(0, 0, -50 * cm),
            logicTube, "Tube",
            logicWorld, false, 0, true);
/// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
///  Собственная фильтрация трубки - включается только
///       при параметре INHERENT_FILTRATION == 1
/// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
    //Если INHERENT_FILTRATION != 0
    if (config.GetCertainParameter("INHERENT_FILTRATION")){
        // Согласно ISO 9236-1, собственная фильтрация
        // кожуха рентгеновской трубки - 2,5 +- 0.2 мм Al
        G4Box *inherentFiltSolid = new G4Box("inherentFilt",
                3 * cm, 3 * cm, 1.25 * mm);
        G4LogicalVolume *inherentFiltLogic =
        new G4LogicalVolume(inherentFiltSolid, Al, "inherentFilt");
        new G4PVPlacement(0, G4ThreeVector(0, 0, 4 * cm),
        inherentFiltLogic, "inherentFilt",
        logicTube, false, 0, true); }
/// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
///                     Фильтр
/// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
    G4Material *filterMat = Al;
    if (!(FILTER_WIDTH <= 0)){
        switch (int(config.GetCertainParameter("FILTER_MATERIAL"))) {
            case 0: filterMat = Al; break;
            case 1: filterMat = Cu; break;
            case 2: filterMat = Sn; break;
            case 3: filterMat = Zn; break;
            default: filterMat = Al; break; }
        std::cout << "Filter Material is: ";
        std::cout << *filterMat;
        G4Box* solidFilt = new G4Box("Filter",
                5.*cm, 5.*cm, (FILTER_WIDTH/2)*mm);
        G4LogicalVolume* logicFilt = new G4LogicalVolume(solidFilt, filterMat,"Filter");
        new G4PVPlacement(0,G4ThreeVector(0,0,-40*cm), logicFilt,
                "Filter", logicWorld, false, 0, true);
    } else { std::cout << "Filter width is 0 or less. If that's not "
          "intended, then check configs.\n";}
/// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
///                      Детектор
/// oooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOoooOOOooo
    G4Box* solidDet = new G4Box("Detector", 10*cm, 10*cm, 1*mm);
    G4LogicalVolume* logicDet = new G4LogicalVolume(solidDet, Si,"Detector");
    new G4PVPlacement(0,G4ThreeVector(0,0,50*cm),logicDet,"Detector",
    logicWorld,false,0,true);
    return physWorld; }
/// Объявление чувствительной области
void DetectorConstr::ConstructSDandField() {
    G4String trackerChamberSDname = "DetectorSD";
    DetSD* aTrackerSD = new DetSD(trackerChamberSDname);
    G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD);
    // Добавляем чувствительный объем ко всем логическим областям с именем Detector
    SetSensitiveDetector("Detector", aTrackerSD, true);  }
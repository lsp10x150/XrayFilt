#include <G4SIunits.hh>
#include <map>
#include <ExG4PrimaryGeneratorAction01.hh>
#include "G4RunManager.hh"
#include"QBBC.hh"
#include "G4UImanager.hh"
#include "ExG4DetectorConstruction01.hh"
#include "ExG4ActionInitialization01.hh"
#ifdef G4UI_USE
#include "G4VisExecutive.hh"//Визуализация
#include "G4UIExecutive.hh"//Выбор соответствующего интерфейса пользователя
#endif
int cntr = 0;
int startTime = time(NULL);

int main(int argc,char** argv)
{
G4RunManager* runManager = new G4RunManager;
//runManager->SetNumberOfThreads(G4Threading::G4GetNumberOfCores());
runManager->SetUserInitialization(new ExG4DetectorConstruction01);
runManager->SetUserInitialization(new QBBC);
runManager->SetUserInitialization(new ExG4ActionInitialization01);
runManager->Initialize();
G4VisManager* visManager = new G4VisExecutive;
visManager->Initialize();
G4UImanager* UImanager = G4UImanager::GetUIpointer();
if ( argc == 1 ) {
#ifdef G4UI_USE
G4UIExecutive* ui = new G4UIExecutive(argc, argv);
UImanager->ApplyCommand("/control/execute vis.mac");
ui->SessionStart();
delete ui;
#endif
}
else {
G4String command = "/control/execute ";
G4String fileName = argv[1];
UImanager->ApplyCommand(command+fileName);
}
delete runManager;
return 0;
}

﻿#include <G4SIunits.hh>
#include <map>
#include <ExG4PrimaryGeneratorAction01.hh>
#include <ExG4DetectorSD.hh>
#include "G4RunManager.hh"
#include"QBBC.hh"
#include "G4UImanager.hh"
#include "ExG4DetectorConstruction01.hh"
#include "ExG4ActionInitialization01.hh"
#ifdef G4UI_USE
#include "G4VisExecutive.hh"//Визуализация
#include "G4UIExecutive.hh"//Выбор соответствующего интерфейса пользователя
#include "G4GeometryManager.hh"
#include "spectraManager.hh"
#endif
int cntr = 0;                   // Счетчик для откидывания в консоль информации о текущем количестве сгенерированных частиц
int startTime = time(NULL); // Время запуска программы для откидывания в консоль информации о времени прошешем с момента запуска
spectraManager spectras;

int main(int argc,char** argv)
{
G4double FILTER_WIDTH = 10; // Толщина фильтра в мм, далее передается в констуктор геометрии
G4RunManager* runManager = new G4RunManager;
//runManager->SetNumberOfThreads(G4Threading::G4GetNumberOfCores()); // Метод для указания количества рабочих потоков
// пока предполагаю работу в однопоточном режиме
G4VUserDetectorConstruction *geometry = new ExG4DetectorConstruction01(FILTER_WIDTH); // Передача толщины фильтра
runManager->SetUserInitialization(geometry);
// в конструктор геометрии, а конструктора геометрии в ранМенеджер
runManager->SetUserInitialization(new QBBC); // В качестве списка физических взаимодействий выбран QBBC
// Этот список рекомендуется в медицинских приложениях
runManager->SetUserInitialization(new ExG4ActionInitialization01);
runManager->Initialize();
G4VisManager* visManager = new G4VisExecutive;
visManager->Initialize();
G4UImanager* UImanager = G4UImanager::GetUIpointer();

/// Запуск визуализирущего макроса
/*
if ( argc == 1 ) {
#ifdef G4UI_USE
G4UIExecutive* ui = new G4UIExecutive(argc, argv);
UImanager->ApplyCommand("/control/execute vis.mac");
ui->SessionStart();
delete ui;
#endif
}
 */
/// Запуск макроса без визуализации
//else {
//G4String command = "/control/execute ";
//G4String fileName = argv[1];
//UImanager->ApplyCommand(command+fileName);
//}
runManager->BeamOn(3000000);
spectras.PushGottenSpectraToFile();
spectras.RenewGottenSpectra();
for (int i = 9; i != 0; --i){
    cntr = 0;
    FILTER_WIDTH = i;
    geometry = new ExG4DetectorConstruction01(FILTER_WIDTH); // Передача толщины фильтра
    runManager->SetUserInitialization(geometry);
    runManager->ReinitializeGeometry(true);
    runManager->BeamOn(3000000);
    spectras.PushGottenSpectraToFile();
    spectras.RenewGottenSpectra();
}

delete runManager;
return 0;
}

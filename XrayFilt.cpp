#include <G4SIunits.hh>
#include <map>
#include <ExG4PrimaryGeneratorAction01.hh>
#include <ExG4DetectorSD.hh>
#include <GetConfig.hh>
#include "G4RunManager.hh"
#include"QBBC.hh"
#include "G4UImanager.hh"
#include "ExG4DetectorConstruction01.hh"
#include "ExG4ActionInitialization01.hh"
#include "G4GeometryManager.hh"
#include "spectraManager.hh"
#ifdef G4UI_USE
#include "G4VisExecutive.hh"//Визуализация
#include "G4UIExecutive.hh"//Выбор соответствующего интерфейса пользователя
#endif
int cntr = 0;
int startTime = time(nullptr); // Время старта программы
Config config;           // Объект параметров хранит переменные, необходимые для запуска программы,
                         // прочитанные из файла config.dat
spectraManager spectras; // Объект менеджера спектров, в котором
                         // хранятся исходный спектр и спектр текущей итерации

int main(int argc,char** argv)
{
    G4String configFilePath = argv[1];
    config.SetConfigFile(configFilePath);
    config.ShowParameters();
    if (!spectras.SetInitialSpectraFile(config.GetPathToInitialSpectra()))
        std::cout << "Could not retrieve initial spectra file. \n";
    //spectras.ShowSpectra();

    const G4int n_particles = config.GetCertainParameter("N_PARTICLES");
    G4double filter_width = config.GetCertainParameter("FILTER_WIDTH");
    // Толщина фильтра в мм, далее передается в констуктор геометрии
    const G4int n_iterations = config.GetCertainParameter("N_ITERATIONS") - 1;
    const G4double step_reducing_filter_width =
            config.GetCertainParameter("STEP_REDUCING_FILTER_WIDTH");

/// Выделение памяти для ранМенеджера и запуск его конструктора
    G4RunManager* runManager = new G4RunManager;
/// Инициализация спсиска физических процессов и передача его в ранМенеджер
    auto physList = new QBBC; // В качестве списка физических взаимодействий выбран QBBC
    physList->SetVerboseLevel(0);// Этот список рекомендуется в медицинских приложениях
    runManager->SetUserInitialization(physList);
/// Инициализация геометрии см. ExG4DetectorConstruction01.cpp
    G4VUserDetectorConstruction *geometry = new ExG4DetectorConstruction01(filter_width); // Передача толщины фильтра
    runManager->SetUserInitialization(geometry);// в конструктор геометрии, а конструктора геометрии в ранМенеджер
/// Инициализация пользовательских действий см. ExG4ActionInitialization01.cpp
    runManager->SetUserInitialization(new ExG4ActionInitialization01);
    runManager->Initialize();

/// Запуск визуализирущего макроса (исключительно для демонстрационных целей)
    if ( argc == 3 ) {
        G4VisManager* visManager = new G4VisExecutive;
        visManager->Initialize();
        G4UImanager* UImanager = G4UImanager::GetUIpointer();
        #ifdef G4UI_USE
        G4UIExecutive* ui = new G4UIExecutive(argc, argv);
        G4String command = "/control/execute ";
        G4String fileName = argv[2];
        UImanager->ApplyCommand(command+fileName);
        ui->SessionStart();
        delete ui;
        #endif
    }

/// В рабочем режиме исполняется цикл, если n_iterations != 0, иначе выполняется только один прогон симуляции
    else {
        runManager->BeamOn(n_particles);
        spectras.PushGottenSpectraToFile();
        spectras.RenewGottenSpectra();

        if(n_iterations) {
            for (int i = 0; i < n_iterations; ++i) {
                cntr = 0;
                filter_width -= step_reducing_filter_width;
                geometry = new ExG4DetectorConstruction01(filter_width);
                runManager->SetUserInitialization(geometry);
                runManager->ReinitializeGeometry(true);
                runManager->BeamOn(n_particles);
                spectras.PushGottenSpectraToFile();
                spectras.RenewGottenSpectra();
            }
        }
    }
delete runManager;
return 0;
}
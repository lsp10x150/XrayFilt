#include "PrimaryGenAction.hh"
#include "DetSD.hh"
#include "Config.hh"
#include "G4RunManager.hh"
#include "QBBC.hh"
#include "G4UImanager.hh"
#include "DetectorConstr.hh"
#include "ActionInit.hh"
#include "G4GeometryManager.hh"
#include "SpectraManager.hh"
#ifdef G4UI_USE
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#endif
int cntr = 0;
int startTime = time(nullptr); // Время старта программы
// Объект параметров хранит переменные, необходимые для запуска программы,
// прочитанные из файла config.dat
Config config;
// Объект менеджера спектров, в котором
// хранятся исходный спектр и спектр текущей итерации
SpectraManager spectras;
int main(int argc,char** argv) {
    if (argv[1] == 0) {
        std::cout << "To run this process properly, one should input "
                     "a path to config.dat after ./Xrayfilt.\n"
                     "In such manner: './XrayFilt config.dat'\n"
                     "Don't be upset. Try again.\n";
        return EXIT_FAILURE; }
    // первый аргумент - путь к файлу с настройками
    G4String configFilePath = argv[1];
    // устанавливаем путь для чтения
    config.SetConfigFile(configFilePath);
    // Вывод прочтенных параметров в консоль
    config.ShowParameters();
/// Если файл не прочелся, уведомдяем пользователя
    if (!spectras.SetInitialSpectraFile(config.GetPathToInitialSpectra()))
        std::cout << "Could not retrieve initial spectra file. \n";
/// Установка промежуточных переменных для параметров из конфиг для удобства
    const G4int n_particles = config.GetCertainParameter("N_PARTICLES");
    G4double filter_width = config.GetCertainParameter("FILTER_WIDTH");
    const G4int n_iterations = config.GetCertainParameter("N_ITERATIONS") - 1;
    const G4double step_reducing_filter_width =
            config.GetCertainParameter("STEP_REDUCING_FILTER_WIDTH");
/// Выделение памяти для ранМенеджера и запуск его конструктора
    G4RunManager* runManager = new G4RunManager;
/// Инициализация спсиска физических процессов и его передача  в ранМенеджер
    // В качестве списка физических взаимодействий выбран QBBC
    auto physList = new QBBC;
    physList->SetVerboseLevel(0);
    runManager->SetUserInitialization(physList);
/// Инициализация геометрии см. DetectorConstr.cpp
    // Передача толщины фильтра
    G4VUserDetectorConstruction *geometry = new DetectorConstr(filter_width);
    // в конструктор геометрии, а конструктора геометрии в ранМенеджер
    runManager->SetUserInitialization(geometry);
/// Инициализация пользовательских действий см. ActionInit.cpp
    runManager->SetUserInitialization(new ActionInit);
    runManager->Initialize();
/// Запуск визуализирущего макроса (исключительно для демонстрационных целей)
    if ( argc == 3 ) {
        G4VisManager *visManager = new G4VisExecutive;
        visManager->Initialize();
        G4UImanager *UImanager = G4UImanager::GetUIpointer();
#ifdef G4UI_USE
        G4UIExecutive *ui = new G4UIExecutive(argc, argv);
        G4String command = "/control/execute ";
        G4String fileName = argv[2];
        UImanager->ApplyCommand(command + fileName);
        ui->SessionStart();
        delete ui;
#endif
/// В рабочем режиме исполняется цикл, если n_iterations != 0,
/// иначе выполняется только один прогон симуляции
    } else {
        runManager->BeamOn(n_particles);
        spectras.PushGottenSpectraToFile();
        spectras.RenewGottenSpectra();
        if(n_iterations) {
            for (int i = 0; i < n_iterations; ++i) {
                cntr = 0;
                filter_width -= step_reducing_filter_width;
                geometry = new DetectorConstr(filter_width);
                runManager->SetUserInitialization(geometry);
                runManager->ReinitializeGeometry(true);
                runManager->BeamOn(n_particles);
                spectras.PushGottenSpectraToFile();
                spectras.RenewGottenSpectra(); } } }
delete runManager;
return EXIT_SUCCESS; }
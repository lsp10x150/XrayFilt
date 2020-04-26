#include<G4Step.hh>
#include<fstream>
#include<iostream>
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "ExG4DetectorSD.hh"

ExG4DetectorSD::ExG4DetectorSD(G4String name): G4VSensitiveDetector(name),
                             HIST_MAX(100*keV),// Инициализация верхней границы
                             HIST_MIN(0 *keV)// Инициализация нижней границы
{
  for(int i = 0; i<NOBINSenergies; i++){
    histogram[i] = 0;
    histogram_angle[i] = 0;
  }
}

G4bool ExG4DetectorSD::ProcessHits(G4Step* step, G4TouchableHistory* history)
   {
           /// Заполняем гистограмму энергетического распределения
    double bin_width = (HIST_MAX - HIST_MIN) / NOBINSenergies;
    double energy = step->GetPreStepPoint()->GetKineticEnergy();
    if(step->GetTrack()->GetDefinition()->GetParticleName() == "gamma" ){
            // Определяем индекс (номер) бина гистограммы энергии
         int index = int(floor((energy-HIST_MIN)/bin_width));
            // Добавляем +1 в соответствующий бин
         if(index >= 0 && index < NOBINSenergies)
           histogram[index]++;
           /// Далее заполняем гистограмму углового распределения
         G4ThreeVector ang = step->GetPreStepPoint()->GetMomentumDirection(); // Получаем вектор направления частицы
         G4ThreeVector *centerVector = new G4ThreeVector(0, 0, 1); // Задаем единичный вектор в направлении оси OZ для измерения угла
         double angle=ang.angle(*centerVector); // Применяем фунцию класса G4ThreeVector - находим угол относительно вектора centerVector
         double bin_width_ang = (181) / NOBINSangles;
         index = int(floor((angle)/bin_width_ang));
         if(index >= 0 && index < NOBINSangles)
             histogram_angle[index]++;
}
     step->GetTrack()->SetTrackStatus(fStopAndKill);
     return true;
   }


ExG4DetectorSD::~ExG4DetectorSD()
{
    std::ofstream file("spectrum.dat");
    double bin_width = (HIST_MAX - HIST_MIN) / NOBINSenergies;
    for(int i = 0; i<NOBINSenergies; i++)
    {
        double energy = i*bin_width + HIST_MIN;
        file << std::setw(15) << energy/keV << " "
             << std::setw(15) << histogram[i] << std::endl;
    }
    file.close();
    file.open("angle.dat");
    bin_width = (181) / NOBINSangles;
    for(int i = 0; i<NOBINSangles; i++)
    {
        double angle = i*bin_width;
        file << std::setw(15) << angle << " "
             << std::setw(15) << histogram_angle[i] << std::endl;
    }
    file.close();
}
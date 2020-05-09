#include<G4Step.hh>
#include<fstream>
#include<iostream>
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "ExG4DetectorSD.hh"

ExG4DetectorSD::ExG4DetectorSD(G4String name): G4VSensitiveDetector(name),
                             HIST_MAX(160),// Инициализация верхней границы
                             HIST_MIN(0) // Инициализация нижней границы
                             {
  for(int i = 0; i<HIST_MAX; i++){
    histogram[i] = 0;
    histogram_angle[i] = 0;
  }
}

G4bool ExG4DetectorSD::ProcessHits(G4Step* step, G4TouchableHistory* history)
   {
           /// Заполняем гистограмму энергетического распределения
        double energy = step->GetPreStepPoint()->GetKineticEnergy()/keV;
        if(step->GetTrack()->GetDefinition()->GetParticleName() == "gamma" ){
         int index = int(floor(energy));
         if(index >= 0 && index < HIST_MAX)
           histogram[index]++;
           /// Далее заполняем гистограмму углового распределения
         G4ThreeVector ang = step->GetPreStepPoint()->GetMomentumDirection();
         G4ThreeVector *centerVector = new G4ThreeVector(0, 0, 1);
         double angle=ang.angle(*centerVector);
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
    for(int i = 0; i<HIST_MAX; i++)
    {
        double energy = i;
        file << std::setw(15) << energy << " "
             << std::setw(15) << histogram[i] << std::endl;
    }
    file.close();
    file.open("angle.dat");
    for(int i = 0; i<181; i++)
    {
        double angle = i;
        file << std::setw(15) << angle << " "
             << std::setw(15) << histogram_angle[i] << std::endl;
    }
    file.close();
}
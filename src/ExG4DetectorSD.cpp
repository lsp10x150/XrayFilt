#include<G4Step.hh>
#include<fstream>
#include<iostream>
#include <ExG4PrimaryGeneratorAction01.hh>
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "ExG4DetectorSD.hh"

ExG4DetectorSD::ExG4DetectorSD(G4String name): G4VSensitiveDetector(name){}

G4bool ExG4DetectorSD::ProcessHits(G4Step* step, G4TouchableHistory* history)
   {
           /// Вызываем метод спектраМенеджера,
           /// заполняющий гистограмму энергетического рапсределения
     spectras.CollectSpectra(step, history);
    /*
           /// Гистограмма углового распределения
     G4ThreeVector ang = step->GetPreStepPoint()->GetMomentumDirection();
     G4ThreeVector *centerVector = new G4ThreeVector(0, 0, 1);
     double angle=ang.angle(*centerVector);
     double bin_width_ang = (181) / NOBINSangles;
     index = int(floor((angle)/bin_width_ang));
     if(index >= 0 && index < NOBINSangles)
         histogram_angle[index]++;
          */
     step->GetTrack()->SetTrackStatus(fStopAndKill); // "Убиваем" частицу, попавшую в детектор
     return true;
   }

ExG4DetectorSD::~ExG4DetectorSD(){}
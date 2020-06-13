#include<G4Step.hh>
#include <PrimaryGenAction.hh>
#include "G4ThreeVector.hh"
#include "DetSD.hh"
DetSD::DetSD(G4String name): G4VSensitiveDetector(name){}
G4bool DetSD::ProcessHits(G4Step* step, G4TouchableHistory* history)
   { // Вызываем метод спектраМенеджера,
    // заполняющий гистограмму энергетического рапсределения
    spectras.CollectSpectra(step, history);
    // "Убиваем" частицу, попавшую в детектор
    step->GetTrack()->SetTrackStatus(fStopAndKill);
    return true; }
DetSD::~DetSD(){}
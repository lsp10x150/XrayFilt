#include <G4Gamma.hh>
#include <G4Electron.hh>
#include "ExG4PrimaryGeneratorAction01.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include<ctime>

void counter() // Функция выводит в консоль сведения о количестве обработанных событий и времени работы программы
{
    ++cntr;
    if (cntr % 1000 == 0) std::cout << cntr << " particles processed. Processing time: " << std::time(NULL) - startTime << " seconds.\n";
}

std::map<G4double, G4double> spectra (map_start_values, map_start_values + map_start_values_size);

ExG4PrimaryGeneratorAction01::ExG4PrimaryGeneratorAction01()
: G4VUserPrimaryGeneratorAction(),
  fParticleGun(0), 
  fEnvelopeBox(0)
{
  G4int n_particle = 1;
  fParticleGun  = new G4ParticleGun(n_particle);
  //fParticleGun->SetParticleDefinition(G4Gamma::GammaDefinition());  // Устанавливаем гамма-кванты в качестве испускаемого типа начальных частиц в источнике
    fParticleGun->SetParticleDefinition(G4Electron::ElectronDefinition());
}

ExG4PrimaryGeneratorAction01::~ExG4PrimaryGeneratorAction01()
{
  delete fParticleGun;
}

void ExG4PrimaryGeneratorAction01::GeneratePrimaries(G4Event* anEvent)
{
        //G4double angleX = (G4UniformRand()*0.33 - 0.16);
        //G4double angleY = (G4UniformRand()*0.33 - 0.16);
        //fParticleGun->SetParticleMomentumDirection(G4ThreeVector(angleX, angleY,1.));
    //fParticleGun->SetParticleEnergy(spectra.upper_bound(G4UniformRand())->second*keV); // Установка начальной энергии испускаемых частиц, 50 кэВ
    G4double x0 = -3*cm;
    G4double y0 = 0+0.6*cm*G4UniformRand()-0.3*cm;
    G4double z0 = -49*cm+0.6*cm*G4UniformRand()-0.3*cm;
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(1.,0.,0.));
    fParticleGun->SetParticleEnergy(100*keV);
    fParticleGun->SetParticlePosition(G4ThreeVector(x0,y0,z0));
    fParticleGun->GeneratePrimaryVertex(anEvent);
  counter();
}
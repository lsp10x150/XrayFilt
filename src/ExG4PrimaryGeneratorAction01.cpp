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
#include <ctime>
#include <fstream>
#include <map>
#include <algorithm>

void counter() // Функция выводит в консоль сведения о количестве обработанных событий и времени работы программы
{
    ++cntr;
    if (cntr % 1000 == 0) std::cout << cntr << " particles processed. It is " << spectras.GetCntr() <<
    " iteration. Processing time: " <<
    std::time(NULL) - startTime << " seconds." << std::endl;
}



ExG4PrimaryGeneratorAction01::ExG4PrimaryGeneratorAction01()
: G4VUserPrimaryGeneratorAction(),
  fParticleGun(0), 
  fEnvelopeBox(0)
{
  //spectraManager initialSpectra;
  G4int n_particle = 1; // Число частиц в одном первичном событии
  fParticleGun  = new G4ParticleGun(n_particle); // Инициализация пушки частиц
  fParticleGun->SetParticleDefinition(G4Gamma::GammaDefinition()); // Установка пушки на излучение гамма-частиц
}

ExG4PrimaryGeneratorAction01::~ExG4PrimaryGeneratorAction01()
{
  delete fParticleGun;
}

/// Данный метод вызывается на каждом шаге при рождении первичной частицы в пушке. Здесь устанавливаются
/// исходные параметры частицы: направление, энергия и точка в пространстве, где родится частица.
void ExG4PrimaryGeneratorAction01::GeneratePrimaries(G4Event* anEvent)
{
    /// Установка направления частицы.
    /// Угол вылета частицы в направлении детектора должен быть случайным в определенных пределах.
    /// Для эффективности в рамках модели выбран телесный угол описанной вокруг детектора окружности.
    /// Переменнные angleX и angleY принимают случайное значение
    G4double angleX = (G4UniformRand()*0.2 - 0.1); // Контролирует угол вылета частиц
    G4double angleY = (G4UniformRand()*0.2 - 0.1);
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(angleX, angleY,1.));

    /// Переменной kineticEnergy присваивается энергия в соответствии с подготовленным в spectraManager::initialSpectra
    /// распределением вероятностей
    G4double kineticEnergy = spectras.getInitialSpectra().upper_bound(G4UniformRand())->second;
    fParticleGun->SetParticleEnergy(kineticEnergy*keV); // Установка начальной энергии испускаемых частиц
    G4double x0 = 0*cm;
    G4double y0 = 0*cm;
    G4double z0 = -50*cm;
    fParticleGun->SetParticlePosition(G4ThreeVector(x0,y0,z0));

    fParticleGun->GeneratePrimaryVertex(anEvent);
  counter();
}
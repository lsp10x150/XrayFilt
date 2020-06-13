#include <G4Gamma.hh>
#include "PrimaryGenAction.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include <fstream>
#include <map>
#include <algorithm>
/// Функция-счетчик событий - выводит в консоль сведения о
/// количестве обработанных событий и времени работы программы
void counter() {
    ++cntr;
    if (cntr % 1000 == 0) std::cout << std::setw(12) <<
    cntr << " particles processed. It is " << std::setw(2) <<
    spectras.GetCntr() << " iteration. Processing time: " <<
    std::setw(9) << std::time(0) - startTime << " seconds." <<
    std::endl; }
/// Конструктор
PrimaryGenAction::PrimaryGenAction()
: G4VUserPrimaryGeneratorAction(),
    fParticleGun(0),
    fEnvelopeBox(0) {
    // Число частиц в одном первичном событии
    G4int n_particle = 1;
    // Инициализация пушки частиц
    fParticleGun  = new G4ParticleGun(n_particle);
    // Установка пушки на излучение гамма-частиц
    fParticleGun->SetParticleDefinition(G4Gamma::GammaDefinition()); }
PrimaryGenAction::~PrimaryGenAction() {
  delete fParticleGun; }
/// Данный метод вызывается на каждом шаге при рождении
/// первичной частицы в пушке. Здесь устанавливаются
/// исходные параметры частицы: направление, энергия и
/// точка в пространстве, где родится частица.
void PrimaryGenAction::GeneratePrimaries(G4Event* anEvent) {
    // Установка направления частицы.
    // Угол вылета частицы в направлении детектора должен быть
    // случайным в определенных пределах.
    // Для эффективности в рамках модели выбран телесный угол
    // описанной вокруг детектора окружности.
    // Переменнные angleX и angleY принимают случайное значение
    G4double angleX = (G4UniformRand()*0.2 - 0.1);
    G4double angleY = (G4UniformRand()*0.2 - 0.1);
    fParticleGun->SetParticleMomentumDirection
                    (G4ThreeVector(angleX, angleY,1.));
    // Переменной kineticEnergy присваивается энергия в соответствии с
    // подготовленным в SpectraManager распределением вероятностей
    G4double kineticEnergy = spectras.getInitialSpectra().upper_bound
                                         (G4UniformRand())->second;
    // Установка начальной энергии испускаемых частиц
    fParticleGun->SetParticleEnergy(kineticEnergy*keV);
    // Положение пушки частиц
    fParticleGun->SetParticlePosition(G4ThreeVector
                                     (0*cm,0*cm,-50*cm));
    fParticleGun->GeneratePrimaryVertex(anEvent);
// Вызов функции-счетчика
  counter(); }
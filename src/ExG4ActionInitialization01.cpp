/// \file ExG4ActionInitialization01.cpp
/// \brief Implementation of the ExG4ActionInitialization01 class
#include <G4SIunits.hh>
#include "ExG4ActionInitialization01.hh"
#include "ExG4PrimaryGeneratorAction01.hh"

ExG4ActionInitialization01::ExG4ActionInitialization01()
 : G4VUserActionInitialization()
{}

ExG4ActionInitialization01::~ExG4ActionInitialization01()
{}

void ExG4ActionInitialization01::Build() const
{
SetUserAction(new ExG4PrimaryGeneratorAction01);//Задается источник первичных частиц
}

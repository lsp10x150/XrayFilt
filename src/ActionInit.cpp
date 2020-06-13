#include <G4SIunits.hh>
#include "ActionInit.hh"
#include "PrimaryGenAction.hh"
ActionInit::ActionInit()
 : G4VUserActionInitialization(){}
ActionInit::~ActionInit(){}
void ActionInit::Build() const {
SetUserAction(new PrimaryGenAction); }
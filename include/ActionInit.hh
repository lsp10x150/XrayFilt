#ifndef ExG4ActionInitialization01_h
#define ExG4ActionInitialization01_h 1
#include "G4VUserActionInitialization.hh"
class ActionInit : public G4VUserActionInitialization {
public:
    ActionInit();
    virtual ~ActionInit();
    virtual void Build() const; };
#endif
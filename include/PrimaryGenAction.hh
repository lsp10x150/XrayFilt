#ifndef B1PrimaryGeneratorAction_h
#define B1PrimaryGeneratorAction_h 1
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"
#include "SpectraManager.hh"
#include "Config.hh"
#include <map>
class G4ParticleGun;
class G4Event;
class G4Box;
extern int cntr;
extern int startTime;
extern SpectraManager spectras;
extern Config config;
class PrimaryGenAction : public G4VUserPrimaryGeneratorAction {
    G4ParticleGun*  fParticleGun;
    G4Box* fEnvelopeBox;
public:
    PrimaryGenAction();
    virtual ~PrimaryGenAction();
    virtual void GeneratePrimaries(G4Event*); };
#endif
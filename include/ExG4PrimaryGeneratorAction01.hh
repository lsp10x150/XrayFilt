#ifndef B1PrimaryGeneratorAction_h
#define B1PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"
#include "spectraManager.hh"
#include "GetConfig.hh"
#include <map>

class G4ParticleGun;
class G4Event;
class G4Box;
extern int cntr;
extern int startTime;
extern spectraManager spectras;
extern Config config;

class ExG4PrimaryGeneratorAction01 : public G4VUserPrimaryGeneratorAction
{
  public:
    //spectraManager initialSpectra;
    ExG4PrimaryGeneratorAction01();
    virtual ~ExG4PrimaryGeneratorAction01();
    virtual void GeneratePrimaries(G4Event*);
    const G4ParticleGun* GetParticleGun() const { return fParticleGun; }
  private:
    G4ParticleGun*  fParticleGun;
    G4Box* fEnvelopeBox;
};
#endif

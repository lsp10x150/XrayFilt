#ifndef B1PrimaryGeneratorAction_h
#define B1PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"
#include <map>

class G4ParticleGun;
class G4Event;
class G4Box;
typedef std::pair<G4double , G4double> pair_t;
extern int cntr;
extern int startTime;
const pair_t map_start_values[] = { // Мой спектр
        pair_t(0.02658550318098, 12 ),
        pair_t(0.053234329075122, 13 ),
        pair_t(0.081823626110617, 14 ),
        pair_t(0.111653134508814, 15 ),
        pair_t(0.142293439188655, 16 ),
        pair_t(0.173213082362022, 17 ),
        pair_t(0.204012562730332, 18 ),
        pair_t(0.234407055003141, 19 ),
        pair_t(0.264200420835176, 20 ),
        pair_t(0.293247777546305, 21 ),
        pair_t(0.321448507825111, 22 ),
        pair_t(0.348726284663961, 23 ),
        pair_t(0.375040845517513, 24 ),
        pair_t(0.400375593313247, 25 ),
        pair_t(0.424736834938719, 26 ),
        pair_t(0.448136383604373, 27 ),
        pair_t(0.470598978711248, 28 ),
        pair_t(0.492138034599138, 29 ),
        pair_t(0.512789322840818, 30 ),
        pair_t(0.53259066523567, 31 ),
        pair_t(0.551565895179835, 32 ),
        pair_t(0.569756298379362, 33 ),
        pair_t(0.587201448112932, 34 ),
        pair_t(0.603926300519828, 35 ),
        pair_t(0.619956706028652, 36 ),
        pair_t(0.635334157320708, 37 ),
        pair_t(0.650085883357916, 38 ),
        pair_t(0.664239448948841, 39 ),
        pair_t(0.677821688630853, 40 ),
        pair_t(0.690860762754532, 41 ),
        pair_t(0.703381037774936, 42 ),
        pair_t(0.715405790598128, 43 ),
        pair_t(0.726958608593056, 44 ),
        pair_t(0.738058560819749, 45 ),
        pair_t(0.748725637963912, 46 ),
        pair_t(0.758979283984152, 47 ),
        pair_t(0.768837017578665, 48 ),
        pair_t(0.778315344047926, 49 ),
        pair_t(0.787430848748876, 50 ),
        pair_t(0.796198334317606, 51 ),
        pair_t(0.804631898502778, 52 ),
        pair_t(0.812744225372991, 53 ),
        pair_t(0.820549805148855, 54 ),
        pair_t(0.828059129132801, 55 ),
        pair_t(0.835286326315037, 56 ),
        pair_t(0.842237361878686, 57 ),
        pair_t(0.857638828158384, 58 ),
        pair_t(0.879197839585235, 59 ),
        pair_t(0.885387454181694, 60 ),
        pair_t(0.89134040233438, 61 ),
        pair_t(0.897066167805789, 62 ),
        pair_t(0.902571526106705, 63 ),
        pair_t(0.907864441879342, 64 ),
        pair_t(0.912951100950257, 65 ),
        pair_t(0.917839979542019, 66 ),
        pair_t(0.927394287409285, 67 ),
        pair_t(0.931903836979664, 68 ),
        pair_t(0.937492040056222, 69 ),
        pair_t(0.94150511260957, 70 ),
        pair_t(0.945359501528835, 71 ),
        pair_t(0.949059117865342, 72 ),
        pair_t(0.952608370582591, 73 ),
        pair_t(0.95601130155589, 74 ),
        pair_t(0.959270060594281, 75 ),
        pair_t(0.962389142575522, 76 ),
        pair_t(0.965369863549834, 77 ),
        pair_t(0.968217069862392, 78 ),
        pair_t(0.970931968218, 79 ),
        pair_t(0.973518793799046, 80 ),
        pair_t(0.975978142147543, 81 ),
        pair_t(0.978314184010187, 82 ),
        pair_t(0.980527007253832, 83 ),
        pair_t(0.982620466304496, 84 ),
        pair_t(0.984593996861714, 85 ),
        pair_t(0.986451506266877, 86 ),
        pair_t(0.988191961401036, 87 ),
        pair_t(0.989818710772386, 88 ),
        pair_t(0.991330121619511, 89 ),
        pair_t(0.992729536202297, 90 ),
        pair_t(0.994014337455297, 91 ),
        pair_t(0.995187962144081, 92 ),
        pair_t(0.996246497069468, 93 ),
        pair_t(0.997193517631399, 94 ),
        pair_t(0.998016430361762, 95 ),
        pair_t(0.998719049267825, 96 ),
        pair_t(0.999302304176167, 97 ),
        pair_t(0.999769831798267, 98 ),
        pair_t(1, 99 ),
        pair_t( 1, 100)
};
const int map_start_values_size = sizeof(map_start_values) / sizeof(map_start_values[0]);

class ExG4PrimaryGeneratorAction01 : public G4VUserPrimaryGeneratorAction
{
  public:
    ExG4PrimaryGeneratorAction01();
    virtual ~ExG4PrimaryGeneratorAction01();
    virtual void GeneratePrimaries(G4Event*);
    const G4ParticleGun* GetParticleGun() const { return fParticleGun; }
  private:
    G4ParticleGun*  fParticleGun;
    G4Box* fEnvelopeBox;
};
#endif

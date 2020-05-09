#include<G4VSensitiveDetector.hh>
#ifndef ExG4DetectorSD_h
#define ExG4DetectorSD_h 1


   class G4Step;
   class G4TouchableHistory;
   class ExG4DetectorSD: public G4VSensitiveDetector
     {
     private:
       static const int NOBINSangles = 181;
       const double HIST_MAX;
       const double HIST_MIN;
       int histogram[180];
       int histogram_angle[NOBINSangles];
     public:
        ExG4DetectorSD(G4String name);
        ~ExG4DetectorSD();
        G4bool ProcessHits(G4Step* step, G4TouchableHistory* history);
     };
#endif

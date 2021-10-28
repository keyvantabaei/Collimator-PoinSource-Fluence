#ifndef HistoManager_h
#define HistoManager_h 1

#include "globals.hh"

class TFile;
class TTree;
class TH3D;
class HistoManager
{
public:
 HistoManager();
~HistoManager();

void Book();
void Save();
void Draw();
void Fill_3D_Histogram(G4double,G4double,G4double,G4double);


private:

TH3D*   _histo3Ddose;


TFile* rootfile;

};
#endif
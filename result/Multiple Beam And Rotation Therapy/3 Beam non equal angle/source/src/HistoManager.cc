#include "HistoManager.hh"
#include <TTree.h>
#include <TFile.h>
#include <TH3D.h>
//there is another way to include following header .
#include <CLHEP/Units/SystemOfUnits.h>
HistoManager::HistoManager():rootfile(0)
{

  _histo3Ddose=0;

}
HistoManager::~HistoManager(){if(rootfile)delete rootfile;}

void HistoManager::Save()
{
    if(!rootfile)return;
    rootfile->Write();
    rootfile->Close();
}

void HistoManager::Book()
{
rootfile = new TFile("result.root","RECREATE");



_histo3Ddose = new TH3D("3d_dose", "3d_dose", 100, 0, 100, 100, 0, 100,100,0,100);


}


void HistoManager::Fill_3D_Histogram(G4double x,G4double y,G4double z,G4double pdd)
{

  _histo3Ddose->SetBinContent(x,y,z,pdd);

}



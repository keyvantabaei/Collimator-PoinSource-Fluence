
#include "k1RA.hh"
#include "k1DC.hh"
#include "HistoManager.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4AccumulableManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

G4Run* k1RA::GenerateRun()
{ 
  _run = new Run();
  return _run;
}
k1RA::k1RA(HistoManager* histo): G4UserRunAction(),_histo(histo)
{  
doses=new G4double[1000000];
}


k1RA::~k1RA()
{ }


void k1RA::BeginOfRunAction(const G4Run* run)
{ 
  G4cout << "### Run " << run->GetRunID() << " start." << G4endl;
  _histo->Book();

  for(int i=0;i<1000000;i++)doses[i]=0;

    // reset accumulables to their initial values
  G4AccumulableManager* accumulableManager = G4AccumulableManager::Instance();
  accumulableManager->Reset();

  //inform the runManager to save random number seed
  G4RunManager::GetRunManager()->SetRandomNumberStore(false);
}


void k1RA::EndOfRunAction(const G4Run* run)
{
  G4int nofEvents = run->GetNumberOfEvent();
  if (nofEvents == 0) return;


// G4double halfY=50*mm;
// G4double halfX=50*mm;
// G4double halfZ=50*mm;

// G4double Voxeldimention=1*mm;



Run* _run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
auto doseMatrix=_run->GetDose();

//Find Max
// G4int cn=10000*49+100*49+49;
// G4double isocenter=doseMatrix[cn];


//Save Matrix Dose
G4double pdd;
G4double pddmax=0;


for(int j=0;j<1000000;j++)
{

  if(doseMatrix[j]!=0)
  {
          G4int ix=(G4int)j/10000;
          G4int iy=(G4int)((j-ix*10000)/100);
          G4int iz=(G4int)(j-((G4int)j/10000)*10000 - ((G4int)((j-ix*10000)/100))*100 );

          // G4double X=Voxeldimention*(ix)-halfX+halfX;
          // G4double Y=Voxeldimention*(iy)-halfY+halfY;
          // G4double Z=Voxeldimention*(iz)-halfZ+halfZ;

          _histo->Fill_3D_Histogram(ix,iy,iz,doseMatrix[j]);

  }
}
_histo->Save();
G4cout<<"Matrix Dose Saved ./"<<G4endl;
}

#include "phantomSD.hh"


#include "G4VSensitiveDetector.hh"
#include "G4HCofThisEvent.hh"
#include "G4SDManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "k1DC.hh"
#include "G4RunManager.hh"
#include "G4ThreeVector.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"
#include "Run.hh"
#include "G4Gamma.hh"
#include "G4Electron.hh"

phantomSD::phantomSD(const G4String& name,const G4String& HCname):
G4VSensitiveDetector(name),
_phantomHC(NULL)
{
collectionName.insert(HCname);

}

phantomSD::~phantomSD(){}

void phantomSD::Initialize(G4HCofThisEvent* hc)
{
_phantomHC = new phantomHC(SensitiveDetectorName,collectionName[0]);
G4int hcID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
hc->AddHitsCollection(hcID,_phantomHC);
}
G4bool phantomSD::ProcessHits(G4Step* step,G4TouchableHistory*)
{
    // auto charge = step->GetTrack()->GetDefinition()->GetPDGCharge();
    auto edep = step->GetTotalEnergyDeposit()/joule;
    if (edep==0.) return false;

    // auto e = step->Get
    const G4VTouchable* touchable = step->GetPreStepPoint()->GetTouchable();
    // //0 for z
    G4int iz =touchable->GetReplicaNumber(0);
    // if(iz==7){
    //2 for y
    G4int iy =touchable->GetReplicaNumber(2);
    // 1 for x
    G4int ix =touchable->GetReplicaNumber(1);


// G4double Z=Voxeldimention*(iz+1)-halfZ;


    G4ThreeVector pos = step->GetPreStepPoint()->GetPosition();
  
    auto mass =touchable->GetVolume(0)->GetLogicalVolume()->GetMass()/kg;

    G4double dose=edep/mass;

    // RUN

    Run* run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
    G4int cn=ix*10000+iy*100+iz;
    run->AddData(dose,cn);
    // }
    //end RUN
    
    //HIT

    // auto hc = new phantomHit();
    // hc->Fill(dose,cn);
    // _phantomHC->insert(hc);

    //end HIT
return true;

}
void phantomSD::EndOfEvent(G4HCofThisEvent*)
{
}
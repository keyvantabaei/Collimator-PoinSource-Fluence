#include "HistoManager.hh"
#include "G4Run.hh"
#include "Run.hh"
#include "G4DataVector.hh"
#include "G4SystemOfUnits.hh"

Run::Run():G4Run()
{
  // voxel=new std::tuple<G4double,G4double,G4double>[10000];
  //     for(int i=0;i<10000;i++)
  //     {
  //       voxel[i]=std::make_tuple(0,0,0);
  //     }
  // vec_voxel=0;
  voxels=new G4double[1000000];
    for(int i=0; i<1000000; i++) voxels[i] =0;
}
Run::~Run(){}
void Run::Merge(const G4Run* run)
{
  const Run* localRun = static_cast<const Run*>(run);
  for(int i=0; i<(int)sizeof(voxels); i++) voxels[i] += localRun->voxels[i];
  G4Run::Merge(run);
}

void Run::EndOfRun()
{

}
void Run::AddData(G4double dose,G4int cn)
{
  voxels[cn]+=dose;
  // G4cout<<"-----------------------------------------____>> ;:::::::::::::::::"<<voxels[cn]<<G4endl;
}

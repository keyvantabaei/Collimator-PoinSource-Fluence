
#include "k1DC.hh"
#include "G4SDManager.hh"
#include "k1Geometery.cc"
#include "phantomSD.hh"


k1DC::k1DC():G4VUserDetectorConstruction(),_phantom_size(G4ThreeVector(0,0,0))
{
}
k1DC::~k1DC()
{
}

G4VPhysicalVolume* k1DC::Construct()
{
          G4double a=3*cm;
          G4double b=3*cm;
          G4double SSD=80*cm;
    SetPhantomSize(G4ThreeVector(10*cm,10*cm,10*cm));
    SetCellCount(G4ThreeVector(100,100,100));
    Geometery geo;
    Struct _world =geo.Box("world","air",G4ThreeVector(1.5*m,1.5*m,1.5*m),G4ThreeVector(),0);
    Struct _phantom= geo.Box("waterphantom","water",_phantom_size,G4ThreeVector(0,0,0),_world._logic);
    _phantom_detector=_phantom._logic;
    // _phantom_detector=geo.NestedParameterization(_phantom_detector,_phantom_size,_cell_count,"water");
  


return _world._physical;
}
void k1DC::ConstructSDandField()
{
  // phantomSD* _water_phantom_SD = new phantomSD("k1/phantomSD","edep");
  // G4SDManager::GetSDMpointer()->AddNewDetector(_water_phantom_SD);
  // SetSensitiveDetector(_phantom_detector,_water_phantom_SD);

}
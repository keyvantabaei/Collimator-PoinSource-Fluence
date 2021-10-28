
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
    Struct _world =geo.Box("world","air",G4ThreeVector(2.5*m,2.5*m,2.5*m),G4ThreeVector(),0);
    Struct _phantom= geo.Box("waterphantom","water",_phantom_size,G4ThreeVector(0,0,_phantom_size.z()/2),_world._logic);
    _phantom_detector=_phantom._logic;
    // _phantom_detector=geo.NestedParameterization(_phantom_detector,_phantom_size,_cell_count,"water");
  //Wedge
double _90deg=1.5707963268;
G4double wedge_z=10*cm;
G4double wedge_x1=10*cm;
G4double wedge_x0=0.01*cm;
G4double wedge_y=tan((1*_90deg)/6)*wedge_x1;
// G4cout<<"---------------------------->> Y :"<<wedge_y<<G4endl;
G4double originX=wedge_y/4-wedge_x0/4+wedge_y/2;
// wedge_y = 26.7949 mm theta =15 deg
// wedge_y = 10 mm theta =45 deg
geo.GenericTrapezoid("T2","pb",wedge_z,wedge_x1,wedge_x0,wedge_y,G4ThreeVector(0,0,12*cm),G4ThreeVector(90*deg,0,90*deg),_world._logic)._logic;


return _world._physical;
}
void k1DC::ConstructSDandField()
{
  // phantomSD* _water_phantom_SD = new phantomSD("k1/phantomSD","edep");
  // G4SDManager::GetSDMpointer()->AddNewDetector(_water_phantom_SD);
  // SetSensitiveDetector(_phantom_detector,_water_phantom_SD);

}

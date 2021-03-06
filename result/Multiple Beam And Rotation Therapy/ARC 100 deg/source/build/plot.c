#include <TFile.h>
#include <TH2D.h>



double_t Find_Max_Depth_Dose(TH2D* h2)
{
double_t max_dose=0;

for(Int_t i=0;i<100;i++)
if(max_dose<h2->GetBinContent(49,i))
max_dose=h2->GetBinContent(49,i);

return max_dose;
}

double_t Find_Max_Depth_Dose(TH3D* h3)
{
double_t max_dose=0;

for(Int_t i=0;i<100;i++)
if(max_dose<h3->GetBinContent(49,49,i))
max_dose=h3->GetBinContent(49,49,i);

return max_dose;
}

double_t Find_Max_Depth_Dose2(TH3D* h3){
double_t max_dose=0;

for(Int_t i=49;i<52;i++)
for(Int_t j=49;j<52;j++)
for(Int_t k=49;k<52;k++)
if(max_dose<h3->GetBinContent(i,j,k))
max_dose=h3->GetBinContent(i,j,k);



return max_dose;
}

void XZPDDIsodose(){
   TFile* f =new TFile("result.root");  
TCanvas* c1 = new TCanvas("c1", "");
TH3D* h3 = (TH3D*)f->Get("3d_dose");
c1->Divide(2,1);





TH2D* h2zx=(TH2D*)h3->Project3D("zx COLTZ");
// double_t max_depth_dose=Find_Max_Depth_Dose(h2zx);
// double_t max_depth_dose=Find_Max_Depth_Dose(h3);
double_t Isocenter=h2zx->GetBinContent(49,49);
// double_t Isocenter=h3->GetBinContent(49,49,49);

TH2D* h2_pddxz=new TH2D("h3","h3",100,0,100,100,0,100);
for(Int_t i=0;i<100;i++)
for(Int_t j=0;j<100;j++)
h2_pddxz->SetBinContent(i,j,(h2zx->GetBinContent(i,j)/Isocenter)*100);



   double contours[26];
   contours[0] = 10;
   contours[1] = 20;
   contours[2] = 30;
   contours[3] = 40;
   contours[4] = 50;
   contours[5] = 60;
   contours[6] = 70;
   contours[7] = 80;
   contours[8] = 90;
   contours[9] = 100;
   contours[10] = 120;
   contours[11] = 140;
   contours[12] = 160;
   contours[13] = 180;
   contours[14] = 190;
   contours[15] = 200;
   contours[16] = 220;
   contours[17] = 240;
   contours[18] = 260;
   contours[19] = 280;
   contours[20] = 300;
   contours[21] = 320;
   contours[22] = 340;
   contours[23] = 360;
   contours[24] = 380;
   contours[25] = 400;
   c1->cd(1);
// gStyle->SetOptStat(0.1);
double_t _z,_pdd;
TTree* _tree = new TTree("depth_dose", "Edep");
_tree->Branch("Z", &_z, "Z/D");
_tree->Branch("pdd", &_pdd, "pdd/D");

double_t max=Find_Max_Depth_Dose2(h3);
// double_t max=h3->GetBinContent(49,49,49);
for(Int_t i=0;i<100;i++)
{
_z=i;
_pdd=(h3->GetBinContent(49,49,i)/max)*100;
_tree->Fill();
_pdd=(h3->GetBinContent(50,50,i)/max)*100;
_tree->Fill();
_pdd=(h3->GetBinContent(51,51,i)/max)*100;
_tree->Fill();

_pdd=(h3->GetBinContent(49,50,i)/max)*100;
_tree->Fill();
_pdd=(h3->GetBinContent(49,51,i)/max)*100;
_tree->Fill();
_pdd=(h3->GetBinContent(50,49,i)/max)*100;

_pdd=(h3->GetBinContent(50,51,i)/max)*100;
_tree->Fill();
_pdd=(h3->GetBinContent(51,49,i)/max)*100;
_tree->Fill();
_pdd=(h3->GetBinContent(51,50,i)/max)*100;
_tree->Fill();

}


_tree->SetMarkerStyle(6);
_tree->SetMarkerColor(kBlack);
_tree->Draw("pdd:Z","","C");
TH1F *htemp1 = (TH1F*)gPad->GetPrimitive("htemp");
htemp1->SetTitle("Percentage Depth Dose,10 MeV Opposite plan source ; Depth (mm) ; Relative Dose");
   c1->cd(2);
   gStyle->SetOptStat(0.1);
   h2_pddxz->SetTitle("Isodose 10 MeV Plan Source; X (mm) ; Z (mm)");
   h2_pddxz->Smooth();
   h2_pddxz->DrawCopy("colz");
   h2_pddxz->SetContour(26,contours);
   h2_pddxz->Draw("cont3 same");
   h2_pddxz->SetLineColor(kBlack);


c1->cd();
c1->Update();
}
void Isocenter_XYPlan(){
TFile* f =new TFile("result.root");  
TCanvas* c1 = new TCanvas("c1", "");
TH3D* h3 = (TH3D*)f->Get("3d_dose");
c1->Divide(2,1);

TH2D* h2=(TH2D*)h3->Project3D("zx COLTZ");
double_t max_depth_dose=Find_Max_Depth_Dose(h2);
// double_t max_depth_dose=Find_Max_Depth_Dose(h3);
// double_t Isocenter=h2->GetBinContent(49,49);
// double_t Isocenter=h3->GetBinContent(49,49,49);

TH2D* h2_pdd=new TH2D("h3","h3",100,0,100,100,0,100);
for(Int_t i=0;i<100;i++)
for(Int_t j=0;j<100;j++)
h2_pdd->SetBinContent(i,j,(h2->GetBinContent(i,j)/max_depth_dose)*100);



   double contours[26];
   contours[0] = 10;
   contours[1] = 20;
   contours[2] = 30;
   contours[3] = 40;
   contours[4] = 50;
   contours[5] = 60;
   contours[6] = 70;
   contours[7] = 80;
   contours[8] = 90;
   contours[9] = 100;
   contours[10] = 120;
   contours[11] = 140;
   contours[12] = 160;
   contours[13] = 180;
   contours[14] = 190;
   contours[15] = 200;
   contours[16] = 220;
   contours[17] = 240;
   contours[18] = 260;
   contours[19] = 280;
   contours[20] = 300;
   contours[21] = 320;
   contours[22] = 340;
   contours[23] = 360;
   contours[24] = 380;
   contours[25] = 400;
   c1->cd(1);
   gStyle->SetOptStat(0.1);
   h2_pdd->SetTitle("Isodose 10 MeV Plan Source; Z (mm) ; X (mm)");
   h2_pdd->Smooth();
   h2_pdd->DrawCopy("colz");
   h2_pdd->SetContour(26,contours);
   h2_pdd->Draw("cont3 same");
   h2_pdd->SetLineColor(kBlack);


c1->cd();
c1->Update();
}
void Isocenter_XZPlan(){
TFile* f =new TFile("result.root");  
TCanvas* c1 = new TCanvas("c1", "");
TH3D* h3 = (TH3D*)f->Get("3d_dose");

TH2D* h2=(TH2D*)h3->Project3D("zx COLTZ");
// double_t max_depth_dose=Find_Max_Depth_Dose(h2);
// double_t max_depth_dose=Find_Max_Depth_Dose(h3);
double_t Isocenter=h2->GetBinContent(49,49);
// double_t Isocenter=h3->GetBinContent(49,49,49);

TH2D* h2_pdd=new TH2D("h3","h3",100,0,100,100,0,100);
for(Int_t i=0;i<100;i++)
for(Int_t j=0;j<100;j++)
h2_pdd->SetBinContent(i,j,(h2->GetBinContent(i,j)/Isocenter)*100);



   double contours[26];
   contours[0] = 10;
   contours[1] = 20;
   contours[2] = 30;
   contours[3] = 40;
   contours[4] = 50;
   contours[5] = 60;
   contours[6] = 70;
   contours[7] = 80;
   contours[8] = 90;
   contours[9] = 100;
   contours[10] = 120;
   contours[11] = 140;
   contours[12] = 160;
   contours[13] = 180;
   contours[14] = 190;
   contours[15] = 200;
   contours[16] = 220;
   contours[17] = 240;
   contours[18] = 260;
   contours[19] = 280;
   contours[20] = 300;
   contours[21] = 320;
   contours[22] = 340;
   contours[23] = 360;
   contours[24] = 380;
   contours[25] = 400;
   gStyle->SetOptStat(0.1);
   h2_pdd->SetTitle("Isodose 10 MeV Plan Source  100 Deg Arc ; Z (mm) ; X (mm)");
   h2_pdd->Smooth();
   h2_pdd->DrawCopy("colz");
   h2_pdd->SetContour(26,contours);
   h2_pdd->Draw("cont3 same");
   h2_pdd->SetLineColor(kBlack);


c1->cd();
c1->Update();
}
void Isocenter_YZPlan(){
TFile* f =new TFile("result.root");  
TCanvas* c1 = new TCanvas("c1", "");
TH3D* h3 = (TH3D*)f->Get("3d_dose");


TH2D* h2=(TH2D*)h3->Project3D("yz COLTZ");
double_t max_depth_dose=Find_Max_Depth_Dose(h2);

TH2D* h2_pdd=new TH2D("h3","h3",100,0,100,100,0,100);
for(Int_t i=0;i<100;i++)
for(Int_t j=0;j<100;j++)
h2_pdd->SetBinContent(i,j,(h2->GetBinContent(i,j)/max_depth_dose)*100);



   double contours[26];
   contours[0] = 10;
   contours[1] = 20;
   contours[2] = 30;
   contours[3] = 40;
   contours[4] = 50;
   contours[5] = 60;
   contours[6] = 70;
   contours[7] = 80;
   contours[8] = 90;
   contours[9] = 100;
   contours[10] = 120;
   contours[11] = 140;
   contours[12] = 160;
   contours[13] = 180;
   contours[14] = 190;
   contours[15] = 200;
   contours[16] = 220;
   contours[17] = 240;
   contours[18] = 260;
   contours[19] = 280;
   contours[20] = 300;
   contours[21] = 320;
   contours[21] = 340;
   contours[23] = 360;
   contours[24] = 380;
   contours[25] = 400;


   h2_pdd->Smooth();
   h2_pdd->DrawCopy("colz");
   h2_pdd->SetContour(26,contours);
   h2_pdd->Draw("cont3 same");
   h2_pdd->SetLineColor(kBlack);
   h2_pdd->SetTitle("Scattered Photon Energy Spectrom Per 50 keV 7x7 cm; Energy (keV) ; Photons");




c1->cd();
c1->Update();
}
void Depth_Dose(){
TFile* f =new TFile("result.root");  
TCanvas* c1 = new TCanvas("c1", "");
TH3D* h3 = (TH3D*)f->Get("3d_dose");
double_t _z,_pdd;
TTree* _tree = new TTree("depth_dose", "Edep");
_tree->Branch("Z", &_z, "Z/D");
_tree->Branch("pdd", &_pdd, "pdd/D");

double_t max=Find_Max_Depth_Dose2(h3);
// double_t max=h3->GetBinContent(49,49,49);
for(Int_t i=0;i<100;i++)
{
_z=i;
_pdd=(h3->GetBinContent(49,49,i)/max)*100;
_tree->Fill();
_pdd=(h3->GetBinContent(50,50,i)/max)*100;
_tree->Fill();
_pdd=(h3->GetBinContent(51,51,i)/max)*100;
_tree->Fill();

_pdd=(h3->GetBinContent(49,50,i)/max)*100;
_tree->Fill();
_pdd=(h3->GetBinContent(49,51,i)/max)*100;
_tree->Fill();
_pdd=(h3->GetBinContent(50,49,i)/max)*100;

_pdd=(h3->GetBinContent(50,51,i)/max)*100;
_tree->Fill();
_pdd=(h3->GetBinContent(51,49,i)/max)*100;
_tree->Fill();
_pdd=(h3->GetBinContent(51,50,i)/max)*100;
_tree->Fill();

}



_tree->Draw("pdd:Z","","C");
TH1F *htemp1 = (TH1F*)gPad->GetPrimitive("htemp");
htemp1->SetTitle("Percentage Depth Dose,10 MeV Opposite plan source ; Depth (mm) ; Relative Dose");
c1->cd();
c1->Update();
}

void plot() 
{ 
Isocenter_XZPlan();
}




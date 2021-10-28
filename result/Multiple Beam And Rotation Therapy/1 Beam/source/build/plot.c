#include <TTree.h>
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
void XZXYIsodose(){
   TFile* f =new TFile("result.root");  
TCanvas* c1 = new TCanvas("c1", "");
TH3D* h3 = (TH3D*)f->Get("3d_dose");
c1->Divide(2,1);


TH2D* h2xy=(TH2D*)h3->Project3D("xy COLTZ");
// double_t max_depth_dose=Find_Max_Depth_Dose(h2);
// double_t max_depth_dose=Find_Max_Depth_Dose(h3);
double_t Isocenter=h2xy->GetBinContent(49,49);
// double_t Isocenter=h3->GetBinContent(49,49,49);

TH2D* h2_pddxy=new TH2D("h3","h3",100,0,100,100,0,100);
for(Int_t i=0;i<100;i++)
for(Int_t j=0;j<100;j++)
h2_pddxy->SetBinContent(i,j,(h2xy->GetBinContent(i,j)/Isocenter)*100);


TH2D* h2zx=(TH2D*)h3->Project3D("zx COLTZ");
double_t max_depth_dose=Find_Max_Depth_Dose(h2zx);
// double_t max_depth_dose=Find_Max_Depth_Dose(h3);
// double_t Isocenter=h2->GetBinContent(49,49);
// double_t Isocenter=h3->GetBinContent(49,49,49);

TH2D* h2_pddxz=new TH2D("h3","h3",100,0,100,100,0,100);
for(Int_t i=0;i<100;i++)
for(Int_t j=0;j<100;j++)
h2_pddxz->SetBinContent(i,j,(h2zx->GetBinContent(i,j)/max_depth_dose)*100);



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
   h2_pddxy->SetTitle("Isodose 10 MeV Plan Source; Y (mm) ; X (mm)");
   h2_pddxy->Smooth();
   h2_pddxy->DrawCopy("colz");
   h2_pddxy->SetContour(26,contours);
   h2_pddxy->Draw("cont3 same");
   h2_pddxy->SetLineColor(kBlack);
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


void plot() 
{ 
XZXYIsodose();
}




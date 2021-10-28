#include <TTree.h>
#include <TFile.h>
#include <TH1D.h>

void latplot() 
{ 


TFile* r1 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/PDD & Lateral/Plan Source/Lateral/Energy/500keV/result.root");
TFile* r2 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/PDD & Lateral/Plan Source/Lateral/Energy/2MeV/result.root");             
TFile* r3 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/PDD & Lateral/Plan Source/Lateral/Energy/co60/result.root");       
   

      
      
      


  
c1->Divide(2,1);
      
      
TTree* tree1 = (TTree*)r1->Get("Ntuple1");
TTree* tree2 = (TTree*)r2->Get("Ntuple1");
TTree* tree3 = (TTree*)r3->Get("Ntuple1");


  c1->cd(1);

tree2->SetMarkerColor(kBlue);
tree2->SetMarkerStyle(7);
tree2->Draw("edep:X");



tree3->SetMarkerStyle(7);
tree3->SetMarkerColor(kGreen);
tree3->Draw("edep:X","","same");


tree1->SetMarkerStyle(7);
tree1->SetMarkerColor(kRed);
tree1->Draw("edep:X","","same");



TH1F *htemp = (TH1F*)gPad->GetPrimitive("htemp");
htemp->SetTitle("Lateral Dose , Z =12 mm ; X (mm) ; Dose (Gy)");
   c1->Update();
   auto legend = new TLegend(0.1,0.7,0.48,0.9);
   legend->SetHeader("Energy","C"); // option "C" allows to center the header
   legend->AddEntry(tree1,"500 keV","p");
   legend->AddEntry(tree2,"2 MeV","p");
   legend->AddEntry(tree3,"Co60","p");


   legend->Draw();
   






  TFile* r4 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/PDD & Lateral/Plan Source/Lateral/Field/5x5/result.root");
  TFile* r5 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/PDD & Lateral/Plan Source/Lateral/Field/7x7/result.root");             
  TFile* r6 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/PDD & Lateral/Plan Source/Lateral/Field/9x9/result.root");       
   

      
      
   

  

      
      
TTree* tree4 = (TTree*)r4->Get("Ntuple1");
TTree* tree5 = (TTree*)r5->Get("Ntuple1");
TTree* tree6 = (TTree*)r6->Get("Ntuple1");


c1->cd(2);
tree4->SetMarkerStyle(7);
tree4->SetMarkerColor(kRed);
tree4->Draw("edep:X");



tree5->SetMarkerStyle(7);
tree5->SetMarkerColor(kBlue);
tree5->Draw("edep:X","","same");


tree6->SetMarkerStyle(7);
tree6->SetMarkerColor(kGreen);
tree6->Draw("edep:X","","same");



TH1F *htemp1 = (TH1F*)gPad->GetPrimitive("htemp");
htemp1->SetTitle("Lateral Dose , Z =12 mm ; X (mm) ; Dose (Gy)");
     
   auto legend1 = new TLegend(0.1,0.7,0.48,0.9);
   legend1->SetHeader("Field Size","C"); // option "C" allows to center the header
   legend1->AddEntry(tree4,"5x5 cm","p");
   legend1->AddEntry(tree5,"7x7 cm","p");
   legend1->AddEntry(tree6,"10x10 cm","p");
   legend1->Draw();
   

 



}


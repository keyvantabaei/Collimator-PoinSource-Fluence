#include <TTree.h>
#include <TFile.h>
#include <TH1D.h>

void plot() 
{ 












  TFile* r1 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/PDD & Lateral/Plan Source/PDD/Energy/500keV/result.root");
  TFile* r2 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/PDD & Lateral/Plan Source/PDD/Energy/2MeV/result.root");             
  TFile* r3 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/PDD & Lateral/Plan Source/PDD/Energy/co60/result.root");       
   

      
      
      

  TCanvas* c1 = new TCanvas("c1", "  ");

  

      
      
TTree* tree1 = (TTree*)r1->Get("Ntuple1");
TTree* tree2 = (TTree*)r2->Get("Ntuple1");
TTree* tree3 = (TTree*)r3->Get("Ntuple1");




tree2->SetMarkerColor(kBlue);
tree2->Draw("edep:Z");

tree3->SetMarkerColor(kGreen);
tree3->Draw("edep:Z","","same");





tree1->SetMarkerColor(kRed);
tree1->Draw("edep:Z","","same");




  
   //tree1->SetTitle("Scattered Photon Energy Spectrom Per 50 keV ; Energy (keV) ; Photons");
   
   
      auto legend = new TLegend(0.1,0.7,0.48,0.9);
   legend->SetHeader("","C"); // option "C" allows to center the header
   legend->AddEntry(tree1,"5x5   field size ","l");
   legend->AddEntry(tree2,"7x7   field size ","l");
   legend->AddEntry(tree3,"10x10 field size ","l");


   legend->Draw();
   
  c1->cd();
  c1->Update(); 

 




// TH2F *htemp = (TH2F*)c1->GetPrimitive("Ntuple1"); 
// TFile* f =new TFile("result.root");  
// TCanvas* c1 = new TCanvas("c1", "  ");
// TTree* tree = (TTree*)f->Get("Ntuple1");
// tree->Draw("edep:Z");
// c1->cd();
// c1->Update(); 
// htemp->SetTitle("Energy Deposit Water Phantom ; Depth (mm) ; Energy (keV)");
// Double_t edep;
// tree->SetBranchAddress("edep",&edep);
// TH1D *hpx   = new TH1D("h1","edep distribution",500,0,0.5);
// //read all entries and fill the histograms
// Long64_t nentries = tree->GetEntries();
// for (Long64_t i=0;i<nentries;i++) 
// {
// tree->GetEntry(i);
// hpx->Fill(edep);
// }
// hpx->Draw();
}


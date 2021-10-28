#include <TTree.h>
#include <TFile.h>
#include <TH1D.h>

void plot() 
{ 





















  TFile* r1 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/SSD/50/result.root");
  TFile* r2 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/SSD/60/result.root");             
  TFile* r3 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/SSD/70/result.root");       
  TFile* r4 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/SSD/80/result.root");        
  TFile* r5 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/SSD/100/result.root");     
      
      
      

  TCanvas* c1 = new TCanvas("c1", "  ");

  
   
  TH1D* hist1 = (TH1D*)r1->Get("SPH10cm");
  TH1D* hist2 = (TH1D*)r1->Get("SPH10cm");
  TH1D* hist3 = (TH1D*)r3->Get("SPH10cm");
  TH1D* hist4 = (TH1D*)r1->Get("SPH10cm");
  TH1D* hist5 = (TH1D*)r5->Get("SPH10cm");
  
  hist1->Draw();
  hist2->Draw("SAME");
  hist3->Draw("SAME");
  hist4->Draw("SAME");
  hist5->Draw("SAME");
  
   hist1->SetTitle("Scattered Photon Energy Spectrom Per 50 keV ; Energy (keV) ; Photons");
   
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


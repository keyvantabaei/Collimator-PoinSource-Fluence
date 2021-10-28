#include <TTree.h>
#include <TFile.h>
#include <TH1D.h>

void plot() 
{ 

















  TFile* r1 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Wedge/Pointsource/15/result.root");
  TFile* r2 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Wedge/Pointsource/30/result.root");             
  TFile* r3 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Wedge/Pointsource/45/result.root");       
  TFile* r4 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Wedge/Pointsource/60/result.root");         
      
      
      

  TCanvas* c1 = new TCanvas("c1", "  ");
 // c1->SetFrameLineColor(0);
  //c1->SetStyle("Classic");
   //  c1->SetFillColor(5);
   //c1->SetFrameFillColor(10);
   
   
   
  TH1D* hist1 = (TH1D*)r1->Get("E10cm");
  TH1D* hist2 = (TH1D*)r2->Get("E10cm");
  TH1D* hist3 = (TH1D*)r3->Get("E10cm");
  TH1D* hist4 = (TH1D*)r4->Get("E10cm");

      
    hist3->Draw("C");
    hist3->SetLineColor(kGreen);
    hist3->SetLineWidth(2);
    
      hist1->Draw("SAME C");
    hist1->SetLineColor(kBlack);
    hist1->SetLineWidth(2); 
  
    hist4->Draw("SAME C");
    hist4->SetLineColor(kBlue);
    hist4->SetLineWidth(2);
    
    hist2->Draw("SAME C");
    hist2->SetLineColor(kYellow);
    hist2->SetLineWidth(2);
        

    


    

   
    hist1->Draw("SAME C");
    hist1->SetLineColor(kBlack);
    hist1->SetLineWidth(2); 
    
   hist3->SetTitle("Scattered Electrons Energy Spectrom Per 50 keV ; Energy (keV) ; Photons");
  
   
   auto legend = new TLegend(0.1,0.7,0.48,0.9);
   legend->SetHeader("","C"); // option "C" allows to center the header
   legend->AddEntry(hist1,"5x5   field size ","l");
   legend->AddEntry(hist2,"7x7   field size ","l");
   legend->AddEntry(hist3,"10x10 field size ","l");
   legend->AddEntry(hist4,"15x15 field size ","l");

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


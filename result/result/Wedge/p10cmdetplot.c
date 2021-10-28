#include <TTree.h>
#include <TFile.h>
#include <TH1D.h>

void p10cmdetplot() 
{ 







TString detector="APH10cm";









  TFile* r1 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Wedge/Pointsource/60/result.root");
  TFile* r2 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Wedge/Pointsource/45/result.root");             
  TFile* r3 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Wedge/Pointsource/30/result.root");       
  TFile* r4 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Wedge/Pointsource/15/result.root");        
       
      
      
      

  TCanvas* c1 = new TCanvas("c1", "  ");

   
   c1->Divide(2,2);
   
  TH1D* hist1 = (TH1D*)r1->Get(detector);
  TH1D* hist2 = (TH1D*)r2->Get(detector);
  TH1D* hist3 = (TH1D*)r3->Get(detector);
  TH1D* hist4 = (TH1D*)r4->Get(detector);

  
    c1->cd(1);
    
    
    hist4->Draw("C");
    hist4->SetLineColor(kBlue);
    hist4->SetLineWidth(2);

    
    
    hist1->Draw("SAME C");
    hist1->SetLineColor(kBlack);
    hist1->SetLineWidth(2);


    hist3->Draw("SAME C");
    hist3->SetLineColor(kGreen);
    hist3->SetLineWidth(2);
    
    hist2->Draw("SAME C");
    hist2->SetLineColor(kYellow);
    hist2->SetLineWidth(2);


    


   hist4->SetTitle("ALL Photon Energy Spectrom Per 50 keV; Energy (keV) ; Photons");
  
   
   auto legend = new TLegend(0.1,0.7,0.48,0.9);
   legend->SetHeader("Angle","C"); // option "C" allows to center the header
   legend->AddEntry(hist1,"60 deg","l");
   legend->AddEntry(hist2,"45 deg","l");
   legend->AddEntry(hist3,"30 deg","l");
   legend->AddEntry(hist4,"15 deg","l");

   legend->Draw();





 
 detector="SPH10cm";
 
  TFile* r5 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Wedge/Pointsource/60/result.root");
  TFile* r6 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Wedge/Pointsource/45/result.root");             
  TFile* r7 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Wedge/Pointsource/30/result.root");
  TFile* r8 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Wedge/Pointsource/15/result.root");       

 

  TH1D* hist5 = (TH1D*)r5->Get(detector);
  TH1D* hist6 = (TH1D*)r6->Get(detector);
  TH1D* hist7 = (TH1D*)r7->Get(detector);
  TH1D* hist8 = (TH1D*)r8->Get(detector);

  


    c1->cd(2);
    
    
        hist8->Draw("C");
    hist8->SetLineColor(kBlue);
    hist8->SetLineWidth(2);
    
        hist5->Draw("SAME C");
    hist5->SetLineColor(kBlack);
    hist5->SetLineWidth(2); 
    


    hist7->Draw("SAME C");
    hist7->SetLineColor(kGreen);
    hist7->SetLineWidth(2);
    
    hist6->Draw("SAME C");
    hist6->SetLineColor(kYellow);
    hist6->SetLineWidth(2);


    
 

   hist8->SetTitle("Scattered Photon Energy Spectrom Per 50 keV; Energy (keV) ; Photons");
  
   
   auto legend1 = new TLegend(0.1,0.7,0.48,0.9);
   legend1->SetHeader("Angle","C"); // option "C" allows to center the header
   legend1->AddEntry(hist5,"60 deg","l");
   legend1->AddEntry(hist6,"45 deg","l");
   legend1->AddEntry(hist7,"30 deg","l");
   legend1->AddEntry(hist8,"15 deg","l");

   legend1->Draw();






detector="E10cm";

 
  TFile* r9  = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Wedge/Pointsource/60/result.root");
  TFile* r10 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Wedge/Pointsource/45/result.root");      
  TFile* r11 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Wedge/Pointsource/30/result.root");    
  TFile* r12 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Wedge/Pointsource/15/result.root");       





  TH1D* hist9 = (TH1D*)r9->Get(detector);
  TH1D* hist10 = (TH1D*)r10->Get(detector);
  TH1D* hist11 = (TH1D*)r11->Get(detector);
  TH1D* hist12 = (TH1D*)r12->Get(detector);

  


    c1->cd(3);
    
    

    
    hist12->Draw("C");
    hist12->SetLineColor(kBlue);
    hist12->SetLineWidth(2);
    
        hist9->Draw("SAME C");
    hist9->SetLineColor(kBlack);
    hist9->SetLineWidth(2); 

    hist11->Draw("SAME C");
    hist11->SetLineColor(kGreen);
    hist11->SetLineWidth(2);
    
    hist10->Draw("SAME C");
    hist10->SetLineColor(kYellow);
    hist10->SetLineWidth(2);



   hist12->SetTitle("Electron Energy Spectrom Per 50 keV; Energy (keV) ; Electron");
  
   
   auto legend2 = new TLegend(0.1,0.7,0.48,0.9);
   legend2->SetHeader("Angle","C"); // option "C" allows to center the header
   legend2->AddEntry(hist9,"60 deg","l");
   legend2->AddEntry(hist10,"45 deg","l");
   legend2->AddEntry(hist11,"30 deg","l");
   legend2->AddEntry(hist12,"15 deg","l");

   legend2->Draw();


   gPad->SetLogy(1);








}


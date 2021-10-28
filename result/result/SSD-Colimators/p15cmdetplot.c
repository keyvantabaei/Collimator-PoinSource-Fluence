#include <TTree.h>
#include <TFile.h>
#include <TH1D.h>

void p15cmdetplot() 
{ 







TString detector="APH15cm";









  TFile* r1 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/SSD/colimator opeeniing/100/result.root");
  TFile* r2 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/SSD/colimator opeeniing/80/result.root");             
  TFile* r3 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/SSD/colimator opeeniing/70/result.root");       
  TFile* r4 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/SSD/colimator opeeniing/60/result.root");        
TFile* r1234= new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/SSD/colimator opeeniing/50/result.root");        
      
      
      

  TCanvas* c1 = new TCanvas("c1", "  ");
 // c1->SetFrameLineColor(0);
  //c1->SetStyle("Classic");
   //  c1->SetFillColor(5);
   //c1->SetFrameFillColor(10);
   
   c1->Divide(2,2);
   
  TH1D* hist1 = (TH1D*)r1->Get(detector);
  TH1D* hist2 = (TH1D*)r2->Get(detector);
  TH1D* hist3 = (TH1D*)r3->Get(detector);
  TH1D* hist4 = (TH1D*)r4->Get(detector);
TH1D* hist1234= (TH1D*)r1234->Get(detector);
  
    c1->cd(1);
    
    
    hist1234->Draw("C");
    hist1234->SetLineColor(kRed);
    hist1234->SetLineWidth(2);  
    
    
    hist1->Draw("SAME C");
    hist1->SetLineColor(kBlack);
    hist1->SetLineWidth(2);

    hist4->Draw("SAME C");
    hist4->SetLineColor(kBlue);
    hist4->SetLineWidth(2);

    hist3->Draw("SAME C");
    hist3->SetLineColor(kGreen);
    hist3->SetLineWidth(2);
    
    hist2->Draw("SAME C");
    hist2->SetLineColor(kYellow);
    hist2->SetLineWidth(2);


    


   hist1234->SetTitle("ALL Photon Energy Spectrom Per 50 keV ; Energy (keV) ; Photons");
  
   
   auto legend = new TLegend(0.1,0.7,0.48,0.9);
   legend->SetHeader("SSD","C"); // option "C" allows to center the header
   legend->AddEntry(hist1,"100 cm","l");
   legend->AddEntry(hist2,"80 cm","l");
   legend->AddEntry(hist3,"70 cm","l");
   legend->AddEntry(hist4,"60 cm","l");
   legend->AddEntry(hist1234,"60 cm","l");
   legend->Draw();





 
 detector="SPH15cm";
 
  TFile* r5 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/SSD/colimator opeeniing/100/result.root");
  TFile* r6 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/SSD/colimator opeeniing/80/result.root");             
  TFile* r7 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/SSD/colimator opeeniing/70/result.root");
  TFile* r8 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/SSD/colimator opeeniing/60/result.root");       
TFile* r5678= new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/SSD/colimator opeeniing/50/result.root"); 
 

  TH1D* hist5 = (TH1D*)r5->Get(detector);
  TH1D* hist6 = (TH1D*)r6->Get(detector);
  TH1D* hist7 = (TH1D*)r7->Get(detector);
  TH1D* hist8 = (TH1D*)r8->Get(detector);
  TH1D* hist5678 = (TH1D*)r5678->Get(detector);
  


    c1->cd(2);
    
    
        hist5678->Draw("C");
    hist5678->SetLineColor(kRed);
    hist5678->SetLineWidth(2);
    
    
        hist5->Draw("SAME C");
    hist5->SetLineColor(kBlack);
    hist5->SetLineWidth(2); 
    
    hist8->Draw("SAME C");
    hist8->SetLineColor(kBlue);
    hist8->SetLineWidth(2);

    hist7->Draw("SAME C");
    hist7->SetLineColor(kGreen);
    hist7->SetLineWidth(2);
    
    hist6->Draw("SAME C");
    hist6->SetLineColor(kYellow);
    hist6->SetLineWidth(2);


    
 

   hist5678->SetTitle("Scattered Photon Energy Spectrom Per 50 keV; Energy (keV) ; Photons");
  
   
   auto legend1 = new TLegend(0.1,0.7,0.48,0.9);
   legend1->SetHeader("SSD","C"); // option "C" allows to center the header
   legend1->AddEntry(hist5,"100 cm","l");
   legend1->AddEntry(hist6,"80 cm","l");
   legend1->AddEntry(hist7,"70 cm","l");
   legend1->AddEntry(hist8,"60 cmm","l");
   legend1->AddEntry(hist5678,"50 cm","l");
   legend1->Draw();






detector="E15cm";

 
  TFile* r9  = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/SSD/colimator opeeniing/100/result.root");
  TFile* r10 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/SSD/colimator opeeniing/80/result.root");      
  TFile* r11 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/SSD/colimator opeeniing/70/result.root");    
  TFile* r12 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/SSD/colimator opeeniing/60/result.root");       
  TFile* r912= new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/SSD/colimator opeeniing/50/result.root");




  TH1D* hist9 = (TH1D*)r9->Get(detector);
  TH1D* hist10 = (TH1D*)r10->Get(detector);
  TH1D* hist11 = (TH1D*)r11->Get(detector);
  TH1D* hist12 = (TH1D*)r12->Get(detector);
  TH1D* hist912 = (TH1D*)r912->Get(detector);
  


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



    hist912->Draw("SAME C");
    hist912->SetLineColor(kRed);
    hist912->SetLineWidth(2);

   hist12->SetTitle("Electron Energy Spectrom Per 50 keV; Energy (keV) ; Electron");
  
   
   auto legend2 = new TLegend(0.1,0.7,0.48,0.9);
   legend2->SetHeader("SSD","C"); // option "C" allows to center the header
   legend2->AddEntry(hist9,"100 cm","l");
   legend2->AddEntry(hist10,"80 cm","l");
   legend2->AddEntry(hist11,"70 cm","l");
   legend2->AddEntry(hist12,"60 cm","l");
   legend2->AddEntry(hist912,"50 cm","l");
   legend2->Draw();


   gPad->SetLogy(1);








}


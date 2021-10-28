#include <TTree.h>
#include <TFile.h>
#include <TH1D.h>

void p10cmeplot() 
{ 







TString detector="E10cm";









  TFile* r1 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 500keV/r1/no air/result.root");
  TFile* r2 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 500keV/r2/no air/result.root");             
  TFile* r3 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 500keV/r3/no air/result.root");       
  TFile* r4 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 500keV/r4/no air/result.root");        
TFile* r1234= new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 500keV/r5/no air/result.root");        
      
      
      

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
    hist1->Draw("C");
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


    
    hist1234->Draw("SAME C");
    hist1234->SetLineColor(kRed);
    hist1234->SetLineWidth(2);  

   hist1->SetTitle("Electrons Energy Spectrom Per 50 keV, 500keV ; Energy (keV) ; Electron");
  
   
   auto legend = new TLegend(0.1,0.7,0.48,0.9);
   legend->SetHeader("Field Size","C"); // option "C" allows to center the header
   legend->AddEntry(hist1,"5x5 cm","l");
   legend->AddEntry(hist2,"7x7 cm","l");
   legend->AddEntry(hist3,"10x10 cm","l");
   legend->AddEntry(hist4,"15x15 cm","l");
   legend->AddEntry(hist1234,"20x20 cm","l");
   legend->Draw();
   gPad->SetLogy(1);




 
 
 
  TFile* r5 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy co60/r1/no air/result.root");
  TFile* r6 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy co60/r2/no air/result.root");             
  TFile* r7 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy co60/r3/no air/result.root");       
  TFile* r8 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy co60/r4/no air/result.root");        
TFile* r5678= new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy co60/r5/no air/result.root");  
 

  TH1D* hist5 = (TH1D*)r5->Get(detector);
  TH1D* hist6 = (TH1D*)r6->Get(detector);
  TH1D* hist7 = (TH1D*)r7->Get(detector);
  TH1D* hist8 = (TH1D*)r8->Get(detector);
  TH1D* hist5678 = (TH1D*)r5678->Get(detector);
  


    c1->cd(2);
    
        hist5->Draw("C");
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


    
    hist5678->Draw("SAME C");
    hist5678->SetLineColor(kRed);
    hist5678->SetLineWidth(2); 

   hist5->SetTitle("Electrons Energy Spectrom Per 50 keV Co60; Energy (keV) ; Electron");
  
   
   auto legend1 = new TLegend(0.1,0.7,0.48,0.9);
   legend1->SetHeader("Field Size","C"); // option "C" allows to center the header
   legend1->AddEntry(hist5,"5x5 cm","l");
   legend1->AddEntry(hist6,"7x7 cm","l");
   legend1->AddEntry(hist7,"10x10 cm","l");
   legend1->AddEntry(hist8,"15x15 cm","l");
   legend1->AddEntry(hist5678,"20x20 cm","l");
   legend1->Draw();


   gPad->SetLogy(1);





 
  TFile* r9  = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 2MeV/r1/no air/result.root");
  TFile* r10 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 2MeV/r2/no air/result.root");             
  TFile* r11 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 2MeV/r3/no air/result.root");       
  TFile* r12 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 2MeV/r4/no air/result.root");        
  TFile* r912= new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 2MeV/r5/no air/result.root");  




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

   hist12->SetTitle("Electrons Energy Spectrom Per 50 keV 2 MeV; Energy (keV) ; Electron");
  
   
   auto legend2 = new TLegend(0.1,0.7,0.48,0.9);
   legend2->SetHeader("Field Size","C"); // option "C" allows to center the header
   legend2->AddEntry(hist9,"5x5 cm","l");
   legend2->AddEntry(hist10,"7x7 cm","l");
   legend2->AddEntry(hist11,"10x10 cm","l");
   legend2->AddEntry(hist12,"15x15 cm","l");
   legend2->AddEntry(hist912,"20x20 cm","l");
   legend2->Draw();


   gPad->SetLogy(1);





  TFile* r17 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 4MeV/r1/no air/result.root");
  TFile* r18 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 4MeV/r2/no air/result.root");             
  TFile* r19 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 4MeV/r3/no air/result.root");       
  TFile* r20 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 4MeV/r4/no air/result.root");        
 TFile* r1720= new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 4MeV/r5/no air/result.root"); 



  TH1D* hist17 = (TH1D*)r17->Get(detector);
  TH1D* hist18 = (TH1D*)r18->Get(detector);
  TH1D* hist19 = (TH1D*)r19->Get(detector);
  TH1D* hist20 = (TH1D*)r20->Get(detector);
  TH1D* hist1720 = (TH1D*)r1720->Get(detector);
  


    c1->cd(4);
    hist20->Draw("C");
    hist20->SetLineColor(kBlue);
    hist20->SetLineWidth(2);

    hist19->Draw("SAME C");
    hist19->SetLineColor(kGreen);
    hist19->SetLineWidth(2);
    
    hist18->Draw("SAME C");
    hist18->SetLineColor(kYellow);
    hist18->SetLineWidth(2);

    hist17->Draw("SAME C");
    hist17->SetLineColor(kBlack);
    hist17->SetLineWidth(2); 
    
        hist1720->Draw("SAME C");
    hist1720->SetLineColor(kRed);
    hist1720->SetLineWidth(2);

   hist20->SetTitle("Electrons Energy Spectrom Per 50 keV 4 MeV; Energy (keV) ; Electron");
  
   
   auto legend3 = new TLegend(0.1,0.7,0.48,0.9);
   legend3->SetHeader("Field Size","C"); // option "C" allows to center the header
   legend3->AddEntry(hist17,"5x5 cm","l");
   legend3->AddEntry(hist18,"7x7 cm","l");
   legend3->AddEntry(hist19,"10x10 cm","l");
   legend3->AddEntry(hist20,"15x15 cm","l");
   legend3->AddEntry(hist1720,"20x20 cm","l");
   legend3->Draw();


   gPad->SetLogy(1);



}


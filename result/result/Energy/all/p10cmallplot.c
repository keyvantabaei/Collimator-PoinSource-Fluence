#include <TTree.h>
#include <TFile.h>
#include <TH1D.h>

void p10cmallplot() 
{ 










TString detector="APH10cm";









  TFile* r1 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 500keV/r1/result.root");
  TFile* r2 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy co60/r1/result.root");             
  TFile* r3 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 2MeV/r1/result.root");       
  TFile* r4 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 4MeV/r1/result.root");        

      
      
      

  TCanvas* c1 = new TCanvas("c1", "  ");
 // c1->SetFrameLineColor(0);
  //c1->SetStyle("Classic");
   //  c1->SetFillColor(5);
   //c1->SetFrameFillColor(10);
   
   c1->Divide(3,2);
   
  TH1D* hist1 = (TH1D*)r1->Get(detector);
  TH1D* hist2 = (TH1D*)r2->Get(detector);
  TH1D* hist3 = (TH1D*)r3->Get(detector);
  TH1D* hist4 = (TH1D*)r4->Get(detector);

  


    c1->cd(1);
    hist4->Draw("C");
    hist4->SetLineColor(kBlue);
    hist4->SetLineWidth(2);

    hist3->Draw("SAME C");
    hist3->SetLineColor(kGreen);
    hist3->SetLineWidth(2);
    
    hist2->Draw("SAME C");
    hist2->SetLineColor(kYellow);
    hist2->SetLineWidth(2);

    hist1->Draw("SAME C");
    hist1->SetLineColor(kBlack);
    hist1->SetLineWidth(2); 

   hist4->SetTitle("ALL Photon Energy Spectrom Per 50 keV 5x5 cm ; Energy (keV) ; Photons");
  
   
   auto legend = new TLegend(0.1,0.7,0.48,0.9);
   legend->SetHeader("Energy","C"); // option "C" allows to center the header
   legend->AddEntry(hist1,"500keV","l");
   legend->AddEntry(hist2,"co60","l");
   legend->AddEntry(hist3,"2 MeV","l");
   legend->AddEntry(hist4,"4 MeV","l");
   legend->Draw();





 
 
 
  TFile* r5 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 500keV/r2/result.root");
  TFile* r6 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy co60/r2/result.root");             
  TFile* r7 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 2MeV/r2/result.root");       
  TFile* r8 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 4MeV/r2/result.root");  
 

  TH1D* hist5 = (TH1D*)r5->Get(detector);
  TH1D* hist6 = (TH1D*)r6->Get(detector);
  TH1D* hist7 = (TH1D*)r7->Get(detector);
  TH1D* hist8 = (TH1D*)r8->Get(detector);

  


    c1->cd(2);
    hist8->Draw("C");
    hist8->SetLineColor(kBlue);
    hist8->SetLineWidth(2);

    hist7->Draw("SAME C");
    hist7->SetLineColor(kGreen);
    hist7->SetLineWidth(2);
    
    hist6->Draw("SAME C");
    hist6->SetLineColor(kYellow);
    hist6->SetLineWidth(2);

    hist5->Draw("SAME C");
    hist5->SetLineColor(kBlack);
    hist5->SetLineWidth(2); 

   hist8->SetTitle("ALL Photon Energy Spectrom Per 50 keV 7x7 cm; Energy (keV) ; Photons");
  
   
   auto legend1 = new TLegend(0.1,0.7,0.48,0.9);
   legend1->SetHeader("Energy","C"); // option "C" allows to center the header
   legend1->AddEntry(hist5,"500keV","l");
   legend1->AddEntry(hist6,"co60","l");
   legend1->AddEntry(hist7,"2 MeV","l");
   legend1->AddEntry(hist8,"4 MeV","l");
   legend1->Draw();








  TFile* r9 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 500keV/r3/result.root");
  TFile* r10 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy co60/r3/result.root");             
  TFile* r11 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 2MeV/r3/result.root");       
  TFile* r12 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 4MeV/r3/result.root");




  TH1D* hist9 = (TH1D*)r9->Get(detector);
  TH1D* hist10 = (TH1D*)r10->Get(detector);
  TH1D* hist11 = (TH1D*)r11->Get(detector);
  TH1D* hist12 = (TH1D*)r12->Get(detector);

  


    c1->cd(3);
    hist12->Draw("C");
    hist12->SetLineColor(kBlue);
    hist12->SetLineWidth(2);

    hist11->Draw("SAME C");
    hist11->SetLineColor(kGreen);
    hist11->SetLineWidth(2);
    
    hist10->Draw("SAME C");
    hist10->SetLineColor(kYellow);
    hist10->SetLineWidth(2);

    hist9->Draw("SAME C");
    hist9->SetLineColor(kBlack);
    hist9->SetLineWidth(2); 

   hist12->SetTitle("ALL Photon Energy Spectrom Per 50 keV 10x10 cm; Energy (keV) ; Photons");
  
   
   auto legend2 = new TLegend(0.1,0.7,0.48,0.9);
   legend2->SetHeader("Energy","C"); // option "C" allows to center the header
   legend2->AddEntry(hist9,"500keV","l");
   legend2->AddEntry(hist10,"co60","l");
   legend2->AddEntry(hist11,"2 MeV","l");
   legend2->AddEntry(hist12,"4 MeV","l");
   legend2->Draw();











  TFile* r13 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 500keV/r4/result.root");
  TFile* r14 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy co60/r4/result.root");             
  TFile* r15 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 2MeV/r4/result.root");       
  TFile* r16 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 4MeV/r4/result.root");



  TH1D* hist13 = (TH1D*)r13->Get(detector);
  TH1D* hist14 = (TH1D*)r14->Get(detector);
  TH1D* hist15 = (TH1D*)r15->Get(detector);
  TH1D* hist16 = (TH1D*)r16->Get(detector);

  


    c1->cd(4);
    hist16->Draw("C");
    hist16->SetLineColor(kBlue);
    hist16->SetLineWidth(2);

    hist15->Draw("SAME C");
    hist15->SetLineColor(kGreen);
    hist15->SetLineWidth(2);
    
    hist14->Draw("SAME C");
    hist14->SetLineColor(kYellow);
    hist14->SetLineWidth(2);

    hist13->Draw("SAME C");
    hist13->SetLineColor(kBlack);
    hist13->SetLineWidth(2); 

   hist16->SetTitle("ALL Photon Energy Spectrom Per 50 keV 15x15 cm; Energy (keV) ; Photons");
  
   
   auto legend3 = new TLegend(0.1,0.7,0.48,0.9);
   legend3->SetHeader("Energy","C"); // option "C" allows to center the header
   legend3->AddEntry(hist9,"500keV","l");
   legend3->AddEntry(hist10,"co60","l");
   legend3->AddEntry(hist11,"2 MeV","l");
   legend3->AddEntry(hist12,"4 MeV","l");
   legend3->Draw();






  TFile* r17 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 500keV/r5/result.root");
  TFile* r18 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy co60/r5/result.root");             
  TFile* r19 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 2MeV/r5/result.root");       
  TFile* r20 = new TFile("/home/k1/k1-Files/Programing/Geant4-workshop/reports/2/result/Energy 4MeV/r5/result.root");



  TH1D* hist17 = (TH1D*)r17->Get(detector);
  TH1D* hist18 = (TH1D*)r18->Get(detector);
  TH1D* hist19 = (TH1D*)r19->Get(detector);
  TH1D* hist20 = (TH1D*)r20->Get(detector);

  


    c1->cd(5);
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

   hist20->SetTitle("ALL Photon Energy Spectrom Per 50 keV 20x20 cm; Energy (keV) ; Photons");
  
   
   auto legend4 = new TLegend(0.1,0.7,0.48,0.9);
   legend4->SetHeader("Energy","C"); // option "C" allows to center the header
   legend4->AddEntry(hist17,"500keV","l");
   legend4->AddEntry(hist18,"co60","l");
   legend4->AddEntry(hist19,"2 MeV","l");
   legend4->AddEntry(hist20,"4 MeV","l");
   legend4->Draw();







}


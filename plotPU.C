// root -b -q plotPU.C++

#include "TFile.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TColor.h"


void plotPU(){

  TFile* f_2016UL_inclusive = TFile::Open("../../utils/pu_weights_2016UL_inclusive.root");
  TFile* f_2016UL_preVFP    = TFile::Open("../../utils/pu_weights_2016UL_preVFP.root");
  TFile* f_2016UL_postVFP   = TFile::Open("../../utils/pu_weights_2016UL_postVFP.root");
  
  auto hMC_inclusive   = (TH1F*) f_2016UL_inclusive->Get("MC_out_of_the_box");
  auto hMC_w_inclusive = (TH1F*) f_2016UL_inclusive->Get("MC_reweighted");
  auto hData_inclusive = (TH1F*) f_2016UL_inclusive->Get("Data");
  auto h_w_inclusive   = (TH1F*) f_2016UL_inclusive->Get("weights");

  auto hMC_preVFP   = (TH1F*) f_2016UL_preVFP->Get("MC_out_of_the_box");
  auto hMC_w_preVFP = (TH1F*) f_2016UL_preVFP->Get("MC_reweighted");
  auto hData_preVFP = (TH1F*) f_2016UL_preVFP->Get("Data");
  auto h_w_preVFP   = (TH1F*) f_2016UL_preVFP->Get("weights");

  auto hMC_postVFP   = (TH1F*) f_2016UL_postVFP->Get("MC_out_of_the_box");
  auto hMC_w_postVFP = (TH1F*) f_2016UL_postVFP->Get("MC_reweighted");
  auto hData_postVFP = (TH1F*) f_2016UL_postVFP->Get("Data");
  auto h_w_postVFP = (TH1F*) f_2016UL_postVFP->Get("weights");


  TCanvas* c_w = new TCanvas();
  c_w->cd();

  h_w_inclusive->SetStats(false);
  h_w_inclusive->SetMaximum(3.1);
  
  h_w_inclusive->SetLineColor(kGray+2);
  h_w_preVFP   ->SetLineColor(kBlue);
  h_w_postVFP  ->SetLineColor(kRed);

  h_w_inclusive->Draw("hist");
  h_w_preVFP   ->Draw("samehist");
  h_w_postVFP  ->Draw("samehist");

  TLegend* leg_w = new TLegend(0.56,0.61,0.88,0.88);
  leg_w->AddEntry(h_w_inclusive,   "weights inclusive",   "f");
  leg_w->AddEntry(h_w_preVFP,      "weights preVFP",      "f");
  leg_w->AddEntry(h_w_postVFP,     "weights postVFP",     "f");
  leg_w->Draw();

  c_w->SaveAs("pu_weights.png");


  
  TCanvas* c = new TCanvas();
  c->cd();

  hMC_inclusive->SetStats(false);
  hMC_inclusive->SetMaximum(0.08);
  // hData_inclusive->GetXaxis()->SetTitle("true number of interactions");
  // hData_inclusive->GetYaxis()->SetTitle("normalizer to unity");

  hMC_inclusive->SetLineColor(kGreen+3);
  hMC_inclusive->SetLineStyle(4);

  hMC_preVFP   ->SetLineColor(kGreen+2);
  hMC_preVFP   ->SetLineStyle(5);

  hMC_postVFP ->SetLineColor(kGreen+1);
  hMC_postVFP ->SetLineStyle(6);

  hMC_w_inclusive->SetLineColor(kGray+2);
  hMC_w_inclusive->SetFillColor(kGray+1);
  hMC_w_inclusive->SetFillStyle(3004);

  hMC_w_preVFP   ->SetLineColor(kBlue);
  hMC_w_preVFP   ->SetFillColor(kBlue-9);
  hMC_w_preVFP   ->SetFillStyle(3005);

  hMC_w_postVFP ->SetLineColor(kRed);
  hMC_w_postVFP  ->SetFillColor(kRed-9);
  hMC_w_postVFP  ->SetFillStyle(3006);

  hData_inclusive->SetMarkerStyle(20);
  hData_inclusive->SetMarkerSize(0.6);	 
  hData_inclusive->SetMarkerColor(kBlack);

  hData_preVFP   ->SetMarkerStyle(20);
  hData_preVFP   ->SetMarkerSize(0.6);	 
  hData_preVFP   ->SetMarkerColor(kBlue);

  hData_postVFP  ->SetMarkerStyle(20);
  hData_postVFP  ->SetMarkerSize(0.6);	 
  hData_postVFP  ->SetMarkerColor(kRed);
  

  hMC_inclusive  ->Draw("hist");
  hMC_preVFP     ->Draw("samehist");
  hMC_postVFP    ->Draw("samehist");
  hMC_w_inclusive->Draw("samehist");
  hMC_w_preVFP   ->Draw("samehist");
  hMC_w_postVFP  ->Draw("samehist");
  hData_inclusive->Draw("samep");
  hData_preVFP   ->Draw("samep");
  hData_postVFP  ->Draw("samep");  


  TLegend* leg = new TLegend(0.56,0.61,0.88,0.88);
  leg->AddEntry(hMC_inclusive,   "MC inclusive",   "f");
  leg->AddEntry(hMC_preVFP,      "MC preVFP",      "f");
  leg->AddEntry(hMC_postVFP,     "MC postVFP",     "f");
  leg->AddEntry(hMC_w_inclusive, "MC w inclusive", "f");
  leg->AddEntry(hMC_w_preVFP,    "MC w preVFP",    "f");
  leg->AddEntry(hMC_w_postVFP,   "MC w postVFP",   "f");
  leg->AddEntry(hData_inclusive, "data inclusive", "p");
  leg->AddEntry(hData_preVFP,    "data preVFP",    "p");
  leg->AddEntry(hData_postVFP,   "data postVFP",   "p");
  leg->SetLineColor(kWhite);
  leg->Draw();

  c->SaveAs("pu_all.png");

}

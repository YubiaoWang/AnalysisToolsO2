// This is a template. To use the JetSpectrum drawing functions, rename this file to JetSpectrum_RunMacro.C and edit it how you want and run "root pathToFolderAnalysisToolsO2/Jets/JetSpectrum_RunMacro.C+"

#include "TStyle.h"
#include "TGraph.h"
#include "TFile.h"
#include "TFitResult.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TF1.h"
#include "TLatex.h"
#include "TLine.h"
#include "TRatioPlot.h"
#include "TLegend.h"
#include "TH1.h"

#include "./JetFit_inputs.h"
#include "../Utilities/HistogramUtilities.h"
#include "../Utilities/HistogramUtilities.C"
#include "../Utilities/Fits.h"
#include "../Utilities/Fits.C"

using namespace std;


void Draw_Pt_spectrum_Full_Fit(std::string options);

// Misc utilities
void SetStyle(Bool_t graypalette=kFALSE);

/////////////////////////////////////////////////////
///////////////////// Main Macro ////////////////////
/////////////////////////////////////////////////////

void JetFit_DrawingMacro() {
  // Set the default style
  SetStyle();

  Draw_Pt_spectrum_Full_Fit("");
}


void SetStyle(Bool_t graypalette) {
  cout << "Setting style!" << endl;
  
  gStyle->Reset("Plain");
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  if(graypalette) gStyle->SetPalette(8,0);
  else gStyle->SetPalette(1);
  gStyle->SetCanvasColor(10);
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetFrameLineWidth(1);
  gStyle->SetFrameFillColor(kWhite);
  gStyle->SetPadColor(10);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  gStyle->SetPadBottomMargin(0.15);
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetHistLineWidth(1);
  gStyle->SetHistLineColor(kRed);
  gStyle->SetFuncWidth(2);
  gStyle->SetFuncColor(kGreen);
  gStyle->SetLineWidth(2);
  gStyle->SetLineScalePS(1);
  gStyle->SetLabelSize(0.045,"xyz");
  gStyle->SetLabelOffset(0.01,"y");
  gStyle->SetLabelOffset(0.01,"x");
  gStyle->SetLabelColor(kBlack,"xyz");
  gStyle->SetTitleSize(0.05,"xyz");
  gStyle->SetTitleOffset(1.4,"y");
  gStyle->SetTitleOffset(1.2,"x");
  gStyle->SetTitleFillColor(kWhite);
  gStyle->SetTextSizePixels(26);
  gStyle->SetTextFont(42);
  //  gStyle->SetTickLength(0.04,"X");  gStyle->SetTickLength(0.04,"Y"); 

  gStyle->SetLegendBorderSize(0);
  gStyle->SetLegendFillColor(kWhite);
  //  gStyle->SetFillColor(kWhite);
  gStyle->SetLegendFont(42);
}


void Draw_Pt_spectrum_Full_Fit(std::string options) {
  TGraphErrors* GraphErrors_input = (TGraphErrors*)((TGraphErrors*)file_HEP_fullJetSpectrum->Get("Table 6/Graph1D_y1"))->Clone("GraphErrors_input");

  TH1D* H1D_input = TGraphErrorsToTH1D(GraphErrors_input);

  std::vector<double> binning = GetTH1Bins(H1D_input);

  double fitPtRange[2] = {binning.front(), binning.back()}; 
  std::tuple<TF1*, TMatrixDSym, TFitResultPtr> exponentialFitFunctionResult = ExponentialFitWithLogTransfo(H1D_input, fitPtRange);
  TF1* fitFunctionDrawn = std::get<0>(exponentialFitFunctionResult);

  fitFunctionDrawn->Print("V");
  // auto parfitFunctionDrawn = fitFunctionDrawn->GetParameters(); // std::array<double, nParameters>
  // for (int iParam : parfitFunctionDrawn.size()) {
  //   cout << parfitFunctionDrawn->GetName() << 
  // }

  TFitResultPtr fitResult = std::get<2>(exponentialFitFunctionResult);
  TGraphErrors* fitFunctionTGraphErrors = GetFunctionTGraphErrorsFromFitResult(fitPtRange, fitFunctionDrawn, fitResult);

  TString* pdfName = new TString("FullJetSpectra_withExpFit");
  TString textContext = "";

  Draw_TH1_Histogram(H1D_input, textContext, pdfName, texPtX, texJet_dNdeta, texCollisionDataInfo, drawnWindowAuto, legendPlacementAuto, contextPlacementAuto, "logy,fitSingle", fitFunctionTGraphErrors);
}
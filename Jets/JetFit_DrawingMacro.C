// This is a template. To use the JetSpectrum drawing functions, rename this file to JetSpectrum_RunMacro.C and edit it how you want and run "root pathToFolderAnalysisToolsO2/Jets/JetSpectrum_RunMacro.C+"

#include "./Utilities/Fits.h"
#include "./Utilities/Fits.C"

using namespace std;


void Draw_Pt_spectrum_Full_Fit(std::string options);

// Misc utilities
void SetStyle(Bool_t graypalette=kFALSE);

/////////////////////////////////////////////////////
///////////////////// Main Macro ////////////////////
/////////////////////////////////////////////////////

void JetSpectrum_RunMacro() {
  // Set the default style
  SetStyle();

  Draw_Pt_spectrum_Full_Fit("");
}



void Draw_Pt_spectrum_Full_Fit(std::string options) {

  TGraphErrors* GraphErrors_input = (TGraphErrors*)((TGraphErrors*)file_HEP_fullJetSpectrum->Get("Table 6"))->Clone("Hist1D_1");

  TH1D* H1D_input = TGraphErrorsToTH1D(GraphErrors_input);

  std::vector<double> binning = GetTH1Bins(H1D_input);

  double fitPtRange[2] = {binning.begin(), binnin.back()}; 
  std::tuple<TF1*, TMatrixDSym, TFitResultPtr> exponentialFitFunctionResult = exponentialFitWithLog(H1D_input, fitPtRange);
  TF1* fitFunctionDrawn = std::get<0>(tsallisFitFunctionResult);

  fitFunctionDrawn->Print("V");
  // auto parfitFunctionDrawn = fitFunctionDrawn->GetParameters(); // std::array<double, nParameters>
  // for (int iParam : parfitFunctionDrawn.size()) {
  //   cout << parfitFunctionDrawn->GetName() << 
  // }

  TFitResultPtr fitResult = std::get<2>(tsallisFitFunctionResult);
  TGraphErrors* fitFunctionTGraphErrors = getFunctionTGraphErrorsFromFitResult(fitPtRange, fitFunctionDrawn, fitResult);

  TString* pdfName = new TString("FullJetSpectra_withExpFit");

  Draw_TH1_Histogram(H1D_input, textContext, pdfName, texPtX, texJet_dNdeta, texCollisionDataInfo, drawnWindowAuto, legendPlacementAuto, contextPlacementAuto, "logy,fitSingle", fitFunctionTGraphErrors);
}
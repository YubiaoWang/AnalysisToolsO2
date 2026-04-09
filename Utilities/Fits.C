#ifndef FITS_C
#define FITS_C

TGraphErrors* GetFunctionTGraphErrorsFromFitResult(double* xRangeFit, TF1* fitFunctionDrawn, TFitResultPtr fitResult, int nPointsGraph = 1000){
  std::vector<double> xAxisGraph= {};
  std::vector<double> yAxisGraph= {};
  std::vector<double> yAxisGraphErrors= {};
  // double* ;

  for(int iPoint = 0; iPoint < nPointsGraph; iPoint++){
    xAxisGraph.push_back(xRangeFit[0]+iPoint*1./nPointsGraph*(xRangeFit[1]-xRangeFit[0]));
    yAxisGraph.push_back(fitFunctionDrawn->Eval(xAxisGraph.back()));
    yAxisGraphErrors.push_back(0);
  }
  double oneSigmaInterval = 0.683;
  fitResult->GetConfidenceIntervals(nPointsGraph, 1, 1, &xAxisGraph[0], &yAxisGraphErrors[0], oneSigmaInterval, false);
  TGraphErrors* fitFunctionTGraphErrors = new TGraphErrors(nPointsGraph, &xAxisGraph[0], &yAxisGraph[0], nullptr, &yAxisGraphErrors[0]);
  return fitFunctionTGraphErrors;
}

TGraphErrors* GetFunctionTGraphErrorsFromCovMatrix(double* xRangeFit, TF1* fitFunctionDrawn, TMatrixDSym* covMatrix, int nPointsGraph = 1000){
  std::vector<double> xAxisGraph= {};
  std::vector<double> yAxisGraph= {};
  std::vector<double> yAxisGraphErrors= {};
  // double* ;

  for(int iPoint = 0; iPoint < nPointsGraph; iPoint++){
    xAxisGraph.push_back(xRangeFit[0]+iPoint*1./nPointsGraph*(xRangeFit[1]-xRangeFit[0]));
    yAxisGraph.push_back(fitFunctionDrawn->Eval(xAxisGraph.back()));
    yAxisGraphErrors.push_back(fitFunctionDrawn->EvalUncertainty(xAxisGraph.back(), covMatrix));
  }
  TGraphErrors* fitFunctionTGraphErrors = new TGraphErrors(nPointsGraph, &xAxisGraph[0], &yAxisGraph[0], nullptr, &yAxisGraphErrors[0]);
  return fitFunctionTGraphErrors;
}




//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// Fits ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

std::tuple<TF1*, TMatrixDSym, TFitResultPtr> TsallisFit(TH1D* &histogramInput, double* xRangeFit) {
  ////////////////////////////////// Fit initialisation //////////////////////////////////
  //Fit tools initialisation
  TF1 *fitFunctionInit;
  TF1 *fitFunctionFinal;
  TF1 *fitFunctionDrawn; // drawn over the full range

  TFitResultPtr fFitResult;

  const int nParameters = 2;
  std::array<double, nParameters> parfitFunctionInit;
  std::array<double, nParameters> parfitFunctionFinal;

  ////////////////////////////////////////////////////////////////////
  //////////////////////////// Fit start /////////////////////////////
  ////////////////////////////////////////////////////////////////////

  // double xHistMax = xRange[1];
  // double xHistMin = xRange[0];
  
  fitFunctionInit = new TF1("fitFunctionInit_", "x*(1+1/([0]*[1])*x)**(-[0])", xRangeFit[0], xRangeFit[1]);
  // fitFunctionInit = new TF1("fitFunctionInit_", "[0]*exp(([1]-x)**[2])", xRangeFit[0], xRangeFit[1]);
  fitFunctionInit->SetParName(0, "n");
  fitFunctionInit->SetParName(1, "T");
  // fitFunctionInit->SetParName(2, "b");
  fitFunctionInit->SetParameters(8, 0.9);

  histogramInput->Fit(fitFunctionInit, "R0QL"); // P: Use Pearson chi-square method, using expected errors instead of the observed one given by TH1::GetBinError (default case). The expected error is instead estimated from the square-root of the bin function value. (WL for weithged likelihood is currently bugged in root, the fit crashes)

  fitFunctionInit->GetParameters(&parfitFunctionInit[0]);

  fitFunctionFinal = new TF1("fitFunctionFinal_", "x*(1+1/([0]*[1])*x)**(-[0])", xRangeFit[0], xRangeFit[1]);
  // fitFunctionFinal = new TF1("fitFunctionFinal_", "[0]*exp(([1]-x)**[2])", xRangeFit[0], xRangeFit[1]);
  fitFunctionInit->SetParName(0, "n");
  fitFunctionInit->SetParName(1, "T");
  // fitFunctionInit->SetParName(2, "b");
  fitFunctionFinal->SetParameters(parfitFunctionInit[0], parfitFunctionInit[1]);
  // fitFunctionFinal->SetParameters(parfitFunctionInit[0], parfitFunctionInit[1], parfitFunctionInit[2]);
  // fitFunctionFinal->SetParLimits(0, 0., 1.1*yHistMax);
  // fitFunctionFinal->SetParLimits(1, -10, 10);
  // fitFunctionFinal->SetParLimits(2, 0.1, 100);

  fFitResult = histogramInput->Fit(fitFunctionFinal, "R0QPS"); // P: Use Pearson chi-square method, using expected errors instead of the observed one given by TH1::GetBinError (default case). The expected error is instead estimated from the square-root of the bin function value. (WL for weithged likelihood is currently bugged in root, the fit crashes)
  // gauss->Draw("same");
  fitFunctionFinal->GetParameters(&parfitFunctionFinal[0]);
  TMatrixDSym covMatrixFit = fFitResult->GetCovarianceMatrix();

  Double_t *pDataSmall = covMatrixFit.GetMatrixArray();
  for (int i = 0; i < nParameters*nParameters; i++) {
    cout << "i = " << i << ", covMatrixFit[i]" << pDataSmall[i] << endl;
  }

  fitFunctionDrawn = new TF1("fitFunctionDrawn_", "x*(1+1/([0]*[1])*x)**(-[0])", xRangeFit[0], xRangeFit[1]);
  // fitFunctionDrawn = new TF1("fitFunctionDrawn_", "[0]*exp(([1]-x)**[2])", xRangeFit[0], xRangeFit[1]);
  fitFunctionDrawn->SetParameters(parfitFunctionFinal[0], parfitFunctionFinal[1]);
  // fitFunctionDrawn->SetParameters(parfitFunctionFinal[0], parfitFunctionFinal[1], parfitFunctionFinal[2]);
  // fitFunctionDrawn->SetParameters(5, 0.9);

  // cout << "init:  n = " << parfitFunctionInit[0] << ", T = " << parfitFunctionInit[1]<< endl;
  // cout << "final: n = " << parfitFunctionFinal[0] << ", T = " << parfitFunctionFinal[1]<< endl;

  std::tuple<TF1*, TMatrixDSym, TFitResultPtr> fitFunctionAndFitParams(fitFunctionDrawn, covMatrixFit, fFitResult);
  return fitFunctionAndFitParams;
}

std::tuple<TF1*, TMatrixDSym, TFitResultPtr> ExponentialFitWithLogTransfo(TH1D* &histogramInput, double* xRangeFit) {
  // Transforming distribution wiht application of ln()
  TH1D* H1D_logInput = (TH1D*)histogramInput->Clone((TString)histogramInput->GetName()+(TString)"logTransfo");
  for (int iBin = 1; iBin < histogramInput->GetNbinsX() +1; iBin++) {
    H1D_logInput->SetBinContent(iBin, std::log(H1D_logInput->GetBinContent(iBin)));
    H1D_logInput->SetBinError(iBin, H1D_logInput->GetBinError(iBin)/H1D_logInput->GetBinContent(iBin)); // df = dx/x if f=ln(x)
  }

  ////////////////////////////////// Fit initialisation //////////////////////////////////
  //Fit tools initialisation
  TF1 *fitFunctionInit;
  TF1 *fitFunctionFinal;
  TF1 *fitFunctionDrawn; // drawn over the full range

  TFitResultPtr fFitResult;

  const int nParameters = 3;
  std::array<double, nParameters> parfitFunctionInit;
  std::array<double, nParameters> parfitFunctionFinal;

  ////////////////////////////////////////////////////////////////////
  //////////////////////////// Fit start /////////////////////////////
  ////////////////////////////////////////////////////////////////////

  // double xHistMax = xRange[1];
  // double xHistMin = xRange[0];
  fitFunctionInit = new TF1("fitFunctionInit_", "[0] + [1]*log(x) + [2]*x*log(x)", xRangeFit[0], xRangeFit[1]); //eventually x**[3] should be replaced with fit to PYTHIA fulljet spectra
  fitFunctionInit->SetParName(0, "C");
  fitFunctionInit->SetParName(1, "expb");
  fitFunctionInit->SetParName(2, "expa");

  int x30 = H1D_logInput->GetXaxis()->FindBin(30.0);
  double y30 = H1D_logInput->GetBinContent(x30);

  fitFunctionInit->SetParameters(std::log(std::max(1e-12, y30)), -5.0, 0.0);

  // M0QR was used by archita, R0QL by me; Archita's better
  H1D_logInput->Fit(fitFunctionInit, "M0QR"); // 

  // parfitFunctionInit = fitFunctionInit->GetParameters();
  fitFunctionInit->GetParameters(&parfitFunctionInit[0]);

  // fitFunctionFinal = new TF1("fitFunctionFinal_", "[0] + [1]*log(x) + [2]*x*log(x)", xRangeFit[0], xRangeFit[1]);
  fitFunctionFinal = new TF1("fitFunctionDrawn_", "exp([0])*pow(x, [1]+[2]*x)", xRangeFit[0], xRangeFit[1]);
  fitFunctionInit->SetParName(0, "C");
  fitFunctionInit->SetParName(1, "expb");
  fitFunctionInit->SetParName(2, "expa");
  fitFunctionFinal->SetParameters(parfitFunctionInit[0], parfitFunctionInit[1], parfitFunctionInit[2]);
  // fitFunctionFinal->SetParLimits(0, 0., 1.1*yHistMax);
  // fitFunctionFinal->SetParLimits(1, -10, 10);
  // fitFunctionFinal->SetParLimits(2, 0.1, 100);

  fFitResult = histogramInput->Fit(fitFunctionFinal, "M0QRS");

  // parfitFunctionFinal = fitFunctionFinal->GetParameters();
  fitFunctionFinal->GetParameters(&parfitFunctionFinal[0]);

  TMatrixDSym covMatrixFit = fFitResult->GetCovarianceMatrix();

  Double_t *pDataSmall = covMatrixFit.GetMatrixArray();
  for (int i = 0; i < nParameters*nParameters; i++) {
    cout << "covMatrixFit[" << i << "] =" << pDataSmall[i] << endl;
  }

  fitFunctionDrawn = new TF1("fitFunctionDrawn_", "exp([0])*pow(x, [1]+[2]*x)", xRangeFit[0], xRangeFit[1]);
  fitFunctionDrawn->SetParName(0, "C");
  fitFunctionDrawn->SetParName(1, "expb");
  fitFunctionDrawn->SetParName(2, "expa");
  fitFunctionDrawn->SetParameters(parfitFunctionFinal[0], parfitFunctionFinal[1], parfitFunctionFinal[2]);
  // fitFunctionDrawn->SetParameters(5, 0.9);

  // cout << "init:  n = " << parfitFunctionInit[0] << ", T = " << parfitFunctionInit[1]<< endl;
  // cout << "final: n = " << parfitFunctionFinal[0] << ", T = " << parfitFunctionFinal[1]<< endl;

  std::tuple<TF1*, TMatrixDSym, TFitResultPtr> fitFunctionAndFitParams(fitFunctionDrawn, covMatrixFit, fFitResult);
  return fitFunctionAndFitParams;
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// Rebin with Fit ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

std::pair<TH1D*, TGraphErrors*> RebinWithTsallisFit(TH1D* &histogramInput, int nBinsX, double* binsX, double* xRangeFit, TString histName) {
  std::tuple<TF1*, TMatrixDSym, TFitResultPtr> tsallisFitFunctionResult = TsallisFit(histogramInput, xRangeFit);
  TF1* fitFunctionDrawn = std::get<0>(tsallisFitFunctionResult);
  TFitResultPtr fitResult = std::get<2>(tsallisFitFunctionResult);
  TGraphErrors* fitFunctionTGraphErrors = GetFunctionTGraphErrorsFromFitResult(xRangeFit, fitFunctionDrawn, fitResult);

  ///////////////////////////////////////////////////////////////////////////////////
  //////////////////////////// Rebin of input histogram /////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////

  TH1D* histogramRebinned = new TH1D(histName+(TString)"_rebinned", histName+(TString)"_rebinned", nBinsX, binsX);
  for(int iBin = 0; iBin < nBinsX; iBin++){
    // histogramRebinned->SetBinContent(iBin, histogramInput->GetBinContent(iBin)); // Getting bin center here not ideal; should try to read and apply "Where to stick your data points: The treatment of measurements within wide bins"
    histogramRebinned->SetBinContent(iBin, fitFunctionDrawn->Eval(histogramRebinned->GetXaxis()->GetBinCenter(iBin))); // Getting bin center here not ideal; should try to read and apply "Where to stick your data points: The treatment of measurements within wide bins"
    // cout << "histogramRebinned(" << iBin << ") = " << histogramRebinned->GetBinContent(iBin) << endl; 
    // histogramRebinned->SetBinError(iBin, fitFunctionDrawn->EvalUncertainty(histogramRebinned->GetXaxis()->GetBinCenter(iBin), nullptr));
    double oneSigmaInterval = 0.683;
    double errorEval[1] = {0};
    double xEval[1] = {(double)histogramRebinned->GetXaxis()->GetBinCenter(iBin)};
    fitResult->GetConfidenceIntervals(1, 1, 1, xEval, errorEval, oneSigmaInterval, false);
    histogramRebinned->SetBinError(iBin, errorEval[0]);
  }

  std::pair<TH1D*, TGraphErrors*> rebinResultAndFitFunction(histogramRebinned, fitFunctionTGraphErrors);
  return rebinResultAndFitFunction;
}


std::pair<TH1D*, TGraphErrors*> RebinWithFit(TH1D* &histogramInput, int nBinsX, double* binsX, double* xRangeFit, TString histName, std::tuple<TF1*, TMatrixDSym, TFitResultPtr> fitFunctionResult) {
  TF1* fitFunctionDrawn = std::get<0>(fitFunctionResult);
  TFitResultPtr fitResult = std::get<2>(fitFunctionResult);
  TGraphErrors* fitFunctionTGraphErrors = GetFunctionTGraphErrorsFromFitResult(xRangeFit, fitFunctionDrawn, fitResult);

  ///////////////////////////////////////////////////////////////////////////////////
  //////////////////////////// Rebin of input histogram /////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////

  TH1D* histogramRebinned = new TH1D(histName+(TString)"_rebinned", histName+(TString)"_rebinned", nBinsX, binsX);
  for(int iBin = 0; iBin < nBinsX; iBin++){
    // histogramRebinned->SetBinContent(iBin, histogramInput->GetBinContent(iBin)); // Getting bin center here not ideal; should try to read and apply "Where to stick your data points: The treatment of measurements within wide bins"
    histogramRebinned->SetBinContent(iBin, fitFunctionDrawn->Eval(histogramRebinned->GetXaxis()->GetBinCenter(iBin))); // Getting bin center here not ideal; should try to read and apply "Where to stick your data points: The treatment of measurements within wide bins"
    // cout << "histogramRebinned(" << iBin << ") = " << histogramRebinned->GetBinContent(iBin) << endl; 
    // histogramRebinned->SetBinError(iBin, fitFunctionDrawn->EvalUncertainty(histogramRebinned->GetXaxis()->GetBinCenter(iBin), nullptr));
    double oneSigmaInterval = 0.683;
    double errorEval[1] = {0};
    double xEval[1] = {(double)histogramRebinned->GetXaxis()->GetBinCenter(iBin)};
    fitResult->GetConfidenceIntervals(1, 1, 1, xEval, errorEval, oneSigmaInterval, false);
    histogramRebinned->SetBinError(iBin, errorEval[0]);
  }

  std::pair<TH1D*, TGraphErrors*> rebinResultAndFitFunction(histogramRebinned, fitFunctionTGraphErrors);
  return rebinResultAndFitFunction;
}

#endif
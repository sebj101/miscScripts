// barSourceTests.C
// Uses data taken at UCL with a strontium-90 source

std::vector<const char*> days = {/*"05", "06", */"09", "10", "11", "12", 
				 "13", "16",/* "17",*/ "19", "20", "23"};
std::vector<const char*> thresholds = {"5", "10", "15", "20"};
std::vector<const char*> trigCh     = {"3", "4"};
std::vector<const char*> readCh     = {"3", "4"};
std::vector<int> sourceDist   = {16, 32, 48, 64, 80, 96, 112};

double getDeltaT(const char* inputname1){
  
  ifstream f0 (Form("%s", inputname1));
  string line;
  double acqTot = 0.;
  double acq0;

  while ( getline(f0, line)){
    std::size_t pos = line.find(")");
     std::string add0 = line.substr (pos+1, line.size()-1);
     // cout<<add0<<endl;
     acq0 = stod(add0);
     acqTot += acq0;
  }
  f0.close();
  return acqTot;
}

void barSourceTests(const char* saveDir, const char* fileDir="/unix/dune/tof/") 
{
  TFile *fout = new TFile(saveDir, "recreate");

  for (int i = 0; i<days.size(); i++) {
    void* dirp = gSystem->OpenDirectory(Form("%s/2018Jul%s", fileDir, days.at(i)));
    const char* entry;
    TString barFile;
    while ((entry = (char*)gSystem->GetDirEntry(dirp))) {
      barFile = entry; // The bar numbers
      // cout<<barFile<<endl;
      // Append bar name, source position, threshold, readout channel and trigger channel
      if (barFile.Contains("BarD")) {
	for (int t=0; t<thresholds.size(); t++) {
	  for (int tch=0; tch<trigCh.size(); tch++) { 
	    TGraph *gRateVsPos = new TGraph();
	    gRateVsPos->SetName(Form("gRateVsPos_%s_ch%s_thr%s", barFile.Data(), trigCh.at(tch), thresholds.at(t)));
	    gRateVsPos->SetTitle(Form("%s, %s mV threshold; Source position / cm; Signal rate / s^{-1}", barFile.Data(), thresholds.at(t)));
	    gRateVsPos->GetXaxis()->SetTitleSize(.05);
	    gRateVsPos->GetYaxis()->SetTitleSize(.05);
	    gRateVsPos->GetXaxis()->SetLabelSize(.05);
	    gRateVsPos->GetYaxis()->SetLabelSize(.05);
	    for (int src=0; src<sourceDist.size(); src++) {
	      TString filename = Form("%s/2018Jul%s/%s/SourceAt%dcm/TrigCh%s_thres%smV_20mVdiv.ch3.traces.times", fileDir, days.at(i), barFile.Data(), sourceDist.at(src), trigCh.at(tch), thresholds.at(t));
	      cout<<filename<<endl;
	      if (FILE *file = fopen(filename.Data(), "r")) {
		int nEntries = 0;
		cout<<"File exists"<<endl;
		// Check how many traces there are meant to be for each of these
		TFile *fin = new TFile(Form("%s/2018Jul%s/%s/SourceAt%dcm/TrigCh%s_thres%smV_20mVdiv.ch3.traces.root", fileDir, days.at(i), barFile.Data(), sourceDist.at(src), trigCh.at(tch), thresholds.at(t)), "read");
		TKey *key;
		TIter next(fin->GetListOfKeys());
		while ((key = (TKey*) next())) nEntries++;
		cout<<"Number of traces "<<nEntries<<endl;

		double deltaT = getDeltaT(filename.Data());
		cout.precision(10);
		cout<<deltaT<<endl;
		double activity = (double)nEntries/deltaT;
		cout<<"Measured activity = "<<activity<<" Bq"<<endl;

		fin->Close();
		delete fin;
		delete key;
		fclose(file);
		gRateVsPos->SetPoint(gRateVsPos->GetN(), sourceDist.at(src), activity);	
	      } // File exists
	    } // source position
	    fout->cd();
	    gRateVsPos->Write();
	  } // trigger channel
	} // threshold
      } // Directory contains a bar
    } // Looping over directories
  } // Loop over days

  fout->Close();
  delete fout;

} // barSourceTests

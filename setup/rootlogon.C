
{
  TStyle *myStyle = new TStyle("myStyle", "my root style");

  myStyle->SetCanvasBorderMode(0);
  myStyle->SetPadBorderMode(0);
  myStyle->SetPadColor(0);
  myStyle->SetCanvasColor(0);
  myStyle->SetStatColor(0);

  // Axis label sizes
  myStyle->SetLabelSize(.05,"x"); // size of axis values
  myStyle->SetLabelSize(.05,"y");
  myStyle->SetLabelSize(.05,"z");
  myStyle->SetTitleSize(.05,"x"); // size of axis titles
  myStyle->SetTitleSize(.05,"y");
  myStyle->SetTitleSize(.05,"z");
  myStyle->SetTitleOffset(1.1, "x");
  myStyle->SetTitleOffset(1.1, "y");
  //  myStyle->SetTitleOffset(1.1, "z");
  
  // Minor modifications
  myStyle->SetOptStat(0);
  myStyle->SetPalette(60);
  myStyle->SetNumberContours(80);
  
  // Title stuff
  myStyle->SetTitleFillColor(0);
  myStyle->SetTitleTextColor(1);
  myStyle->SetTitleStyle(1001);
  myStyle->SetTitleFont(42, "");
  myStyle->SetTitleSize(.05,"");
  myStyle->SetTitleBorderSize(0);
  myStyle->SetTitleX(0.1);
  myStyle->SetTitleY(0.995);
  myStyle->SetTitleW(0.8);
  
  // canvas positioning                                                 
  myStyle->SetPadBottomMargin(0.13);
  myStyle->SetPadTopMargin(0.1);
  myStyle->SetPadLeftMargin(0.15);
  myStyle->SetPadRightMargin(0.1);
  myStyle->SetPadTickX(1);
  myStyle->SetPadTickY(1);

  // Legend stuff
  myStyle->SetLegendFont(42);
  myStyle->SetLegendBorderSize(1);
  
  TStyle *def = new TStyle("Default","Default Style");

  //gROOT->Reset();
  gROOT->SetStyle("myStyle");
}

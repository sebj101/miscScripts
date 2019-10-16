
{
  TStyle *myStyle = new TStyle("myStyle", "my root style");

  // from ROOT plain style                                                      
  myStyle->SetCanvasBorderMode(0);
  myStyle->SetPadBorderMode(0);
  myStyle->SetPadColor(0);
  myStyle->SetCanvasColor(0);
  myStyle->SetTitleColor(0);
  myStyle->SetStatColor(0);
  myStyle->SetLabelSize(.05,"x"); // size of axis values
  myStyle->SetLabelSize(.05,"y");
  myStyle->SetLabelSize(.05,"z");
  myStyle->SetTitleSize(.05,"x"); // size of axis titles
  myStyle->SetTitleSize(.05,"y");
  myStyle->SetTitleSize(.05,"z");

  // Minor modifications
  myStyle->SetOptStat(0);
  myStyle->SetPalette(55);

  // Title position
  myStyle->SetTitleStyle(0);
  myStyle->SetTitleFont(42);
  myStyle->SetTitleX(0.1f);
  myStyle->SetTitleW(0.8f);
  //  myStyle->SetTitleXOffset(0.8f);
  
  // canvas positioning                                                 
  //  myStyle->SetCanvasDefX(900);
  //  myStyle->SetCanvasDefY(20);
  //  myStyle->SetCanvasDefH(550);
  //  myStyle->SetCanvasDefW(540);
  myStyle->SetPadBottomMargin(0.13);
  myStyle->SetPadTopMargin(0.1);
  myStyle->SetPadLeftMargin(0.13);
  myStyle->SetPadRightMargin(0.1);

  //myStyle->SetPadTickX(1);
  //myStyle->SetPadTickY(1);


  
  gROOT->SetStyle("myStyle");
}

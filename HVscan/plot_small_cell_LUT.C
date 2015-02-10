{
  gROOT->LoadMacro("small_cell_LUT.C");
  TGraph * plot = new TGraph();
  Int_t c=0;
  for(Int_t i=0; i<=256; i++)
  {
    printf("%d\n",i+1);
    plot->SetPoint(c,i,small_cell_LUT(i));
    c++;
  };
  TCanvas * c1 = new TCanvas("c1","c1",500,700);
  plot->Draw("AP");
};

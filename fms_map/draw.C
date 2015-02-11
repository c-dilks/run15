void draw()
{
  TFile * infile = new TFile("tree.root","READ");
  TTree * tr = (TTree*) infile->Get("geotr");
  
  Int_t nstb,row,col;
  char cell_type[32];
  char hvaddress_char[8];
  tr->SetBranchAddress("nstb",&nstb);
  tr->SetBranchAddress("row",&row);
  tr->SetBranchAddress("col",&col);
  tr->SetBranchAddress("cell_type",cell_type);
  tr->SetBranchAddress("hvaddress_char",hvaddress_char);

  // cell types
  const Int_t NUM_TYPES=4;
  char cell_type_def[NUM_TYPES][32];
  strcpy(cell_type_def[0],"large_edge");
  strcpy(cell_type_def[1],"large_regular");
  strcpy(cell_type_def[2],"small_russian");
  strcpy(cell_type_def[3],"small_yale");
  char cell_type_legend[1024];
  strcpy(cell_type_legend,"legend:");
  for(Int_t i=0; i<NUM_TYPES; i++) 
    sprintf(cell_type_legend,"%s %d=%s",cell_type_legend,i+1,cell_type_def[i]);


  // fms display
  TH2F* large_type=new TH2F("large_type","cell types",34,-98.6,98.6,34,-98.6,98.6);
  TH2F* small_type=new TH2F("small_type","cell types",52,-98.6,98.6,52,-98.6,98.6);
  TH2F* large_pp=new TH2F("large_pp","patch panel",34,-98.6,98.6,34,-98.6,98.6);
  TH2F* small_pp=new TH2F("small_pp","patch panel",52,-98.6,98.6,52,-98.6,98.6);
  TH2F* large_pprow=new TH2F("large_pprow","patch panel row",34,-98.6,98.6,34,-98.6,98.6);
  TH2F* small_pprow=new TH2F("small_pprow","patch panel row",52,-98.6,98.6,52,-98.6,98.6);
  TH2F* large_ppcol=new TH2F("large_ppcol","patch panel column",34,-98.6,98.6,34,-98.6,98.6);
  TH2F* small_ppcol=new TH2F("small_ppcol","patch panel column",52,-98.6,98.6,52,-98.6,98.6);
  TH2F* large_qtcrate=new TH2F("large_qtcrate","qt crate",34,-98.6,98.6,34,-98.6,98.6);
  TH2F* small_qtcrate=new TH2F("small_qtcrate","qt crate",52,-98.6,98.6,52,-98.6,98.6);
  TH2F* large_qtslot=new TH2F("large_qtslot","qt slot",34,-98.6,98.6,34,-98.6,98.6);
  TH2F* small_qtslot=new TH2F("small_qtslot","qt slot",52,-98.6,98.6,52,-98.6,98.6);
  TH2F* large_qtcard=new TH2F("large_qtcard","qt card",34,-98.6,98.6,34,-98.6,98.6);
  TH2F* small_qtcard=new TH2F("small_qtcard","qt card",52,-98.6,98.6,52,-98.6,98.6);
  TH2F* large_qtchan=new TH2F("large_qtchan","qt chan",34,-98.6,98.6,34,-98.6,98.6);
  TH2F* small_qtchan=new TH2F("small_qtchan","qt chan",52,-98.6,98.6,52,-98.6,98.6);

  TH2F* large_hvcrate=new TH2F("large_hvcrate","lecroy crate",34,-98.6,98.6,34,-98.6,98.6);
  TH2F* large_hvslot=new TH2F("large_hvslot","lecroy slot",34,-98.6,98.6,34,-98.6,98.6);
  TH2F* large_hvchan=new TH2F("large_hvchan","lecroy channel",34,-98.6,98.6,34,-98.6,98.6);

  TH2F* small_hvboard=new TH2F("small_hvboard","motherboard number",52,-98.6,98.6,52,-98.6,98.6);
  TH2F* small_hvchip=new TH2F("small_hvchip","motherboard chip",52,-98.6,98.6,52,-98.6,98.6);
  TH2F* small_hvchan=new TH2F("small_hvchan","motherboard channel",52,-98.6,98.6,52,-98.6,98.6);
  TH2F* small_hvaddress=new TH2F("small_hvaddress","base address (text = address integer)",52,-98.6,98.6,52,-98.6,98.6);
  TH2F* small_hvaddress_char=new TH2F("small_hvaddress_char","base address (text = address integer)",52,-98.6,98.6,52,-98.6,98.6);


  large_type->GetXaxis()->SetTitle(cell_type_legend);
  large_type->SetMinimum(0);
  large_type->SetMaximum(NUM_TYPES);
  small_type->GetXaxis()->SetTitle(cell_type_legend);
  small_type->SetMinimum(0);
  small_type->SetMaximum(NUM_TYPES);

  large_pp->SetMinimum(0);
  small_pp->SetMinimum(0);
  large_pprow->SetMinimum(0);
  small_pprow->SetMinimum(0);
  large_ppcol->SetMinimum(0);
  small_ppcol->SetMinimum(0);
  large_qtcrate->SetMinimum(0);
  small_qtcrate->SetMinimum(0);
  large_qtslot->SetMinimum(0);
  small_qtslot->SetMinimum(0);
  large_qtcard->SetMinimum(0);
  small_qtcard->SetMinimum(0);
  large_qtchan->SetMinimum(0);
  small_qtchan->SetMinimum(0);
  large_hvcrate->SetMinimum(7005);
  large_hvslot->SetMinimum(0);
  large_hvchan->SetMinimum(0);
  small_hvboard->SetMinimum(0);
  small_hvchip->SetMinimum(0);
  small_hvchan->SetMinimum(0);
  small_hvaddress->SetMinimum(224);

  large_pp->SetMaximum(3);
  small_pp->SetMaximum(3);
  large_pprow->SetMaximum(22);
  small_pprow->SetMaximum(22);
  large_ppcol->SetMaximum(18);
  small_ppcol->SetMaximum(18);
  large_qtcrate->SetMaximum(5);
  small_qtcrate->SetMaximum(5);
  large_qtslot->SetMaximum(17);
  small_qtslot->SetMaximum(17);
  large_qtcard->SetMaximum(4);
  small_qtcard->SetMaximum(4);
  large_qtchan->SetMaximum(8);
  small_qtchan->SetMaximum(8);
  large_hvcrate->SetMaximum(7009);
  large_hvslot->SetMaximum(17);
  large_hvchan->SetMaximum(17);
  small_hvboard->SetMaximum(4);
  small_hvchip->SetMaximum(4);
  small_hvchan->SetMaximum(4);
  small_hvaddress->SetMaximum(256);

  tr->Project("large_pp","-5.8*(row+0.5-17):5.8*2*(nstb-1.5)*(col+.5)","pp*(nstb==1||nstb==2)");
  tr->Project("small_pp","-3.8*(row-11.5):3.8*2*(nstb-3.5)*(col+.5)","pp*(nstb==3||nstb==4)");
  tr->Project("large_pprow","-5.8*(row+0.5-17):5.8*2*(nstb-1.5)*(col+.5)","pprow*(nstb==1||nstb==2)");
  tr->Project("small_pprow","-3.8*(row-11.5):3.8*2*(nstb-3.5)*(col+.5)","pprow*(nstb==3||nstb==4)");
  tr->Project("large_ppcol","-5.8*(row+0.5-17):5.8*2*(nstb-1.5)*(col+.5)","ppcol*(nstb==1||nstb==2)");
  tr->Project("small_ppcol","-3.8*(row-11.5):3.8*2*(nstb-3.5)*(col+.5)","ppcol*(nstb==3||nstb==4)");
  tr->Project("large_qtcrate","-5.8*(row+0.5-17):5.8*2*(nstb-1.5)*(col+.5)","qtcrate*(nstb==1||nstb==2)");
  tr->Project("small_qtcrate","-3.8*(row-11.5):3.8*2*(nstb-3.5)*(col+.5)","qtcrate*(nstb==3||nstb==4)");
  tr->Project("large_qtslot","-5.8*(row+0.5-17):5.8*2*(nstb-1.5)*(col+.5)","(qtslot+0.01)*(nstb==1||nstb==2)");
  tr->Project("small_qtslot","-3.8*(row-11.5):3.8*2*(nstb-3.5)*(col+.5)","(qtslot+0.01)*(nstb==3||nstb==4)");
  tr->Project("large_qtcard","-5.8*(row+0.5-17):5.8*2*(nstb-1.5)*(col+.5)","(qtcard+0.01)*(nstb==1||nstb==2)");
  tr->Project("small_qtcard","-3.8*(row-11.5):3.8*2*(nstb-3.5)*(col+.5)","(qtcard+0.01)*(nstb==3||nstb==4)");
  tr->Project("large_qtchan","-5.8*(row+0.5-17):5.8*2*(nstb-1.5)*(col+.5)","(qtchan+0.01)*(nstb==1||nstb==2)");
  tr->Project("small_qtchan","-3.8*(row-11.5):3.8*2*(nstb-3.5)*(col+.5)","(qtchan+0.01)*(nstb==3||nstb==4)");

  tr->Project("large_hvcrate","-5.8*(row+0.5-17):5.8*2*(nstb-1.5)*(col+.5)","hvcrate*(nstb==1||nstb==2)");
  tr->Project("large_hvslot","-5.8*(row+0.5-17):5.8*2*(nstb-1.5)*(col+.5)","(hvslot+0.01)*(nstb==1||nstb==2)");
  tr->Project("large_hvchan","-5.8*(row+0.5-17):5.8*2*(nstb-1.5)*(col+.5)","(hvchan+0.01)*(nstb==1||nstb==2)");

  tr->Project("small_hvboard","-3.8*(row-11.5):3.8*2*(nstb-3.5)*(col+.5)","hvboard*(nstb==3||nstb==4)");
  tr->Project("small_hvchip","-3.8*(row-11.5):3.8*2*(nstb-3.5)*(col+.5)","(hvchip+0.01)*(nstb==3||nstb==4)");
  tr->Project("small_hvchan","-3.8*(row-11.5):3.8*2*(nstb-3.5)*(col+.5)","(hvchan+0.01)*(nstb==3||nstb==4)");
  tr->Project("small_hvaddress","-3.8*(row-11.5):3.8*2*(nstb-3.5)*(col+.5)","hvaddress*(nstb==3||nstb==4)");

  /*
  Int_t binn;
  for(Int_t i=0; i<tr->GetEntries(); i++)
  {
    tr->GetEntry(i);
    if(nstb==3 || nstb==4)
    {
      binn = small_hvaddress->FindBin(3.8*2*(nstb-3.5)*(col+.5),-3.8*(row-11.5));
      small_hvaddress->SetBinContent(binn,hvaddress_char);
    };
  };
  */



  TH2F* largetxt=new TH2F("largetxt","largetxt",34,-98.6,98.6,34,-98.6,98.6);
  TH2F* smalltxt=new TH2F("smalltxt","smalltxt",52,-98.6,98.6,52,-98.6,98.6);
  tr->Project("largetxt","-5.8*(row+0.5-17):5.8*2*(nstb-1.5)*(col+.5)","(col+row*17+1)*(nstb==1||nstb==2)");
  tr->Project("smalltxt","-3.8*(row-11.5):3.8*2*(nstb-3.5)*(col+.5)","(col+row*12+1)*(nstb==3||nstb==4)");
  largetxt->SetMarkerSize(0.5);
  smalltxt->SetMarkerSize(0.5);
  TLine * vline = new TLine(0,-98.6,0,98.6);
  TLine * hline = new TLine(-98.6,0,98.6,0);
  TLine * short_vline = new TLine(0,-46,0,46);
  TLine * short_hline = new TLine(-46,0,46,0);
  TLine * svline[4];
    svline[0] = new TLine(3.8*2*(4-3.5)*(3+.5)+3.8/2, -3.8*(0-11.5)+3.8/2, 3.8*2*(4-3.5)*(3+.5)+3.8/2, -3.8*(6-11.5)-3.8/2);
    svline[1] = new TLine(3.8*2*(4-3.5)*(3+.5)+3.8/2, -3.8*(17-11.5)+3.8/2, 3.8*2*(4-3.5)*(3+.5)+3.8/2, -3.8*(23-11.5)-3.8/2);
    svline[2] = new TLine(3.8*2*(3-3.5)*(3+.5)-3.8/2, -3.8*(0-11.5)+3.8/2, 3.8*2*(3-3.5)*(3+.5)-3.8/2, -3.8*(6-11.5)-3.8/2);
    svline[3] = new TLine(3.8*2*(3-3.5)*(3+.5)-3.8/2, -3.8*(17-11.5)+3.8/2, 3.8*2*(3-3.5)*(3+.5)-3.8/2, -3.8*(23-11.5)-3.8/2);
  TLine * shline[4];
    shline[0] = new TLine(3.8*2*(4-3.5)*(4+.5)+3.8/2, -3.8*(7-11.5)-3.8/2, 3.8*2*(4-3.5)*(11+.5)+3.8/2, -3.8*(7-11.5)-3.8/2);
    shline[1] = new TLine(3.8*2*(4-3.5)*(4+.5)+3.8/2, -3.8*(15-11.5)-3.8/2, 3.8*2*(4-3.5)*(11+.5)+3.8/2, -3.8*(15-11.5)-3.8/2);
    shline[2] = new TLine(3.8*2*(3-3.5)*(4+.5)-3.8/2, -3.8*(7-11.5)-3.8/2, 3.8*2*(3-3.5)*(11+.5)-3.8/2, -3.8*(7-11.5)-3.8/2);
    shline[3] = new TLine(3.8*2*(3-3.5)*(4+.5)-3.8/2, -3.8*(15-11.5)-3.8/2, 3.8*2*(3-3.5)*(11+.5)-3.8/2, -3.8*(15-11.5)-3.8/2);
  TLine * ibox[4];
    ibox[0] = new TLine(-5*3.8,5*3.8,5*3.8,5*3.8);
    ibox[1] = new TLine(5*3.8,5*3.8,5*3.8,-5*3.8);
    ibox[2] = new TLine(5*3.8,-5*3.8,-5*3.8,-5*3.8);
    ibox[3] = new TLine(-5*3.8,-5*3.8,-5*3.8,5*3.8);
  TLine * obox[4];
    obox[0] = new TLine(-12*3.8,12*3.8,12*3.8,12*3.8);
    obox[1] = new TLine(12*3.8,12*3.8,12*3.8,-12*3.8);
    obox[2] = new TLine(12*3.8,-12*3.8,-12*3.8,-12*3.8);
    obox[3] = new TLine(-12*3.8,-12*3.8,-12*3.8,12*3.8);
  char wname[32];
  vline->SetLineColor(kBlack);
  hline->SetLineColor(kBlack);
  vline->SetLineWidth(2.5);
  hline->SetLineWidth(2.5);
  short_vline->SetLineColor(kBlack);
  short_hline->SetLineColor(kBlack);
  short_vline->SetLineWidth(2.5);
  short_hline->SetLineWidth(2.5);


  // cell type
  Double_t row_map,col_map,type_weight;
  Int_t binn;
  for(Int_t i=0; i<tr->GetEntries(); i++)
  {
    tr->GetEntry(i);
    for(Int_t tt=0; tt<NUM_TYPES; tt++)
      if(!strcmp(cell_type,cell_type_def[tt])) type_weight=tt+1;
    if(nstb==1||nstb==2) 
    {
      row_map = -5.8*(row+0.5-17);
      col_map = 5.8*2*(nstb-1.5)*(col+0.5);
      binn = large_type->FindBin(col_map,row_map);
      large_type->SetBinContent(binn,type_weight);
    }
    else
    {
      row_map = -3.8*(row-11.5);
      col_map = 3.8*2*(nstb-3.5)*(col+0.5);
      binn = small_type->FindBin(col_map,row_map);
      small_type->SetBinContent(binn,type_weight);
    };
  };


  // draw
  TFile * outfile = new TFile("maps.root","RECREATE");

  TCanvas * type_canv = new TCanvas("type_canv","type_canv",1000,650); 
  large_type->Draw("zcol");
  small_type->Draw("zcolsame");
  largetxt->Draw("textsame");
  smalltxt->Draw("textsame");
  vline->Draw();
  hline->Draw();
  for(Int_t ii=0; ii<4; ii++) 
  {
    svline[ii]->Draw();
    shline[ii]->Draw();
    ibox[ii]->Draw();
    obox[ii]->Draw();
  };
  type_canv->SetGrid(0,0);
  type_canv->Write();

  TCanvas * pp_canv = new TCanvas("pp_canv","pp_canv",1000,650); 
  large_pp->Draw("zcol");
  small_pp->Draw("zcolsame");
  largetxt->Draw("textsame");
  smalltxt->Draw("textsame");
  vline->Draw();
  hline->Draw();
  for(Int_t ii=0; ii<4; ii++) 
  {
    svline[ii]->Draw();
    shline[ii]->Draw();
    ibox[ii]->Draw();
    obox[ii]->Draw();
  };
  pp_canv->SetGrid(0,0);
  pp_canv->Write();

  TCanvas * pprow_canv = new TCanvas("pprow_canv","pprow_canv",1000,650); 
  large_pprow->Draw("zcol");
  small_pprow->Draw("zcolsame");
  largetxt->Draw("textsame");
  smalltxt->Draw("textsame");
  vline->Draw();
  hline->Draw();
  for(Int_t ii=0; ii<4; ii++) 
  {
    svline[ii]->Draw();
    shline[ii]->Draw();
    ibox[ii]->Draw();
    obox[ii]->Draw();
  };
  pprow_canv->SetGrid(0,0);
  pprow_canv->Write();

  TCanvas * ppcol_canv = new TCanvas("ppcol_canv","ppcol_canv",1000,650); 
  large_ppcol->Draw("zcol");
  small_ppcol->Draw("zcolsame");
  largetxt->Draw("textsame");
  smalltxt->Draw("textsame");
  vline->Draw();
  hline->Draw();
  for(Int_t ii=0; ii<4; ii++) 
  {
    svline[ii]->Draw();
    shline[ii]->Draw();
    ibox[ii]->Draw();
    obox[ii]->Draw();
  };
  ppcol_canv->SetGrid(0,0);
  ppcol_canv->Write();

  TCanvas * qtcrate_canv = new TCanvas("qtcrate_canv","qtcrate_canv",1000,650); 
  large_qtcrate->Draw("zcol");
  small_qtcrate->Draw("zcolsame");
  largetxt->Draw("textsame");
  smalltxt->Draw("textsame");
  vline->Draw();
  hline->Draw();
  for(Int_t ii=0; ii<4; ii++) 
  {
    svline[ii]->Draw();
    shline[ii]->Draw();
    ibox[ii]->Draw();
    obox[ii]->Draw();
  };
  qtcrate_canv->SetGrid(0,0);
  qtcrate_canv->Write();

  TCanvas * qtslot_canv = new TCanvas("qtslot_canv","qtslot_canv",1000,650); 
  large_qtslot->Draw("zcol");
  small_qtslot->Draw("zcolsame");
  largetxt->Draw("textsame");
  smalltxt->Draw("textsame");
  vline->Draw();
  hline->Draw();
  for(Int_t ii=0; ii<4; ii++) 
  {
    svline[ii]->Draw();
    shline[ii]->Draw();
    ibox[ii]->Draw();
    obox[ii]->Draw();
  };
  qtslot_canv->SetGrid(0,0);
  qtslot_canv->Write();

  TCanvas * qtcard_canv = new TCanvas("qtcard_canv","qtcard_canv",1000,650); 
  large_qtcard->Draw("zcol");
  small_qtcard->Draw("zcolsame");
  largetxt->Draw("textsame");
  smalltxt->Draw("textsame");
  vline->Draw();
  hline->Draw();
  for(Int_t ii=0; ii<4; ii++) 
  {
    svline[ii]->Draw();
    shline[ii]->Draw();
    ibox[ii]->Draw();
    obox[ii]->Draw();
  };
  qtcard_canv->SetGrid(0,0);
  qtcard_canv->Write();

  TCanvas * qtchan_canv = new TCanvas("qtchan_canv","qtchan_canv",1000,650); 
  large_qtchan->Draw("zcol");
  small_qtchan->Draw("zcolsame");
  largetxt->Draw("textsame");
  smalltxt->Draw("textsame");
  vline->Draw();
  hline->Draw();
  for(Int_t ii=0; ii<4; ii++) 
  {
    svline[ii]->Draw();
    shline[ii]->Draw();
    ibox[ii]->Draw();
    obox[ii]->Draw();
  };
  qtchan_canv->SetGrid(0,0);
  qtchan_canv->Write();

  TCanvas * large_hvcrate_canv = new TCanvas("large_hvcrate_canv","large_hvcrate_canv",1000,650); 
  large_hvcrate->Draw("zcol");
  largetxt->Draw("textsame");
  smalltxt->Draw("textsame");
  vline->Draw();
  hline->Draw();
  for(Int_t ii=0; ii<4; ii++) 
  {
    svline[ii]->Draw();
    shline[ii]->Draw();
    ibox[ii]->Draw();
    obox[ii]->Draw();
  };
  large_hvcrate_canv->SetGrid(0,0);
  large_hvcrate_canv->Write();

  TCanvas * large_hvslot_canv = new TCanvas("large_hvslot_canv","large_hvslot_canv",1000,650); 
  large_hvslot->Draw("zcol");
  largetxt->Draw("textsame");
  smalltxt->Draw("textsame");
  vline->Draw();
  hline->Draw();
  for(Int_t ii=0; ii<4; ii++) 
  {
    svline[ii]->Draw();
    shline[ii]->Draw();
    ibox[ii]->Draw();
    obox[ii]->Draw();
  };
  large_hvslot_canv->SetGrid(0,0);
  large_hvslot_canv->Write();

  TCanvas * large_hvchan_canv = new TCanvas("large_hvchan_canv","large_hvchan_canv",1000,650); 
  large_hvchan->Draw("zcol");
  largetxt->Draw("textsame");
  smalltxt->Draw("textsame");
  vline->Draw();
  hline->Draw();
  for(Int_t ii=0; ii<4; ii++) 
  {
    svline[ii]->Draw();
    shline[ii]->Draw();
    ibox[ii]->Draw();
    obox[ii]->Draw();
  };
  large_hvchan_canv->SetGrid(0,0);
  large_hvchan_canv->Write();

  TCanvas * small_hvboard_canv = new TCanvas("small_hvboard_canv","small_hvboard_canv",1000,650); 
  small_hvboard->GetXaxis()->SetRangeUser(-46,46);
  small_hvboard->GetYaxis()->SetRangeUser(-46,46);
  small_hvboard->Draw("zcol");
  smalltxt->Draw("textsame");
  short_vline->Draw();
  short_hline->Draw();
  for(Int_t ii=0; ii<4; ii++) 
  {
    svline[ii]->Draw();
    shline[ii]->Draw();
    ibox[ii]->Draw();
    obox[ii]->Draw();
  };
  small_hvboard_canv->SetGrid(0,0);
  small_hvboard_canv->Write();

  TCanvas * small_hvchip_canv = new TCanvas("small_hvchip_canv","small_hvchip_canv",1000,650); 
  small_hvchip->GetXaxis()->SetRangeUser(-46,46);
  small_hvchip->GetYaxis()->SetRangeUser(-46,46);
  small_hvchip->Draw("zcol");
  smalltxt->Draw("textsame");
  short_vline->Draw();
  short_hline->Draw();
  for(Int_t ii=0; ii<4; ii++) 
  {
    svline[ii]->Draw();
    shline[ii]->Draw();
    ibox[ii]->Draw();
    obox[ii]->Draw();
  };
  small_hvchip_canv->SetGrid(0,0);
  small_hvchip_canv->Write();

  TCanvas * small_hvchan_canv = new TCanvas("small_hvchan_canv","small_hvchan_canv",1000,650); 
  small_hvchan->GetXaxis()->SetRangeUser(-46,46);
  small_hvchan->GetYaxis()->SetRangeUser(-46,46);
  small_hvchan->Draw("zcol");
  smalltxt->Draw("textsame");
  short_vline->Draw();
  short_hline->Draw();
  for(Int_t ii=0; ii<4; ii++) 
  {
    svline[ii]->Draw();
    shline[ii]->Draw();
    ibox[ii]->Draw();
    obox[ii]->Draw();
  };
  small_hvchan_canv->SetGrid(0,0);
  small_hvchan_canv->Write();

  TCanvas * small_hvaddress_canv = new TCanvas("small_hvaddress_canv","small_hvaddress_canv",1000,650); 
  small_hvaddress->GetXaxis()->SetRangeUser(-46,46);
  small_hvaddress->GetYaxis()->SetRangeUser(-46,46);
  small_hvaddress->Draw("zcol");
  small_hvaddress->SetMarkerSize(0.8);
  small_hvaddress->Draw("textsame");
  //small_hvaddress_char->Draw("textsame");
  short_vline->Draw();
  short_hline->Draw();
  for(Int_t ii=0; ii<4; ii++) 
  {
    svline[ii]->Draw();
    shline[ii]->Draw();
    ibox[ii]->Draw();
    obox[ii]->Draw();
  };
  small_hvaddress_canv->SetGrid(0,0);
  small_hvaddress_canv->Write();
};

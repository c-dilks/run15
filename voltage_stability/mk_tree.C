void mk_tree(const char * filename="master", Int_t month0=2, Int_t day0=20, Int_t timecut=0)
{
  char outfilename[128];
  sprintf(outfilename,"rootfile.2015.%d.%d.root",month0,day0);
  TFile * outfile = new TFile(outfilename,"RECREATE");
  TTree * tr = new TTree();
  tr->ReadFile(filename,"crate/I:date/C:time/C:slot/I:chan/I:setpoint/I:readback/F");
  tr->Write("tr");
  Int_t crate,slot,chan,setpoint;
  Int_t year,month,day,hour,minute,second;
  Int_t c;
  Float_t readback;
  char date[32];
  char time[32];
  Color_t color[4] = {kRed,kGreen+1,kBlue,kMagenta};

  tr->SetBranchAddress("crate",&crate);
  tr->SetBranchAddress("date",date);
  tr->SetBranchAddress("time",time);
  tr->SetBranchAddress("slot",&slot);
  tr->SetBranchAddress("chan",&chan);
  tr->SetBranchAddress("setpoint",&setpoint);
  tr->SetBranchAddress("readback",&readback);

  TGraph * stability[4][16][16]; // [crate] [slot] [chan]
  Int_t stability_i[4][16][16];
  for(Int_t c=0; c<4; c++)
  {
    for(Int_t sl=0; sl<16; sl++)
    {
      for(Int_t ch=0; ch<16; ch++)
      {
        stability[c][sl][ch] = new TGraph();
        //printf("%d %d %d %p\n",c,sl,ch,(void*)(stability[c][sl][ch]));
        stability_i[c][sl][ch] = 0;
        stability[c][sl][ch]->SetMarkerStyle(kFullCircle);
        stability[c][sl][ch]->SetMarkerColor(color[c]);
      };
    };
  };
  

  for(Int_t i=0; i<tr->GetEntries(); i++)
  {
    tr->GetEntry(i);
    sscanf(date,"%d.%d.%d",&year,&month,&day);
    if(month==month0 && day==day0)
    {
      sscanf(time,"%d.%d.%d",&hour,&minute,&second);
      c = CrateToIndex(crate);
      if(100*hour+minute>=timecut)
      {
        stability[c][slot][chan]->SetPoint(
          stability_i[c][slot][chan],
          100*hour+minute,
          setpoint-readback);
        stability_i[c][slot][chan]++;
      };
    };
  };



  TLatex * color_leg[4];
  char color_leg_txt[4][8];
  for(Int_t c=0; c<4; c++)
  {
    sprintf(color_leg_txt[c],"%d",IndexToCrate(c));
    color_leg[c] = new TLatex(0.0,0.9-c*0.1,color_leg_txt[c]);
    color_leg[c]->SetNDC();
    color_leg[c]->SetTextColor(color[c]);
    color_leg[c]->SetTextSize(0.08);
  };

  gStyle->SetTitleH(0.1);
  gStyle->SetTitleW(0.7);
  TMultiGraph * multi_stability[16][16]; // [slot] [chan]
  char multi_stability_t[16][16][512];
  TCanvas * canv = new TCanvas("canv","canv",700,1200);
  canv->Divide(1,8);
  Int_t padnum=1;
  Int_t pagenum=1;
  char pdfname[64];
  char pdfnameL[64];
  char pdfnameR[64];
  char canv_writename[64];
  sprintf(pdfname,"monitor.%d.%d.%d.pdf",year,month,day);
  sprintf(pdfnameL,"%s(",pdfname);
  sprintf(pdfnameR,"%s)",pdfname);
  for(Int_t sl=0; sl<16; sl++)
  {
    for(Int_t ch=0; ch<16; ch++)
    {
      sprintf(multi_stability_t[sl][ch],
        "V_{set}-V_{read} vs. time (%d,%d) on %d-%d-%d",
        sl,ch,year,month,day);
      multi_stability[sl][ch] = new TMultiGraph();
      multi_stability[sl][ch]->SetTitle(multi_stability_t[sl][ch]);
      for(Int_t c=0; c<4; c++)
      {
        if(stability[c][sl][ch]!=NULL)
        {
          multi_stability[sl][ch]->Add(stability[c][sl][ch]);
        };
      };
      canv->cd(padnum);
      canv->GetPad(padnum)->SetGrid(1,1);
      multi_stability[sl][ch]->Draw("AP");
      multi_stability[sl][ch]->GetXaxis()->SetLabelSize(0.08);
      multi_stability[sl][ch]->GetYaxis()->SetLabelSize(0.08);
      for(Int_t c=0; c<4; c++) color_leg[c]->Draw();
      //printf("%d %d\n",pagenum,padnum);
      padnum++;
      if(padnum>8)
      {
        if(pagenum==1) canv->Print(pdfnameL,"PDF");
        else if(pagenum==32) canv->Print(pdfnameR,"PDF");
        else canv->Print(pdfname,"PDF");
        sprintf(canv_writename,"stability_slot%d_ch%d-%d",sl,
          (pagenum%2)?0:8,(pagenum%2)?7:15);
        canv->Write(canv_writename);
        pagenum++;
        padnum=1;
      };
    };
  };

  TH2F * rms_plot[4];
  char rms_plot_t[4][64];
  char rms_plot_n[4][32];
  TH2F * ave_plot[4];
  char ave_plot_t[4][64];
  char ave_plot_n[4][32];
  Int_t binn;
  for(Int_t c=0; c<4; c++)
  {
    sprintf(rms_plot_t[c],"RMS(V_{set}-V_{read}) vs. slot,channel [%d];slot;channel",IndexToCrate(c));
    sprintf(rms_plot_n[c],"rms_plot_%d",IndexToCrate(c));
    rms_plot[c] = new TH2F(rms_plot_n[c],rms_plot_t[c],16,-0.5,15.5,16,-0.5,15.5);
    sprintf(ave_plot_t[c],"|<V_{set}-V_{read}>| vs. slot,channel [%d];slot;channel",IndexToCrate(c));
    sprintf(ave_plot_n[c],"ave_plot_%d",IndexToCrate(c));
    ave_plot[c] = new TH2F(ave_plot_n[c],ave_plot_t[c],16,-0.5,15.5,16,-0.5,15.5);
    for(Int_t sl=0; sl<16; sl++)
    {
      for(Int_t ch=0; ch<16; ch++)
      {
        if(stability_i[c][sl][ch])
        {
          binn = rms_plot[c]->FindBin(sl,ch);
          rms_plot[c]->SetBinContent(binn,stability[c][sl][ch]->GetRMS(2));
          ave_plot[c]->SetBinContent(binn,fabs(stability[c][sl][ch]->GetMean(2)));
        };
      };
    };
  };

  TCanvas * rms_canv = new TCanvas("rms_canv","rms_canv",750,750);
  rms_canv->Divide(2,2);
  char draw_style[16];
  strcpy(draw_style,"lego2");
  //for(Int_t c=1; c<5; c++) rms_canv->GetPad(c)->SetLogz();
  rms_canv->cd(1); rms_plot[0]->Draw(draw_style);
  rms_canv->cd(3); rms_plot[1]->Draw(draw_style);
  rms_canv->cd(2); rms_plot[2]->Draw(draw_style);
  rms_canv->cd(4); rms_plot[3]->Draw(draw_style);
  rms_canv->Write();

  TCanvas * ave_canv = new TCanvas("ave_canv","ave_canv",750,750);
  ave_canv->Divide(2,2);
  char draw_style[16];
  strcpy(draw_style,"lego2");
  //for(Int_t c=1; c<5; c++) ave_canv->GetPad(c)->SetLogz();
  ave_canv->cd(1); ave_plot[0]->Draw(draw_style);
  ave_canv->cd(3); ave_plot[1]->Draw(draw_style);
  ave_canv->cd(2); ave_plot[2]->Draw(draw_style);
  ave_canv->cd(4); ave_plot[3]->Draw(draw_style);
  ave_canv->Write();




  printf("%s created\n",pdfname);
  printf("%s created\n",outfilename);
}

Int_t CrateToIndex(Int_t crate0)
{
  return crate0-7005;
}

Int_t IndexToCrate(Int_t index0)
{
  return index0+7005;
}

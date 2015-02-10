Double_t small_cell_LUT(Int_t val)
{
  Double_t r1=255000;
  Double_t r2=40000;
  Double_t rdac=50000;
  Double_t vref=1.228;
  Double_t vscale=200;
  Double_t diodes=0.001;
  Double_t trdac = rdac/256*(256-val);
  Double_t reg = (r1+r2+trdac) / (r2+trdac)*vref;
  printf("%f\n",(reg-diodes)*vscale);
  return (reg-diodes)*vscale;
};

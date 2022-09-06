#include <cstdlib>
#include "ap_int.h"
#include <vector>
#include "algo_top.h"

//    eta:       0  1  2  3  4   5  6  7  8   9 10 11 12  13 14 15 16  17 18 19 20  21 22 23 24  25 26 27 28  29 30 31 32 33
// phi
// 0       
// 1       
// 2
// 3             ____________________________________________________________________________________________________________
// 4             |                                                    |                                                     |
// 5             |                                                    |                                                     |
// 6             |                                                    |                                                     |
// 7             |                                                    |                                                     |
// 8             |                                                    |                                                     |
// 9             |                   -ve eta                          |                     +ve eta                         | 
// 10            |                                                    |                                                     |
// 11            |                                                    |                                                     |
// 12            |                                                    |                                                     |
// 13            |                                                    |                                                     |
// 14            |                                                    |                                                     |
// 15            |__________________________________________________________________________________________________________|
//
// create 3 jets in eta+ and 3 jets in eta-

GCTint_t bestOf2(const GCTint_t& t0, const GCTint_t& t1) {
  GCTint_t x;
  x = (t0.et > t1.et) ? t0 : t1;
  return x;
}

GCTint_t getPeakOfStrip(const etaStrip_t& etaStrip){
#pragma HLS ARRAY_PARTITION variable=etaStrip  complete dim=0
#pragma HLS latency min=4

  GCTint_t best01 = bestOf2(etaStrip.t[0],etaStrip.t[1]);
  GCTint_t best23 = bestOf2(etaStrip.t[2],etaStrip.t[3]);
  GCTint_t best45 = bestOf2(etaStrip.t[4],etaStrip.t[5]);
  GCTint_t best67 = bestOf2(etaStrip.t[6],etaStrip.t[7]);
  GCTint_t best89 = bestOf2(etaStrip.t[8],etaStrip.t[9]);
  GCTint_t best1011 = bestOf2(etaStrip.t[10],etaStrip.t[11]);
  GCTint_t best0123 = bestOf2(best01, best23);
  GCTint_t best4567 = bestOf2(best45, best67);
  GCTint_t best891011 = bestOf2(best89, best1011);
  GCTint_t best01234567 = bestOf2(best0123, best4567);
  GCTint_t bestAll = bestOf2(best01234567, best891011);
  
  return bestAll;
}

GCTint_t getPeakBin(const etaStripPeak_t& etaStripPeak){
#pragma HLS ARRAY_PARTITION variable=etaStripPeak  complete dim=0
#pragma HLS latency min=2

  GCTint_t best01 = bestOf2(etaStripPeak.p[0], etaStripPeak.p[1]);
  GCTint_t best23 = bestOf2(etaStripPeak.p[2], etaStripPeak.p[3]);
  GCTint_t best45 = bestOf2(etaStripPeak.p[4], etaStripPeak.p[5]);
  GCTint_t best67 = bestOf2(etaStripPeak.p[6], etaStripPeak.p[7]);
  GCTint_t best89 = bestOf2(etaStripPeak.p[8], etaStripPeak.p[9]);
  GCTint_t best1011 = bestOf2(etaStripPeak.p[10], etaStripPeak.p[11]);
  GCTint_t best1213 = bestOf2(etaStripPeak.p[12], etaStripPeak.p[13]);
  GCTint_t best1415 = bestOf2(etaStripPeak.p[14], etaStripPeak.p[15]);
  GCTint_t best141516 = bestOf2(best1415, etaStripPeak.p[16]);
  GCTint_t best0123 = bestOf2(best01, best23);
  GCTint_t best4567 = bestOf2(best45, best67);
  GCTint_t best891011 = bestOf2(best89, best1011);
  GCTint_t best8910111213 = bestOf2(best891011, best1213);
  GCTint_t best01234567 = bestOf2(best0123, best4567);
  GCTint_t best012345678910111213 = bestOf2(best01234567, best8910111213);
  GCTint_t bestAll = bestOf2(best012345678910111213, best141516);

  return bestAll;
}

GCTint_t getPeakPosition(const region_t& region){
#pragma HLS ARRAY_PARTITION variable=region complete dim=0
#pragma HLS latency min=7

  etaStripPeak_t etaPeak;
#pragma HLS ARRAY_PARTITION variable=etaPeak  complete dim=0

  etaPeak.p[0] = getPeakOfStrip(region.s0);
  etaPeak.p[1] = getPeakOfStrip(region.s1);
  etaPeak.p[2] = getPeakOfStrip(region.s2);
  etaPeak.p[3] = getPeakOfStrip(region.s3);
  etaPeak.p[4] = getPeakOfStrip(region.s4);
  etaPeak.p[5] = getPeakOfStrip(region.s5);
  etaPeak.p[6] = getPeakOfStrip(region.s6);
  etaPeak.p[7] = getPeakOfStrip(region.s7);
  etaPeak.p[8] = getPeakOfStrip(region.s8);
  etaPeak.p[9] = getPeakOfStrip(region.s9);
  etaPeak.p[10] = getPeakOfStrip(region.s10);
  etaPeak.p[11] = getPeakOfStrip(region.s11);
  etaPeak.p[12] = getPeakOfStrip(region.s12);
  etaPeak.p[13] = getPeakOfStrip(region.s13);
  etaPeak.p[14] = getPeakOfStrip(region.s14);
  etaPeak.p[15] = getPeakOfStrip(region.s15);
  etaPeak.p[16] = getPeakOfStrip(region.s16);
  GCTint_t max = getPeakBin(etaPeak);

  return max;
}

region_t initStructure_neg(ap_uint<12> temp[N_GCTETA][N_GCTPHI]){
#pragma HLS ARRAY_PARTITION variable=temp  complete dim=0
#pragma HLS latency min=4

  region_t r;
#pragma HLS ARRAY_PARTITION variable=r complete dim=0

  for(loop i=0; i<12; i++){
#pragma HLS unroll
    r.s0.t[i].et = temp[0][4+i];
    r.s0.t[i].eta = 0;
    r.s0.t[i].phi = 4+i;
    r.s1.t[i].et = temp[1][4+i];
    r.s1.t[i].eta = 1;
    r.s1.t[i].phi = 4+i;
    r.s2.t[i].et = temp[2][4+i];
    r.s2.t[i].eta = 2;
    r.s2.t[i].phi = 4+i;
    r.s3.t[i].et = temp[3][4+i];
    r.s3.t[i].eta = 3;
    r.s3.t[i].phi = 4+i;
    r.s4.t[i].et = temp[4][4+i];
    r.s4.t[i].eta = 4;
    r.s4.t[i].phi = 4+i;
    r.s5.t[i].et = temp[5][4+i];
    r.s5.t[i].eta = 5;
    r.s5.t[i].phi = 4+i;
    r.s6.t[i].et = temp[6][4+i];
    r.s6.t[i].eta = 6;
    r.s6.t[i].phi = 4+i;
    r.s7.t[i].et = temp[7][4+i];
    r.s7.t[i].eta = 7;
    r.s7.t[i].phi = 4+i;
    r.s8.t[i].et = temp[8][4+i];
    r.s8.t[i].eta = 8;
    r.s8.t[i].phi = 4+i;
    r.s9.t[i].et = temp[9][4+i];
    r.s9.t[i].eta = 9;
    r.s9.t[i].phi = 4+i;
    r.s10.t[i].et = temp[10][4+i];
    r.s10.t[i].eta = 10;
    r.s10.t[i].phi = 4+i;
    r.s11.t[i].et = temp[11][4+i];
    r.s11.t[i].eta = 11;
    r.s11.t[i].phi = 4+i;
    r.s12.t[i].et = temp[12][4+i];
    r.s12.t[i].eta = 12;
    r.s12.t[i].phi = 4+i;
    r.s13.t[i].et = temp[13][4+i];
    r.s13.t[i].eta = 13;
    r.s13.t[i].phi = 4+i;
    r.s14.t[i].et = temp[14][4+i];
    r.s14.t[i].eta = 14;
    r.s14.t[i].phi = 4+i;
    r.s15.t[i].et = temp[15][4+i];
    r.s15.t[i].eta = 15;
    r.s15.t[i].phi = 4+i;
    r.s16.t[i].et = temp[16][4+i];
    r.s16.t[i].eta = 16;
    r.s16.t[i].phi = 4+i;
  }
  return r;
}

region_t initStructure_pos(ap_uint<12> temp[N_GCTETA][N_GCTPHI]){
#pragma HLS ARRAY_PARTITION variable=temp  complete dim=0
#pragma HLS latency min=4

  region_t r;
#pragma HLS ARRAY_PARTITION variable=r complete dim=0

  for(loop i=0; i<12; i++){
#pragma HLS unroll
    r.s0.t[i].et = temp[17][4+i];
    r.s0.t[i].eta = 17;
    r.s0.t[i].phi = 4+i;
    r.s1.t[i].et = temp[18][4+i];
    r.s1.t[i].eta = 18;
    r.s1.t[i].phi = 4+i;
    r.s2.t[i].et = temp[19][4+i];
    r.s2.t[i].eta = 19;
    r.s2.t[i].phi = 4+i;
    r.s3.t[i].et = temp[20][4+i];
    r.s3.t[i].eta = 20;
    r.s3.t[i].phi = 4+i;
    r.s4.t[i].et = temp[21][4+i];
    r.s4.t[i].eta = 21;
    r.s4.t[i].phi = 4+i;
    r.s5.t[i].et = temp[22][4+i];
    r.s5.t[i].eta = 22;
    r.s5.t[i].phi = 4+i;
    r.s6.t[i].et = temp[23][4+i];
    r.s6.t[i].eta = 23;
    r.s6.t[i].phi = 4+i;
    r.s7.t[i].et = temp[24][4+i];
    r.s7.t[i].eta = 24;
    r.s7.t[i].phi = 4+i;
    r.s8.t[i].et = temp[25][4+i];
    r.s8.t[i].eta = 25;
    r.s8.t[i].phi = 4+i;
    r.s9.t[i].et = temp[26][4+i];
    r.s9.t[i].eta = 26;
    r.s9.t[i].phi = 4+i;
    r.s10.t[i].et = temp[27][4+i];
    r.s10.t[i].eta = 27;
    r.s10.t[i].phi = 4+i;
    r.s11.t[i].et = temp[28][4+i];
    r.s11.t[i].eta = 28;
    r.s11.t[i].phi = 4+i;
    r.s12.t[i].et = temp[29][4+i];
    r.s12.t[i].eta = 29;
    r.s12.t[i].phi = 4+i;
    r.s13.t[i].et = temp[30][4+i];
    r.s13.t[i].eta = 30;
    r.s13.t[i].phi = 4+i;
    r.s14.t[i].et = temp[31][4+i];
    r.s14.t[i].eta = 31;
    r.s14.t[i].phi = 4+i;
    r.s15.t[i].et = temp[32][4+i];
    r.s15.t[i].eta = 32;
    r.s15.t[i].phi = 4+i;
    r.s16.t[i].et = temp[33][4+i];
    r.s16.t[i].eta = 33;
    r.s16.t[i].phi = 4+i;
  }
  return r;
}

ap_uint<12> getEt(ap_uint<12> temp[N_GCTETA][N_GCTPHI], ap_uint<7> eta, ap_uint<7> phi){
#pragma HLS ARRAY_PARTITION variable=temp complete dim=0
#pragma HLS latency min=5

ap_uint<12> tempX[N_GCTETA+6][N_GCTPHI+6] ;
#pragma HLS ARRAY_PARTITION variable=tempX complete dim=0

  for(loop i=0; i<N_GCTETA+6; i++){
//#pragma HLS unroll
    for(loop j=0; j<N_GCTPHI+6; j++){
#pragma HLS unroll
      tempX[i][j] = 0 ;
   }}

  for(loop i=0; i<N_GCTETA; i++){
//#pragma HLS unroll
    for(loop j=0; j<N_GCTPHI; j++){
#pragma HLS unroll
      tempX[i+3][j+3] = temp[i][j] ;
   }}

  ap_uint<12> et1, et_sumEta[7] = {0};
#pragma HLS ARRAY_PARTITION variable=et_sumEta complete dim=0

  for(loop i=0; i<N_GCTETA; i++){
//#pragma HLS unroll
    for(loop j=0; j<N_GCTPHI; j++){
#pragma HLS unroll
    if (i==eta && j==phi){
     for(loop k=0; k<7; k++){
#pragma HLS unroll
     et1 = tempX[i+k][j] + tempX[i+k][j+1] + tempX[i+k][j+2] + tempX[i+k][j+3] ;
     et_sumEta[k] = et1 + tempX[i+k][j+4] + tempX[i+k][j+5] + tempX[i+k][j+6] ;
      }
     }
   }}

    et1 = et_sumEta[0] + et_sumEta[1] + et_sumEta[2] + et_sumEta[3] ;
    ap_uint<12> jet_et = et1 + et_sumEta[4] + et_sumEta[5] + et_sumEta[6]  ;

  return jet_et;
}

void RemoveTmp(ap_uint<12> temp[N_GCTETA][N_GCTPHI], ap_uint<7> eta, ap_uint<7> phi){
#pragma HLS ARRAY_PARTITION variable=temp complete dim=0
#pragma HLS latency min=4

 
  for(loop i=0; i<N_GCTETA; i++){
    if(i+3 >= eta && i <= eta+3) {
    for(loop j=0; j<N_GCTPHI; j++){
#pragma HLS unroll
      if(j+3 >= phi && j <= phi+3) {
        temp[i][j] = 0;
      }
    }}
  }
  return;
}

ap_uint<26> recoJet(ap_uint<12> temporary[N_GCTETA][N_GCTPHI], ap_uint<1> flag){ 
#pragma HLS ARRAY_PARTITION variable=temporary  complete dim=0
#pragma HLS latency min=23

  ap_uint<26> jetReturn ;

  region_t region;
#pragma HLS ARRAY_PARTITION variable=region  complete dim=0

  if(flag == 0) region = initStructure_neg(temporary);
  else region = initStructure_pos(temporary);

  GCTint_t regionMax = getPeakPosition(region);  

  ap_uint<12> jet_et = getEt(temporary, regionMax.eta, regionMax.phi);

  jetReturn.range(11, 0) = jet_et;
  jetReturn.range(18, 12) = regionMax.eta;
  jetReturn.range(25, 19) = regionMax.phi;

  RemoveTmp(temporary, regionMax.eta, regionMax.phi);


return jetReturn ;
}

GCTJet_t jet(const GCTintTowers_t& GCTintTowers) {
#pragma HLS ARRAY_PARTITION variable=GCTintTowers complete dim=0
#pragma HLS latency min=136

//#pragma HLS PIPELINE II=6

//  std::cout<<"inside jet.cpp"<<std::endl;

  ap_uint<26> jet_pos[3]; 
  ap_uint<26> jet_neg[3];

#pragma HLS ARRAY_PARTITION variable=jet_pos  complete dim=0
#pragma HLS ARRAY_PARTITION variable=jet_neg  complete dim=0

  for(loop i=0; i<3; i++){
#pragma HLS unroll
    jet_pos[i] = 0;
    jet_neg[i] = 0;
  }

  ap_uint<12> temporary[N_GCTETA][N_GCTPHI];
  ap_uint<12> temporary1[N_GCTETA][N_GCTPHI];
#pragma HLS ARRAY_PARTITION variable=temporary  complete dim=0
#pragma HLS ARRAY_PARTITION variable=temporary1  complete dim=0

  for(loop i=0; i<N_GCTETA; i++){
    for(loop j=0; j<N_GCTPHI; j++){
#pragma HLS unroll
      temporary[i][j] = GCTintTowers.GCTtower[i][j].et;
      temporary1[i][j] = GCTintTowers.GCTtower[i][j].et;
    }
  }

  jet_neg[0] = recoJet(temporary,0) ;
  jet_neg[1] = recoJet(temporary,0) ;
  jet_neg[2] = recoJet(temporary,0) ;

  jet_pos[0] = recoJet(temporary1,1) ;
  jet_pos[1] = recoJet(temporary1,1) ;
  jet_pos[2] = recoJet(temporary1,1) ;

  GCTJet_t GCTJets;
#pragma HLS ARRAY_PARTITION variable=GCTJets  complete dim=0

  for(loop i=0; i<3; i++){
#pragma HLS unroll
    GCTJets.et[i] = jet_pos[i].range(11, 0);
    GCTJets.eta[i] = jet_pos[i].range(18, 12);
    GCTJets.phi[i] = jet_pos[i].range(25, 19);
    GCTJets.et[i+3] = jet_neg[i].range(11, 0);
    GCTJets.eta[i+3] = jet_neg[i].range(18, 12);
    GCTJets.phi[i+3] = jet_neg[i].range(25, 19);
  }

//  std::cout<<"done making jets"<<std::endl;

  return GCTJets;
}


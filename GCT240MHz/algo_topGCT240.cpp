#include "algo_topGCT240.h"

GCTcard_t processInputLinks(ap_uint<384> link_in[N_INPUT_LINKS]){
#pragma HLS ARRAY_PARTITION variable=link_in complete dim=0
 
  GCTcard_t GCTcardIn ;
   
  for(loop i=0; i<N_RCTCARDS_PHI; i++){
#pragma HLS UNROLL
    for(loop j=0; j<N_RCTGCT_FIBERS; j++){
#pragma HLS UNROLL
      ap_uint<32> start = 0;
      loop index = N_RCTGCT_FIBERS*i+j;
      for(loop k=0; k<N_RCTTOWERS_FIBER; k++){
#pragma HLS UNROLL
        GCTcardIn.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTtowers[k].hoe = link_in[index].range(start+3, start) ;
        GCTcardIn.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTtowers[k].et = link_in[index].range(start+14, start+4) ;
        GCTcardIn.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTtowers[k].hoe = link_in[index+20].range(start+3, start) ;
        GCTcardIn.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTtowers[k].et = link_in[index+20].range(start+14, start+4) ;
        start += 15;
      }
      for(loop k=0; k<N_RCTCLUSTERS_FIBER; k++){
#pragma HLS UNROLL
        GCTcardIn.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et = link_in[index].range(start+11, start) ;
        GCTcardIn.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].towEta = link_in[index].range(start+16, start+12) ;
        GCTcardIn.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].towPhi = link_in[index].range(start+18, start+17);
        GCTcardIn.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].crEta = link_in[index].range(start+21, start+19);
        GCTcardIn.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].crPhi = link_in[index].range(start+24, start+22);
        GCTcardIn.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].satur = link_in[index].range(start+27, start+25);
        GCTcardIn.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et5x5 = link_in[index].range(start+42, start+28);
        GCTcardIn.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et2x5 = link_in[index].range(start+57, start+43);
        GCTcardIn.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].brems = link_in[index].range(start+59, start+58);
        GCTcardIn.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et = link_in[index+20].range(start+11, start) ;
        GCTcardIn.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].towEta = link_in[index+20].range(start+16, start+12) ;
        GCTcardIn.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].towPhi = link_in[index+20].range(start+18, start+17);
        GCTcardIn.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].crEta = link_in[index+20].range(start+21, start+19);
        GCTcardIn.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].crPhi = link_in[index+20].range(start+24, start+22);
        GCTcardIn.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].satur = link_in[index+20].range(start+27, start+25);
        GCTcardIn.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et5x5 = link_in[index+20].range(start+42, start+28);
        GCTcardIn.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et2x5 = link_in[index+20].range(start+57, start+43);
        GCTcardIn.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].brems = link_in[index+20].range(start+59, start+58);
        start += 60;
      }
    }
  }
  //std::cout<<"inside algo_top: "<<link_in[7].range(116, 105)<<"\t"<<GCTcardIn.RCTcardEtaPos[1].RCTtoGCTfiber[3].RCTtowers[7].et<<std::endl;
  //std::cout<<"inside algo_top: "<<link_in[14].range(86, 75)<<"\t"<<GCTcardIn.RCTcardEtaPos[3].RCTtoGCTfiber[2].RCTtowers[5].et<<std::endl;
  //
//  cout << " input " << GCTcardIn.RCTcardEtaPos[0].RCTtoGCTfiber[0].RCTclusters[0].et << endl ;
//  cout << " input " << GCTcardIn.RCTcardEtaPos[1].RCTtoGCTfiber[0].RCTclusters[0].et << endl ;
//  cout << " input " << GCTcardIn.RCTcardEtaPos[2].RCTtoGCTfiber[0].RCTclusters[0].et << endl ;

//  cout << " input " << GCTcardIn.RCTcardEtaNeg[1].RCTtoGCTfiber[0].RCTclusters[0].et << endl ;
//  cout << " input " << GCTcardIn.RCTcardEtaNeg[2].RCTtoGCTfiber[0].RCTclusters[0].et << endl ;
//  cout << " input " << GCTcardIn.RCTcardEtaNeg[2].RCTtoGCTfiber[1].RCTclusters[1].et << endl ;

  return GCTcardIn;
}

GCTcard_t getClustersCombined(const GCTcard_t& GCTcard){
#pragma HLS latency min=11
#pragma HLS ARRAY_PARTITION variable=GCTcard complete dim=0
//#pragma HLS PIPELINE II=6

  GCTcard_t GCTcombinedClusters ;
#pragma HLS ARRAY_PARTITION variable=GCTcombinedClusters complete dim=0
// first we initialize the output == input 
//
  for(int i=0; i<N_RCTCARDS_PHI; i++){
//#pragma HLS unroll 
    for(int j=0; j<N_RCTGCT_FIBERS; j++){
//#pragma HLS unroll 
      for(int k=0; k<N_RCTCLUSTERS_FIBER; k++){
#pragma HLS unroll 
        GCTcombinedClusters.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et  = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et  ;
        GCTcombinedClusters.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et  = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et  ;
      }
    }
  }

// we will store new et in the GCTcombinedClusters, 0'ing lower clusters after stiching, dont need to care about other variables they stay the 
// same as input for now at least
// we combine even phi boudaries positive eta, when combined the lowest et is set to 0

  for(int i=0; i<N_RCTCARDS_PHI-1; i=i+2){
//#pragma HLS unroll 
    for(int j=0; j<N_RCTGCT_FIBERS; j++){
//#pragma HLS unroll 
      for(int k=0; k<N_RCTCLUSTERS_FIBER; k++){
#pragma HLS unroll 
        ap_uint<15> eta1 = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].towEta*5+GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].crEta ;
        ap_uint<15> phi1 = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].crPhi ;
        if(GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].towPhi == 3 && phi1 == 4){
          for(int j1=0; j1<N_RCTGCT_FIBERS; j1++){
//#pragma HLS unroll 
            for(int k1=0; k1<N_RCTCLUSTERS_FIBER; k1++){
#pragma HLS unroll 
              ap_uint<15> eta2 = GCTcard.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].towEta*5+GCTcard.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].crEta ;
              ap_uint<15> phi2 = GCTcard.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].crPhi ;
              if( GCTcard.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].towPhi == 0 && phi2 == 0) {
                ap_uint<15> dEta ; dEta=(eta1 > eta2)?(eta1-eta2):(eta2-eta1) ;
                if(dEta < 2) {
                  ap_uint<12> one = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et ;
                  ap_uint<12> two = GCTcard.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].et ;
                  if(one > two){ 
                    GCTcombinedClusters.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et = one + two ;
                    GCTcombinedClusters.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].et = 0 ; 
                  }
                  else {
                    GCTcombinedClusters.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et = 0 ;
                    GCTcombinedClusters.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].et = one + two ; 
                  }
                }
              }
            }
          }
        }
      }
    }
  }

// now we combine odd phi boundaries positive eta

  for(int i=1; i<N_RCTCARDS_PHI-1; i=i+2){
//#pragma HLS unroll 
    for(int j=0; j<N_RCTGCT_FIBERS; j++){
//#pragma HLS unroll 
      for(int k=0; k<N_RCTCLUSTERS_FIBER; k++){
#pragma HLS unroll 
        ap_uint<15> eta1 = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].towEta*5+GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].crEta ;
        ap_uint<15> phi1 = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].crPhi ;
        if(GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].towPhi == 3 && phi1 == 4) {
          for(int j1=0; j1<N_RCTGCT_FIBERS; j1++){
//#pragma HLS unroll 
            for(int k1=0; k1<N_RCTCLUSTERS_FIBER; k1++){
#pragma HLS unroll 
              ap_uint<15> eta2 = GCTcard.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].towEta*5+GCTcard.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].crEta ;
              ap_uint<15> phi2 = GCTcard.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].crPhi ;
              if(GCTcard.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].towPhi == 0 && phi2 == 0) {
                ap_uint<15> dEta ; dEta=(eta1 > eta2)?(eta1-eta2):(eta2-eta1) ;
                if(dEta <2) {
                  ap_uint<12> one = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et ;
                  ap_uint<12> two = GCTcard.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].et ;
                  if(one > two){ 
                    GCTcombinedClusters.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et = one + two ;
                    GCTcombinedClusters.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].et = 0 ; 
                  }
                  else {
                    GCTcombinedClusters.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et = 0 ;
                    GCTcombinedClusters.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].et = one + two ; 
                  }
                }
              }
            }
          }
        }
      }
    }
  }

// repeat above steps for negative eta
// even phi boundaries

  for(int i=0; i<N_RCTCARDS_PHI-1; i=i+2){
//#pragma HLS unroll 
    for(int j=0; j<N_RCTGCT_FIBERS; j++){
//#pragma HLS unroll 
      for(int k=0; k<N_RCTCLUSTERS_FIBER; k++){
#pragma HLS unroll 
        ap_uint<15> eta1 = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].towEta*5+GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].crEta ;
        ap_uint<15> phi1 = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].crPhi ;
        if(GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].towPhi == 0 && phi1 == 0 ) {
          for(int j1=0; j1<N_RCTGCT_FIBERS; j1++){
//#pragma HLS unroll 
            for(int k1=0; k1<N_RCTCLUSTERS_FIBER; k1++){
#pragma HLS unroll 
              ap_uint<15> eta2 = GCTcard.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].towEta*5+GCTcard.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].crEta ;
              ap_uint<15> phi2 = GCTcard.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].crPhi ;
              if(GCTcard.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].towPhi == 3 && phi2 == 4 ) {
                ap_uint<15> dEta ; dEta=(eta1 > eta2)?(eta1-eta2):(eta2-eta1) ;
                if(dEta < 2) {
                  ap_uint<12> one = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et ;
                  ap_uint<12> two = GCTcard.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].et ;
                  if(one > two){ 
                    GCTcombinedClusters.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et = one + two ;
                    GCTcombinedClusters.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].et = 0 ; 
                  }
                  else {
                    GCTcombinedClusters.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et = 0 ;
                    GCTcombinedClusters.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].et = one + two ;
                  }
                }
              }
            }
          }
        }
      }
    }
  }

// now we combine odd boundaries 

  for(int i=1; i<N_RCTCARDS_PHI-1; i=i+2){
//#pragma HLS unroll 
    for(int j=0; j<N_RCTGCT_FIBERS; j++){
//#pragma HLS unroll 
      for(int k=0; k<N_RCTCLUSTERS_FIBER; k++){
#pragma HLS unroll 
        ap_uint<15> eta1 = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].towEta*5+GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].crEta ;
        ap_uint<15> phi1 = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].crPhi ;
        if(GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].towPhi == 0 && phi1 == 0 ) {
          for(int j1=0; j1<N_RCTGCT_FIBERS; j1++){
//#pragma HLS unroll 
            for(int k1=0; k1<N_RCTCLUSTERS_FIBER; k1++){
#pragma HLS unroll 
              ap_uint<15> eta2 = GCTcard.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].towEta*5+GCTcard.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].crEta ;
              ap_uint<15> phi2 = GCTcard.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].crPhi ;
              if(GCTcard.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].towPhi == 3 && phi2 == 4 ) {
                ap_uint<15> dEta ; dEta=(eta1 > eta2)?(eta1-eta2):(eta2-eta1) ;
                if(dEta < 2) {
                  ap_uint<12> one = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et ;
                  ap_uint<12> two = GCTcard.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].et ;
                  if(one > two){ 
                    GCTcombinedClusters.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et = one + two ;
                    GCTcombinedClusters.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].et = 0 ; 
                  }
                  else {
                    GCTcombinedClusters.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et = 0 ;
                    GCTcombinedClusters.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].et = one + two ; 
                  }
                }
              }
            }
          }
        }
      }
    }
  }

//

// we need to store what we did before we start phi stiching
//
  GCTcard_t GCTout ;
#pragma HLS ARRAY_PARTITION variable=GCTout complete dim=0

  for(int i=0; i<N_RCTCARDS_PHI; i++){
//#pragma HLS unroll 
    for(int j=0; j<N_RCTGCT_FIBERS; j++){
//#pragma HLS unroll 
      for(int k=0; k<N_RCTCLUSTERS_FIBER; k++){
#pragma HLS unroll 
        GCTout.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et  = GCTcombinedClusters.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et  ;
        GCTout.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et  = GCTcombinedClusters.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et  ;
      }
    }
  }


// now we combine eta boundaries, just positive and negative eta 

  for(int i=0; i<N_RCTCARDS_PHI; i++){
//#pragma HLS unroll 
    for(int j=0; j<N_RCTGCT_FIBERS; j++){
//#pragma HLS unroll 
      for(int k=0; k<N_RCTCLUSTERS_FIBER; k++){
#pragma HLS unroll 
        ap_uint<15> phi1 = (i*4+GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].towPhi)*5+GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].crPhi ;
        ap_uint<15> eta1 = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].crEta ;
        if(GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].towEta == 0 && eta1 == 0 ) {
          for(int j1=0; j1<N_RCTGCT_FIBERS; j1++){
//#pragma HLS unroll 
            for(int k1=0; k1<N_RCTCLUSTERS_FIBER; k1++){
#pragma HLS unroll 
              ap_uint<15> phi2 = (i*4+(3-GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j1].RCTclusters[k1].towPhi))*5+(4-GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j1].RCTclusters[k1].crPhi) ;
              ap_uint<15> eta2 = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j1].RCTclusters[k1].crEta ;
              if(GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j1].RCTclusters[k1].towEta == 0 && eta2 == 0 ) {
                ap_uint<15> dPhi ; dPhi=(phi1 > phi2)?(phi1-phi2):(phi2-phi1) ;
                if(dPhi < 2) {
                  ap_uint<12> one = GCTcombinedClusters.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et ;
                  ap_uint<12> two = GCTcombinedClusters.RCTcardEtaNeg[i].RCTtoGCTfiber[j1].RCTclusters[k1].et ;
                  if(one > two){ 
                    GCTout.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et = one + two ;
                    GCTout.RCTcardEtaNeg[i].RCTtoGCTfiber[j1].RCTclusters[k1].et = 0 ; 
                  }
                  else {
                    GCTout.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et = 0 ;
                    GCTout.RCTcardEtaNeg[i].RCTtoGCTfiber[j1].RCTclusters[k1].et = one + two ; 
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  return GCTout;
}


GCTinternal_t getClustersTowers(const GCTcard_t& GCTcard){
#pragma HLS latency min=11
#pragma HLS ARRAY_PARTITION variable=GCTcard complete dim=0

  GCTcard_t GCTcombinedClusters ;
#pragma HLS ARRAY_PARTITION variable=GCTcombinedClusters complete dim=0

  GCTinternal_t GCTout ;
#pragma HLS ARRAY_PARTITION variable=GCTout complete dim=0

// here we will stitch the clusters in phi and eta

  GCTcombinedClusters = getClustersCombined(GCTcard) ;

// create internal structure of GCT card
// we start from RCT card 0 - it is overlap with other GCT card and fill structure that we will use to send data to Correlator
// we only need to care about clusters et in combinrdClusters, since the rest remains unchanged wrt input, the cluster that we set to 0
// remain in the data at the same place , it will just get 0 et now
// we need to code Positive and Negative Eta differently !  For negative Eta link 0 for each RCT
// region becomes 3 in GCT output, the RCT card is rotated around 0:0 point of the card 
// First 20 fibers - positive Eta , second 20 - negative. Eta coded 0...16 and towEtaNeg = 0 or 1 for clusters ; 
// Phi is coded 0...19 , in case if whole card 0...33 and subdevision 1/5 in crPhi and crEta 0...4 for 
// position in tower
//
// towers are put in link starting from eta=0, the link number defines Eta negative or positive and Phi position of tower.
//
//
  for(int i=0; i<N_RCTCARDS_PHI; i++){
//#pragma HLS unroll 
    for(int j=0; j<N_RCTGCT_FIBERS; j++){
//#pragma HLS unroll 
      for(int k=0; k<N_RCTCLUSTERS_FIBER; k++){
#pragma HLS unroll 
        GCTout.GCTCorrfiber[i*4+j].GCTclusters[k].et  = GCTcombinedClusters.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et;
        GCTout.GCTCorrfiber[i*4+j].GCTclusters[k].towEtaNeg  = 0;
        GCTout.GCTCorrfiber[i*4+j].GCTclusters[k].towEta  = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].towEta;
        GCTout.GCTCorrfiber[i*4+j].GCTclusters[k].towPhi  = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].towPhi+i*4;
        GCTout.GCTCorrfiber[i*4+j].GCTclusters[k].crEta  = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].crEta;
        GCTout.GCTCorrfiber[i*4+j].GCTclusters[k].crPhi  = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].crPhi;
        GCTout.GCTCorrfiber[i*4+j].GCTclusters[k].satur  = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].satur;
        GCTout.GCTCorrfiber[i*4+j].GCTclusters[k].brems = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].brems;
        
        GCTout.GCTCorrfiber[i*4+(3-j)+N_GCTPOSITIVE_FIBERS].GCTclusters[k].et  = GCTcombinedClusters.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et;
        GCTout.GCTCorrfiber[i*4+(3-j)+N_GCTPOSITIVE_FIBERS].GCTclusters[k].towEtaNeg  = 1;
        GCTout.GCTCorrfiber[i*4+(3-j)+N_GCTPOSITIVE_FIBERS].GCTclusters[k].towEta  = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].towEta;
        GCTout.GCTCorrfiber[i*4+(3-j)+N_GCTPOSITIVE_FIBERS].GCTclusters[k].towPhi  = (3-GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].towPhi)+i*4;
        GCTout.GCTCorrfiber[i*4+(3-j)+N_GCTPOSITIVE_FIBERS].GCTclusters[k].crEta  = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].crEta;
        GCTout.GCTCorrfiber[i*4+(3-j)+N_GCTPOSITIVE_FIBERS].GCTclusters[k].crPhi  = (4-GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].crPhi);
        GCTout.GCTCorrfiber[i*4+(3-j)+N_GCTPOSITIVE_FIBERS].GCTclusters[k].satur  = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].satur;
        GCTout.GCTCorrfiber[i*4+(3-j)+N_GCTPOSITIVE_FIBERS].GCTclusters[k].brems  = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].brems;
      }
      for(int k=0; k<N_RCTTOWERS_FIBER; k++){
#pragma HLS unroll 
        GCTout.GCTCorrfiber[i*4+j].GCTtowers[k].et  = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTtowers[k].et  ;
        GCTout.GCTCorrfiber[i*4+j].GCTtowers[k].hoe  = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTtowers[k].hoe  ;
        GCTout.GCTCorrfiber[i*4+(3-j)+N_GCTPOSITIVE_FIBERS].GCTtowers[k].et  = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTtowers[k].et  ;
        GCTout.GCTCorrfiber[i*4+(3-j)+N_GCTPOSITIVE_FIBERS].GCTtowers[k].hoe  = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTtowers[k].hoe  ;
      }
    }
  }
    
  return GCTout ;
}

GCTintTowers_t  getFullTowers(const GCTinternal_t& GCTinternal) {
#pragma HLS latency min=5
#pragma HLS ARRAY_PARTITION variable=GCTinternal complete dim=0

  GCTintTowers_t GCTintTowers;
#pragma HLS ARRAY_PARTITION variable=GCTintTowers complete dim=0

//-- positive eta
//

  for(int i=0; i<N_GCTPOSITIVE_FIBERS; i=i+4){
//#pragma HLS unroll 
    for(int i1=0; i1<4; i1++){
//#pragma HLS unroll 
      for(int k=0; k<N_GCTTOWERS_FIBER; k++){
#pragma HLS unroll 
        ap_uint<15> phi = i+i1 ; 
        ap_uint<15> eta = N_GCTETA/2 + k ; 
        GCTintTowers.GCTtower[eta][phi].et  = GCTinternal.GCTCorrfiber[phi].GCTtowers[k].et ;
    	for(int ic1=0; ic1<4; ic1++){
//#pragma HLS unroll 
          for(int jc=0; jc<N_GCTCLUSTERS_FIBER; jc++){
#pragma HLS unroll 
            ap_uint<15> eta1 = N_GCTETA/2 + GCTinternal.GCTCorrfiber[i+ic1].GCTclusters[jc].towEta ; 
            ap_uint<15> phi1 = GCTinternal.GCTCorrfiber[i+ic1].GCTclusters[jc].towPhi ; 
            if( eta == eta1 && phi == phi1) GCTintTowers.GCTtower[eta][phi].et  = GCTintTowers.GCTtower[eta][phi].et + GCTinternal.GCTCorrfiber[i+ic1].GCTclusters[jc].et ;
          }
        }
      }
    }
  }

//-- negative eta
//

  for(int i=N_GCTPOSITIVE_FIBERS; i<N_GCTINTERNAL_FIBERS; i=i+4){
//#pragma HLS unroll 
    for(int i1=0; i1<4; i1++){
//#pragma HLS unroll
      for(int k=0; k<N_GCTTOWERS_FIBER; k++){
#pragma HLS unroll 
        ap_uint<15> eta = N_GCTETA/2 - k - 1 ; 
        ap_uint<15> phi = i+i1-N_GCTPOSITIVE_FIBERS ; 
        GCTintTowers.GCTtower[eta][phi].et  = GCTinternal.GCTCorrfiber[i+i1].GCTtowers[k].et ;
        for(int ic1=0; ic1<4; ic1++){
//#pragma HLS unroll 
          for(int jc=0; jc<N_GCTCLUSTERS_FIBER; jc++){
#pragma HLS unroll 
            ap_uint<15> eta1 = N_GCTETA/2 - 1 - GCTinternal.GCTCorrfiber[i+ic1].GCTclusters[jc].towEta ;
            ap_uint<15> phi1 = GCTinternal.GCTCorrfiber[i+ic1].GCTclusters[jc].towPhi ;
            if( eta == eta1 && phi == phi1) GCTintTowers.GCTtower[eta][phi].et  = GCTintTowers.GCTtower[eta][phi].et + GCTinternal.GCTCorrfiber[i+ic1].GCTclusters[jc].et ;
          }
        }
      }
    }
  }

  return GCTintTowers ;

//end
}

//void algo_top(const GCTcard_t& GCTcard, ap_uint<15> cluster[10]){
//void algo_top(const GCTcard_t& GCTcard, GCTtoCorr_t& GCTtoCorr){
void algo_topGCT240(ap_uint<384> link_in[N_INPUT_LINKS], ap_uint<384> link_out[N_OUTPUT_LINKS]){
#pragma HLS ARRAY_PARTITION variable=link_in complete dim=0
#pragma HLS ARRAY_PARTITION variable=link_out complete dim=0
#pragma HLS PIPELINE II=6
#pragma HLS INTERFACE ap_ctrl_hs port=return
#pragma HLS latency min=120

  GCTcard_t GCTcard ;
  GCTtoCorr_t GCTtoCorr ;

#pragma HLS ARRAY_PARTITION variable=GCTcard complete dim=0
#pragma HLS ARRAY_PARTITION variable=GCTtoCorr complete dim=0

  GCTcard = processInputLinks(link_in);

  GCTinternal_t GCTinternal ;
#pragma HLS ARRAY_PARTITION variable=GCTinternal complete dim=0

// first we fill the GCT area with proper et and eta/phi; the eta is 0....16 and towEtaNeg = 0 or 1
// Phi 0....15 since this is half GCT card and 0...3 is overlap currently on one side, crEta/Phi 0...4
// new: need to have overlap on both Phi 0...19  0...3 16...19 overlap

  GCTinternal = getClustersTowers(GCTcard) ;


  GCTintTowers_t GCTintTowers;
#pragma HLS ARRAY_PARTITION variable=GCTintTowers complete dim=0

// here we combine towers and clusters to get full towers, and move to internal GCT card coordinate 0...33 in eta and 0...15 in phi,
// should change to 0...31 for the whole card

  GCTintTowers = getFullTowers(GCTinternal) ;

//ok now we have towers combined with clusters, now need to recalculate positions of all clusters in GCT coordinates

// OUTPUT TO CORRELATOR !!!!
// remove overlap region, we send out 24 fibers: 12 pos/12 neg
// all phi now decreases by 4
// this we send to Correlator

  for(int i=4; i<N_GCTPOSITIVE_FIBERS-4; i++){
//#pragma HLS unroll 
    for(int k=0; k<N_GCTCLUSTERS_FIBER; k++){
#pragma HLS unroll 
      GCTtoCorr.GCTCorrfiber[i-4].GCTclusters[k].et  = GCTinternal.GCTCorrfiber[i].GCTclusters[k].et   ;
      GCTtoCorr.GCTCorrfiber[i-4].GCTclusters[k].towEtaNeg  = GCTinternal.GCTCorrfiber[i].GCTclusters[k].towEtaNeg  ;
      GCTtoCorr.GCTCorrfiber[i-4].GCTclusters[k].towEta  =  N_GCTETA/2 + GCTinternal.GCTCorrfiber[i].GCTclusters[k].towEta ;
      GCTtoCorr.GCTCorrfiber[i-4].GCTclusters[k].towPhi  =  GCTinternal.GCTCorrfiber[i].GCTclusters[k].towPhi-4 ;
      GCTtoCorr.GCTCorrfiber[i-4].GCTclusters[k].crEta  =  GCTinternal.GCTCorrfiber[i].GCTclusters[k].crEta ;
      GCTtoCorr.GCTCorrfiber[i-4].GCTclusters[k].crPhi  =  GCTinternal.GCTCorrfiber[i].GCTclusters[k].crPhi ;
      GCTtoCorr.GCTCorrfiber[i-4].GCTclusters[k].satur  =  GCTinternal.GCTCorrfiber[i].GCTclusters[k].satur ;
      GCTtoCorr.GCTCorrfiber[i-4].GCTclusters[k].hoe  =   0 ;
      GCTtoCorr.GCTCorrfiber[i-4].GCTclusters[k].iso  =   0 ;
      GCTtoCorr.GCTCorrfiber[i-4].GCTclusters[k].shape  =  0 ;
      GCTtoCorr.GCTCorrfiber[i-4].GCTclusters[k].brems  =  GCTinternal.GCTCorrfiber[i].GCTclusters[k].brems ;
    }
    for(int k=0; k<N_GCTTOWERS_FIBER; k++){
#pragma HLS unroll 
      GCTtoCorr.GCTCorrfiber[i-4].GCTtowers[k].et  = GCTinternal.GCTCorrfiber[i].GCTtowers[k].et ;
      GCTtoCorr.GCTCorrfiber[i-4].GCTtowers[k].hoe  = GCTinternal.GCTCorrfiber[i].GCTtowers[k].hoe ;
    }
  }


  for(int i=N_GCTPOSITIVE_FIBERS+4; i<N_GCTINTERNAL_FIBERS-4; i++){
//#pragma HLS unroll 
    for(int k=0; k<N_GCTCLUSTERS_FIBER; k++){
#pragma HLS unroll 
      GCTtoCorr.GCTCorrfiber[i-12].GCTclusters[k].et  = GCTinternal.GCTCorrfiber[i].GCTclusters[k].et   ;
      GCTtoCorr.GCTCorrfiber[i-12].GCTclusters[k].towEtaNeg  = GCTinternal.GCTCorrfiber[i].GCTclusters[k].towEtaNeg  ;
      GCTtoCorr.GCTCorrfiber[i-12].GCTclusters[k].towEta  =  N_GCTETA/2 - GCTinternal.GCTCorrfiber[i].GCTclusters[k].towEta - 1 ;
      GCTtoCorr.GCTCorrfiber[i-12].GCTclusters[k].towPhi  =  GCTinternal.GCTCorrfiber[i].GCTclusters[k].towPhi-4 ;
      GCTtoCorr.GCTCorrfiber[i-12].GCTclusters[k].crEta  =  GCTinternal.GCTCorrfiber[i].GCTclusters[k].crEta ;
      GCTtoCorr.GCTCorrfiber[i-12].GCTclusters[k].crPhi  =  GCTinternal.GCTCorrfiber[i].GCTclusters[k].crPhi ;
      GCTtoCorr.GCTCorrfiber[i-12].GCTclusters[k].satur  =  GCTinternal.GCTCorrfiber[i].GCTclusters[k].satur ;
      GCTtoCorr.GCTCorrfiber[i-12].GCTclusters[k].hoe  =  0  ;
      GCTtoCorr.GCTCorrfiber[i-12].GCTclusters[k].iso  =  0  ;
      GCTtoCorr.GCTCorrfiber[i-12].GCTclusters[k].shape  =  0  ;
      GCTtoCorr.GCTCorrfiber[i-12].GCTclusters[k].brems  =  GCTinternal.GCTCorrfiber[i].GCTclusters[k].brems ;
    }
    for(int k=0; k<N_GCTTOWERS_FIBER; k++){
#pragma HLS unroll 
      GCTtoCorr.GCTCorrfiber[i-12].GCTtowers[k].et  = GCTinternal.GCTCorrfiber[i].GCTtowers[k].et ;
      GCTtoCorr.GCTCorrfiber[i-12].GCTtowers[k].hoe  = GCTinternal.GCTCorrfiber[i].GCTtowers[k].hoe ;
    }
  }

// this is for testing jet algo
/*
 
  GCTJet_t jets;
#pragma HLS ARRAY_PARTITION variable=jets  complete dim=0
  jets = jet(GCTintTowers);


  link_out[0] = 0;
  link_out[1] = 0;
  ap_uint<32> start = 0;

  for(loop i=0; i<3; i++){
#pragma HLS UNROLL
    link_out[0].range(start+11, start) = jets.et[i];
    link_out[0].range(start+18, start+12) = jets.eta[i];
    link_out[0].range(start+25, start+19) = jets.phi[i];

    link_out[1].range(start+11, start) = jets.et[i+3];
    link_out[1].range(start+18, start+12) = jets.eta[i+3];
    link_out[1].range(start+25, start+19) = jets.phi[i+3];

    link_out[0].range(start+11, start) = GCTintTowers.GCTtower[i][5].et;
    link_out[0].range(start+18, start+12) = GCTinternal.GCTCorrfiber[0].GCTclusters[i].towEta;
    link_out[0].range(start+25, start+19) = GCTinternal.GCTCorrfiber[0].GCTclusters[i].towPhi - 4;
//
    link_out[1].range(start+11, start) = GCTintTowers.GCTtower[i][6].et;
    link_out[1].range(start+18, start+12) = GCTinternal.GCTCorrfiber[0].GCTclusters[i+1].towEta;
    link_out[1].range(start+25, start+19) = GCTinternal.GCTCorrfiber[0].GCTclusters[i+1].towPhi - 4;

    start += 64;
  }
*/

        /*--------------------------------- link 0, ... , 24  ------------------------------------*/

//         cout << " here " << endl ;

    for(loop i=0; i<N_GCTCORR_FIBERS; i++){
    #pragma HLS unroll 
        link_out[i] = 0;
        for(loop k=0; k<N_GCTTOWERS_FIBER; k++){
        #pragma HLS unroll 
          ap_uint<32> start = k*15 ;
          ap_uint<32> end = k*15 + 14 ;
          link_out[i].range(end,start) = GCTtoCorr.GCTCorrfiber[i].GCTtowers[k].hoe | ((ap_uint<15>) GCTtoCorr.GCTCorrfiber[i].GCTtowers[k].et << 4) ;
//         cout << " " << GCTtoCorr.GCTCorrfiber[i].GCTtowers[k].et ;
         }
//        cout << " \ "  ;

        for(loop k=0; k<N_GCTCLUSTERS_FIBER; k++){
        #pragma HLS UNROLL
            ap_uint<32> start = 255 + 60*k;
            ap_uint<32> end =  314 + 60*k;
            link_out[i].range(end, start) = GCTtoCorr.GCTCorrfiber[i].GCTclusters[k].et | ((ap_uint<60>) GCTtoCorr.GCTCorrfiber[i].GCTclusters[k].towEta << 12) | ((ap_uint<60>) GCTtoCorr.GCTCorrfiber[i].GCTclusters[k].towPhi << 18) | ((ap_uint<60>) GCTtoCorr.GCTCorrfiber[i].GCTclusters[k].crEta << 23) | ((ap_uint<60>) GCTtoCorr.GCTCorrfiber[i].GCTclusters[k].crPhi << 26) | ((ap_uint<60>) GCTtoCorr.GCTCorrfiber[i].GCTclusters[k].satur << 29) | ((ap_uint<60>) GCTtoCorr.GCTCorrfiber[i].GCTclusters[k].hoe << 32) | ((ap_uint<60>) GCTtoCorr.GCTCorrfiber[i].GCTclusters[k].iso << 35) | ((ap_uint<60>) GCTtoCorr.GCTCorrfiber[i].GCTclusters[k].shape << 38) | ((ap_uint<60>) GCTtoCorr.GCTCorrfiber[i].GCTclusters[k].brems << 41) ;
//        cout << " " << GCTtoCorr.GCTCorrfiber[i].GCTclusters[k].et ;
          }
//        cout << "  " << endl ;
       }
}

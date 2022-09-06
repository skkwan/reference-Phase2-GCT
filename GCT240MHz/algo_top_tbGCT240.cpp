#include "algo_topGCT240.h"
#include <cstdlib>

int main(){

  GCTcard_t GCTcard ; 


  ap_uint<15> cluster[10];

  srand((unsigned)time(0));


  for(int i=0; i<N_RCTCARDS_PHI; i++){
    for(int j=0; j<N_RCTGCT_FIBERS; j++){
      for(int k=0; k<N_RCTTOWERS_FIBER; k++){
        GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTtowers[k].et = 0 ;
        GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTtowers[k].et = 0 ;
      }
      for(int k=0; k<N_RCTCLUSTERS_FIBER; k++){
        GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et = 0 ;
        GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].towEta = 0 ;
        GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].towPhi = 0 ;
        GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].crEta = 0 ;
        GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].crPhi = 0 ;
        GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et = 0 ;
        GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].towEta = 0 ;
        GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].towPhi = 0 ;
        GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].crEta = 0 ;
        GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].crPhi = 0 ;
      }
    }
  }

  GCTcard.RCTcardEtaPos[0].RCTtoGCTfiber[0].RCTclusters[0].et = 50 ;
  GCTcard.RCTcardEtaPos[0].RCTtoGCTfiber[0].RCTclusters[0].towEta = 2 ;
  GCTcard.RCTcardEtaPos[0].RCTtoGCTfiber[0].RCTclusters[0].towPhi = 3 ;
  GCTcard.RCTcardEtaPos[0].RCTtoGCTfiber[0].RCTclusters[0].crEta = 0 ;
  GCTcard.RCTcardEtaPos[0].RCTtoGCTfiber[0].RCTclusters[0].crPhi = 4 ;

  GCTcard.RCTcardEtaPos[1].RCTtoGCTfiber[0].RCTclusters[0].et = 100 ;
  GCTcard.RCTcardEtaPos[1].RCTtoGCTfiber[0].RCTclusters[0].towEta = 1 ;
  GCTcard.RCTcardEtaPos[1].RCTtoGCTfiber[0].RCTclusters[0].towPhi = 0 ;
  GCTcard.RCTcardEtaPos[1].RCTtoGCTfiber[0].RCTclusters[0].crEta = 4 ;
  GCTcard.RCTcardEtaPos[1].RCTtoGCTfiber[0].RCTclusters[0].crPhi = 0 ;
//  GCTcard.RCTcardEtaPos[1].RCTtoGCTfiber[3].RCTtowers[7].et = 30 ;
//
  GCTcard.RCTcardEtaNeg[1].RCTtoGCTfiber[0].RCTclusters[0].et = 15 ;
  GCTcard.RCTcardEtaNeg[1].RCTtoGCTfiber[0].RCTclusters[0].towEta = 4 ;
  GCTcard.RCTcardEtaNeg[1].RCTtoGCTfiber[0].RCTclusters[0].towPhi = 0 ;
  GCTcard.RCTcardEtaNeg[1].RCTtoGCTfiber[0].RCTclusters[0].crEta = 3 ;
  GCTcard.RCTcardEtaNeg[1].RCTtoGCTfiber[0].RCTclusters[0].crPhi = 0 ;

  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[0].RCTclusters[0].et = 20 ;
  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[0].RCTclusters[0].towEta = 4 ;
  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[0].RCTclusters[0].towPhi = 3 ;
  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[0].RCTclusters[0].crEta = 4 ;
  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[0].RCTclusters[0].crPhi = 4 ;
//  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[3].RCTtowers[7].et = 5 ;
  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[1].RCTclusters[1].et = 40 ;
  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[1].RCTclusters[1].towEta = 0 ;
  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[1].RCTclusters[1].towPhi = 1 ;
  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[1].RCTclusters[1].crEta = 0 ;
  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[1].RCTclusters[1].crPhi = 4 ;
  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[1].RCTtowers[1].et = 55 ;

  GCTcard.RCTcardEtaPos[2].RCTtoGCTfiber[0].RCTclusters[0].et = 10 ;
  GCTcard.RCTcardEtaPos[2].RCTtoGCTfiber[0].RCTclusters[0].towEta = 0 ;
  GCTcard.RCTcardEtaPos[2].RCTtoGCTfiber[0].RCTclusters[0].towPhi = 2 ;
  GCTcard.RCTcardEtaPos[2].RCTtoGCTfiber[0].RCTclusters[0].crEta = 0 ;
  GCTcard.RCTcardEtaPos[2].RCTtoGCTfiber[0].RCTclusters[0].crPhi = 0 ;


  GCTcard.RCTcardEtaPos[0].RCTtoGCTfiber[2].RCTtowers[5].et = 11 ;
  GCTcard.RCTcardEtaPos[1].RCTtoGCTfiber[2].RCTtowers[5].et = 12 ;
  GCTcard.RCTcardEtaPos[2].RCTtoGCTfiber[2].RCTtowers[5].et = 13 ;
  GCTcard.RCTcardEtaPos[3].RCTtoGCTfiber[2].RCTtowers[5].et = 14 ;
  GCTcard.RCTcardEtaPos[4].RCTtoGCTfiber[2].RCTtowers[5].et = 15 ;

  GCTcard.RCTcardEtaNeg[0].RCTtoGCTfiber[1].RCTtowers[5].et = 21 ;
  GCTcard.RCTcardEtaNeg[1].RCTtoGCTfiber[1].RCTtowers[5].et = 22 ;
  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[1].RCTtowers[5].et = 23 ;
  GCTcard.RCTcardEtaNeg[3].RCTtoGCTfiber[1].RCTtowers[5].et = 24 ;
  GCTcard.RCTcardEtaNeg[4].RCTtoGCTfiber[1].RCTtowers[5].et = 25 ;

  ap_uint<384> link_in[N_INPUT_LINKS]; // 40 input links, each GCT phi-half (SLR) has 10 RCT cards, each card having 4 output links
  ap_uint<384> link_out[N_OUTPUT_LINKS]; // 24 output links
  ap_uint<32> start = 0;

  for(size_t i=0; i<N_INPUT_LINKS; i++){
    link_in[i] = 0;
  }

  for(loop i=0; i<N_RCTCARDS_PHI; i++){  // 5 RCT cards in each eta-half
    for(loop j=0; j<N_RCTGCT_FIBERS; j++){  // 4 links in each RCT card
      start = 4;
      loop index = N_RCTGCT_FIBERS*i+j;
      for(loop k=0; k<N_RCTTOWERS_FIBER; k++){  // 17 towers per RCT link
        link_in[index].range(start+11, start) = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTtowers[k].et; 
        link_in[index+20].range(start+11, start) = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTtowers[k].et;
        start += 15;
      }

      start = start - 4 ;

      for(loop k=0; k<N_RCTCLUSTERS_FIBER; k++){ // 2 clusters per RCT link
        link_in[index].range(start+11, start) = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et;
        link_in[index].range(start+16, start+12) = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].towEta;
        link_in[index].range(start+18, start+17) = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].towPhi;
        link_in[index].range(start+21, start+19) = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].crEta; 
        link_in[index].range(start+24, start+22) = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].crPhi;

        link_in[index+20].range(start+11, start) = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et;
        link_in[index+20].range(start+16, start+12) = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].towEta;
        link_in[index+20].range(start+18, start+17) = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].towPhi;
        link_in[index+20].range(start+21, start+19) = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].crEta;
        link_in[index+20].range(start+24, start+22) = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].crPhi;
        start += 60;
      }

    }
  }

  //std::cout<<"inside tb: "<<GCTcard.RCTcardEtaPos[1].RCTtoGCTfiber[3].RCTtowers[7].et<<"\t"<<link_in[7].range(116, 105)<<std::endl;
  //std::cout<<"inside tb: "<<GCTcard.RCTcardEtaPos[3].RCTtoGCTfiber[2].RCTtowers[5].et<<"\t"<<link_in[14].range(86, 75)<<std::endl;


  GCTtoCorr_t GCTtoCorr ;
  
  algo_topGCT240(link_in, link_out);


    for(loop i=0; i<N_GCTCORR_FIBERS; i++){
    #pragma HLS unroll 
        cout << "f" << i << " / " ;
        for(loop k=0; k<N_GCTTOWERS_FIBER; k++){
        #pragma HLS unroll 
          ap_uint<32> start = k*15+4 ;
          ap_uint<32> end = k*15 + 14 ;
          cout << " " << link_out[i].range(end,start) ;
         }
        cout << " / " ;
        for(loop k=0; k<N_GCTCLUSTERS_FIBER; k++){
        #pragma HLS UNROLL
            ap_uint<32> start = 255 + 60*k;
//            ap_uint<32> end =  314 + 60*k;
            ap_uint<32> end =  266 + 60*k;
            cout << " " << link_out[i].range(end, start) ;
          }
          cout << endl ;
       }

  return 0;
}

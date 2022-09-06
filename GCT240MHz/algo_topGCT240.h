#ifndef _ALGO_TOP_H_
#define _ALGO_TOP_H_

#include <iostream>
#include "ap_int.h"
#include "ap_utils.h"
#include "algo_top_parameters.h"

#define N_RCTCARDS_PHI 5 
#define N_RCTGCT_FIBERS 4 
#define N_RCTTOWERS_FIBER 17 
#define N_RCTCLUSTERS_FIBER 2 

#define N_GCTCORR_FIBERS 24
#define N_GCTTOWERS_FIBER 17 
#define N_GCTCLUSTERS_FIBER 2 

#define N_GCTINTERNAL_FIBERS 40
#define N_GCTPOSITIVE_FIBERS 20
#define N_GCTETA 34
#define N_GCTPHI 20

typedef ap_uint<10> loop;
using namespace std;

typedef struct {
ap_uint<12> et ;
ap_uint<5> towEta ;
ap_uint<2> towPhi ;
ap_uint<3> crEta ;
ap_uint<3> crPhi ;
ap_uint<3> satur ;
ap_uint<15> et5x5 ;
ap_uint<15> et2x5 ;
ap_uint<2> brems ;
} RCTcluster_t ;

typedef struct {
ap_uint<11> et ;
ap_uint<4> hoe ;
} RCTtower_t ;

typedef struct {
RCTtower_t RCTtowers[N_RCTTOWERS_FIBER] ;
RCTcluster_t RCTclusters[N_RCTCLUSTERS_FIBER] ;
} RCTtoGCTfiber_t ;

typedef struct {
RCTtoGCTfiber_t RCTtoGCTfiber[N_RCTGCT_FIBERS] ;
} RCTcard_t ;

typedef struct {
RCTcard_t RCTcardEtaPos[N_RCTCARDS_PHI] ;
RCTcard_t RCTcardEtaNeg[N_RCTCARDS_PHI] ;
} GCTcard_t ;

typedef struct {
ap_uint<12> et ;
ap_uint<1> towEtaNeg ;
ap_uint<6> towEta ;
ap_uint<5> towPhi ;
ap_uint<3> crEta ;
ap_uint<3> crPhi ;
ap_uint<3> satur ;
ap_uint<3> hoe ;
ap_uint<3> iso ;
ap_uint<3> shape ;
ap_uint<2> brems ;
} GCTcluster_t ;

typedef struct {
ap_uint<11> et ;
ap_uint<4> hoe ;
} GCTtower_t ;

typedef struct {
GCTtower_t GCTtowers[N_GCTTOWERS_FIBER] ;
GCTcluster_t GCTclusters[N_GCTCLUSTERS_FIBER] ;
} GCTCorrfiber_t ;

typedef struct {
GCTCorrfiber_t GCTCorrfiber[N_GCTCORR_FIBERS] ;
} GCTtoCorr_t ;

typedef struct {
GCTCorrfiber_t GCTCorrfiber[N_GCTINTERNAL_FIBERS] ;
} GCTinternal_t ;


typedef struct {
GCTtower_t GCTtower[N_GCTETA][N_GCTPHI] ;
} GCTintTowers_t ;

typedef struct {
   ap_uint<12> et ;
   ap_uint<7> eta ;
   ap_uint<7> phi ;
} GCTint_t ;

typedef struct {
   GCTint_t t[12];
} etaStrip_t ;

typedef struct {
   GCTint_t p[17];
} etaStripPeak_t ;

typedef struct {
   etaStrip_t s0;
   etaStrip_t s1;
   etaStrip_t s2;
   etaStrip_t s3;
   etaStrip_t s4;
   etaStrip_t s5;
   etaStrip_t s6;
   etaStrip_t s7;
   etaStrip_t s8;
   etaStrip_t s9;
   etaStrip_t s10;
   etaStrip_t s11;
   etaStrip_t s12;
   etaStrip_t s13;
   etaStrip_t s14;
   etaStrip_t s15;
   etaStrip_t s16;
} region_t;

typedef struct {
   ap_uint<12> et[6] ;
   ap_uint<7> eta[6] ;
   ap_uint<7> phi[6] ;
} GCTJet_t ;

//void algo_top(const GCTcard_t& GCTcard, ap_uint<15> cluster[10]);
//void algo_top(const GCTcard_t& GCTcard, GCTtoCorr_t& GCTtoCorr) ;
void algo_topGCT240(ap_uint<384> link_in[N_INPUT_LINKS], ap_uint<384> link_out[N_OUTPUT_LINKS]);

GCTinternal_t getClustersTowersGCT(const GCTcard_t& GCTcard) ;

GCTcard_t getClustersCombinedGCT(const GCTcard_t& GCTcard) ; 

GCTintTowers_t  getFullTowersGCT(const GCTinternal_t& GCTinternal) ;

GCTJet_t jet(const GCTintTowers_t& GCTintTowers);

#endif

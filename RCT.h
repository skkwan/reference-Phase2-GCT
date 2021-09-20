#ifndef _ALGO_TOP_H_
#define _ALGO_TOP_H_

#include <iostream>
#include <ap_axi_sdata.h>
#include <hls_stream.h>
#include "ap_int.h"
#include <algorithm>
#include <utility>
#include <stdint.h>

#define CRYSTAL_IN_PHI 20
#define CRYSTAL_IN_ETA 15
#define TOTAL_CLUSTER 10
#define TOWER_IN_ETA 3
#define TOWER_IN_PHI 4
#define N_INPUT_LINKS 26
#define N_INPUT_LINKS_ECAL 12
#define N_INPUT_LINKS_HCAL 2
#define N_INPUT_LINKS 26
#define N_OUTPUT_LINKS 4
#define CRYSTAL_IN_TOWER 25
#define HCAL_TOWER_IN_ETA 4
#define HCAL_TOWER_IN_PHI 4


typedef ap_uint<5> loop;
typedef ap_uint<6> loop6;

using namespace std;

class crystalMax{
    public:
    ap_uint<10> energy;
    ap_uint<5> phiMax;
    ap_uint<5> etaMax;

    crystalMax(){
        energy = 0;
        phiMax = 0;
        etaMax = 0;
    }

    crystalMax& operator=(const crystalMax& rhs){
        energy = rhs.energy;
        phiMax = rhs.phiMax;
        etaMax = rhs.etaMax;
        return *this;
    }
};

class crystal{
    public:
    ap_uint<10> energy;
    ap_uint<4> timing;

    crystal(){
        energy = 0;
        timing = 0;
    }

    crystal(ap_uint<14> i){
    	this->energy = i.range(9, 0);
    	this->timing = i.range(13, 10);
    }

    crystal& operator=(const crystal& rhs){
        energy = rhs.energy;
        timing = rhs.timing;
        return *this;
    }
};

class clusterInfo{
    public:
    ap_uint<10> seedEnergy;
    ap_uint<15> energy;
    ap_uint<15> et5x5;
    ap_uint<15> et2x5;
    ap_uint<5> phiMax;
    ap_uint<5> etaMax;
    ap_uint<2> brems;

    clusterInfo(){
        seedEnergy = 0;
        energy = 0;
        et5x5 = 0;
        et2x5 = 0;
        phiMax = 0;
        etaMax = 0;
        brems = 0;
    }

    clusterInfo& operator=(const clusterInfo& rhs){
        seedEnergy = rhs.seedEnergy;
        energy = rhs.energy;
        et5x5 = rhs.et5x5;
        et2x5 = rhs.et2x5;
        phiMax = rhs.phiMax;
        etaMax = rhs.etaMax;
        brems = rhs.brems;
        return *this;
    }
};

class Cluster{
    public:
    ap_uint<28> data;

    Cluster(){
        data = 0;
    }

    Cluster& operator=(const Cluster& rhs){
        data = rhs.data;
        return *this;
    }

    Cluster(ap_uint<12> clusterEnergy, ap_uint<5> towerEta, ap_uint<2> towerPhi, ap_uint<3> clusterEta, ap_uint<3> clusterPhi, ap_uint<3> satur){
        data = (clusterEnergy) | 
      (((ap_uint<32>) towerEta)  << 12) | 
      (((ap_uint<32>) towerPhi)  << 17) | 
      (((ap_uint<32>) clusterEta)  << 19) | 
      (((ap_uint<32>) clusterPhi) << 22) | 
      (((ap_uint<32>) satur)       << 25);
    }

    ap_uint<12> clusterEnergy() {return (data & 0xFFF);}
    ap_uint<5> towerEta() {return ((data >> 12) & 0x37);}
    ap_uint<2> towerPhi() {return ((data >> 17) & 0x3);}
    ap_uint<3> clusterEta() {return ((data >> 19) & 0x7);}
    ap_uint<3> clusterPhi() {return ((data >> 22) & 0x7);}
    ap_uint<3> satur() {return ((data >> 25) & 0x7);}
	
    operator uint32_t() {return (ap_uint<28>) data;}

};

template<int D, int U>
struct ap_axiu <D, U, 0, 0>{
	ap_uint<D>       data;
	ap_uint<U>       user;
	ap_uint<1>       last;
};

namespace algo {
	typedef ap_axiu<32, 8, 0, 0> axiword32;
	typedef ap_axiu<64, 8, 0, 0> axiword64;
	typedef ap_axiu<256, 8, 0, 0> axiword256;
	typedef ap_axiu<320, 8, 0, 0> axiword320;
	typedef ap_axiu<384, 8, 0, 0> axiword384;
	typedef ap_axiu<448, 8, 0, 0> axiword448;
	typedef ap_axiu<512, 8, 0, 0> axiword512;
	typedef ap_axiu<576, 8, 0, 0> axiword576;
}

void algo_top(hls::stream<algo::axiword384> link_in[N_INPUT_LINKS], hls::stream<algo::axiword384> link_out[N_OUTPUT_LINKS]);
//void algo_top(hls::stream<algo::axiword384> link_in[N_INPUT_LINKS], ap_uint<384> outWord_384b[N_OUTPUT_LINKS]) ;

typedef struct {
    ap_uint<10> energy;
    ap_uint<5> phi;
    ap_uint<5> eta;
} ecaltp_t ;

typedef struct {
ecaltp_t cr0;
ecaltp_t cr1 ;
ecaltp_t cr2 ;
ecaltp_t cr3 ;
ecaltp_t cr4 ;
ecaltp_t cr5 ;
ecaltp_t cr6 ;
ecaltp_t cr7 ;
ecaltp_t cr8 ;
ecaltp_t cr9 ;
ecaltp_t cr10 ;
ecaltp_t cr11 ;
ecaltp_t cr12 ;
ecaltp_t cr13 ;
ecaltp_t cr14 ;
ecaltp_t cr15 ;
ecaltp_t cr16 ;
ecaltp_t cr17 ;
ecaltp_t cr18 ;
ecaltp_t cr19 ;
} etaStrip_t ;

typedef struct {
etaStrip_t etaStrip0 ;
etaStrip_t etaStrip1 ;
etaStrip_t etaStrip2 ;
etaStrip_t etaStrip3 ;
etaStrip_t etaStrip4 ;
etaStrip_t etaStrip5 ;
etaStrip_t etaStrip6 ;
etaStrip_t etaStrip7 ;
etaStrip_t etaStrip8 ;
etaStrip_t etaStrip9 ;
etaStrip_t etaStrip10 ;
etaStrip_t etaStrip11 ;
etaStrip_t etaStrip12 ;
etaStrip_t etaStrip13 ;
etaStrip_t etaStrip14 ;
} ecalRegion_t ;

typedef struct {
ecaltp_t pk0;
ecaltp_t pk1;
ecaltp_t pk2;
ecaltp_t pk3;
ecaltp_t pk4;
ecaltp_t pk5;
ecaltp_t pk6;
ecaltp_t pk7;
ecaltp_t pk8;
ecaltp_t pk9;
ecaltp_t pk10;
ecaltp_t pk11;
ecaltp_t pk12;
ecaltp_t pk13;
ecaltp_t pk14;
} etaStripPeak_t ;

class tower_t {
    public:
        ap_uint<16> data;

    tower_t(){
        data = 0;
    }
    tower_t& operator=(const tower_t& rhs){
        data = rhs.data;
        return *this;
    }

    tower_t(ap_uint<12> et, ap_uint<3> hoe, ap_uint<1> satur){
        data = (et) | 
      (((ap_uint<16>) hoe)  << 12) | 
      (((ap_uint<16>) satur)  << 15);
    }

    ap_uint<12> et() {return (data & 0xFFF);}
    ap_uint<3> hoe() {return ((data >> 12) & 0x7);}
    ap_uint<1> satur() {return ((data >> 15) & 0x2);}
	
    operator uint16_t() {return (uint16_t) data;}

};

class towerHCAL{
    public:
    ap_uint<10> et;
    ap_uint<6> fb;

    towerHCAL(){
        et = 0;
        fb = 0;
    }

    towerHCAL& operator=(const towerHCAL& rhs){
        et = rhs.et;
        fb = rhs.fb;
        return *this;
    }

    towerHCAL(ap_uint<16> i){
        this->et = i.range(9, 0);
    	this->fb = i.range(15, 10);
    }
};

typedef struct {
tower_t tower0 ;
tower_t tower1 ;
tower_t tower2 ;
tower_t tower3 ;
tower_t tower4 ;
tower_t tower5 ;
tower_t tower6 ;
tower_t tower7 ;
tower_t tower8 ;
tower_t tower9 ;
tower_t tower10 ;
tower_t tower11 ;
} region3x4_t ;


typedef struct {
ap_uint<12> et[3][4];
} towers3x4_t ;


#endif

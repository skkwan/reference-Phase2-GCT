#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <stdint.h>
#include <unistd.h>

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "algo_top.h"
#include "algo_top_parameters.h"

using namespace std;

int main() {

	ap_uint<576> link_in[N_INPUT_LINKS];
        ap_uint<576> link_inSLRA[N_INPUT_LINKS_SLRA];
	ap_uint<576> link_out[N_OUTPUT_LINKS];

    size_t start = 0;
    size_t end = 13;

    for(size_t i=0; i<N_INPUT_LINKS; i++){
    	   link_in[i] = 0;
       }

    for(size_t i=0; i<N_INPUT_LINKS_SLRA; i++){
    	   link_inSLRA[i] = 0;
       }

    ap_uint<8> wordId, wordId1, wordId2, startId ;
    for(size_t i=0; i<CRYSTAL_IN_ETA; i++){
        for(size_t j=0; j<CRYSTAL_IN_PHI; j++){
            wordId = (i/5)*4+(j/5) ;
            startId = (i%5)*5+(j%5) ;
            start = startId*14 ; end = start + 13 ;
// temporary
        		link_in[wordId].range(end, start) = 0 ; //  [i][j] crystal in 15:20 

                 if(i == 0 && j == 0) link_in[wordId].range(end, start) = 10 ;
                 if(i == 4 && j == 4) link_in[wordId].range(end, start) = 14 ;
                 if(i == 5 && j == 5) link_in[wordId].range(end, start) = 11 ;
                 if(i == 9 && j == 3) link_in[wordId].range(end, start) = 30 ;
//                 if(i == 11 && j == 3) link_in[wordId].range(end, start) = 35 ;
                 if(i == 11 && j == 16) link_in[wordId].range(end, start) = 3 ;
//                 if(i == 10 && j == 11) link_in[wordId].range(end, start) = 3 ;
//                 if(i == 10 && j == 12) link_in[wordId].range(end, start) = 17 ;
//                 if(i == 6 && j == 15) link_in[wordId].range(end, start) = 19 ;
//                 if(i == 6 && j == 16) link_in[wordId].range(end, start) = 6 ;
                 if(i == 14 && j == 15) link_in[wordId].range(end, start) = 5 ;



//temporary1
                       wordId1 = wordId + 12 ;
                       link_in[wordId1].range(end, start) = 0 ; //  [i][j] crystal in 15:20 

                 if(i == 14 && j == 11) link_in[wordId1].range(end, start) = 11 ;
                 if(i == 0 && j == 16) link_in[wordId1].range(end, start) = 15 ;
//                 if(i == 5 && j == 5) link_in[wordId1].range(end, start) = 12 ;
//                 if(i == 9 && j == 3) link_in[wordId1].range(end, start) = 31 ;
                 if(i == 11 && j == 3) link_in[wordId1].range(end, start) = 36 ;
//                 if(i == 11 && j == 6) link_in[wordId1].range(end, start) = 4 ;
//                 if(i == 10 && j == 11) link_in[wordId1].range(end, start) = 4 ;
//                 if(i == 10 && j == 12) link_in[wordId1].range(end, start) = 18 ;
//                 if(i == 6 && j == 15) link_in[wordId1].range(end, start) = 20 ;
//                 if(i == 6 && j == 16) link_in[wordId1].range(end, start) = 7 ;
//                 if(i == 7 && j == 15) link_in[wordId1].range(end, start) = 6 ;

//temporary2
                       wordId2 = wordId1 + 12 ;
                       link_in[wordId2].range(end, start) = 0 ; //  [i][j] crystal in 15:20 

                 if(i == 0 && j == 5) link_in[wordId2].range(end, start) = 12 ;
                 if(i == 1 && j == 9) link_in[wordId2].range(end, start) = 6 ;
//                 if(i == 5 && j == 5) link_in[wordId2].range(end, start) = 13 ;
//                 if(i == 9 && j == 3) link_in[wordId2].range(end, start) = 32 ;
//                 if(i == 11 && j == 3) link_in[wordId2].range(end, start) = 37 ;
//                 if(i == 11 && j == 6) link_in[wordId2].range(end, start) = 5 ;
//                 if(i == 10 && j == 11) link_in[wordId2].range(end, start) = 5 ;
//                 if(i == 10 && j == 12) link_in[wordId2].range(end, start) = 19 ;
//                 if(i == 6 && j == 15) link_in[wordId2].range(end, start) = 21 ;
//                 if(i == 6 && j == 16) link_in[wordId2].range(end, start) = 8 ;
                 if(i == 14 && j == 1) link_in[wordId2].range(end, start) = 55 ;
				


         	}
		}


          link_inSLRA[0].range(11, 0) = 120 ;
          link_inSLRA[0].range(71, 60) = 140 ;
          link_inSLRA[0].range(191, 180) = 160 ;
	
          link_inSLRA[1].range(11, 0) = 100 ;
          link_inSLRA[1].range(16, 12) = 9 ;

	// Run the algorithm

	  algo_top(link_in, link_inSLRA,  link_out);


//	  	cout << hex << "link_out[0]: " << link_out[0] << endl;
//	  	cout << hex << "link_out[1]: " << link_out[1] << endl;
//	  	cout << hex << "link_out[2]: " << link_out[2] << endl;
//	  	cout << hex << "link_out[3]: " << link_out[3] << endl;

	  cout << "printing towers et" << endl;

	  		start = 4;
	  		for(loop oLink=0; oLink<17; oLink++){
	  			size_t end = start + 10;
	  			cout << link_out[0].range(end, start) << " " << link_out[1].range(end, start) << " " << link_out[2].range(end, start) << " " << link_out[3].range(end, start) << endl;
	  			start += 15;
	  		}

	  		cout << "printing cluster et" << endl;
for(loop k=0; k<4; k++){
for(loop i=255; i<320; i=i+60)
cout << link_out[k].range(11+i, 0+i) << " " << link_out[k].range(16+i, 12+i) << " " << link_out[k].range(18+i, 17+i) << " " << link_out[k].range(21+i, 19+i) << " " << link_out[k].range(24+i, 22+i) << " " << link_out[k].range(27+i, 25+i) << " " << link_out[k].range(42+i, 28+i) << " " << link_out[k].range(57+i, 43+i) << " " << link_out[k].range(59+i, 58+i) <<  endl ;
}

return 0;

}




#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <stdint.h>
#include <unistd.h>

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include <argp.h>
#include "algo_top.h"

using namespace std;
using namespace algo;

int main() {

	hls::stream<axiword384> link_in[N_INPUT_LINKS];
	hls::stream<axiword384> link_out[N_OUTPUT_LINKS];

		// Copy the file data to the stream
		ap_uint<384> bigdataword[N_INPUT_LINKS];


		    for (size_t k = 0; k < N_INPUT_LINKS; k++) {		    
		      bigdataword[k] = 0 ;
		    }


/*

		for (size_t i = 0, low = 0, high = 63; i < 6;  i++, low += 64, high += 64) {
		  for (size_t k = 0; k < N_INPUT_LINKS; k++) {
		      bigdataword1[k].range(high, low) = 0;
		    }

		  if (high == 383) {
		    for (size_t k = 0; k < N_INPUT_LINKS; k++) {		    
		      link_in[k].write({bigdataword1[k], 0, 1});
		    }
		    low = 0;
		    high = 63;
		  }
		}
*/

        size_t start = 0;
        size_t end = 13;


        ap_uint<6> wordId, wordId1, startId ;
        for(loop i=0; i<CRYSTAL_IN_ETA; i++){
                for(loop j=0; j<CRYSTAL_IN_PHI; j++){
                       wordId = (i/5)*4+(j/5) ;
                       startId = (i%5)*5+(j%5) ;
                       start = startId*14 ; end = start + 13 ;
// temporary
                       bigdataword[wordId].range(end, start) = 0 ; //  [i][j] crystal in 15:20 

                 if(i == 0 && j == 0) bigdataword[wordId].range(end, start) = 10 ;
                 if(i == 4 && j == 4) bigdataword[wordId].range(end, start) = 15 ;
                 if(i == 4 && j == 9) bigdataword[wordId].range(end, start) = 20 ;
                 if(i == 3 && j == 13) bigdataword[wordId].range(end, start) = 13 ;
                 if(i == 10 && j == 2) bigdataword[wordId].range(end, start) = 25 ;
                 if(i == 12 && j == 5) bigdataword[wordId].range(end, start) = 30 ;
                 if(i == 11 && j == 11) bigdataword[wordId].range(end, start) = 40 ;
                 if(i == 13 && j == 15) bigdataword[wordId].range(end, start) = 16 ;
                 if(i == 9 && j == 19) bigdataword[wordId].range(end, start) = 100 ;
                 if(i == 0 && j == 19) bigdataword[wordId].range(end, start) = 54 ;

//temporary1
                       wordId1 = wordId + 12 ;
                       bigdataword[wordId1].range(end, start) = 0 ; //  [i][j] crystal in 15:20 

                 if(i == 1 && j == 2) bigdataword[wordId1].range(end, start) = 11 ;
                 if(i == 4 && j == 6) bigdataword[wordId1].range(end, start) = 18 ;
                 if(i == 4 && j == 9) bigdataword[wordId1].range(end, start) = 23 ;
                 if(i == 3 && j == 13) bigdataword[wordId1].range(end, start) = 33 ;
                 if(i == 8 && j == 3) bigdataword[wordId1].range(end, start) = 27 ;
                 if(i == 13 && j == 5) bigdataword[wordId1].range(end, start) = 31 ;
                 if(i == 11 && j == 9) bigdataword[wordId1].range(end, start) = 60 ;
                 if(i == 7 && j == 15) bigdataword[wordId1].range(end, start) = 17 ;
                 if(i == 1 && j == 19) bigdataword[wordId1].range(end, start) = 200 ;
                 if(i == 8 && j == 19) bigdataword[wordId1].range(end, start) = 54 ;

         }}

      start = 0; end = 15;
        for(loop i=0; i<HCAL_TOWER_IN_ETA; i++){
           for(loop j=0; j<HCAL_TOWER_IN_PHI; j++){
                 bigdataword[24].range(end, start) = 0 ; 
                 if(i == 0 && j == 0) bigdataword[24].range(end, start) = 66 ;
                 if(i == 0 && j == 1) bigdataword[24].range(end, start) = 67 ;
                 if(i == 0 && j == 2) bigdataword[24].range(end, start) = 68 ;
                 if(i == 0 && j == 3) bigdataword[24].range(end, start) = 69 ;
                 if(i == 3 && j == 0) bigdataword[24].range(end, start) = 10 ;
                 if(i == 3 && j == 1) bigdataword[24].range(end, start) = 20 ;
                 if(i == 3 && j == 2) bigdataword[24].range(end, start) = 30 ;
                 if(i == 3 && j == 3) bigdataword[24].range(end, start) = 40 ;
                 bigdataword[25].range(end, start) = 0 ; 
                 if(i == 0 && j == 0) bigdataword[25].range(end, start) = 88 ;
                 if(i == 1 && j == 0) bigdataword[25].range(end, start) = 77 ;
                 start += 16; end += 16;
        }}


		    for (size_t k = 0; k < N_INPUT_LINKS; k++) {		    
		      link_in[k].write({bigdataword[k], 0, 1});
		    }


	// Run the algorithm

	  algo_top(link_in, link_out);


	ap_uint<384> bigdataword2[N_OUTPUT_LINKS];
	axiword384 r384;
	  for (size_t k = 0; k < N_OUTPUT_LINKS; k++) {
		r384 = link_out[k].read();
		bigdataword2[k] = r384.data;
	  }

		cout << "printing towers et" << endl;

		start = 0;
		for(loop oLink=0; oLink<6; oLink++){
			size_t end = start + 15;
			cout << bigdataword2[0].range(end, start) << endl;
			start += 16;
		}

		start = 0;
		for(loop oLink=0; oLink<6; oLink++){
			size_t end = start + 15;
			cout << bigdataword2[1].range(end, start) << endl;
			start += 16;
		}

		start = 0;
		for(loop oLink=0; oLink<6; oLink++){
			size_t end = start + 15;
			cout << bigdataword2[2].range(end, start) << endl;
			start += 16;
		}

		start = 0;
		for(loop oLink=0; oLink<6; oLink++){
			size_t end = start + 15;
			cout << bigdataword2[3].range(end, start) << endl;
			start += 16;
		}

		cout << "printing cluster et" << endl;

		cout << bigdataword2[0].range(107, 96) << endl;
		cout << bigdataword2[0].range(135, 124) << endl;
		cout << bigdataword2[1].range(107, 96) << endl;
		cout << bigdataword2[1].range(135, 124) << endl;
		cout << bigdataword2[2].range(107, 96) << endl;
		cout << bigdataword2[2].range(135, 124) << endl;
		cout << bigdataword2[3].range(107, 96) << endl;
		cout << bigdataword2[3].range(135, 124) << endl;
	

return 0;

}


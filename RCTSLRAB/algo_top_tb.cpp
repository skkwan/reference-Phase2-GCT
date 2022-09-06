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

        ap_uint<384> link_inSLRA[N_INPUT_LINKS_SLRA];
        ap_uint<384> link_inSLRB[N_INPUT_LINKS_SLRB];
	ap_uint<384> link_out[N_OUTPUT_LINKS];

    size_t start = 0;
    size_t end = 13;

    for(size_t i=0; i<N_INPUT_LINKS_SLRA; i++){
    	   link_inSLRA[i] = 0;
       }
    for(size_t i=0; i<N_INPUT_LINKS_SLRB; i++){
    	   link_inSLRB[i] = 0;
       }

          link_inSLRA[0].range(11, 0) = 120 ;
          link_inSLRA[0].range(71, 60) = 140 ;
          link_inSLRA[0].range(191, 180) = 160 ;
	
          link_inSLRA[1].range(11, 0) = 100 ;
          link_inSLRA[1].range(16, 12) = 9 ;

          link_inSLRB[0].range(11, 0) = 220 ;
          link_inSLRB[0].range(71, 60) = 240 ;
          link_inSLRB[0].range(191, 180) = 260 ;
	
          link_inSLRB[2].range(11, 0) = 150 ;
          link_inSLRB[2].range(16, 12) = 7 ;


          link_inSLRB[3].range(9, 0) = 288 ;
          link_inSLRB[3].range(99, 90) = 99 ;

	// Run the algorithm

	  algo_topAB(link_inSLRA, link_inSLRB, link_out);


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




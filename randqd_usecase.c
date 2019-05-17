#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <time.h>

// RANDQD LIB
#include "src/randqd.h"

int main(int argc, char const *argv[])
{   
    fputs(" -------------------------------------------------\n", stdout);
	fputs("|             randqd.c - some usecase             |\n",stdout);
	fputs(" -------------------------------------------------\n", stdout);
	fputs("|             start seed = 734728374UL            |\n",stdout);
	fputs(" -------------------------------------------------\n", stdout);

    init_rseed(734728374UL); // init seed with a random number
                            // must be UNSIGNED LONG

    uint32_t v1 = randqd_uint32() % 100;         // v1 in the range 0 to 99
    uint32_t v2 = randqd_uint32() % 100 + 1;     // v2 in the range 1 to 100
    uint32_t v3 = randqd_uint32() % 30 + 1985;   // v3 in the range 1985-2014 

    fprintf(stdout,"- random number in the range 0 to 99: %u\n",v1);
    fprintf(stdout,"- random number in the range 1 to 100: %u\n",v2);
    fprintf(stdout,"- random number in the range 1985-2014 : %u\n",v3);
    

    for (size_t i = 0; i < 3; i++)
    {
        double rand_num = randqd_double()* 2.0 - 1.0;
        fprintf(stdout,"- double random number in the range [-1,1] : %f\n",rand_num);
    }
    
    return 0;
}

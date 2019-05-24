#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <inttypes.h>


// RANDQD LIB
#include "src/randq.h"
/*
 * Robert Jenkins' 96 bit Mix Function
 */ 
uint32_t mix(uint32_t a, uint32_t b, uint32_t c)
{
    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
}

int main(int argc, char const *argv[])
{   
    fputs(" ---------------------------------------------------------------\n", stdout);
	fputs("|                      randqd.c - some usecase                  |\n",stdout);
    fputs(" ---------------------------------------------------------------\n", stdout);

    int pid = getpid() ;                                // get it as per your OS
    struct timeval t;
    gettimeofday(&t, NULL);
    uint32_t seed = mix(t.tv_usec, t.tv_sec, pid);      // a mix for the seed
    fprintf(stdout,"   ==> calculate a 'start seed':  %"PRId32"\n",seed);

    fputs(" ---------------------------------------------------------------\n", stdout);
	fputs("|  suspenders-and-belt, full-body-armor,never-any-doubt method  |\n",stdout);
	fputs(" ---------------------------------------------------------------\n", stdout);

    srandq64((uint64_t) seed);                           // init seed with a random number


    uint64_t v1 = randq64_uint64() % 100;                // v1 in the range 0 to 99
    uint32_t v2 = randq64_uint32() % 30 + 1985;          // v3 in the range 1985-2014 

    fprintf(stdout,"- random number in the range 0 to 99: %"PRIu64"\n",v1);
    fprintf(stdout,"- random number in the range 1985-2014: %"PRId32"\n",v2);
    

    for (size_t i = 0; i < 3; i++)
    {
        double rand_num = randq64_double()* 2.0 - 1.0;
        fprintf(stdout,"- double random number in the range [-1,1] : %f\n",rand_num);
    }

    srandqd(seed);                                      // init seed with a random number
                                                        // must be UNSIGNED LONG
    fputs(" ---------------------------------------------------------------\n", stdout);
	fputs("|                      Quick and Dirty method                   |\n",stdout);
    fputs(" ---------------------------------------------------------------\n", stdout);

    uint32_t v3 = randqd_uint32() % 100;                // v1 in the range 0 to 99
    uint32_t v4 = randqd_uint32() % 100 + 1;            // v2 in the range 1 to 100
    uint32_t v5 = randqd_uint32() % 30 + 1985;          // v3 in the range 1985-2014 

    fprintf(stdout,"- random number in the range 0 to 99: %"PRId32"\n",v3);
    fprintf(stdout,"- random number in the range 1 to 100: %"PRId32"\n",v4);
    fprintf(stdout,"- random number in the range 1985-2014 : %"PRId32"\n",v5);
    
    for (size_t i = 0; i < 3; i++)
    {
        double rand_num = randqd_double()* 2.0 - 1.0;
        fprintf(stdout,"- double random number in the range [-1,1] : %f\n",rand_num);
    }    
    
    return 0;
}
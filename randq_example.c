#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

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
    fputs(" -------------------------------------------------\n", stdout);
	fputs("|             randqd.c - some usecase             |\n",stdout);
	fputs(" -------------------------------------------------\n", stdout);

    int pid = getpid() ;                                // get it as per your OS
    struct timeval t;
    gettimeofday(&t, NULL);
    uint32_t seed = mix(t.tv_usec, t.tv_sec, pid);      // a mix for the seed
    fprintf(stdout,"   ==> calculate a 'start seed': %u\n\n",seed);
    srandqd(seed);                                   // init seed with a random number
                                                        // must be UNSIGNED LONG

    uint32_t v1 = randqd_uint32() % 100;                // v1 in the range 0 to 99
    uint32_t v2 = randqd_uint32() % 100 + 1;            // v2 in the range 1 to 100
    uint32_t v3 = randqd_uint32() % 30 + 1985;          // v3 in the range 1985-2014 

    fprintf(stdout,"- random number in the range 0 to 99: %u\n",v1);
    fprintf(stdout,"- random number in the range 1 to 100: %u\n",v2);
    fprintf(stdout,"- random number in the range 1985-2014 : %u\n",v3);
    

    for (size_t i = 0; i < 10; i++)
    {
        double rand_num = randqd_double()* 2.0 - 1.0;
        fprintf(stdout,"- double random number in the range [-1,1] : %f\n",rand_num);
    }    
    
    return 0;
}
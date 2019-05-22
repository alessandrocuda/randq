#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

// CMOCKA INCLUDE
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

// RANDQD LIB
#include "src/randq.h"

#define MAX_ITER 42000

static void
hello_message()
{
	fputs(" -------------------------------------------------\n", stdout);
	fputs("|      Pseudo-Random Number Generators UTEST      |\n",stdout);
	fputs(" -------------------------------------------------\n", stdout);
	fputs("|  Propriety of a RN with interval [0,1]:         |\n",stdout);
    fputs("|   - mean: 1/2                                   |\n",stdout);
    fputs("|   - variance: 1/12                              |\n",stdout);
	fputs(" -------------------------------------------------\n", stdout);
}

/*
 *  To check whether your compiler and machine have the desired overflow
 *  properties, see if you can generate the following sequence of 32-bit 
 *  values for the given starting state 0x0000000000
 *  SEE "Numerical Recipes in C" Second Edition at page 284 for more details
 */
static void
randq_uinteger_test(void **state)
{
    (void) state;

    static const uint32_t sequence[] = {
        0x0000000000,0x3C6EF35FUL, 0x47502932UL, 0xD1CCF6E9UL, 0xAAF95334UL, 0x6252E503UL,
        0x9F2EC686UL, 0x57FE6C2DUL, 0xA3D95FA8UL, 0x81FDBEE7UL, 0x94F0AF1AUL,0xCBF633B1UL,
    };

    srandqd(sequence[0]);

    for (size_t i = 0; i < (sizeof(sequence) / sizeof(uint32_t)) - 1; ++i) {
        assert_true(sequence[i+1] == randqd_uint32());
    }
}

/*
 * Check if the function double randqd_double() can generate
 * double random double values within the range [0, 1) 
 */
static void
randq_double_0_to_1(void **state)
{
    (void) state;
    uint32_t    start_seed = 589765974UL;
    uint32_t    greater_then = 0, less_then = 0, other = 0;

    srandqd(start_seed);

    for (size_t i = 0; i < MAX_ITER; ++i) {
        randqd_uint32();
        double rand_num = randqd_double();
        assert_true(rand_num >= 0 && rand_num < 1);

        if (rand_num < 0.5){
            ++less_then;
        } else if (rand_num > 0.5) {
            ++greater_then;
        } else {
            ++other;
        }
    }

    assert_true(greater_then && less_then);
    fprintf(stdout,"[    -->     greater than 0.5: %d (%f%%) - less than 0.5: %d (%f%%) - other: %d (%f%%)\n",
            greater_then, (double) greater_then / MAX_ITER,
            less_then, (double) less_then / MAX_ITER,
            other, (double) other / MAX_ITER);

}

/*
 * Check if the function double randq64_double() can generate
 * double random double values within the range [0, 1) 
 */
static void
randq64_double_0_to_1(void **state)
{
    (void) state;
    uint64_t    start_seed = 589765974ULL;
    uint32_t    greater_then = 0, less_then = 0, other = 0;

    srandq64(start_seed);

    for (size_t i = 0; i < MAX_ITER; ++i) {
        randq64_uint64();
        double rand_num = randq64_double();
        assert_true(rand_num >= 0 && rand_num < 1);

        if (rand_num < 0.5){
            ++less_then;
        } else if (rand_num > 0.5) {
            ++greater_then;
        } else {
            ++other;
        }
    }

    assert_true(greater_then && less_then);
    printf("[    -->     greater than 0.5: %d (%f%%) - less than 0.5: %d (%f%%) - other: %d (%f%%)\n",
            greater_then, (double) greater_then / MAX_ITER,
            less_then, (double) less_then / MAX_ITER,
            other, (double) other / MAX_ITER);

}
/*
 * Calculate mean and variance for both method
 */
void mean_and_variance(char* method){
    double      sum = 0;
    double      mean, variance; 
    uint32_t    start_seed = 4345UL;

    fprintf(stdout,"Calculate mean and variance for method: %s \n",method);

    if( strcmp(method,"64bit"))
        srandq64((uint64_t) start_seed);
    else if (strcmp(method,"QS")) 
        srandqd(start_seed);

    // Determinate Mean
    for (size_t i = 0; i < 1000; ++i)
    {   
        double rand_num = 0.0;
        if( strcmp(method,"64bit")){
            randq64_uint64();
            rand_num = randq64_double();
        }
        else if (strcmp(method,"QS"))
        {
            randqd_uint32();
            rand_num = randqd_double();
        }
         
       
        sum = sum + rand_num;
    }
    mean = sum / 1000;
    fprintf(stdout," - sum: %f\n",sum);

    // Determinate Variance

    if( strcmp(method,"64bit"))
        srandq64((uint64_t) start_seed);
    else if (strcmp(method,"QS")) 
        srandqd(start_seed);

    sum = 0;
    for (size_t i = 0; i < 1000; ++i)
    {
        double rand_num = 0.0;
        if( strcmp(method,"64bit")){
            randq64_uint64();
            rand_num = randq64_double();
        }
        else if (strcmp(method,"QS"))
        {
            randqd_uint32();
            rand_num = randqd_double();
        }
        sum = sum + ((rand_num - mean)*(rand_num - mean));
    }

    variance = sum/1000; 

    printf(" - Mean:%f \n - Variance:%f \n",mean,variance);
}

int
main(void)
{   
    hello_message();

    fputs("\nMean and variance for both method between in [0,1]\n",stdout);
    mean_and_variance("64bit");
    mean_and_variance("QS");

    fputs("\nStarting Cmocka test:\n",stdout);

    const struct CMUnitTest randqd_group[] = {
        cmocka_unit_test(randq_uinteger_test),
        cmocka_unit_test(randq_double_0_to_1),
        cmocka_unit_test(randq64_double_0_to_1)
    };

    return cmocka_run_group_tests(randqd_group, NULL, NULL);
}


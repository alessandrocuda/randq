#include <stdbool.h>

#include "randqd.h"

/*
 * Copyright (c) 2019 Alessandro Cudazzo
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

bool is_rseed_init = false;
static uint32_t rqd_seed = 0UL;


/**
 * Init the First Seed
 *
 * \start_seed      Started seed
 */
void srandqd(uint32_t start_seed)
{
    rqd_seed = start_seed;
}

/**
 * Return a random sample in the range [0, 2^32 - 1].
 * look in  "Numerical Recipes in C" Second Edition 
 * for the numbers explanation
 *
 * \return      Random number between [0, 2^32 - 1]
 */
uint32_t randqd_uint32()
{    
    rqd_seed = (uint32_t) (1664525UL * rqd_seed + 1013904223UL);
    return rqd_seed;
}

/**
 * Return a random number in the range [0, 1)
 *
 * \return      Random number between [0, 1)
 */
double randqd_double()
{
    return randqd_uint32() / (double) (1L << 32);
}
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



/**
 * Return a random sample in the range [0, 2^32 - 1].
 * look in  "Numerical Recipes in C" Second Edition 
 * for the numbers explanation
 *
 * \param       x   PRNG state
 * \return      Random number between [0, 2^32 - 1]
 */
inline uint32_t randqd_uint32(uint32_t x)
{
    return (uint32_t) (1664525UL * x + 1013904223UL);
}

/**
 * Return a random number in the range [0, 1)
 *
 * \param       x   PRNG state
 * \return      Random number between [0, 1)
 */
inline double randqd_double(uint32_t x)
{
    return randqd_uint32(x) / (double) (1L << 32);
}


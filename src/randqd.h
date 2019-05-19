/**
 * Copyright (c) 2019 Alessandro Cudazzo
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See `LICENCE` file for details.
 */

#ifndef RANDQD_H
#define RANDQD_H

#include <stdint.h>

#define RANDQD_VERSION "0.3"


/*
*********************************************************************
*             A better way to generate a random number              *
*********************************************************************
*
*   PRNG (Pseudo-Random Number Generators):
*   First, and perhaps most important: be very, very suspicious of a 
*   system-supplied rand(). System-supplied rand()s are almost always 
*   linear congruential generators that will eventually repeat itself,
*   with a period.
*
*   A better way to generate a random number is th "Quick and Dirty" 
*   Generators, described in  "Numerical Recipes in C" Second Edition 
*   at page 284, relies on 32-bit arithmetic.
*   It's works on a 32bit machine, so we need to use uint32_t.
*/

/**
 * Init the First Seed
 *
 * \start_seed      Started seed
 */
void srandqd(uint32_t start_seed);

/**
 * Returns a random value within the range [0, 2^32 - 1]
 *
 * \return      Random number between [0, 2^32 - 1]
 */
uint32_t randqd_uint32();

/**
 * Returns a random value within the range [0, 1)
 *
 * \return      Random number between [0, 1)
 */
double randqd_double();



#endif

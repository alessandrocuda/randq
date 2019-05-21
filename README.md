# randq.c
randq stand for "random quick": Quick Pseudo-Random Number Generators (PRNGs) Lib developed in C99.
## A better way to generate a random number    

PRNG (Pseudo-Random Number Generators):
First, and perhaps most important: be very, very suspicious of a 
system-supplied rand(). System-supplied rand()s are almost always 
linear congruential generators that will eventually repeat itself,
with a period.
So, never use the built-in generators in the C and C++ languages, 
especially rand  and srand. These have no standard implementation 
and are often badly flawed.
 
This Library provides two  better way to generate a random number:
-   The **"suspenders-and-belt, full-body-armor, never-any-doubt"**
         generator  laying on 64bit and respect all the constraints
            defined in "Numerical Recipes" Third Edition at page 342.
            The period of the generator is 3.138*10^57.

            srandq64, randq64_uint64, randq64_uint32, randq64_double;
 
-   the **"Quick and Dirty"** Generators laying on 32bit defined in
            "Numerical Recipes in C" Second Edition. Use it only in very
            special cases, where speed is critical and if you don’t need
            a period longer than 2^32.
            
            srandqd, randqd_uint32 and randq_double;
 
> This generators are not designed for cryptographic use

## Table of Contents 
- [Usage](#usage)
- [Testing](#testing)
- [Todo](#todo)
- [Support](#support)
- [License](#license)


## Usage
``randq.c`` and ``randq.h`` should be dropped into an existing project and compiled along with it. The library provides 7 functions for generate a random number:

> Function that use "suspenders-and-belt, full-body-armor,never-any-doubt" method:
```c

void srandq64(uint64_t start_seed);

uint64_t randq64_uint64();

uint32_t randq64_uint32();

double randq64_double();
```

- **void srandq64(uint64_t start_seed)**:
Allow to initialize the starting seed for the randq library, accept a ``uint64_t`` value.

- **uint64_t randq64_uint64()**: Returns a unsigned long long int random value within the range [0, 2^64 - 1]

- **uuint32_t randq64_uint32()**: Returns a unsigned long int random value within the range [0, 2^32 - 1]

- **double randq64_double()**: Returns a double random value within the range [0, 1)


> Function that use "Quick and Dirty" method:
```c
void srandqd(uint32_t start_seed);

uint32_t randqd_uint32();

double randqd_double();
```

- **void srandqd(uint32_t start_seed)**: Allow to initialize the starting seed for the randq library, accept a ``uint32_t`` value.

- **uint32_t randqd_uint32()**: Returns a unsigned long int random value within the range [0, 2^32 - 1]

- **double randqd_double()**: Returns a double random value within the range [0, 1)

### Examples
```c
/*
 * With Quick and Dirty Generator - randqd_
 */

// v1 in the range 0 to 99
uint32_t v1 = randqd_uint32() % 100; 
// v2 in the range 1985-2014         
uint32_t v2 = randqd_uint32() % 30 + 1985;          
// v3 in the range -1 to 1
double v3 = randqdd_double()* 2.0 - 1.0;

/*
 * With "suspenders-and-belt, full-body-armor, never-any-doubt" 
 * Generator - randq64_
 */

// v1 in the range 0 to 99
uint64_t v4 = randq64_uint64() % 100;                
// v2 in the range 1985-2014         
uint64_t v5 = randq64_uint32() % 100 + 1;            
// v3 in the range -1 to 1
double v6 = randq64_double()* 2.0 - 1.0;
```
## Testing
This repo proviedes a unit test done with CMocka and some examples. 
```bash
./randqd_usecase    # show some examples
./randqd_utest      # unit test performed with CMocka
```
### System requirements for building and running ``randqd_utest.c``
To build ``randqd_utest``  you need CMocka as unit testing framework for C installed on your system:
#### MacOS with Homebrew
```bash
brew install cmocka
```
#### Linux Ubuntu/Debian
```bash
apt-get install libcmocka-dev 
```

### BUILD
These instructions will get you a copy of ``randqd_utest`` and ``randqd_example`` up and running on your local machine for testing purposes.

```bash
git clone https://github.com/alessandrocuda/randq.git
cd randq/
make                # or 'make all'
```

or build just ``randqd_utest``  or ``randqd_example``
```bash
make randqd_utest              
make randqd_example
```

## TODO
- [ ] add Thread safe to all functions

## Support

Reach out to me at one of the following places!

- Website at <a href="https://alessandrocudazzo.it" target="_blank">Alessandro Cudazzo</a>.
- Twitter at <a href="http://twitter.com/alessandrocuda" target="_blank">`@alessandrocuda`</a>

## License
[![License](http://img.shields.io/:license-mit-blue.svg?style=flat-square)](http://badges.mit-license.org)

This library is free software; you can redistribute it and/or modify it under
the terms of the MIT license. 

- **[MIT license](LICENSE)**
- Copyright 2019 © <a href="https://alessandrocudazzo.it" target="_blank">Alessandro Cudazzo</a>.
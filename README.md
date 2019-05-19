# randqd.c
Pseudo-Random Number Generators (PRNGs): using "quick and dirty" linear congruential method developed in C.

## A better way to generate a random number    

First, and perhaps most important: be very, very suspicious of a 
system-supplied rand(). System-supplied rand()s are almost always 
linear congruential generators that will eventually repeat itself,
with a period.
A better way to generate a random number is th "Quick and Dirty" 
Generators, described in  "Numerical Recipes in C" Second Edition 
at page 284, relies on 32-bit arithmetic.
It's works on a 32bit machine, so we need to use uint32_t.

## Table of Contents (Optional)

> If you're `README` has a lot of info, section headers might be nice.

- [Usage](#usage)
- [Testing](#testing)
- [Support](#support)
- [License](#license)


## Usage
``randqd.c`` and ``randqd``.h should be dropped into an existing project and compiled along with it. The library provides 3 functions for generate a random number:

```c
void srandqd(uint32_t start_seed);

uint32_t randqd_uint32();

double randqd_double();
```

#### - void srandqd(uint32_t start_seed)
Allow to initialize the starting seed for the randqd library, accept a ``uint32_t`` value.

#### - uint32_t randqd_uint32();
Returns a unsigned long int random value within the range [0, 2^32 - 1]

#### - double randqd_double();
Returns a double random value within the range [0, 1)

### Examples
```c
// v1 in the range 0 to 99
uint32_t v1 = randqd_uint32() % 100;
// v2 in the range 1 to 100
uint32_t v2 = randqd_uint32() % 100 + 1;    
// v3 in the range 1985-2014         
uint32_t v3 = randqd_uint32() % 30 + 1985;          
// v4 in the range -1 to 1
double v4 = randqd_double()* 2.0 - 1.0;
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
git clone https://github.com/alessandrocuda/randqd.git
cd randqd/
make                # or 'make all'
```

or build just ``randqd_utest``  or ``randqd_example``
```bash
make randqd_utest              
make randqd_example
```
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
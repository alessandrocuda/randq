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

## Usage
randqd.c and randqd.h should be dropped into an existing project and compiled along with it. The library provides 3 functions for generate a random number:

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

## Testing
This repo proviedes a unit test done with CMocka and some usecase. 
```bash
./randqd_usecase    # show some usecase
./randqd_utest      # unit test performed with CMocka
```
### Dependency
To build ``randqd_utest``  you need CMocka installed on your system:
#### MacOS with Homebrew
```bash
brew install cmocka
```
#### Linux Ubuntu/Debian

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

```bash
git clone https://github.com/alessandrocuda/randqd.git
cd randqd/
make                # or 'make all'
```

## License
This library is free software; you can redistribute it and/or modify it under
the terms of the MIT license. 

[MIT][mit-license] © [Alessandro Cudazzo][alessandrocuda]

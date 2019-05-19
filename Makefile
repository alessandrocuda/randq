#
# 'make depend' 		uses makedepend to automatically generate dependencies 
#               		(dependencies are added to end of Makefile)
# 'make' or 'make all'	build executable file 'randqd_example' and 'randqd_utest'
# 'make randqd_example'		build executable file 'randqd_example'
# 'make randqd_utest'	build executable file 'randqd_utest'
# 'make clean'  		removes all .o 
# 'make clean_all'  	removes all .o and executable files
#

# define C compiler to use
CC = gcc

# define any compile-time flags
CFLAGS = -std=c99 -Wall -g

# define any directories containing header files other than /usr/include
#
INCLUDES =

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS = 
LDFLAGS = -lm -lcmocka

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
LIBS = 


# define the C source files
SOURCEDIR := .
#COM_SOURCES := $(shell find $(SOURCEDIR) -name '*.c')
COM_SOURCES := $(SOURCEDIR)/src/randqd.c
RANDQD_TEST_SOURCES := $(SOURCEDIR)/randqd_utest.c  
RANDQD_GEN_SOURCES := $(SOURCEDIR)/randqd_example.c
# define the C object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
COM_OBJS = $(COM_SOURCES:.c=.o)
RANDQD_GEN_OBJS = $(RANDQD_GEN_SOURCES:.c=.o)
RANDQD_TEST_OBJS = $(RANDQD_TEST_SOURCES:.c=.o)
ALL_OBJ = $(COM_OBJS) $(RANDQD_GEN_OBJS) $(RANDQD_TEST_OBJS)

# define the executable file 
RANDQD_GEN = randqd_example
RANDQD_TEST = randqd_utest

#
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY: depend clean clean_all

all:    $(RANDQD_GEN) $(RANDQD_TEST)
		@echo randqd_usecase and randqd_utest are been compiled

$(RANDQD_GEN): $(COM_OBJS) $(RANDQD_GEN_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(RANDQD_GEN) $(COM_OBJS) $(RANDQD_GEN_OBJS)  $(LIBS)
$(RANDQD_TEST): $(COM_OBJS) $(RANDQD_TEST_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(RANDQD_TEST) $(COM_OBJS) $(RANDQD_TEST_OBJS) $(LFLAGS) $(LIBS) $(LDFLAGS)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
#	$(RM) -v *.o *~ $(MAIN) $(ALL_OBJ)
	$(RM) -v $(ALL_OBJ)
clean_all:
	$(RM) -v $(MAIN) $(ALL_OBJ) $(RANDQD_GEN) $(RANDQD_TEST)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
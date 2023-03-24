#!/bin/bash

# Compile all .c files into object files
gcc -Wall -Werror -fpic -c *.c

# Create the dynamic library
gcc -shared -o liball.so *.o

# Cleanup: remove the object files
rm *.o

#!/bin/bash

# Compile all .c files into object files
gcc -fpic -c *.c -o *.o

# Create the dynamic library
gcc -shared -o liball.so *.o

# Cleanup: remove the object files
rm *.o

sudo ldconfig

#!/bin/bash

# Compile all .c files into object files
gcc -fpic -c dynamic.c -o dynamic.o

# Create the dynamic library
gcc -shared -o liball.so dynamic.o

# Cleanup: remove the object files
rm *.o

sudo ldconfig

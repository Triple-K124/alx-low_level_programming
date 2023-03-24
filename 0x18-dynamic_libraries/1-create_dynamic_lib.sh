#!/bin/bash

# Compile all .c files into object files
for file in *.c
do
    gcc -Wall -Werror -fpic -c "$file"
done

# Create the dynamic library
gcc -shared -o liball.so *.o

# Cleanup: remove the object files
rm *.o


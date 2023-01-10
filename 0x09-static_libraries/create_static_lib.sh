#!/bin/bash
gcc -c liball.c -o liball.o
ar rcs liball.a liball.o

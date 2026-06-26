#!/bin/sh
 
#  Compile and assemble, but do not link
g++ -std=c++23 -c add.cpp


# read ELF file (.o)
readelf -a ./add.o
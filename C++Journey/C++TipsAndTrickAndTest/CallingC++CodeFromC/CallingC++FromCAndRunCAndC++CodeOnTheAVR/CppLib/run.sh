#!/bin/sh

rm ./*.a 
rm ./*.o

LIBNAME=libCppLib

echo "Start Compile ${LIBNAME}.a "

# just dump a C++ binary object
avr-g++ -std=c++03 -mmcu=attiny2313 -Os  -c CppLib.cpp -o ${LIBNAME}.o

# just build a C++ static library 
avr-ar rcs ${LIBNAME}.a ./${LIBNAME}.o


echo "${LIBNAME}.a is created !"

export LIBNAME
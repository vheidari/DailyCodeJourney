#!/bin/sh

rm ./*.a
rm ./*.o

LIBNAME=CppMathLib

echo "Start Compiling  ${LIBNAME}"


avr-g++ -mmcu=attiny2313 -Os -DF_CPU=1000000UL  -c ${LIBNAME}.cpp -o ${LIBNAME}.o
avr-ar rcs  ./lib${LIBNAME}.a ./${LIBNAME}.o


echo "${LIBNAME} is created! job is done"
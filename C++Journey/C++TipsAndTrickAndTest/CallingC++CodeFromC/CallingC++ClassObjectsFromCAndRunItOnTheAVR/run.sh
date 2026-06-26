#!/bin/sh
CPPLIBNAME=CppMathLib
CPPLIBDIR=./CppMathLib


cd ${CPPLIBDIR}

./run.sh

cd .. 


avr-g++  -std=c++03 -I ${CPPLIBDIR} -mmcu=attiny2313 -Os -DF_CPU=1000000UL  -o main.elf main.c -L${CPPLIBDIR} -l${CPPLIBNAME} 
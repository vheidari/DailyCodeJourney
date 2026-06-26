#!/bin/sh


LIBNAME=LibOne

rm ./lib${LIBNAME}.a
rm ./${LIBNAME}.o


g++ -c -std=c++23 ./${LIBNAME}.cpp -o ${LIBNAME}.o

ar rcs lib${LIBNAME}.a ${LIBNAME}.o


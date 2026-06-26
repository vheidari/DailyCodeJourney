#!/bin/sh
 
CPPLIB=./CppLib
LIBRUN="./run.sh"
CPPLIBNAME="CppLib"

# go to CppLib directory
cd ${CPPLIB}

# run run.sh
${LIBRUN}
 
# back to root directory
cd ..


echo "------------------------------------------------------------"
echo 

echo "Start Compile main.c and Linking ${CPPLIBNAME}"

# compile and linking c and cpp through avr-gcc
avr-g++ -I ./CppLib -mmcu=attiny2313 -Os -DF_CPU=1000000UL -o main.elf main.c -L./CppLib -l${CPPLIBNAME}


echo "Job is done, main.elf is made succesfully ;)"

 
echo "------------------------------------------------------------"
echo 

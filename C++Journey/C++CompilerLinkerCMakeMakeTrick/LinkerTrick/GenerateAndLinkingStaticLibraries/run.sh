#!/bin/sh

LIBSDIR=CppStaticLibraries


echo "Start Build Project and Linking LibOne and LibTwo to our C++ Appliction"

cd ./${LIBSDIR}/LibOne
./run.sh

cd ../..

cd ./${LIBSDIR}/LibTwo
./run.sh

cd ../..

g++ -std=c++23 \
	 -I ./${LIBSDIR}/LibOne/Include \
	 -I ./${LIBSDIR}/LibTwo/Include \
	 -L ./${LIBSDIR}/LibOne \
	 -L ./${LIBSDIR}/LibTwo \
	 main.cpp -o main.o  -lLibOne -lLibTwo

echo "Job is done !"
echo 
echo "Start running main.o"
echo 

./main.o

echo
echo "Finish ;)"
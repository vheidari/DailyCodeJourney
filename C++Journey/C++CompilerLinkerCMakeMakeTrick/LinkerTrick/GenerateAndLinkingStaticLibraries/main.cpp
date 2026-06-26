#include <iostream>
#include "./CppStaticLibraries/LibOne/Include/LibOne.hpp"
#include "./CppStaticLibraries/LibTwo/Include/LibTwo.hpp"

int main(int argc, char const *argv[])
{
	libOne();
	libTwo();
	return 0;
}
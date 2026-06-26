#include <avr/io.h>
#include "./CppMathLib/CppMathLib.hpp"

#define true 1

int main(int argc, char const *argv[])
{
	/* AVR Code Here */


	/* Create a C++ Object through CppMathLib.hpp interface */
	CppMathLib* cppMathLibObj = createCppMathLibObj();

	/* Add/Subtract/Multiply/Devision two number through CppMathLib */
	int addResult = callCppMathLibCppAdd(cppMathLibObj, 10, 15);
	int subtractResult = callCppMathLibCppSubtract(cppMathLibObj, 5, 3);
	int multiplyResult = callCppMathLibCppMultiply(cppMathLibObj, 3, 6);
	int devisionResult = callCppMathLibCppDevision(cppMathLibObj, 15, 3);


	while(true) {
		/* AVR Infinity Loop*/
	}

	destroyCppMathLibObj(cppMathLibObj);
	return 0;
}
#include <avr/io.h>

#include "./CppLib/CppLib.hpp"

#define true 1
int main(int argc, char const *argv[])
{
	/* AVR Main Code */


	/* Calling Cpp Code */
	int cppAddResult = cppAdd(10,10);
	int cppSubtractResult = cppSubtract(20,10);
	int cppMultiplyResult = cppMultiply(2, 6);
	int cppDevisionResult = cppDevision(10, 2);

	int addIntThroughCppTemplate  				= cppAddTemplateBaseInt(99,1);
	float addFloatThroughCppTemplate  			= cppAddTemplateBaseFloat(9.5, 15.5);
	double addDoubleThroughCppTemplate  		= cppAddTemplateBaseDouble(912.5000551, 1515.5616416);

	int subtractIntThroughCppTemplate  	    	= cppSubtractTemplateBaseInt(99,1);
	float subtractFloatThroughCppTemplate   	= cppSubtractTemplateBaseFloat(9.5, 15.5);
	double subtractDoubleThroughCppTemplate  	= cppSubtractTemplateBaseDouble(912.5000551, 1515.5616416);

	int multiplyIntThroughCppTemplate  			= cppMultiplyTemplateBaseInt(99,1);
	float multiplyFloatThroughCppTemplate  		= cppMultiplyTemplateBaseFloat(9.5, 15.5);
	double multiplyDoubleThroughCppTemplate  	= cppMultiplyTemplateBaseDouble(912.5000551, 1515.5616416);

	int devisionIntThroughCppTemplate  			= cppDevisionTemplateBaseInt(99,1);
	float devisionFloatThroughCppTemplate  		= cppDevisionTemplateBaseFloat(9.5, 15.5);
	double devisionDoubleThroughCppTemplate  	= cppDevisionTemplateBaseDouble(912.5000551, 1515.5616416);

	while(true) {

		// AVR Loop
	
	}
	return 0;
}
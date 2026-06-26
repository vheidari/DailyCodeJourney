
#include "./CppMathLib.hpp"
#include <stdlib.h> // avr-libc include for malloc and free

/* C++ CppMathLib class */
class CppMathLib {
public:
	 CppMathLib(){}
	 // ~CppMathLib(){}

	int cppAdd(int a, int b) {
		return a + b;
	}

	int cppSubtract(int a, int b) {
		return a - b;
	}

	int cppMultiply(int a, int b) {
		return a * b;
	}

	int cppDevision(int a, int b) {
		return a / b;
	}

};


// List of C interface function that we use to wrappe C++ CppMathLib class
// each function responsiable to handel a part or method on  CppMathLib


CppMathLib* createCppMathLibObj(void) {
	// casting void* to CppMathLib* through (CppMathLib*)malloc
	return (CppMathLib*)malloc(sizeof(CppMathLib));
}

void destroyCppMathLibObj(CppMathLib* object){
	free(object);
}
	
int callCppMathLibCppAdd(CppMathLib* object, int a, int b){
	return object->cppAdd(a , b);
}
	
int callCppMathLibCppSubtract(CppMathLib* object, int a, int b){
	return object->cppSubtract(a, b);
}
	
int callCppMathLibCppMultiply(CppMathLib* object, int a, int b){
	return object->cppMultiply(a, b);
}
	
int callCppMathLibCppDevision(CppMathLib* object, int a, int b){
	return object->cppDevision(a, b);
}



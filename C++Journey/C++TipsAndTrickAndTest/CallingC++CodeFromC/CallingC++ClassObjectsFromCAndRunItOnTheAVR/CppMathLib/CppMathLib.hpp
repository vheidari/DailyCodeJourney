#ifndef CPPMATHLIB__HPP
#define CPPMATHLIB__HPP


#ifdef __cplusplus
extern "C" {
#endif
	
	// Abstract fake CppMathLib as Interface through typedef and struct
	typedef struct CppMathLib CppMathLib;

	CppMathLib* createCppMathLibObj(void);
	void destroyCppMathLibObj(CppMathLib* object);
	int callCppMathLibCppAdd(CppMathLib* object, int a, int b);
	int callCppMathLibCppSubtract(CppMathLib* object, int a, int b);
	int callCppMathLibCppMultiply(CppMathLib* object, int a, int b);
	int callCppMathLibCppDevision(CppMathLib* object, int a, int b);

#ifdef __cplusplus
}
#endif 

#endif
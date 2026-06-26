
#include "./CppLib.hpp"


// Simple C++ Functions 
int cppAdd(int a, int b) {
	return a + b;
}

float cppAdd(float a, float b) {
	return a + b;
}

int cppSubtract(int a, int b) {
	return a - b;
}

int cppMultiply(int a, int b) {
	return a * b;
}

int cppDevision(int a, int b) {
	return (int)a / b;
}

// ---------------------------------------------------------------


// C++ Template base Functions

template<typename T>
T  cppAddTemplateBase(T a, T b) {
	return a + b;
}


// define Explicit type for each type function
template int cppAddTemplateBase<int>(int a, int b);
template float cppAddTemplateBase<float>(float a, float b);
template double cppAddTemplateBase<double>(double a, double b);


int cppAddTemplateBaseInt(int a, int b) {
	cppAddTemplateBase<int>(a, b);
}

float cppAddTemplateBaseFloat(float a, float b) {
	cppAddTemplateBase<float>(a, b);
}


double cppAddTemplateBaseDouble(double a, double b) {
	return cppAddTemplateBase<double>(a, b);
}

// ---------------------------------------------------------------


template<typename T>
T cppSubtractTemplateBase(T a, T b) {
	return a - b;
}

// define Explicit type for each type function
template int cppSubtractTemplateBase<int>(int a, int b);
template float cppSubtractTemplateBase<float>(float a, float b);
template double cppSubtractTemplateBase<double>(double a, double b);


int cppSubtractTemplateBaseInt(int a, int b) {
	cppSubtractTemplateBase<int>(a, b);
}

float cppSubtractTemplateBaseFloat(float a, float b) {
	cppSubtractTemplateBase<float>(a, b);
}


double cppSubtractTemplateBaseDouble(double a, double b) {
	return cppSubtractTemplateBase<double>(a, b);
}


// ---------------------------------------------------------------


template<typename T>
T cppMultiplyTemplateBase(T a, T b) {
	return a * b;
}


// define Explicit type for each type function
template int cppMultiplyTemplateBase<int>(int a, int b);
template float cppMultiplyTemplateBase<float>(float a, float b);
template double cppMultiplyTemplateBase<double>(double a, double b);

int cppMultiplyTemplateBaseInt(int a, int b) {
	cppMultiplyTemplateBase<int>(a, b);
}

float cppMultiplyTemplateBaseFloat(float a, float b) {
	cppMultiplyTemplateBase<float>(a, b);
}


double cppMultiplyTemplateBaseDouble(double a, double b) {
	return cppMultiplyTemplateBase<double>(a, b);
}



// ---------------------------------------------------------------

template<typename T>
T cppDevisionTemplateBase(T a, T b) {
	return a / b;
}


// define Explicit type for each type function
template int cppDevisionTemplateBase<int>(int a, int b);
template float cppDevisionTemplateBase<float>(float a, float b);
template double cppDevisionTemplateBase<double>(double a, double b);


int cppDevisionTemplateBaseInt(int a, int b) {
	cppDevisionTemplateBase<int>(a, b);
}

float cppDevisionTemplateBaseFloat(float a, float b) {
	cppDevisionTemplateBase<float>(a, b);
}


double cppDevisionTemplateBaseDouble(double a, double b) {
	return cppDevisionTemplateBase<double>(a, b);
}



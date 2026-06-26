#include <iostream>
#include "./GraphicAPI.hpp"

// Here in a simple project we will go to learn and desing a  simple C++ Graphic API through 
// "Raw Function Pointers" -> "type (*FunctionName)(ArgOne, ArgTwo)" like -> "void (*)()" or "int (*pFuncName)(int, int , int)"


int main(int argc, char* argv[]) {

	GraphicAPI gf;

	void (*myCircleDrawFunction)();
	void (*myRectangleDrawFunction)();

	gf.setBackendAPI("DirectX");
	gf.drawCircle(&myCircleDrawFunction);
	gf.drawRectangle(&myRectangleDrawFunction);

	myCircleDrawFunction();
	myRectangleDrawFunction();


	// Getting API through tow function pointer and function pointer casting -> (void(*)()) 
	void (*getDrawCircle)() = (void(*)())gf.getDrawCircle();
	void (*getDrawRectangle)() = (void(*)())gf.getDrawRectangle();
	getDrawCircle();
	getDrawRectangle();

	return 0;
}
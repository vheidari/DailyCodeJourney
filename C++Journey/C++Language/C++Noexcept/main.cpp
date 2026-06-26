#include <iostream>

// lets learn about noexcept specifier (since C++11)
// noexcept :
// 	- when we add it to a function or method in C++ it indication this function will never throw a exceptions.
//  Note :
// 	- As we know we use throw exception inside try{}catch(){} operation.
// 	  when we add noexcept we say hey this function  will never throw a exception
void printAscciLetters() noexcept {
	char letters = ' ';


	for (int i{' '}; i <= '~'; i++) {
		// ((i + 1) % 32 ? ' ': '\n') :
		//  - 32 letter per line 
		// 
		// static_cast help us to convert i from a decimal number to a char
		std::cout << static_cast<char>(i) << ( (i + 1) % 32 ? ' ': '\n' );
	}

	std::cout << '\n';
}

// ---------------------------------------------------------------

 
// below function is a function that throw a exception and we should call it in a try/catch statmenet.
// rather than it will terminat C++ program. as I mention we should don't call it directly.
//
// we can use "throw: in our functions for many part of an appliction and call these function in a try/catch block
// to hanlde errors that throw drop from inside a function.
//
// Note :
// something that I should mention using throw inside a function will make more overhead in C++ program and their will slow down C++ Program 
void throwException() {
	throw "Hey I Throw this exception";
}


// ---------------------------------------------------------------


void dontThrowAExceptionInsideThisFuction() noexcept {
	// Function that labeled as noexcept should not throw a exceptoin throw throw

 	/* throw "Bad Things that you can do here is that you throw a exception here" */

	std::cout << "There is no exception here :) \n";
}	


// ---------------------------------------------------------------


// lets learn about noexcpet in Class base 

class FooWithException {
public:
	FooWithException(){};
	~FooWithException(){}
	static void  callMeDirectly() noexcept {
		std::cout << "I'm a static method and my name is : " << __func__ << ", and you call me directly from \n";
	} 
};




int main(int argc, char *argv[]) {

	printAscciLetters();
	
	// Each function that throw a excaption should invoke in a try/catch block
	try {
		throwException();
	} catch(const char* error) {
		std::cout << error << std::endl;
	}

	// You can't call throwException function directly, it will terminat you C++ program
	// Note:
	//  - I should mention that we can call directly a function that throw an exception but if throw inside the 
	//  - Function handeling properly. they can run until throw exception drop its exception. its best practice to call 
	//  - Any function that throw a excption inside a try/catch block.
	/* throwException(); */


	FooWithException::callMeDirectly();

	return 0;
}
#include <iostream>
#include <iomanip>
#include <type_traits>
#include <limits>

// decleare a template functions for function AddNumber
template<typename T>
T addNumber(T a, T b ) {
	return a + b;
}

// test AddNumber function
void testAddNumber() {
	int ia{}, ib{};
	ia = 10;
	ib = 10;
	std::cout << "result ia + ib = " << addNumber(ia , ib) << "\n";

	float fa{}, fb{};
	fa = 11.5;
	fb = 11.8;
	std::cout << "result fa + fb = " << addNumber(fa , fb) << "\n";
}


// ---------------------------------------------------------------


// decleare a template class for Class Foo
template<typename T>
class  Foo
{
public:
	 Foo(T input):FooValue(input){};
	~ Foo() {
		// constexpr here play a critical role as compile time calculation
		if constexpr (std::is_arithmetic_v<T>) {
			std::cout << "You pass : " << FooValue << " to Foo class." << std::endl;
		} else {
			std::cout << "You pass : " << std::quoted(FooValue) << " to Foo class." << std::endl;
		}
	};
private:
	T FooValue;
};

// test Foo class
void testFoo() {
	Foo f("Hello World!");

	Foo ff(1+2);
}


// ---------------------------------------------------------------




int main(int argc, char *argv[]) {

	testAddNumber();
	testFoo();

	return 0;
}
#include <iostream>
#include <type_traits> // for std::is_class_v


// lets define a concept  and use this concept in our program to identify class objects
// Note:
//  - Concepts are compile base time and they their value is compute during compulation.
//  - We use concepts as template interface
//  - We can use concept directly in our class or functions
template<class T>
concept isItAClass = std::is_class_v<T>;


// Defien some classe 
class Foo {};
struct Bar{};


// Test isItAClass concept
void testConcept() {

	if (isItAClass<Foo>) {
		std::cout << "Yes, Foo is a class !\n";
	} else {
		std::cout << "No, Foo is not a class !\n";
	}


	if (isItAClass<int>) {
		std::cout << "Yes, int is a class !\n";
	} else {
		std::cout << "No, int is not a class !\n";
	}


	if (isItAClass<float>) {
		std::cout << "Yes, float is a class !\n";
	} else {
		std::cout << "No, float is not a class !\n";
	}

	if (isItAClass<Bar>) {
		std::cout << "Yes, Bar is a class !\n";
	} else {
		std::cout << "No, Bar is not a class !\n";
	}


}

// ---------------------------------------------------------------


// define first concept through requires expression  
template <typename T>
concept AddAble = requires(T a, T b) {
	a + b;
};

// use Addable concept in template instead of typename 
template<AddAble VType>
VType addTogether(VType a, VType b) {
	return a + b;
}

void testAddTogether() {
	std::cout << addTogether(1, 3) << std::endl;
	std::cout << addTogether(10.5, 15.15) << std::endl;
	std::cout << addTogether(0.22225551616, 0.641649949) << std::endl;
	std::cout << addTogether(696.0, 0.641649949) << std::endl;
}

// ---------------------------------------------------------------


// define secound concept through require expression
template<typename FloatAddable, typename IntAddable = FloatAddable>
concept GenericAdd = requires(FloatAddable a, IntAddable b) {
	a + b;
}; 


// use GenricAdd concept in template instead of typename
template<GenericAdd T, GenericAdd I>
auto AddTogetherThroughGenericAdd(T a, I b) {
	return a + b;
}


void testAddTogetherThroughGenericAdd() {
	std::cout << AddTogetherThroughGenericAdd(150, 300) << std::endl;
	std::cout << AddTogetherThroughGenericAdd(0.5, 60) << std::endl;
	std::cout << AddTogetherThroughGenericAdd(65, 0.333) << std::endl;
	std::cout << AddTogetherThroughGenericAdd(0.99, 0.0001) << std::endl;
	std::cout << AddTogetherThroughGenericAdd(10.5 ,19) << std::endl;
}

// ---------------------------------------------------------------



int main(int argc, char *argv[]) {

	testConcept();
	testAddTogether();
	testAddTogetherThroughGenericAdd();

	return 0;
}
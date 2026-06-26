#include <iostream>
#include <utility>  // for std::exchange
#include <string>	// for std::string 
#include <iomanip>  // for std::quoted


// Usecase :
// - A Movable Class or Struct Help us to move ownership of a big fat Object in memory to anothers.
// 	 just think about a game object in memory that reserved around 4G of the memory. throgh move semantic we will easily move old ownership
// 	 of the Object and will pass it to a new object that we are define. this featrue "move" help us to prevent any copy and memory allocation and 
//   speed up our program. 



// lets add move simantice to our class 
class Foo {
public:
	// C++ Default constructor
	Foo():FooName("FooFoo"), FooAge(10){};
	
	// Add move simantic logic to Foo class through rvalue refrence 
	// Explanation :
	// 	- Foo constructor could get a Foo object as rvalue reference something like "Foo&& sameFoo" -> rvalue refrence : "Foo&&" 
	//  - if an object implemented move simantic , std::move will use it , something like below example
	//  - In below example we initialize FooName and FooAge through  std::move and std::exchange
	//  - std::move in below example move FooName from sameFoo object and assign it to FooName
	//  - std::exchange in below example updated FooAge in sameFoo with 0 and returned last value of FooAge and assigned it to FooAge 
	Foo(Foo&& sameFoo) noexcept : FooName(std::move(sameFoo.FooName)), FooAge(std::exchange(sameFoo.FooAge, 0)){}

	// public print Method
	void printFooName() {
		std::cout << "FooName : " << std::quoted(FooName) << "\n";
		drawLine();
	}
	void printFooAge() {
		std::cout << "FooAge : " << FooAge << "\n";
		drawLine();
	}


private:
	std::string FooName;
	int FooAge;

	void drawLine() {
		std::cout << "--------------------------------------\n";
	}
};



int main(int argc, const char *argv[]) {
	Foo f;
	std::cout << "Print f object values before move  : \n";
	f.printFooName();
	f.printFooAge();

	 std::cout << "\n";


	// Lets Pass f to new ff through move semantic
	Foo ff = std::move(f);
	std::cout << "Print ff object  values after move f object to ff object  : \n";
	ff.printFooName();
	ff.printFooAge();

	std::cout << "\n";

	// Lets look at f after std::move
	std::cout << "Print f object values after move f object to ff object : \n";
	f.printFooName();
	f.printFooAge();

	std::cout << "Note :\n";
	std::cout << " - FooName in f object is moved!\n";	
	std::cout << " - FooAge in f object is replaced with 0\n";

	return 0;
}
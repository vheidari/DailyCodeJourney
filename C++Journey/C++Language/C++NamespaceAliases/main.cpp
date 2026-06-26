#include <iostream>


// C++ support namesapce and we can define multiple nested namespace 
// C++ also allow us to aliase a long namspace with a small one

namespace First {
	namespace Second {
		namespace Third {
			int aFoo;
		}
	};

};


// lets aliase First::Secound::Third to FST
// below we replace FST with its long version of it (First::Secound::Third)

namespace FST = First::Second::Third;


int main(int argc, char *argv[]) {
	FST::aFoo = 10;

	// These 2 opration is same, but first one is simple, clean and so handy 
	// and second one is long version of it self
	std::cout << FST::aFoo << "\n";
	std::cout << First::Second::Third::aFoo << "\n";

	return 0;

}
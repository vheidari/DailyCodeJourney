#include <iostream>

void addAB(int a, int b) {
	std::cout << "A+B = " << a + b << std::endl;
}


extern "C" int cppmain(void)
{
	std::cout << "Cpp App Main" << std::endl;	
	addAB(10, 12);
	return 0;
}



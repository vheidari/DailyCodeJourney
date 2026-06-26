#include <iostream>
#include <cstdint> // for type uint32_t



void simplePointer() {

	// Simple raw (int/float/double/spacialType) pointer (C base Pointer)
	// 1. Initial with -> type* pointerName;
	// 	1.1 We can pass nullptr as default pointer initilizer
	// 2. Store variable memory address in to Pointer through (&variableName) -> (& -> Reference Address) like : pFoo = &a;
	// 3. Get Pointer address through simple call like : pFoo
	// 4. Get Value that pointer point to its address through (*pFoo) -> (*pointerName) its meaning derefrencing 
	// 5. Update Pointer variable through (*pFoo = newValue)

	// 1 and 1.1
	int* pFoo = nullptr;
	int a = 3;
	
	// 2
	pFoo = &a;
	
	// 3 and 4
	std::cout << "pFoo Address : " << pFoo << ", pFoo value that pFoo pointed : "  << *pFoo << "\n";
	
	// 5
	*pFoo = *pFoo + 1;
	std::cout << "pFoo new value : " << *pFoo << ", pFoo also update \"a\" value : " << a << "\n";

	*pFoo = 10;

	std::cout << "pFoo new value : " << *pFoo << ", pFoo also update \"a\" value : " << a << "\n";

	//-----------------------------------------------

	// lets define on raw pointer for float type
	float b = 12.25;
	float* pBar;
	pBar = &b;
	std::cout << "pBar Address :" << pBar << ", pBar value that pBar pointed : " << *pBar << "\n";
	
	*pBar = 25.12;
	std::cout << "pBar new value : " << *pBar << ", pBar also update \"b\" value : " << b << "\n";

}

void testSimplePointer() {
	simplePointer();
}


//-----------------------------------------------

void simplePointerAsAFunctionArgs(int* pFoo) {
	// Updating pFoo value inside simplePointerAsAFunctionArgs body 
	// Inside the function scope we can access to pFoo address and update its value
	*pFoo += 1;
}

void testSimplePointerAsAFunctionArgs() {
	int pFoo = 1;
	std::cout << "pFoo value Before simplePointerAsFunctionArgs call:" << pFoo << " \n";
	// passing pFoo through & (Reference) symbol
	// Note : & (Reference) on pFoo (&pFoo) will pass pFoo Address to simplePointerAsAFunctionArgs
	simplePointerAsAFunctionArgs(&pFoo);
	simplePointerAsAFunctionArgs(&pFoo);
	simplePointerAsAFunctionArgs(&pFoo);
	simplePointerAsAFunctionArgs(&pFoo);
	std::cout << "pFoo value after 4 time calling simplePointerAsFunctionArgs call : " << pFoo << " \n";
}

//-----------------------------------------------

// Alocating Heap memory through new and a RAW Pointer Example 1
// 1. New keyword in C++ help us to reserve memory in heap
// 2. New keyword return a pointer to type that reserved like something that we do here "new int[size];"
// Function Explanation :
// 	- In "allocateInt" function we get memory size that we need to allocated through new, here spacialy for "int"
//  - then we request for a array of int through "new int[size]"
//  - its return a pointer to address of frist block of memory that before we requested for allocation
//  - inside allocateInt return statement will return a "int*"(that we now as a pointer to a int type) -> int* allocateInt(uint32_t size)
int* allocateInt(uint32_t size) {
	return new int[size];
}

// Note:
// 	- Each time we allocate memory through new and pointer we should delete or deallocate heap memory its mean we must use delete or delete[] to relase memory
// 	- through "delete pointerName" or "delete[] pointerName".
//  - here we use "delete[] get1024IntHeap" because" allocateInt" function allocate a array of int in memory (1024)
void testAllocateManyInt() {
	const uint32_t maxint = 1024;
	// allocate 1024*4 byte in memory => (sizeof(int) * 1024) through "allocateInt" function
	int* get1024IntInHeap = allocateInt(maxint);
	
	// update heap memory blocks through a for loop
	for(uint32_t i{}; i < 1024; i++) {
		get1024IntInHeap[i] = i;
	}

	// display updated memory block through a for loop
	for(uint32_t i{}; i < 1024; i++) {
		std::cout << get1024IntInHeap[i] << ( (i%10 == 0 or (i == maxint-1) ) ? "\n": "-");
	}

	// deallocate (1024*4) byte of memory through delete[]
	delete[] get1024IntInHeap;
}


//-----------------------------------------------

// Alocating Heap memory through new and a RAW Pointer Example 2 
// Note :
//  - Our "allocateAByte" function will return a pointer to a byte of memory in "Heap"
char* allocateAByte() {
	return new char;
}

// Note :
//  - When we allocate memory in heap 100% we should delete or deallocate this memory when our job is done
//  - This is beautifull of C++, that people talk about it :) you can request just for a byte of the memory
void testAllocateAByte() {
	char* myByte = allocateAByte();
	*myByte = 'v';
	std::cout << "Woow we allocate a byte in memory and store  : " << *myByte << " character inside it." << "\n";

	delete myByte;
}

//-----------------------------------------------

// Function Pointer through C++
//  - Function Pointers in C/C++ help us to store a spacific function address in memory to them
//  - then they allow us to call function that they point to it anywhere 

uint32_t addAB(uint32_t a, uint32_t b) {
	return a + b;
}


void callAddABThroughFunctionPointer() {

	// uint32_t (*pAddAB)(uint32_t, uint32_t) -> is a function pointer that is responsiable to store "addAB" 
	// function address in memory then call it with a new like "pAddAB" 

	uint32_t (*pAddAB)(uint32_t, uint32_t) = &addAB;  
	// uint32_t (*pAddAB)(uint32_t, uint32_t) = addAB; /* same as above statement*/  
	std::cout << pAddAB(10,15) << "\n";
}

// Passing a Function to "passFunctionPointerToMe" function as a argument
// Through function pointer we can pass a function address to another functions
void passFunctionPointerToMe(uint32_t (*pAddAB)(uint32_t, uint32_t)) {
	std::cout << pAddAB(5,3) << "\n";
}


void testFunctionPointers() {
	callAddABThroughFunctionPointer();
	passFunctionPointerToMe(addAB);
}


//-----------------------------------------------

// Return a Function Pointer from a function and run it
// Note : 
//  - In this "using myPrintFunction = void (*)();" statement we use "using" to define "myPrintFunction" as a function pointer type 
//  - In rest of program anywhere that we call "myPrintFunction" compiler will know that is a "void (*)()" -> function pointer. 
// Note : here __func__ keyword will return its function name.

void printMe() {
	 std::cout << "You call me ! my name is : " << __func__ << "\n"; 
}

// I use using to define my type as a funciton Pointer
// "void (*)()" in below statment says -> myPrintFunction could store any type of function with this signiture :
// - any void function -> void
// - with any name -> (*)
// - without any argument -> ()
using myPrintFunction = void (*)();

// iWillGiveYouPrintFunction function will return a "void (*)()" that we know it as a function pointer
// iWillGiveYouPrintFunction function will return printMe function address in memory as a function pointer
myPrintFunction iWillGiveYouPrintFunction() {
	return printMe;
}

void testReturnedFunctionPointer() {
	// "void (*getPrintMe)()" is a function pointer that will get "printMe" function address from
	//  "iWillGiveYouPrintFunction" function
	void (*getPrintMe)() = iWillGiveYouPrintFunction();

	getPrintMe();
}



int main(int argc, char *argv[]) {

	testSimplePointer();
	testSimplePointerAsAFunctionArgs();
	testAllocateManyInt();
	testAllocateAByte();
	testFunctionPointers();
	testReturnedFunctionPointer();

	return 0;
}
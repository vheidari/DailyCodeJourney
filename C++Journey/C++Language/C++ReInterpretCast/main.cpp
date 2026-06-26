#include <iostream>
#include <cstdint>
#include <cstring>


// reinterpret_cast operatin is a one of the low level casting operation that allow programer
// Cast or convert 2 unrelated type something that (Raw Pointer Casting -> (typname*)) do in "C"
// We use it in low level programing, file and object serialize and deserialize. 
// We use it to convert and ordering byte for : big endian and little endian.
//
// Note: 
//  - Many resource suggest to programers to be carefull about reinterpret_cast and don't use it. 
//  - Also many resource recommed to programmer that programmer should know about its memory layout then use reinterpret_cast


template<typename T, typename B>
class Foo 
{
public:
	T fooA;
	B fooB;
	Foo(T a, B b): fooA(a), fooB(b){}
	~ Foo(){}

	void setAB(T a, B b){
		fooA = a;
		fooB = b;
	}

	T returnfooA() {
		return fooA;
	}

	B returnfooB() {
		return fooB;
	}

};



// That below example will accidently run and is a bad example of using "reinterpret_cast".
// Why?
// Because it's not a safe conversion type. ...
void badConversion() {
	Foo<int, float> foo(10, 15.5);

	int a = 21;
	float b = 32.2;

	foo.setAB(a, b);

	std::cout << foo.returnfooA() << " : " << foo.returnfooB() << "\n";

	// Bad Bad Bad
	int *getFooAThroughReInterpretCast = reinterpret_cast<int*>(&foo);
	float *getFooBThroughReInterpretCast = reinterpret_cast<float*>(getFooAThroughReInterpretCast);

	std::cout << "This data get through reinterpret_cast : " << *getFooAThroughReInterpretCast << "\n";
	std::cout << "This data get through reinterpret_cast : " << *getFooBThroughReInterpretCast << "\n";
}


// ---------------------------------------------------------------

// Using reinterpret_cast to ordering byte -> little to Big and Big to little endian


uint32_t OrderToLittleEndian(uint32_t orderMetoLittle) {

	uint8_t* getUint32tInByte = reinterpret_cast<uint8_t*>(&orderMetoLittle);
	uint8_t newOrder[sizeof(uint32_t)];
	
	// char* getUint32tInByte = reinterpret_cast<char*>(&orderMetoLittle); // same as above statement
	// char newOrder[sizeof(uint32_t)]; // same as above statement


	newOrder[0] = getUint32tInByte[3];
	newOrder[1] = getUint32tInByte[2];
	newOrder[2] = getUint32tInByte[1];
	newOrder[3] = getUint32tInByte[0];

	uint32_t result;
	std::memcpy(&result, newOrder, sizeof(uint32_t));
	return result;

}

uint32_t OrderToBigEndian(uint32_t orderMeToBig) {
	uint8_t* getUint32tInByte = reinterpret_cast<uint8_t*>(&orderMeToBig);
	uint8_t newOrder[sizeof(uint32_t)];
	newOrder[3] = getUint32tInByte[0];
	newOrder[2] = getUint32tInByte[1];
	newOrder[1] = getUint32tInByte[2];
	newOrder[0] = getUint32tInByte[3];

	uint32_t result;
	std::memcpy(&result, newOrder, sizeof(uint32_t));
	return result;
}

void testLittleAndBigEndian() {
	uint32_t value = 0x12234578;

	// uint32_t bigResult = OrderToBigEndian(value);
 	// std::cout << " : " << std::hex <<  bigResult << "\n";

 	uint32_t littleResult = OrderToLittleEndian(value);
	
	std::cout << "Orginal Value : 0x" << std::hex << value << ", To little : 0x" << std::hex << littleResult << "\n";

	uint32_t bigResult = OrderToLittleEndian(littleResult);
	std::cout << "Little : 0x" << std::hex << littleResult << ", To Big 0x: "<< std::hex << bigResult << "\n";

	std::cout << bigResult[0];

}

// ---------------------------------------------------------------


int main(int argc, char *argv[]) {
	
	badConversion();
	testLittleAndBigEndian();
	
	return 0;
}
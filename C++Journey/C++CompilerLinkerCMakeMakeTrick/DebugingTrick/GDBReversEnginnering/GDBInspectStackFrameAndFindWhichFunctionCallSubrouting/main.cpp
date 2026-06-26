#include <iostream>
#include <string>

void whoCallMe(std::string);
void keyGenrator(std::string str);


void keyGenrator(std::string str) {

	std::string newKey = "";
	
	constexpr unsigned int firstRound 	= 0x0f;
	constexpr unsigned int secoundRound = 0x03;

	// lets generte key code 
	for(int i=0; i < str.size(); i++) {
		
		if(str[i] == '-') {
			newKey += '-';
			continue;
		}
		
		// casting char to a unsigned it -> from `A` to 
		unsigned int getChar = static_cast<unsigned int>(str[i]);
		unsigned int opOne = getChar & firstRound; 		// and string 
		unsigned int opTwo = getChar ^ secoundRound; 	// xor string
		unsigned int opThree = opTwo + secoundRound;    // add with a constance

		newKey += static_cast<char>(opThree);
	}

	whoCallMe(newKey);
}


void whoCallMe(std::string  str) {
	std::cout << str << '\n';
}

int main(int argc, char *argv[]) {

	if(argc != 2) {
		std::cout << "At least you should pass an argument to main.out ex: main <arg1>\n";
		return -1;
	}

	keyGenrator(argv[1]);

	return 0;
}
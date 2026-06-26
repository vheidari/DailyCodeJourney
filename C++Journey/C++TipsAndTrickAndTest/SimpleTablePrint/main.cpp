#include <iostream>


void printTable(const std::string& data , unsigned int selectLine) {
	if(selectLine == 0) std::cout << "┌────────────────┬─────────┐\n";
	if(selectLine <= 2) std::cout << "│ "<< data << "            | " << data <<"     |\n";
	if(selectLine == 2) std::cout << "└────────────────┴─────────┘\n";   
}



constexpr unsigned int maximumLength = 35;

void moreDynamicPrintTable(const std::string& data, unsigned int selectLine) {

	unsigned int columSpace[2]{};
	columSpace[0] = static_cast<unsigned int>( (((maximumLength - data.size()) > maximumLength) || ((maximumLength - data.size()) < 0) ? 0 : (maximumLength - data.size())) );
	columSpace[1] = static_cast<unsigned int>( (((maximumLength - data.size()) > maximumLength) || ((maximumLength - data.size()) < 0) ? 0 : (maximumLength - data.size())) );

	if(selectLine == 0){
		std::cout << "┌";
		for(unsigned int i{}; i <= maximumLength; i++) {
			std::cout << "─"; 
		}
		std::cout << "┬";
		for(unsigned int i{}; i <= maximumLength; i++) {
			std::cout << "─";
		}
		std::cout << "┐\n";
	} 

	if(selectLine <= 2) {
		std::cout << "|" << data.substr(0,(maximumLength - 1));
		for(int i{}; i < columSpace[0] or i <= 0; i++) {
			std::cout << " ";
		}
		std::cout << " | ";
		std::cout << data.substr(0,(maximumLength-1));
		for(int i{}; i < columSpace[1] or i <= 0; i++ ) {
			std::cout << " ";
		}
		std::cout << "|\n";
	}

	if(selectLine == 2 ) {

		std::cout << "└";
		for(unsigned int i{}; i <= maximumLength; i++) {
			std::cout << "─"; 
		}
		std::cout << "┴";
		for(unsigned int i{}; i <= maximumLength; i++) {
			std::cout << "─";
		}
		std::cout << "┘\n";
	};

}

int main(int argc, char *argv[]) {

	std::cout << "Simple print table :\n";
	printTable("one", 0);
	printTable("two", 1);
	printTable("one",1);
	printTable("two",2);


	printTable("one", 0);
	printTable("two", 1);
	printTable("three",1);
	printTable("four",2);
	
	std::cout << "\n------------------------------------------\n\n";
	
	std::cout << "more dynamic print table :\n";
	moreDynamicPrintTable("one", 0);
	moreDynamicPrintTable("two", 1);
	moreDynamicPrintTable("one",1);
	moreDynamicPrintTable("two",2);

	moreDynamicPrintTable("one", 0);
	moreDynamicPrintTable("two", 1);
	moreDynamicPrintTable("three",1);
	moreDynamicPrintTable("four",2);

	moreDynamicPrintTable("Holly", 0);
	moreDynamicPrintTable("Molly", 1);
	moreDynamicPrintTable("Good Guy!",1);
	moreDynamicPrintTable("Bad Guy!",1);
	moreDynamicPrintTable("Good Girl!",1);
	moreDynamicPrintTable("Bad Girl! :)",2);

	// test for more than 14 character
	moreDynamicPrintTable("one one one one one one one one one one one one one one one one ", 0);
	moreDynamicPrintTable("two two two two two two two two two two two two two two two two ", 1);
	moreDynamicPrintTable("three three three three three three three three three three three ",1);
	moreDynamicPrintTable("four four four four four four four four four four four four four ",2);

}
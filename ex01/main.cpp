#include "iter.hpp"

void printInt(int &x) {
	std::cout << x << std::endl;
}

void printString(std::string &s) {
	std::cout << s << std::endl;
}


int main( void ) {
	int arr[] = {1, 2, 3};
	std::string sarr[] = {"hi", "bye"};
	::iter(arr, 3, printInt);
	::iter(sarr, 2, printString);
	return 0;
}
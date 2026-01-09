#include <iostream>
#include <string>
#include "iter.hpp"

// Non-const function (can modify elements)
void incrementInt(int &x)
{
	x++;
}

// Const functions (read-only)
void printInt(const int &x)
{
	std::cout << x << " ";
}

void printString(const std::string &s)
{
	std::cout << s << " ";
}

int main()
{
	std::cout << "=== Test 1: int array (modifiable) ===" << std::endl;

	int intArr[] = {1, 2, 3, 4};

	iter(intArr, 4, incrementInt);
	iter(intArr, 4, printInt);
	std::cout << std::endl;

	std::cout << "\n=== Test 2: const int array (read-only) ===" << std::endl;

	const int constIntArr[] = {10, 20, 30};

	iter(constIntArr, 3, printInt);
	std::cout << std::endl;

	// This should NOT compile
	//iter(constIntArr, 3, incrementInt);

	std::cout << "\n=== Test 3: string array ===" << std::endl;

	std::string strArr[] = {"hello", "world"};

	iter(strArr, 2, printString);
	std::cout << std::endl;

	std::cout << "\n=== Test 4: const string array ===" << std::endl;

	const std::string constStrArr[] = {"bye", "world!"};

	iter(constStrArr, 2, printString);
	std::cout << std::endl;

	return 0;
}

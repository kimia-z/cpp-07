#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"
#include "Array.tpp"

#define MAX_VAL 5

static void fillArrays(Array<int>& arr, int* mirror)
{
	for (int i = 0; i < MAX_VAL; i++)
	{
		int value = rand();
		arr[i] = value;
		mirror[i] = value;
	}
}

static bool compareArrays(Array<int>& arr, const int* mirror)
{
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (arr[i] != mirror[i])
			return false;
	}
	return true;
}

static void printArrays(Array<int>& arr, const int* mirror)
{
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << "mirror[" << i << "] = " << mirror[i] << std::endl;
		std::cout << "Array [" << i << "] = " << arr[i] << std::endl;
	}
}

static bool testCopyConstructor(Array<int>& original)
{
	Array<int> copy(original);

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (copy[i] != original[i])
			return false;
	}

	copy[0] = 42;
	return (original[0] != 42);
}

static bool testCopyAssignment(Array<int>& source)
{
	Array<int> assigned;
	assigned = source;

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (assigned[i] != source[i])
			return false;
	}

	assigned[0] = 99;
	return (source[0] != 99);
}

int main()
{
	srand(time(NULL));

	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];

	fillArrays(numbers, mirror);

	// Copy tests (constructor + assignment)
	{
		if (!testCopyConstructor(numbers))
		{
			std::cerr << "Copy constructor test failed!" << std::endl;
			delete [] mirror;
			return 1;
		}

		if (!testCopyAssignment(numbers))
		{
			std::cerr << "Copy assignment test failed!" << std::endl;
			delete [] mirror;
			return 1;
		}
	}

	// Value consistency test
	if (!compareArrays(numbers, mirror))
	{
		std::cerr << "Values not preserved!" << std::endl;
		delete [] mirror;
		return 1;
	}

	printArrays(numbers, mirror);

	// Out of range tests
	try
	{
		numbers[-1] = 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete [] mirror;
	return 0;
}

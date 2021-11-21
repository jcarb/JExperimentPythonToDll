// MathLibrary.cpp defines the exported functions for the DLL


#include "pch.h"
#include <utility>
#include <limits>
#include "MathLibrary.h"
#include "iostream"

// DLL internal state variables
static unsigned long long previous_;
static unsigned long long current_;
static unsigned index_;

// Init fib sequence
void fibonacci_init(const unsigned long long a, const unsigned long long b)
{
	index_ = 0;
	current_ = a;
	previous_ = b;

	std::cout << "a = " << a << "    b = " << b << std::endl;
}


bool fibonacci_next()
{
	int debugMode = 0;

	std::cout << "At fibonacci_next" << std::endl;

	//while (debugMode == 0)
	{
		int d = 3;
	}


	// check for overflow
	if ((ULLONG_MAX - previous_ < current_) || (UINT_MAX == index_))
	{
		std::cout << "Over flow!" << std::endl;
		return false;
	}


	// Special case when index == 0
	if (index_ > 0)
	{
		previous_ += current_;
	}
	std::swap(current_, previous_);
	++index_;


	return true;

}

// Get current value
unsigned long long fibonacci_current()
{
	std::cout << "                    current value = " << current_ << std::endl;

	return current_;
}

// Get current index 
unsigned fibonacci_index()
{
	return index_;
}


int readStruct(sampleStruct *thisSample)
{
	std::cout << "At readStruct" << std::endl;

	thisSample->Param1 = thisSample->Param1 + 123;
	thisSample->Param2 = thisSample->Param2 + 24440;

	std::cout << thisSample->Param1 << std::endl;
	std::cout << thisSample->Param2 << std::endl;

	int debugMode = 0;
	while (debugMode == 0)
	{
		int d = 3;
	}

	return 1;
}

























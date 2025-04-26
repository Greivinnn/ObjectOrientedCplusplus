// Class 3 - Global Variables and Functions
#include <iostream>
#include "Globals.h"

int gCount = 0;

void Increment(int amount)
{
	gCount += amount;
}

void Print(int value)
{
	std::cout << "Value: [" << value << "]\n";
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		Increment(i);
		Print(gCount);
	}

	return 0;
}
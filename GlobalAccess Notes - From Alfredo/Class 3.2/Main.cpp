// This program demonstrates the use of a global variable and functions to manipulate it.
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
		if (i < 5)
		{
			Increment(GetSum(i));
		}
		else
		{
			Increment(GetDifference(i));
		}
		Print(gCount);
	}

	return 0;
}
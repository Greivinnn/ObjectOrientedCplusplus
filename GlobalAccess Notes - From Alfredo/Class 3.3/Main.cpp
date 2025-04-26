// This program demonstrates the use of a global variable and functions to manipulate it.
#include <iostream>
#include "Globals.h"
#include "Calculate.h"
#include "Math.h"

int gCount = 0;

void Increment(int amount)
{
	gCount += amount;
}

void Print(int value)
{
	// Static is used to keep track of the number of times Print is called
	// This is a static variable, it retains its value between function calls
	static int sLogTracker = 0; // Static variable to track the number of times Print is called
	std::cout << "[" << sLogTracker << "] " << "Value: [" << value << "]\n";
	++sLogTracker;
}

int main()
{
	//for (int i = 0; i < 10; i++)
	//{
	//	if (i < 5)
	//	{
	//		Increment(GetSum(i));
	//	}
	//	else
	//	{
	//		Increment(GetDifference(i));
	//	}
	//	Print(gCount);
	//}

	//Calculate::Clear();
	//Calculate::Add(21);
	//Calculate::Sub(5);
	//Calculate::Mult(2);
	//Calculate::Div(4);
	//Print(Calculate::GetResult());

	//// Solve the equation (32 / 8) * (2 + 3) - 13
	//int div = Math::Div(32, 8);
	//int sum = Math::Add(2, 3);
	//int mul = Math::Mul(div, sum);
	//int sub = Math::Sub(mul, 13);
	//Print(sub);

	//for (int i = 0; i < 5; i++)
	//{
	//	Print(MATH_MIN(rand() % 10, rand() % 10));
	//	Print(MATH_MAX(rand() % 10, rand() % 10));
	//	Print(MAX_CLAMP(rand() % 10, 2, 5));
	//	Print(MATH_ABS(rand() % 10)- 5);
	//}

	// Inline notes
	int add = Math::Add(10, 3);
	Print(add);
	int sub = Math::Sub(25, 30);
	Print(sub);
	int mul = Math::Mul(11, 24);
	Print(mul);
	int div = Math::Div(75, 15);
	Print(div);

	return 0;
}
#include "Calculate.h"

int Calculate::mResult = 0;

void Calculate::Add(int amount)
{
	mResult += amount;
}

void Calculate::Sub(int amount)
{
	mResult -= amount;
}

void Calculate::Mult(int amount)
{
	mResult *= amount;
}

void Calculate::Div(int amount)
{
	mResult /= amount;
}

int Calculate::GetResult()
{
	return mResult;
}

void Calculate::Clear()
{
	mResult = 0;
}

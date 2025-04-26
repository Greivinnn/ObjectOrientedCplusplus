#include "Calculator.h"
#include <iostream>

using namespace GlobalAccess;

int Calculator::_result = 0;

void Calculator::Add(int amount)
{
	_result += amount;
}

void Calculator::Sub(int amount)
{
	_result -= amount;
}

void Calculator::Mul(int amount)
{
	_result *= amount;
}

void Calculator::Div(int amount)
{
	_result /= amount;
}

void Calculator::GetResult()
{
	std::cout << "The final answer is: " << _result << "\n\n";
}

void ::Calculator::Clear()
{
	_result = 0;
}

#pragma once
//Functor

class Calculator
{
public:
	void operator()(int a, int b, int(*func)(int, int))
	{
		total += func(a, b);
	}
	int GetTotal() const
	{
		return total;
	}

private:
	int total = 0;
};
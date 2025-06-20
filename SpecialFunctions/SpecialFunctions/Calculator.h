#pragma once

// functor
class Calculator
{
public:
	// functors override operator()
	void operator()(int a, int b, int(*func)(int, int))
	{
		total += func(a, b);
	}
	void operator()(void(*print)(int))
	{
		print(total);
	}

	int GetTotal() const
	{
		return total;
	}
private:
	int total = 0;
};
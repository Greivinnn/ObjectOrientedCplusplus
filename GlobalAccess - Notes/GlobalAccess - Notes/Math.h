#pragma once

namespace Mathh
{
	class Math
	{
	public:
		void Add(int a, int b);
		void Sub(int a, int b);
		void Mul(int a, int b);
		void Div(int a, int b);
	private:
		int _result;
	};

}

#define MATH_MIN(a,b) ((a < b) ? a : b)
#define MATH_MAX(a, b) ((a > b)) ? a : b)
#define MAX_CLAMP(a, min, max) ((((a < min)? min : a)> max)? max : a)
#define MATH_ABS(a) ((a < 0)? -a : a)
#pragma once

namespace GlobalAccess
{
	class Calculator
	{
	public:
		static void Add(int amount);
		static void Sub(int amount);
		static void Mul(int amount);
		static void Div(int amount);
		static void GetResult();
		static void Clear();
	private:
		static int _result;
	};
}

#pragma once

class Calculate
{
public:
	static void Add(int amount);
	static void Sub(int amount);
	static void Mult(int amount);
	static void Div(int amount);
	static int GetResult();
	static void Clear();

private:
	static int mResult;
};
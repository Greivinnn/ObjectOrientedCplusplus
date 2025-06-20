#pragma once
#include <iostream>

class MyString
{
public:
	MyString(std::size_t s, char* str)
		:size(s), string(new char[s + 1])
	{
		std::memcpy(string, str, s + 1);
	}

private:
	std::size_t size;
	char* string = nullptr;
};
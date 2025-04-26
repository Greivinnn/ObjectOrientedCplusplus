#pragma once
#include <iostream>

namespace GlobalAccess
{
    extern int gIncrementValue; // Declaration of global variable

    class TaskB
    {
    public:
        void AddValues(int num)
        {
            num += gIncrementValue;
            std::cout << "Value of addition: " << num << "\n";
        }
        void SubValue(int num)
        {
            num -= gIncrementValue;
            std::cout << "Value of subtraction: " << num << "\n";
        }
        void Run()
        {
            for (int i = 0; i < 10; ++i)
            {
                if (i <= 5) // Adjusted condition
                {
                    AddValues(i);
                }
                else
                {
                    SubValue(i);
                }
            }
        }
    };
}
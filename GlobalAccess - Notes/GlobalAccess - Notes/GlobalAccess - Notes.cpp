#include <iostream>
#include "TaskB.h"
#include "Calculator.h"
#include "Math.h"
//TASK A

using namespace GlobalAccess;
using namespace Mathh;

int gCount = 0;

void IncrementCountBy(int incrementBy)
{
    if (incrementBy > 0)
    {
        gCount += incrementBy;
    }
    else
    {
        std::cout << "No zero or negative numbers in here\n\n";
    }
}

void PrintValue(int value)
{
    static int sLogTracker = 0;
    std::cout << "[" << sLogTracker << "] Value: " << value << "\n";
    ++sLogTracker;
}

int main()
{
    for (int i = 0; i < 5; ++i)
    {
        PrintValue(MATH_MIN(rand % 10, rand % 10));
    }
}

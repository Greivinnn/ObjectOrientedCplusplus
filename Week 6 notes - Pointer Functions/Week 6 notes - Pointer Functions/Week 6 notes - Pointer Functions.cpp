#include <iostream>
#include "Calculator.h"
#include <vector>

int Add(int a, int b)
{
    return a + b;
}
int Sub(int a, int b)
{
    return a - b;
}
int Multi(int a, int b)
{
    return a * b;
}
int Div(int a, int b)
{
    return a / b;
}
void Print(int val)
{
    std::cout << "Printing... " << val << "\n";
}

int main()
{
   /* int (*mathFunction)(int, int) = Add;
    void (*printFunc)(int) = Print;

    int ret = mathFunction(1, 3);
    printFunc(ret);*/

    // functor
    void (*printFunc)(int) = Print;

    Calculator calc;
    calc(2, 3, Add);
    calc(5, 5, Multi);
    
    printFunc(calc.GetTotal());

    /*std::vector<int> values;
    for (int i = 0; i < 10; ++i)
    {
        values.push_back(i);
    }
    for (auto value : values)
    {
        std::cout << value << " - ";
    }*/

    //Lambda Function
    srand(time(NULL));
    auto CoinFlipCounter = [](int value)->int
        {
            if (value < 5)
            {
                std::cout << "heads\n";
                return 0;
            }
            std::cout << "tails\n";
            return 1;
        };
    int flipCount = 0;
    int totalFlips = (rand() % 100) + 1;
    for (int i = 0; i < totalFlips; ++i)
    {
        flipCount += CoinFlipCounter(rand() % 10);
    }
    if (flipCount > (totalFlips / 2))
    {
        std::cout << "Tail wins\n";
    }
    else
    {
        std::cout << "Heads wins\n";
    }
}

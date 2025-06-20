// SpecialFunctions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>     // cout/cin
#include <vector>       // vector
#include <list>         // list
#include <deque>        // deque
#include <functional>   // function
#include <string>       // to_string
#include <algorithm>    // sort


#include "Calculator.h"
#include "FarmAndSheep.h"

int Add(int a, int b)
{
    return a + b;
}
int Sub(int a, int b)
{
    return a - b;
}
int Mul(int a, int b)
{
    return a * b;
}
int Div(int a, int b)
{
    return a / b;
}
void Print(int val)
{
    std::cout << "Printing " << val << "\n";
}

// Task E
void PrintIsACat(std::string name)
{
    std::cout << name << " Is A Cat\n";
}
void PrintIsADog(std::string name)
{
    std::cout << name << " Is A Dog\n";
}

class Animal
{
public:
    void SetName(const std::string& name) { mName = name; }
    void SetPrintCallback(std::function<void(std::string)> cb) { mPrintCallback = cb; }

    void Print()
    {
        mPrintCallback(mName);
    }
private:
    std::string mName;
    std::function<void(std::string)> mPrintCallback;
};

int main()
{
    std::cout << "Hello World!\n";
    
    void (*printFunc)(int) = Print;

    Calculator calc;
    calc(1, 3, Add);
    calc(5, 2, Mul);
    calc(6, 3, Div);
    calc(1, 7, Sub);
    calc(Print);

    std::vector<int> values;
    for (int i = 0; i < 10; ++i)
    {
        values.push_back(rand());
    }

    for (auto v : values)
    {
        std::cout << "Auto Values : " << v << "\n";
    }
    for (auto v = values.begin(); v != values.end(); ++v)
    {
        std::cout << "Auto Values : " << (*v) << "\n";
    }

    srand(time(nullptr));
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
    int totalFlips = 10 + (rand() % 11); // min + (rand() % (max - min + 1)); // 10-20
    for (int i = 0; i < totalFlips; ++i)
    {
        flipCount += CoinFlipCounter(rand() % 10);
    }
    if (flipCount > (totalFlips / 2))
    {
        std::cout << "Tails Wins!!\n";
    }
    else
    {
        std::cout << "Heads Wins!!\n";
    }


    std::vector<Animal> myAnimals;
    myAnimals.resize(10);
    for (auto& animal : myAnimals)
    {
        animal.SetName("Animal" + std::to_string(rand() % 100));
        if ((rand() % 2) == 0)
        {
            animal.SetPrintCallback(PrintIsACat);
        }
        else
        {
            animal.SetPrintCallback(PrintIsADog);
        }
    }

    for (auto& animal : myAnimals)
    {
        animal.Print();
    }


    std::vector<int> vectorOfInts;
    for (int i = 0; i < 20; ++i)
    {
        vectorOfInts.push_back(rand() % 200);
    }
    for (auto& v : vectorOfInts)
    {
        std::cout << v << " ";
    }
    std::cout << "\n";

    auto SortDecend = [](int a, int b)->bool
    {
        return b < a;
    };

    std::sort(vectorOfInts.begin(), vectorOfInts.end(), SortDecend);
    for (auto& v : vectorOfInts)
    {
        std::cout << v << " ";
    }
    std::cout << "\n";

    auto ModByTen = [](int& val)
    {
        val = val % 10;
    };
    std::for_each(vectorOfInts.begin(), vectorOfInts.end(), ModByTen);
    for (auto& v : vectorOfInts)
    {
        std::cout << v << " ";
    }
    std::cout << "\n";

    // std::transform Unary Operation (pass in value in vector, do function, return result into output vector)
    auto MulRandomOne = [](int val)->int
    {
        return val * (rand() % 20);
    };
    std::vector<int> output;
    output.resize(vectorOfInts.size());
    std::transform(vectorOfInts.begin(), vectorOfInts.end(), output.begin(), MulRandomOne);
    for (auto& v : output)
    {
        std::cout << v << " ";
    }
    std::cout << "\n";


    // std::transform Binary Operation (pass in value from main vector, second vector of same size, return result into outpu vector)
    auto AddOutputTwo = [](int val, int outputVal)->int
    {
        return val + outputVal;
    };

    std::vector<int> addTwoOutput;
    addTwoOutput.resize(vectorOfInts.size());
    std::transform(vectorOfInts.begin(), vectorOfInts.end(), output.begin(), addTwoOutput.begin(), AddOutputTwo);
    for (auto& v : addTwoOutput)
    {
        std::cout << v << " ";
    }
    std::cout << "\n";



    //auto PrintAnimal = [](Animal& animal)
    //    {
    //        animal.Print();
    //    };

    //std::vector<Animal> cats;
    //std::vector<Animal> dogs;
    //std::vector<Animal> birds;
    //std::vector<Animal> sheep;

    //// for_each
    //std::for_each(cats.begin(), cats.end(), PrintAnimal);
    //std::for_each(dogs.begin(), dogs.end(), PrintAnimal);
    //std::for_each(birds.begin(), birds.end(), PrintAnimal);
    //std::for_each(sheep.begin(), sheep.end(), PrintAnimal);

    //for (auto& cat : cats)
    //{
    //    cat.Print();
    //}
    //for (auto& dog : dogs)
    //{
    //    dog.Print();
    //}
    //for (auto& bird : birds)
    //{
    //    bird.Print();
    //}
    //for (auto& sheep : sheep)
    //{
    //    sheep.Print();
    //}

    Farm farm;
    for (int i = 0; i < 3; ++i)
    {
        farm.AddSheep();
    }
    farm.CallSheep();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

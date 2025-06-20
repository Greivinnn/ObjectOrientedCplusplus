#include "FarmAndSheep.h"

#include <iostream>


void Sheep::AddCallback(std::function<void(int)> cb)
{
    mCallback = cb;
}

void Sheep::CallFunction()
{
    if (mCallback != nullptr)
    {
        mCallback(10);
    }
}

void Farm::AddSheep()
{
    Sheep newSheep;
    std::function<void(int)> cb = std::bind(&Farm::SheepCallback, this, std::placeholders::_1);
    newSheep.AddCallback(cb);
    mSheep.push_back(newSheep);
}

void Farm::SheepCallback(int num)
{
    std::cout << "Sheep Callback " << num << "\n";
}

void Farm::CallSheep()
{
    for (auto& sheep : mSheep)
    {
        sheep.CallFunction();
    }
}

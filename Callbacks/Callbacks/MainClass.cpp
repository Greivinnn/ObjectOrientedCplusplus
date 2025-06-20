#include "MainClass.h"
#include <iostream>


void MainClass::AddChildClass()
{
    ChildClass childClass;
    std::function<void(int)> overTenCB = std::bind(&MainClass::OnChildClassOverTen, this, std::placeholders::_1);
    std::function<void(int, int)> underFiveCB = std::bind(&MainClass::OnChildClassUnderFive, this, std::placeholders::_1, std::placeholders::_2);
    std::function<int(int)> getAverageCB = std::bind(&MainClass::OnGetAverage, this, std::placeholders::_1);
    childClass.SetOverTenCallback(overTenCB);
    childClass.SetUnderFiveCallback(underFiveCB);
    childClass.SetGetAverageCallback(getAverageCB);
    mChildClasses.push_back(childClass);
}
void MainClass::Update()
{
    for (ChildClass& cc : mChildClasses)
    {
        cc.SetValue(rand() % 15);
    }
    for (ChildClass& cc : mChildClasses)
    {
        cc.Update();
    };
}
void MainClass::OnChildClassOverTen(int id)
{
    std::cout << ">>ChildClass [" << id << "] is over 10!\n";
}
void MainClass::OnChildClassUnderFive(int id, int value)
{
    std::cout << ">>ChildClass [" << id << "] is under 5 with a value of " << value << ".\n";
}
int MainClass::OnGetAverage(int id)
{
    int total = 0;
    for (ChildClass& cc : mChildClasses)
    {
        if (cc.GetId() != id)
        {
            total += cc.GetValue();
        }
    }
    if (total > 0)
    {
        return total / (int)(mChildClasses.size() - 1);
    }
    return 0;
}
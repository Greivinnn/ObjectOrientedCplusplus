#pragma once
#include <vector>

#include "ChildClass.h"

class MainClass
{
public:
    void AddChildClass();
    void Update();

    // functions to link to callbacks
    void OnChildClassOverTen(int id);
    void OnChildClassUnderFive(int id, int value);
    int OnGetAverage(int id);

private:
    std::vector<ChildClass> mChildClasses;
};
#include "ChildClass.h"
#include <iostream>

int gUniqueId = 0;
ChildClass::ChildClass()
    : mId(++gUniqueId)
    , mMyValue(0)
{

}
int ChildClass::GetId() const
{
    return mId;
}
int ChildClass::GetValue() const
{
    return mMyValue;
}
void ChildClass::SetValue(int value)
{
    mMyValue = value;
}

void ChildClass::Update()
{
    // child is asking a function to give a value
    int average = 0;
    if (mGetAverageCB != nullptr)
    {
        average = mGetAverageCB(mId);
    }

    if (mMyValue > 10)
    {
        // child is letting the parent know something happend
        if (mOverTenCB != nullptr)
        {
            mOverTenCB(mId);
        }
    }
    else if (mMyValue < 5)
    {
        // child letting parent know something else happened
        if (mUnderFiveCB != nullptr)
        {
            mUnderFiveCB(mId, mMyValue);
        }
    }

    std::cout << "Child Class [" << mId << "] is " << ((mMyValue < average) ? "BELOW" : "ABOVE") << " Average\n";
}
void ChildClass::SetOverTenCallback(std::function<void(int)> cb)
{
    mOverTenCB = cb;
}
void ChildClass::SetUnderFiveCallback(std::function<void(int, int)> cb)
{
    mUnderFiveCB = cb;
}
void ChildClass::SetGetAverageCallback(std::function<int(int)> cb)
{
    mGetAverageCB = cb;
}
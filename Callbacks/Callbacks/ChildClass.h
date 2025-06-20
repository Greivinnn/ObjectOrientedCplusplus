#pragma once
#include <functional>

class ChildClass
{
public:
    ChildClass();
    int GetId() const;
    int GetValue() const;
    void SetValue(int value);
    void Update();

    // functions to set callbacks
    void SetOverTenCallback(std::function<void(int)> cb);
    void SetUnderFiveCallback(std::function<void(int, int)> cb);
    void SetGetAverageCallback(std::function<int(int)> cb);

private:
    int mId = 0;
    int mMyValue = 0;
    std::function<void(int)> mOverTenCB;
    std::function<void(int, int)> mUnderFiveCB;
    std::function<int(int)> mGetAverageCB;
};
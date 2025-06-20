#pragma once
#include <functional>
#include <vector>

class Sheep
{
public:
    void AddCallback(std::function<void(int)> cb);
    void CallFunction();
private:
    std::function<void(int)> mCallback;
};

class Farm
{
public:
    void AddSheep();
    void SheepCallback(int num);

    void CallSheep();
private:
    std::vector<Sheep> mSheep;
};
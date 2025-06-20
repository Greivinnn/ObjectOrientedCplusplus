#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <algorithm>


void PrintIsACat(const std::string& name)
{
    std::cout << name << " is a cat!\n";
}
void PrintIsADog(const std::string& name)
{
    std::cout << name << " is a dog!\n";
}

class Animal
{
public:
    Animal(const std::string& name)
        :mName(name)
    {
    }
    Animal()
    {

    }
    void SetName(const std::string& name) { mName = name; }
    void SetPrintCallBack(std::function<void(std::string)> cb) { mPrintCallBack = cb; }

    void Print()
    {
        mPrintCallBack(mName);
    }
private:
    std::string mName;
    std::function<void(std::string)> mPrintCallBack;
};

int main()
{
    std::vector<Animal> listOfAnimals;
    listOfAnimals.resize(10);
    for (auto& animal : listOfAnimals)
    {
        animal.SetName("Animal" + std::to_string(rand() % 100));
        if ((rand() % 2) == 0)
        {
            animal.SetPrintCallBack(PrintIsACat);
        }
        else
        {
            animal.SetPrintCallBack(PrintIsADog);
        }
    }
    for (auto& animal : listOfAnimals)
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
    std::for_each(vectorOfInts.begin(), vectorOfInts.end(), SortDecend);
    for (auto& v : vectorOfInts)
    {
        std::cout << v << " ";
    }
    std::cout << "\n";
        
}


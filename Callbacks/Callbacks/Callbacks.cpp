// Callbacks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MainClass.h"

void SmartPointerStuff()
{
    // Hylander Rules, there can only be one
    // not copied, not moved, can only be shared with .get();
    std::unique_ptr<int> uniquePtr;
    int* ptr = uniquePtr.get();

    // keep a reference count
    // will remove when all references are cleared
    // constructor is called on first creation
    std::shared_ptr<int> sharedPtr;
    // use .get() to see the info, don't pass around std::shared<int>
    // no extra reference, can be nullptr
    int* shPtr = sharedPtr.get();
    // if it is copied, reference count increases, will not remove unless count is 0
    std::shared_ptr<int> anotherSharedPtr = sharedPtr;
    // reset will decrease the reference count, if count is 0, will clean up object
    //  destructor is called when count is 0
    anotherSharedPtr.reset();
    // storing resources, like textures, models, game objects
    //  anytime you're using the object and dont want it deleted while in use

    std::weak_ptr<int> weakPtr = sharedPtr;
    // does not increment the reference count
    // major difference is that it can check if the data is valid
    // weak_ptr is similar to * EXCEPT it can .lock() the data and prevent deletion
    //      when in use
}

int main()
{
    std::cout << "Hello World!\n";

    // temporary function
    // can only be used in the scope it is declared
    //  [] are for what values in the scope can be used in the function
    //      empty means nothing outside of the function can be used
    //      [&] means everything outside of the function can be used
    //      [myValue] means only myValue can be used;
    int myValue = 3;
    auto myLambdaFunction = [myValue](int a, int b)->int
        {
            if (a > b)
            {
                a = a * a * b;
            }
            else
            {
                b = b * b * a;
            }
            return a + b * myValue;
        };
    int value = myLambdaFunction(10, 3);

    MainClass mainClass;
    for (int i = 0; i < 20; ++i)
    {
        mainClass.AddChildClass();
    }

    int count = 0;
    while (count < 20)
    {
        system("cls");
        std::cout << "Main Update\n";
        mainClass.Update();
        getchar();
        ++count;
    }
}

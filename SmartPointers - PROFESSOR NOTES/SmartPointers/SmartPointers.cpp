
#include <iostream>

int* GetValue()
{
    int tempValue = 7;
    return &tempValue;
}

int* GetUniqueTemp()
{
    std::unique_ptr<int> value = std::make_unique<int>(15);
    return value.get();
}

struct CopyPtr
{
    std::unique_ptr<int> intPtr;
};

int main()
{
    std::cout << "Hello World!\n";

    int value = 10;
    int* intPtr = &value;
    int* newInt = new int(5);

    int* tempPtr = GetValue();

    std::unique_ptr<int> uniquePtr = std::make_unique<int>(8);
    std::unique_ptr<int[]> uniqPtrArray = std::make_unique<int[]>(10);

    const int* unPtrAdd = uniquePtr.get();
    //std::unique_ptr<int> unCpy = uniquePtr;

    int* tmpUnique = GetUniqueTemp();

    CopyPtr cpy;
    cpy.intPtr = std::make_unique<int>(5);


    // shared ptr ref count increase by 1
    std::shared_ptr<int> shrPtr = std::make_shared<int>(21);
    // shared ptr ref count increase by 1
    std::shared_ptr<int> shrPtr2 = shrPtr;
    // shared ptr ref count increase by 1
    std::shared_ptr<int> shrPtr3 = shrPtr;
    // shared ptr ref count increase by 1
    std::shared_ptr<int> shrPtr4 = shrPtr;

    // references a shared ptr, BUT ref count does not increase
    // weak_ptr is a pointer to a shared_ptr
    std::weak_ptr<int> weakPtr = shrPtr;


    shrPtr4.reset();
    shrPtr3.reset();
    shrPtr2.reset();
    //shrPtr.reset();

    std::cout << "Int " << value << "\n";
    std::cout << "Ptr " << intPtr << "\n";
    std::cout << "IntPtr " << *intPtr << "\n";
    std::cout << "NewPtr " << newInt << "\n";
    std::cout << "NewIntPtr " << *newInt << "\n";
    std::cout << "TempPtr " << tempPtr << "\n";
    std::cout << "TempIntPtr " << *tempPtr << "\n";
    std::cout << "UniquePtr " << uniquePtr << "\n";
    std::cout << "UniquePtrGet " << uniquePtr.get() << "\n";
    std::cout << "UniqueIntPtr " << *uniquePtr.get() << "\n";
    std::cout << "TempUnPtr " << tmpUnique << "\n";
    std::cout << "TempUnIntPtr " << *tmpUnique << "\n";

    std::cout << "SharedPtr " << shrPtr << "\n";
    std::cout << "SharedPtrGet " << shrPtr.get() << "\n";
    std::cout << "SharedIntPtr " << *shrPtr.get() << "\n";
    //shrPtr.reset();
    // expired checks to see if shared ptr was deleted
    if (!weakPtr.expired())
    {
        // lock creates a tmp shared ptr while in use
        //  gets removed after leaving scope
        std::cout << "WeakPtr " << weakPtr.lock() << "\n";
        std::cout << "WeakPtrGet " << weakPtr.lock().get() << "\n";
        std::cout << "WeakIntPtr " << *weakPtr.lock().get() << "\n";
    }
    shrPtr.reset();
    weakPtr.reset();

    uniquePtr.reset();
    uniqPtrArray.reset();
    delete newInt;
}

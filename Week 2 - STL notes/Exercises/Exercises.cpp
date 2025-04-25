#include <iostream>
#include <list>
#include <time.h>
#include <array>
#include <vector>

int main()
{
    srand(time(NULL));


    // Step 1: Create a vector with 20 elements
    std::vector<int> numbers(20);
    for (int i = 0; i < 20; i++)
    {
        numbers[i] = rand() % 50; // Assign random values
    }

    // Step 2: Print the original 20 elements
    std::cout << "Original vector (20 elements):\n";
    for (int i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n";

    // Step 3: Resize the vector to 21 elements
    numbers.resize(21);
    numbers[20] = rand() % 50; // Add a new random value

    // Print the resized vector with 21 elements
    std::cout << "Resized vector (21 elements):\n";
    for (int i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n";

    // Step 4: Resize the vector to 30 elements
    numbers.resize(30);
    for (int i = 21; i < 30; i++)
    {
        numbers[i] = rand() % 50; // Add new random values
    }

    // Print the resized vector with 30 elements
    std::cout << "Resized vector (30 elements):\n";
    for (int i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n";

    return 0;


    //// Step 1: Create a dynamic array with 20 elements
    //int* originalArray = new int[20];
    //for (int i = 0; i < 20; i++)
    //{
    //    originalArray[i] = rand() % 50; // Assign random values
    //}

    //// Step 2: Print the original 20 elements
    //std::cout << "Original array (20 elements):\n";
    //for (int i = 0; i < 20; i++)
    //{
    //    std::cout << originalArray[i] << " ";
    //}
    //std::cout << "\n";

    //// Step 3: Resize the array to 21 elements
    //int* resizedArray21 = new int[21];
    //for (int i = 0; i < 20; i++)
    //{
    //    resizedArray21[i] = originalArray[i]; // Copy original values
    //}
    //resizedArray21[20] = rand() % 50; // Add a new random value

    //// Print the resized array with 21 elements
    //std::cout << "Resized array (21 elements):\n";
    //for (int i = 0; i < 21; i++)
    //{
    //    std::cout << resizedArray21[i] << " ";
    //}
    //std::cout << "\n";

    //// Step 4: Resize the array to 30 elements
    //int* resizedArray30 = new int[30];
    //for (int i = 0; i < 21; i++)
    //{
    //    resizedArray30[i] = resizedArray21[i]; // Copy original values
    //}
    //for (int i = 21; i < 30; i++)
    //{
    //    resizedArray30[i] = rand() % 50; // Add new random values
    //}

    //// Print the resized array with 30 elements
    //std::cout << "Resized array (30 elements):\n";
    //for (int i = 0; i < 30; i++)
    //{
    //    std::cout << resizedArray30[i] << " ";
    //}
    //std::cout << "\n";

    //// Clean up dynamically allocated memory
    //delete[] originalArray;
    //delete[] resizedArray21;
    //delete[] resizedArray30;

    //return 0;

    // Pros of using an array is that you can access any index of the array you would like
    // Cons of using an array is that you have to do extra steps to resize the array when adding or removing values



    //std::list<int> myList;
    //for (int i = 0; i < 10; i++)
    //{
    //    myList.push_back(rand() % 100);
    //}
    //std::cout << "Original list:\n";
    //for (int& val : myList) // range-based for loop
    //{
    //    std::cout << "Value: " << val << "\n";
    //}
    //std::cout << "\n";

    //for (int i = 0; i < 3; i++)
    //{
    //    myList.pop_back();
    //}

    //for (int i = 0; i < 5; i++)
    //{
    //    myList.push_back(rand() % 50);
    //}

    //std::cout << "Removed 3 elements, then added 5\n";
    //for (int& val : myList) // range-based for loop
    //{
    //    std::cout << "Value: " << val << "\n";
    //}

    //std::cout << "\nFirst Element: " << myList.front();
    //std::cout << "\nLast Element: " << myList.back();
}

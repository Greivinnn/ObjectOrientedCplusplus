#include <iostream>
#include <array>
#include <list>
#include <deque>

struct Node
{
	int value = 0;
	Node* next = nullptr;
	Node* prev = nullptr;
};

int main()
{
	//// This program will ask the user to enter 10 numbers and store them in an array.
	//int maxNumbers = 10;
	//int numbers[100];

	//// Ask the user to enter 10 numbers
	//for (int i = 0; i < maxNumbers; i++)
	//{
	//	std::cout << "Enter number " << i + 1 << ": ";
	//	std::cin >> numbers[i];
	//}

	//// Resize the array to hold 11 numbers
	//int* pNumbers = new int[10];
	//delete[] pNumbers;
	//pNumbers = new int[11];

	//Node* startNode = new Node;
	//Node* node = startNode;
	//node->value = 0;

	//for (int i = 0; i < maxNumbers; i++)
	//{
	//	node->next = new Node();
	//	node = node->next;
	//	node->value = i + 1;
	//}

	//node = startNode;
	//for (int i = 0; i < 3; i++)
	//{
	//	node = node->next;
	//}
	//Node* nextNode = node->next;
	//node->next = nextNode->next;
	//delete nextNode;


	//// std::array
	//std::array<int, 10> myArray = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	//for (int i = 0; i < myArray.size(); i++)
	//{
	//	myArray[i] = i;
	//	myArray.at(i) = i;
	//}

	//int front = myArray.front(); // first element
	//int back = myArray.back(); // last element
	//int empty = myArray.empty(); // check if empty

	//// std::list
	//std::list<int> myList = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	//myList.push_back(11); // add to the end
	//myList.push_front(0); // add to the front
	//myList.front(); // gets the first element
	//myList.back(); // gets the last element
	//myList.insert(myList.begin(), 3); // insert 3 at the beginning
	//myList.clear(); // clear the list
	//myList.emplace_back(12); // add 12 to the end
	//myList.remove(5); // remove 5
	//myList.empty(); // check if empty
	//myArray.size(); // get the size of the list
	//myList.resize(15); // resize the list to 15 elements

	//// Print the list
	//for (int& val : myList) // range-based for loop
	//{
	//	std::cout << "Value: " << val << "\n";
	//}

	//return 0;

     // std::deque (Double-Ended Queue) allows insertion and deletion at both ends efficiently.

    // Create a deque and initialize it with some values
    std::deque<int> myDeque = { 1, 2, 3, 4, 5 };

    // Access elements
    int front = myDeque.front(); // Get the first element
    int back = myDeque.back();   // Get the last element
    std::cout << "Front: " << front << ", Back: " << back << "\n";

    // Add elements
    myDeque.push_back(6);  // Add an element to the end
    myDeque.push_front(0); // Add an element to the front

    // Print the deque
    std::cout << "Deque after push_back and push_front: ";
    for (int val : myDeque)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";

    // Insert elements
    myDeque.insert(myDeque.begin() + 2, 99); // Insert 99 at the 3rd position (index 2)

    // Print the deque after insertion
    std::cout << "Deque after insert: ";
    for (int val : myDeque)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";

    // Remove elements
    myDeque.pop_back();  // Remove the last element
    myDeque.pop_front(); // Remove the first element

    // Print the deque after removal
    std::cout << "Deque after pop_back and pop_front: ";
    for (int val : myDeque)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";

    // Erase elements
    myDeque.erase(myDeque.begin() + 1); // Erase the second element (index 1)

    // Print the deque after erasing
    std::cout << "Deque after erase: ";
    for (int val : myDeque)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";

    // Resize the deque
    myDeque.resize(7, 42); // Resize to 7 elements, fill new elements with 42

    // Print the deque after resizing
    std::cout << "Deque after resize: ";
    for (int val : myDeque)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";

    // Check if the deque is empty
    if (myDeque.empty())
    {
        std::cout << "Deque is empty.\n";
    }
    else
    {
        std::cout << "Deque is not empty.\n";
    }

    // Clear the deque
    myDeque.clear(); // Remove all elements

    // Check the size after clearing
    std::cout << "Size after clear: " << myDeque.size() << "\n";

    return 0;
}
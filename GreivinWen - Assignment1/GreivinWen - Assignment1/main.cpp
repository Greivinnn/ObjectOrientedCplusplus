#include <iostream>
#include <time.h>
#include <list>
#include "Restaurant.h"
#include "Clients.h"
#include "Group.h"

using namespace Assignment1;

//random group creator
std::list<Clients> CreateRandomGroup(int size)
{
    std::list<Clients> clients;
    std::string names[] = { "Darren", "Santi", "Bob", "Alfred", "Juan" };

    for (int i = 0; i < size; i++)
    {
        std::string name = names[rand() % 5] + std::to_string(rand() % 100); // more randomness, "Name67" will be the output
        clients.push_back(Clients(name));
    }
    return clients;
}

int main()
{
    srand(time(NULL));
    
    Restaurant restaurant(5); // create a restaurant with 5 tables
    restaurant.ASCIIArt();

    std::cout << "Welcome to the Kingstaurant, enjoy the service.\n";
    std::cout << "-------------------------------------\n\n";

    //test group
    for (int i = 0; i < 8; i++) // 8 groups more than available tables(5)
    {
        int groupSize = rand() % 4 + 1; // 1-4 people per group
        std::list<Clients> clients = CreateRandomGroup(groupSize);
        restaurant.AddGroup(clients);
    }

    restaurant.Run(50); // run simulation for 50 frames

    // final message
    std::cout << "\nThank you for using the Kingstaurant Simulation.\nPlease give us a good rating online!\n\n";

    return 0;
}

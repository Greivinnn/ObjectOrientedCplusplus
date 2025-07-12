// VGP134Final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "StatsManager.h"
#include "ActionManager.h"
#include <algorithm> // to use all_of

// Part 2: The Road Trip (70%)
//      You are on a road trip.  Manage all the members in your vehicle as well as your fuel consumption.
//      Some code is already setup:
//          - fill out the missing sections
//          - fix any errors you find
//          - there are comments throughout the code stating what each section should accomplish
//          - use error handling as well as move semantics when applicable

int main()
{
    StatsManager statsManager;
    ActionManager actionManager;

    srand(time(NULL));

    // add players to the statsManager
    statsManager.AddPlayer("Greivin");
    statsManager.AddPlayer("JP");
    statsManager.AddPlayer("Santiago");


    // after adding names, add all the callbacks
    actionManager.SetFuelUpdateCallback(std::bind(&StatsManager::UpdateFuel, &statsManager, std::placeholders::_1));
    actionManager.SetEatUpdateCallback(std::bind(&StatsManager::Eat, &statsManager));
    actionManager.SetGetHungryUpdateCallback(std::bind(&StatsManager::GetHungry, &statsManager, std::placeholders::_1, std::placeholders::_2));

    // then initialize the action manager
    actionManager.Initialize(statsManager);

    // run the program
    std::string result = "";
    while (statsManager.GetDistanceTravelled() < 500)
    {
        system("cls");
        std::cout << "The Road Trip\n";
        statsManager.Print();
        std::cout << std::endl;
        // Ask user what options they would like to do next
        //      - options are to refuel, eat, or continue driving
        //      - option "continue driving" is only available if statsManager.CanContinueTravel() is true
        //      - if a option is invalid, notify user
        std::cout << "(Choose what to do)\n";
        std::cout << "1. Refuel\n";
        std::cout << "2. Eat\n";
        std::cout << "3. Continue driving\n";
        std::cout << "Choice (number): ";
        std::cin >> result;

        // using #include <algorith> we can convert the string input into a number input. To make the comparison much easier
        // this bool checks if the inputted value is a number or not. If not we return the error handling message
        bool isNumeric = !result.empty() && std::all_of(result.begin(), result.end(), ::isdigit);
        if (!isNumeric)
        {
            std::cout << "Invalid input. Please enter a number (1, 2, or 3).\n";
            system("pause");
            continue;
        }
        // Convert the input to an integer
        int choice = std::stoi(result);

        if (choice == 1)
        {
            actionManager.DoAction(ActionType::Refuel);
        }
        else if (choice == 2)
        {
            actionManager.DoAction(ActionType::Eat);
        }
        else if (choice == 3)
        {
            if (statsManager.CanContinueTravel())
            {
                actionManager.DoAction(ActionType::Random);
            }
            else
            {
                std::cout << "Unable to continue, players are really hungry or not enough fuel!\n";
            }
        }

        system("pause");
    }
    std::cout << "\n\nThe Road Trip\n";
    statsManager.Print();
    std::cout << std::endl;
    std::cout << "CONGRATULATIONS\n" << std::endl;
    std::cout << "You have reached your destination\n\n" << std::endl;

    // terminate action manager (deletes everything)
    actionManager.Terminate();
    return 0;
}


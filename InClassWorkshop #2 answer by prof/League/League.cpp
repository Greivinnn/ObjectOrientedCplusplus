// League.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "VolleyballLeague.h"

int main()
{
    std::cout << "Hello Volleyball League\n";


    VolleyballLeague volleyballLeague;
    volleyballLeague.AddTeam("Jumpers");
    volleyballLeague.AddTeam("All Sets");
    volleyballLeague.AddTeam("Spikers");
    volleyballLeague.AddTeam("Hoopers");

    volleyballLeague.AddTeam("NotBasketball");
    volleyballLeague.AddTeam("NotSoccer");
    volleyballLeague.AddTeam("BetterThanFootball");
    volleyballLeague.AddTeam("Hi");

    volleyballLeague.AddTeam("Diggers");
    volleyballLeague.AddTeam("Setters");
    volleyballLeague.AddTeam("No Sets");
    volleyballLeague.AddTeam("Painkillers");

    volleyballLeague.AddTeam("Oldies");
    volleyballLeague.AddTeam("Goldies");
    volleyballLeague.AddTeam("Moldies");
    volleyballLeague.AddTeam("The End");

    for (int i = 0; i < 12; ++i)
    {
        volleyballLeague.PlayMatch();
    }
    volleyballLeague.Print();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.h"

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    //create game instance
    Game game;

    // Add 5 players to the game
    for (int i = 1; i <= 5; ++i)
    {
        game.AddPlayer("Player" + std::to_string(i));
    }

    // Initialize the game
    game.Initialize();

    // Start the game
    game.Start();

    // Terminate the game
    game.Terminate();
    return 0;
}

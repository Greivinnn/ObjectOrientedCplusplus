#include "Game.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

void Game::Initialize()
{
	BlackJack::Get()->Initialize();

	// add deck to the table
	std::vector<std::shared_ptr<Card>> deck;
	
	for (int suit = 0; suit < 4; ++suit)
	{
		for (int type = 0; type < 13; ++type)
		{
			char number;
			int value;
			int altValue = 0;

			//assign number and value based on CardType
			switch (static_cast<CardType>(type))
			{
			case CardType::Ace:
				number = 'A';
				value = 1;
				altValue = 11;
				break;
			case CardType::Two:
				number = '2';
				value = 2;
				break;
			case CardType::Three:
				number = '3';
				value = 3;
				break;
            case CardType::Four:
                number = '4';
                value = 4;
                break;
            case CardType::Five:
                number = '5';
                value = 5;
                break;
            case CardType::Six:
                number = '6';
                value = 6;
                break;
            case CardType::Seven:
                number = '7';
                value = 7;
                break;
            case CardType::Eight:
                number = '8';
                value = 8;
                break;
            case CardType::Nine:
                number = '9';
                value = 9;
                break;
            case CardType::Ten:
                number = 'T';
                value = 10;
                break;
            case CardType::Jack:
                number = 'J';
                value = 10; //face cards have a value of 10
                break;
            case CardType::Queen:
                number = 'Q';
                value = 10;
                break;
            case CardType::King:
                number = 'K';
                value = 10;
                break;
			}
            deck.push_back(std::make_shared<Card>
                (static_cast<Suit>(suit), number, value, altValue));    // create a card and add to deckk
		}
	}
    // pass the deck to the blackjack singleton
    BlackJack::Get()->AddDeck(deck);
    std::cout << "The deck has been created and added to the table\n";
}
//start the game logic
void Game::Start()
{
    DealInitialCards();
    //each player takes their turn
    for (auto& player : mPlayers)
    {
        PlayerTurn(player);
    }
    // determine winner
    DetermineWinner();
}
// terminate the game and clean up the code
void Game::Terminate()
{
    for (auto& player : mPlayers)
    {
        player.ReturnCards();
    }
    BlackJack::Get()->Terminate();
    std::cout << "Game terminated and table cleaned.\n";
}
void Game::AddPlayer(const std::string& playerName)
{
    mPlayers.push_back(Player(playerName));
    std::cout << "Player " << playerName << " has been added to the game.\n";
}
// deal the first 2 cards to each player
void Game::DealInitialCards()
{
    for (auto& player : mPlayers)
    {
        player.DrawCard();
        player.DrawCard();
    }
    std::cout << "Each player has been dealt 2 cards, good luck.\n";
}
// handle player turn
void Game::PlayerTurn(Player& player)
{
    std::cout << player.GetName() << "'s turn:\n";

    while (true)
    {
        int handValue = player.GetHandValue();
        if (handValue < 13)
        {
            std::cout << player.GetName() << " has " << handValue << " and requests a new card.\n";
            player.DrawCard();
        }
        else if (handValue >= 14 && handValue <= 17)
        {
            if (rand() % 2 == 0) //  50/50 to draw a card
            {
                std::cout << player.GetName() << " has " << handValue << " and after flipping a coin, has decided to requested a new card.\n";
                player.DrawCard();
            }
            else
            {
                std::cout << player.GetName() << " has " << handValue << " and after flipping a coin, has decided to stay.\n";
                break;
            }
        }
        else if (handValue >= 18 && handValue <= 21) 
        {
            std::cout << player.GetName() << " has " << handValue << " and decides to stay.\n";
            break;
        }

        handValue = player.GetHandValue();

        if (player.IsBust()) // check if anyone cards bust
        {
            std::cout << player.GetName() << " has busted with " << handValue << "!\n";
            break;
        }
    }
}
//determine the winner(s) of the round
void Game::DetermineWinner()
{
    int bestScore = 0;
    std::vector<std::string> winners;

    for (const auto& player : mPlayers)
    {
        int handValue = player.GetHandValue();

        if (!player.IsBust() && handValue > bestScore && handValue <= 21)
        {
            bestScore = handValue;
            winners.clear();
            winners.push_back(player.GetName());
        }
        else if (!player.IsBust() && handValue == bestScore)
        {
            winners.push_back(player.GetName());
        }
    }
    if (winners.empty())
    {
        std::cout << "No winners this round. Everyone busted!\n";
    }
    else
    {
        std::cout << "Winner(s):\n";
        for (const auto& winner : winners)
        {
            std::cout << winner << "\n";
        }
        std::cout << "with a score of " << bestScore << "!\n";
    }
}
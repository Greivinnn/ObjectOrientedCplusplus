#include "Game.h"
#include "Player.h"
#include <iostream>
#include <cstdlib> 
#include <vector>
#include <string> 
#include <algorithm> // For std::shuffle to make it random 100%
#include <random>    // For std::random_device and std::mt19937

void Game::Initialize()
{
    BlackJack::Get()->Initialize();

    // add deck to the table
    std::vector<std::shared_ptr<Card>> deck;

    for (int suit_int = 0; suit_int < 4; ++suit_int)
    {
        for (int type_int = 0; type_int < 13; ++type_int)
        {
            char number_char;
            int value_int;
            int altValue_int = 0; // altValue for Ace is handled by Card constructor or Hand logic, Card stores its own potential values

            CardType type = static_cast<CardType>(type_int);
            Suit suit = static_cast<Suit>(suit_int);

            switch (type)
            {
            case CardType::Ace:
                number_char = 'A';
                value_int = 1; // Primary value for Ace is 1
                altValue_int = 11; // Secondary value for Ace is 11
                break;
            case CardType::Two:
                number_char = '2';
                value_int = 2;
                break;
            case CardType::Three:
                number_char = '3';
                value_int = 3;
                break;
            case CardType::Four:
                number_char = '4';
                value_int = 4;
                break;
            case CardType::Five:
                number_char = '5';
                value_int = 5;
                break;
            case CardType::Six:
                number_char = '6';
                value_int = 6;
                break;
            case CardType::Seven:
                number_char = '7';
                value_int = 7;
                break;
            case CardType::Eight:
                number_char = '8';
                value_int = 8;
                break;
            case CardType::Nine:
                number_char = '9';
                value_int = 9;
                break;
            case CardType::Ten:
                number_char = 'T';
                value_int = 10;
                break;
            case CardType::Jack:
                number_char = 'J';
                value_int = 10;
                break;
            case CardType::Queen:
                number_char = 'Q';
                value_int = 10;
                break;
            case CardType::King:
                number_char = 'K';
                value_int = 10;
                break;
            default: // Should not happen
                number_char = '?';
                value_int = 0;
                break;
            }
            int alt_val_for_card = (type == CardType::Ace) ? 11 : 0; //ternary operators
            deck.push_back(std::make_shared<Card>(suit, number_char, value_int, (type == CardType::Ace ? 11 : 0)));
        }
    }
    //this ensures total randomness, before adding this that I found online, the first 2 players were always getting 20
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
    // pass the deck to the blackjack singleton
    BlackJack::Get()->AddDeck(deck);
    std::cout << "The deck has been created and added to the table\n";
}

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

void Game::DealInitialCards()
{
    for (auto& player : mPlayers)
    {
        player.DrawCard();
        player.DrawCard();
    }
    std::cout << "Each player has been dealt 2 cards, good luck.\n";
}

void Game::PlayerTurn(Player& player)
{
    std::cout << player.GetName() << "'s turn:\n";

    while (true)
    {
        int decisionValue = player.GetHandValue(); // player hand
        int hardValueForDisplay = player.GetHandValues().first; // hand if busted

        if (player.IsBust()) // Checks if busted
        {
            std::cout << player.GetName() << " has busted with " << hardValueForDisplay << "!\n";
            break;
        }

        if (decisionValue <= 13) 
        {
            std::cout << player.GetName() << " has " << decisionValue << " and requests a new card.\n";
            if (!player.DrawCard())
            {
                std::cout << player.GetName() << " cannot draw a card (deck empty?) and stays.\n";
                break;
            }
        }
        else if (decisionValue >= 14 && decisionValue <= 17) // Player has 50/50 chance to hit
        {
            if (rand() % 2 == 0)
            {
                std::cout << player.GetName() << " has " << decisionValue << " and after flipping a coin, has decided to request a new card.\n";
                if (!player.DrawCard())
                {
                    std::cout << player.GetName() << " cannot draw a card (deck empty?) and stays.\n";
                    break;
                }
            }
            else
            {
                std::cout << player.GetName() << " has " << decisionValue << " and after flipping a coin, has decided to stay.\n";
                break;
            }
        }
        else // decisionValue >= 18 (and <= 21 if not busted, or potentially > 21 if soft value is high but hard isn't a bust - IsBust() handles this)
        {
            std::cout << player.GetName() << " has " << decisionValue << " and decides to stay.\n";
            break;
        }
        // If a card was drawn, the loop continues, and IsBust() at the top will check the new hand state.
    }
}

void Game::DetermineWinner()
{
    int bestScore = 0;
    std::vector<std::string> winners;

    for (const auto& player : mPlayers) // Use const auto& if player object isn't modified
    {
        int handValue = player.GetHandValue(); // This is the soft value, which is fine for scoring if not bust

        if (!player.IsBust() && handValue <= 21) // Ensure score is valid
        {
            if (handValue > bestScore)
            {
                bestScore = handValue;
                winners.clear();
                winners.push_back(player.GetName());
            }
            else if (handValue == bestScore)
            {
                winners.push_back(player.GetName());
            }
        }
    }

    if (winners.empty())
    {
        std::cout << "No winners this round. Everyone busted or no valid scores!\n";
    }
    else
    {
        std::cout << "Winner(s):\n";
        for (const auto& winner_name : winners)
        {
            std::cout << winner_name << "\n";
        }
        std::cout << "with a score of " << bestScore << "!\n";
    }
}

#pragma once
#include "BlackJack.h"
#include "Player.h"
#include <vector>

class Game
{
public:
	void Initialize();
	void Start();
	void Terminate();
	void AddPlayer(const std::string& playerName);
private:
	std::vector<Player> mPlayers;	//vector of all players
	// helper methods (can only be called in the game cpp)
	void DealInitialCards();
	void PlayerTurn(Player& player);
	void DetermineWinner();
};
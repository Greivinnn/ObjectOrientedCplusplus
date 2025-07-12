#pragma once

#include "Player.h"
#include <vector>

class StatsManager
{
public:
	void AddPlayer(std::string name);
	const std::vector<Player>& GetPlayers() const;

	int GetFuelAmount() const;

	void UpdateFuel(int amount);
	void GetHungry(int playerIndex, int amount);
	void Eat();

	bool CanContinueTravel() const;
	int GetDistanceTravelled() const;
	void Print();

private:
	int mDistanceTravelled;
	int mFuelAmount = 100;
	std::vector<Player> mPlayers;
};
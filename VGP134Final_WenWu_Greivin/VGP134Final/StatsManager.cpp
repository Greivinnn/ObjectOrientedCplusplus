#include "StatsManager.h"
#include <iostream>

const int WARNING_HUNGER_LEVEL = 3;
const int EXTREME_HUNGER_LEVEL = 5;

void StatsManager::AddPlayer(std::string name)
{
	// add a new player with the new name and set the hungerLevel to 0
	Player newPlayer;
	newPlayer.name = name;
	newPlayer.hungerLevel = 0;

	mPlayers.push_back(newPlayer);
}

const std::vector<Player>& StatsManager::GetPlayers() const
{
	return mPlayers;
}

int StatsManager::GetFuelAmount() const
{
	return mFuelAmount;
}

void StatsManager::UpdateFuel(int amount)
{
	// update the fuel by the amount
	//	- fuel can't be more than 100
	//	- fuel can't be less than 0
	//	- if amount is < 0, also increase the distance traveled by 1
	mFuelAmount += amount;
	if (mFuelAmount > 100)
	{
		mFuelAmount = 100;
	}
	else if (mFuelAmount < 0)
	{
		mFuelAmount = 0;
		mDistanceTravelled++;
	}
	mDistanceTravelled++;
}

void StatsManager::GetHungry(int playerIndex, int amount)
{
	mPlayers[playerIndex].hungerLevel += amount;
}

void StatsManager::Eat()
{
	// set all players hunger levels to 0
	for (auto& p : mPlayers)
	{
		p.hungerLevel = 0;
	}
}

bool StatsManager::CanContinueTravel() const
{
	bool canContinue = true;
	// user can travel as long as:
	//	- fuel is > 0
	//	- not players have hungerLevel >= EXTREME_HUNGER_LEVEL
	if (mFuelAmount <= 0)
	{
		canContinue = false;
	}

	// Check if any player has hungerLevel >= EXTREME_HUNGER_LEVEL
	for (const auto& player : mPlayers)
	{
		if (player.hungerLevel >= EXTREME_HUNGER_LEVEL)
		{
			canContinue = false;
			break; 
		}
	}

	return canContinue;
}

int StatsManager::GetDistanceTravelled() const
{
	return mDistanceTravelled;
}

void StatsManager::Print()
{
	std::cout << "ROAD TRIP PROGRESS:" << std::endl;
	std::cout << "Distance Travelled: " << mDistanceTravelled << "km" << std::endl;
	std::cout << "Fuel: " << mFuelAmount;
	if (mFuelAmount <= 0)
	{
		std::cout << " (MUST REFUEL)";
	}
	else if (mFuelAmount <= 25)
	{
		std::cout << " (Recommend Refuel)";
	}
	std::cout << std::endl << std::endl;
	std::cout << "PLAYER PROGRESS:" << std::endl;
	// display each of the players status
	//	- show the name
	//	- show the hunger level
	//		- notify the player if they should stop soon (hunger level over warning hunger level)
	//		- notify player if they MUST stop for food (hunger level over extreme hunger level)
	for (const auto& player : mPlayers)
	{
		std::cout << "Player name: " << player.name << "\n";
		std::cout << "Player hunger level: " << player.hungerLevel << "\n";

		if (player.hungerLevel > EXTREME_HUNGER_LEVEL)
		{
			std::cout << player.name << " MUST STOP immediatly! Hunger level is over the extreme hunger level!\n";
		}
		else if (player.hungerLevel > WARNING_HUNGER_LEVEL)
		{
			std::cout << player.name << " should stop soon! Hunger level is over the warning hunger level!\n";
		}
		std::cout << "\n";
	}
}

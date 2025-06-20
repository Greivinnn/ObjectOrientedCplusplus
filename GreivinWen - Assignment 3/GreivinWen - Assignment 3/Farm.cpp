#include "Farm.h"
#include "Sheep.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>

void Farm::AddSheep()
{
	Sheep sheep;
	std::function<void(int, int)> GiveBirthCB = std::bind(&Farm::OnSheepGiveBirth, this, std::placeholders::_1, std::placeholders::_2);
	std::function<void(int, int)> DeathCB = std::bind(&Farm::OnSheepDeath, this, std::placeholders::_1, std::placeholders::_2);
	sheep.SetGiveBirthCallback(GiveBirthCB);
	sheep.SetDeathCallback(DeathCB);
	mFlockOfSheep.push_back(sheep);
	std::cout << "Added sheep ID: " << sheep.GetId() << "\n";
	++mTotalSheepEverAdded;
}

void Farm::FarmStatus(int frames)
{
	std::cout << "Welcome to Benny's farm! Frames set to: " << frames << "\n\n";

	int randomSheepNum = (rand() % 11) + 10;
	std::cout << "Initial addition of " << randomSheepNum << " sheeps\n";

	for (int i = 0; i <= randomSheepNum; ++i)
	{
		AddSheep();
	}
	system("pause");
	for (int i = 0; i < frames; ++i)
	{
		system("cls");
		std::cout << "\n--- Frame: " << i + 1 << " ---\n";

		//sheer sheep when its older than 2
		std::for_each(mFlockOfSheep.begin(), mFlockOfSheep.end(), [](Sheep& sheep)
			{
				if (sheep.GetAge() > 2 && !sheep.IsSheered())
				{
					sheep.Sheer();
					std::cout << "Sheep with ID: " << sheep.GetId() << " has been sheered\n";
				}
			});

		// NOTE: this was the biggest headache of this assignment. I kept getting errors because I could not add the sheep inside the loop 
		// also if i did not set a limit of sheeps the code will just loop infinitly haha
		//50% chance to have babaies when >= 3 years old
		int totalNewSheep = 0;  // Track total babies to add

		const int MAX_SHEEP = 100;  // Set a reasonable limit

		std::cout << "\n"; 

		if (mFlockOfSheep.size() < MAX_SHEEP)  // Only if under limit
		{
			for (Sheep& sheep : mFlockOfSheep)
			{
				if (sheep.GetAge() >= 3)
				{
					int chanceOfBaby = rand() % 2;
					if (chanceOfBaby == 0)
					{
						int numSheepsBorned = (rand() % 2) + 1;
						sheep.CallGiveBirthCB(sheep.GetId(), numSheepsBorned);
						totalNewSheep += numSheepsBorned;

						// Don't exceed the limit
						if (mFlockOfSheep.size() + totalNewSheep >= MAX_SHEEP)
							break;
					}
				}
			}
		}
		
		std::cout << "\n";

		// Add all the new babies after the loop is complete
		if (totalNewSheep != 0)
		{
			for (int i = 0; i < totalNewSheep; ++i)
			{
				AddSheep();
			}
		}
		

		//wolfie sneaks in and kills sheep
		int wolfChance = rand() % 4;
		if (wolfChance == 0 && !mFlockOfSheep.empty())
		{
			int sheepEaten = std::min((rand() % 5) + 1, (int)mFlockOfSheep.size());	//std::min makes sure that wolfie does not eat more than the amount we currently have in mFLockOfSheep
			std::cout << "\n" << sheepEaten << " sheep were eaten by WOLFIE!!!\n";

			for (int j = 0; j < sheepEaten; ++j)
			{
				if (!mFlockOfSheep.empty())
				{
					int randomIndex = rand() % mFlockOfSheep.size();
					int sheepId = mFlockOfSheep[randomIndex].GetId();
					int sheepAge = mFlockOfSheep[randomIndex].GetAge();

					mFlockOfSheep[randomIndex].CallDeathCB(sheepId, sheepAge);	// death call back for the sheep death when wolfie eats them
					mFlockOfSheep.erase(mFlockOfSheep.begin() + randomIndex);
				}
			}
		}

		//if sheep is older than 10 it can die (75%)
		for (auto it = mFlockOfSheep.begin(); it != mFlockOfSheep.end();)
		{
			if (it->GetAge() > 10)
			{
				int deathChance = rand() % 4;
				if (deathChance < 3)
				{
					it->CallDeathCB(it->GetId(), it->GetAge());	// death call back for the sheep dying of old age
					it = mFlockOfSheep.erase(it); // Remove the sheep from the flock
					continue;
				}
			}
			++it;
		}

		//increase age by 1 
		for (Sheep& sheep : mFlockOfSheep)
		{
			sheep.IncreaseAge();
		}
		// sort our vector mFlockOfSheep using std::sort, sorting from oldest to youngest
		std::sort(mFlockOfSheep.begin(), mFlockOfSheep.end(), [](const Sheep& a, const Sheep& b)
			{
				return a.GetAge() > b.GetAge();
			});

		std::cout << "\nSheep sorted by age (oldest to youngest):\n";
		for (Sheep& sheep : mFlockOfSheep)
		{
			std::cout << "Sheep ID: " << sheep.GetId() << ", Age: " << sheep.GetAge() << "\n";
		}

		std::cout << "\n--- Frame " << i + 1 << " Summary ---\n";

		// Count sheered sheep
		int sheeredCount = 0;
		for (const Sheep& sheep : mFlockOfSheep)
		{
			if (sheep.IsSheered())
			{
				sheeredCount++;
			}
		}

		std::cout << "Number of sheep sheered: " << sheeredCount << "\n";
		std::cout << "Number of sheep on the farm: " << mFlockOfSheep.size() << "\n";
		std::cout << "==========================================\n\n";

		system("pause");
	}
	std::cout << "\n==========================================\n";
	std::cout << "          FINAL FARM STATISTICS          \n";
	std::cout << "==========================================\n";
	std::cout << "Total sheep ever added to the farm: " << mTotalSheepEverAdded << "\n";
	std::cout << "Total sheep that have died: " << mTotalSheepDied << "\n";
	std::cout << "Current total sheep on the farm: " << mFlockOfSheep.size() << "\n";
	std::cout << "==========================================\n";
}

void Farm::OnSheepGiveBirth(int id, int numSheepsBorned)
{
	std::cout << "Sheep with ID: " << id << " has given birth to " << numSheepsBorned << " baby sheeps!\n";
}

void Farm::OnSheepDeath(int id, int age)
{
	std::cout << "Sheep with ID: " << id << " has sadly passed away, at age: " << age << "\n";
	++mTotalSheepDied;
}

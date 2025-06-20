#pragma once
#include <vector>
#include "Sheep.h"
#include <iostream>

class Farm
{
public:
	void FarmStatus(int frames);
	void AddSheep();

	void OnSheepGiveBirth(int id, int numSheepsBorned);
	void OnSheepDeath(int id, int age);
private:
	std::vector<Sheep> mFlockOfSheep;
	int mTotalSheepEverAdded = 0;
	int mTotalSheepDied = 0;
};
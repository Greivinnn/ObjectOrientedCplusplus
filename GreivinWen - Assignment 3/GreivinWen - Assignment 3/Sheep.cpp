#include "Sheep.h"
#include <iostream>

Sheep::Sheep()
{
	mId = sNextId++;
	mIsSheered = false;
	mAge = 0;
	mLastSheeredAge = -999;
}

int Sheep::IncreaseAge()
{
	mAge++;

	if (mAge - mLastSheeredAge >= 3)
	{
		ResetSheeredStatus();
	}
	return mAge;
}

void Sheep::SetDeathCallback(std::function<void(int, int)> callback)
{
	mDeathCallback = callback;
}

void Sheep::CallDeathCB(int id, int age)
{
	if (mDeathCallback)
	{
		mDeathCallback(id, age);
	}
}

void Sheep::SetGiveBirthCallback(std::function<void(int, int)> callback)
{
	mGiveBirthCallback = callback;
}

void Sheep::CallGiveBirthCB(int id, int numSheepsBorned)
{
	if (mGiveBirthCallback)
	{
		mGiveBirthCallback(id, numSheepsBorned);
	}
}

void Sheep::Sheer()
{
	mIsSheered = true;
	mLastSheeredAge = mAge;
}

void Sheep::ResetSheeredStatus()
{
	mIsSheered = false;
}

int Sheep::GetId() const
{
	return mId;
}

int Sheep::GetAge() const
{
	return mAge;
}

bool Sheep::IsSheered() const
{
	return mIsSheered;
}

int Sheep::sNextId = 1;

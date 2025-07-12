#include "Actions.h"
#include <iostream>

void Action::SetFuelUpdateCallback(std::function<void(int)> cb)
{
	mFuelUpdate = cb;
}

void Action::SetEatUpdateCallback(std::function<void()> cb)
{
	mEatUpdate = cb;
}
void Action::SetGetHungryUpdateCallback(std::function<void(int, int)> cb)
{
	mGetHungryUpdate = cb;
}

ActionType Action::GetType() const
{
	return mActionType;
}

void Action::Print()
{
	std::cout << mDisplayString << std::endl;
}

RefillFuelAction::RefillFuelAction()
{
	mActionType = ActionType::Refuel;
	mDisplayString = "You stop for gas and refuel the vehicle";
}

void RefillFuelAction::DoAction()
{
	Print();
	mFuelUpdate(mAmount);
}


void GetHungryAction::SetDisplayString(std::string str)
{
	mDisplayString = str;
}
void GetHungryAction::SetTargetIndex(int index)
{
	mTargetIndex = index;
}

void GetHungryAction::DoAction()
{
	Print();
	mFuelUpdate(-1);
	mGetHungryUpdate(mTargetIndex, rand() % 3);
}

EatAction::EatAction()
{
	mActionType = ActionType::Eat;
	mDisplayString = "You stop and everyone gets food";
}

void EatAction::DoAction()
{
	Print();
	mEatUpdate();
}

void RandomAction::SetDisplayString(std::string str)
{
	mDisplayString = std::move(str);
}

void RandomAction::DoAction()
{
	Print();
	mFuelUpdate(-1);
}

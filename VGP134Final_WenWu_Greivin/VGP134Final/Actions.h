#pragma once

#include <string>
#include <functional>

enum class ActionType
{
	Random,
	Eat,
	Refuel
};


class Action
{
public:
	virtual ~Action() = default;
	virtual void DoAction() = 0;
	void SetFuelUpdateCallback(std::function<void(int)> cb);
	void SetEatUpdateCallback(std::function<void()> cb);
	void SetGetHungryUpdateCallback(std::function<void(int, int)> cb);

	ActionType GetType() const;

protected:
	void Print();

	ActionType mActionType = ActionType::Random;
	std::string mDisplayString = "";
	std::function<void(int)> mFuelUpdate = nullptr;
	std::function<void()> mEatUpdate = nullptr;
	std::function<void(int, int)> mGetHungryUpdate = nullptr;
};

class RefillFuelAction : public Action
{
public:
	RefillFuelAction();
	void DoAction() override;

private:
	int mAmount = 100;
};

class GetHungryAction : public Action
{
public:
	void SetTargetIndex(int index);
	void SetDisplayString(std::string str);
	void DoAction() override;

private:
	int mTargetIndex = -1;
	int mAmount = 1;
};

class EatAction : public Action
{
public:
	EatAction();
	void DoAction() override;

private:
	int mAmount = 100;
};

class RandomAction : public Action
{
public:
	void SetDisplayString(std::string str);
	void DoAction() override;
};
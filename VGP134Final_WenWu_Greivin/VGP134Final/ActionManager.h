#pragma once

#include "Actions.h"
#include "StatsManager.h"
#include <map>
#include <vector>


class ActionManager
{
public:
	void SetFuelUpdateCallback(std::function<void(int)> cb);
	void SetEatUpdateCallback(std::function<void()> cb);
	void SetGetHungryUpdateCallback(std::function<void(int, int)> cb);

	void Initialize(const StatsManager& statsManager);
	void Terminate();

	void DoAction(ActionType actionType);

private:
	void AddRandomAction(const std::string& str);
	void AddGetHungryAction(const std::string& name, int index);

	std::map<ActionType, std::vector<Action*>> mActions;
	std::function<void(int)> mFuelUpdate = nullptr;
	std::function<void()> mEatUpdate = nullptr;
	std::function<void(int, int)> mGetHungryUpdate = nullptr;
};
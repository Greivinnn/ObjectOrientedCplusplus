#include "ActionManager.h"
#include <iostream>

void ActionManager::SetFuelUpdateCallback(std::function<void(int)> cb)
{
	// store with correct callback
	mFuelUpdate = cb;
}

void ActionManager::SetEatUpdateCallback(std::function<void()> cb)
{
	// store with correct callback
	mEatUpdate = cb;
}

void ActionManager::SetGetHungryUpdateCallback(std::function<void(int, int)> cb)
{
	// store with correct callback
	mGetHungryUpdate = cb;
}

void ActionManager::Initialize(const StatsManager& statsManager)
{
	// adds all the actions for the game
	// get list of players and add the get hungry actions
	auto players = statsManager.GetPlayers();
	for(int i = 0; i < players.size(); ++i)
	{
		AddGetHungryAction(players[i].name, i);
	}

	// random actions (you can add more if you'd like)
	AddRandomAction("You drive further and see nothing interesting");
	AddRandomAction("You drive further and encounter a deer, everyone smiles as it continues into the woods");
	AddRandomAction("You drive further and change the radio station");
	AddRandomAction("You drive further and decide to switch drivers");
	AddRandomAction("You drive further and everyone gets excited seeing an amusement park, but sad when you say we can't stop");
	AddRandomAction("You drive further and enjoy the sunset");
	AddRandomAction("You drive further and get annoyed because the sun is rising");
	AddRandomAction("You drive further and encounter a new city");

	// eat action
	mActions[ActionType::Eat].push_back(new EatAction());

	// refuel action
	mActions[ActionType::Refuel].push_back(new RefillFuelAction());

	// set all the callbacks
	for (auto& actionsOfType : mActions)
	{
		for (auto& action : actionsOfType.second)
		{
			action->SetEatUpdateCallback(mEatUpdate);
			action->SetFuelUpdateCallback(mFuelUpdate);
			action->SetGetHungryUpdateCallback(mGetHungryUpdate);
		}
	}
}

void ActionManager::Terminate()
{
	// terminate everything
	for (auto& actionsOfType : mActions)
	{
		for (auto& action : actionsOfType.second)
		{
			delete action;
		}
		actionsOfType.second.clear();
	}
	mActions.clear();
}

void ActionManager::DoAction(ActionType actionType)
{
	// find an action with the action type
	// pick a random action from a random action in the vector
	// call DoAction();

	// check if actionType exist in the map and has actions
	auto it = mActions.find(actionType);
	if (it == mActions.end() || it->second.empty())
	{
		std::cout << "No actions available for this type\n";
	}
	// gets the vector of actions for the specified actionType
	auto& actions = it->second;
	// picks a random action from the vector
	int randomIndex = rand() % actions.size();
	Action* selectedAction = actions[randomIndex];
	// calls DoAction()
	selectedAction->DoAction();
	
}

void ActionManager::AddRandomAction(const std::string& str)
{
	// adds a random action
	RandomAction* newAction = new RandomAction();
	newAction->SetDisplayString(str);
	mActions[ActionType::Random].push_back(newAction);
}

void ActionManager::AddGetHungryAction(const std::string& name, int index)
{
	// updates a string to add a get hungry action
	std::string str = name + " is getting hungry";
	GetHungryAction* newAction = new GetHungryAction();
	newAction->SetDisplayString(str);
	newAction->SetTargetIndex(index);
	mActions[ActionType::Random].push_back(newAction);
}

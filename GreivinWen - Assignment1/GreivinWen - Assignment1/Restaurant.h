#pragma once
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <map>
#include "Clients.h"
#include "Group.h"

namespace Assignment1
{
	class Restaurant
	{
	public:
		Restaurant(int numTables = 5);
		void ASCIIArt();
		void AddGroup(const std::list<Clients>& clients);
		void Simulate(int frames = 1);
		bool IsFull() const;
		int GetAvailableTable() const;
		void DisplayStatus() const;
		void Run(int maxFrames = 100);
		std::string GetRandomFood() const;
	private:
		int _numberOfTables;
		std::vector<int> _tableOccupied;  // -1 means empty table
		bool _isFull;
		int _foodReturnFrames;
		std::queue<Group*> _waitList;
		std::map<int, Group*> _activeGroups;  // GroupID -> Group*
		std::map<std::string, int> _mainContact;  // Contact Name -> GroupID
		int _nextGroupId;
		std::vector<std::string> _menu;

		// Helper methods
		void UpdateGroupStatus(Group* group);
		void ProcessOrders(Group* group);
		void ServeFood(Group* group);
		void ProcessPayment(Group* group);
		void FreeTable(int tableNum);
	};
}

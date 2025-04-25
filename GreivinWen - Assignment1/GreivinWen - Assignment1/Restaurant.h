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
		Restaurant();
		void ASCIIArt();

	private:
		int _numberOfTables = 5;
		std::vector<int> _tableOccupied;
		bool _isFull = false;
		int _foodReturnFrames = rand() % 3;
		std::queue<Group> _waitList;
		std::map<std::string, int> _mainContact;
	};
}

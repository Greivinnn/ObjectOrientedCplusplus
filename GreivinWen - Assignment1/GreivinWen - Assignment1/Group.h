#pragma once
#include <list>
#include "Clients.h"

namespace Assignment1
{
	class Group
	{
	public:
		// Status codes:
		// 0 - WAITING FOR TABLE
		// 1 - SEATED
		// 2 - ORDERING
		// 3 - WAITING_FOR_FOOD
		// 4 - EATING
		// 5 - PAYING
		// 6 - LEFT

		Group(std::list<Clients> clientList);
		std::string GetContactName() const;
		std::list<Clients> GetMembers();
		void SetStatus(int status);
		int GetStatus() const;
		int GetMemberCount() const;
		void SetTableNumber(int tableNum);
		int GetTableNumber() const;
		bool UpdateFrames();  // Returns true when frames countdown reaches zero
		int GetRemainingFrames() const;
		void SetRemainingFrames(int frames);
	private:
		std::list<Clients> _groupMembers;
		std::string _contactName;
		int _status;
		int _tableNumber;
		int _remainingFrames;
		//random timing values
		int _enterFrames;
		int _orderFrames;
		int _eatFrames;
	};
}
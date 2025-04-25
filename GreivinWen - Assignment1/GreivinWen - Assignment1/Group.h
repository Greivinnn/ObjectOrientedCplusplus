#pragma once
#include <list>
#include "Clients.h"

namespace Assignment1
{
	class Group
	{
	public:
		Group(std::list<Clients> clientList);
		std::string GetContactName() const;
		std::list<Clients> GetMembers();
	private:
		std::list<Clients> _groupMembers;
		std::string _contactName;
	};
}
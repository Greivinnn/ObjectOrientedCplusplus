#include "Group.h"
#include "Clients.h"
#include <list>
#include <string>

using namespace Assignment1;

Group::Group(std::list<Clients> clientList)
	:_groupMembers(clientList)
{
}
std::string Group::GetContactName() const
{
	return _contactName;
}
std::list<Clients> Group::GetMembers()
{
	return _groupMembers;
}
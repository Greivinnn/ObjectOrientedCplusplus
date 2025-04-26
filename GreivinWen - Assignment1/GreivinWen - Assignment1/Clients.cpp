#include <string>
#include "Clients.h"

using namespace Assignment1;

Clients::Clients(std::string name)
	:_customerName(name), _customerFood("")
{
}

void Clients::SetFood(std::string food)
{
	_customerFood = food;
}

std::string Clients::GetName() const
{
	return _customerName;
}

std::string Clients::GetFood() const
{
	return _customerFood;
}

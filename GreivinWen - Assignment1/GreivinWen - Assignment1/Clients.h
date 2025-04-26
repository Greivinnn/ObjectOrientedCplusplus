#pragma once
#include <string>

namespace Assignment1
{
	class Clients
	{
	public: 
		Clients(std::string name);
		void SetFood(std::string food);
		std::string GetName() const;
		std::string GetFood() const;
	private:
		std::string _customerName;
		std::string _customerFood;
	};
}

#pragma once
#include "Hand.h"
#include <string>

class Player
{
public:
	Player(const std::string& name);
	bool DrawCard();	// draw card from table
	void ReturnCards();	// return cards to the table
	int GetHandValue() const;	// get the hands primary value
	bool IsBust() const;	// check if the players cards bust
	std::pair<int, int> GetHandValues() const;
	const std::string& GetName() const;
private:
	std::string mName;
	Hand mHand;			//player hand
};
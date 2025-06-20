#pragma once
#include <vector>
#include <iostream>
#include "Card.h"

class Hand
{
public:
	std::pair<int, int> GetHandValue() const;
	bool DrawCards(int count);
	void ReturnCards();
private:
	std::vector<std::shared_ptr<Card>> mCards;
};
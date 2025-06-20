#include "Hand.h"
#include "Card.h"
#include "BlackJack.h"
#include <iostream>
#include <vector>

std::pair<int, int> Hand::GetHandValue() const
{
	int value = 0;
	int altValue = 0;
	bool hasAce = false;

	for (const auto& card : mCards)
	{
		value += card->value;
		if (card->number == 'A')
		{
			hasAce = true;
			altValue += 11;
		}
		else
		{
			altValue += card->value;
		}
	}
	if (hasAce && altValue > 21)
	{
		altValue = value;
	}

	return { value, hasAce ? altValue : value };	// ternary operator (like a inline if-else statement)
}
void Hand::DrawCards(int count)
{
	auto* table = BlackJack::Get();
	auto& tableCards = table->GetCards();

	for (int i = 0; i < count && !tableCards.empty(); ++i)
	{
		mCards.push_back(tableCards.back());
		tableCards.pop_back();
	}
}
void Hand::ReturnCards()
{
	auto* table = BlackJack::Get();
	auto& tableCards = table->GetCards();

	for (const auto& card : mCards)
	{
		tableCards.push_back(card);
	}

	mCards.clear();
}
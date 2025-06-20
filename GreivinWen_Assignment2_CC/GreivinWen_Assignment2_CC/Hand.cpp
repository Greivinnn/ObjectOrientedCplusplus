#include "Hand.h"
#include "Card.h"
#include "BlackJack.h"
#include <iostream>
#include <vector>

std::pair<int, int> Hand::GetHandValue() const
{
	int value = 0;
	int altValue = 0;
	int aceCount = 0;

	for (const auto& card : mCards)
	{
		value += card->value;
		altValue += card->value; 
		if (card->number == 'A')
		{
			aceCount++;
		}
	}
	for (int i = 0; i < aceCount; ++i) 
	{
		if (altValue + 10 <= 21) 
		{
			altValue += 10;
		}
	}

	return { value, altValue }; 
}

bool Hand::DrawCards(int count)
{
	auto* table = BlackJack::Get();
	// Check if table or its cards are null, though GetCards() returns a reference, so tableCards itself won't be null.
	// The main concern is if table is null or tableCards is empty.
	if (!table) return false;
	auto& tableCards = table->GetCards();

	if (count <= 0) return false; // Cannot draw zero or negative cards

	// If we reach here, there are enough cards.
	int cardsDrawn = 0;
	for (int i = 0; i < count; ++i)
	{
		if (tableCards.empty()) break; // Should not happen if initial check is correct, but helps debugging
		mCards.push_back(tableCards.back());
		tableCards.pop_back();
		cardsDrawn++;
	}
	return cardsDrawn == count; // Return true if the requested number of cards were drawn
}

void Hand::ReturnCards()
{
	auto* table = BlackJack::Get();
	if (!table) return; // Safety check
	auto& tableCards = table->GetCards();

	for (const auto& card : mCards)
	{
		tableCards.push_back(card);
	}

	mCards.clear();
}

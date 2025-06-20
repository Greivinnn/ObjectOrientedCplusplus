#include "BlackJack.h"
#include "Card.h"
#include <iostream>
#include <vector>

BlackJack* BlackJack::Get()
{
	if (!mInstance)
	{
		mInstance = std::unique_ptr<BlackJack>(new BlackJack());
	}
	return mInstance.get();
}
void BlackJack::Initialize()
{
	mCards.clear();
	std::cout << "BlackJack table initialized.\n";
}
void BlackJack::Terminate()
{
	mCards.clear();
	mCards.shrink_to_fit();	// free any unused memory
	mInstance.reset();		// reset instance
	std::cout << "BlackJack table terminated.\n";
}
void BlackJack::AddDeck(const std::vector<std::shared_ptr<Card>>& newDeck)
{
	mCards.insert(mCards.end(), newDeck.begin(), newDeck.end());
}
const std::vector<std::shared_ptr<Card>>& BlackJack::GetCards() const
{
	return mCards;
}
std::vector<std::shared_ptr<Card>>& BlackJack::GetCards()
{
	return mCards;
}
std::unique_ptr<BlackJack> BlackJack::mInstance = nullptr;	// define the static unique ptr instance 
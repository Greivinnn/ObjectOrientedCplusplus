#include "Player.h"
#include "BlackJack.h"
#include <iostream>

Player::Player(const std::string& name)
	:mName(name)
{
}

bool Player::DrawCard()
{
	return mHand.DrawCards(1);
}

void Player::ReturnCards()
{
	mHand.ReturnCards();
}

int Player::GetHandValue() const
{
	// Returns the "soft" hand value for decision making (Ace as 11 if not busting)
	return mHand.GetHandValue().second;
}

bool Player::IsBust() const
{
	// Bust is determined by the "hard" hand value (Ace as 1)
	int handValue = mHand.GetHandValue().first;
	return handValue > 21;
}

std::pair<int, int> Player::GetHandValues() const
{
	return mHand.GetHandValue();
}

const std::string& Player::GetName() const
{
	return mName;
}

#include "Player.h"
#include "BlackJack.h"
#include <iostream>

Player::Player(const std::string& name)
	:mName(name)
{
}
void Player::DrawCard()
{
	mHand.DrawCards(1);
}
void Player::ReturnCards()
{
	mHand.ReturnCards();
}
int Player::GetHandValue() const
{
	return mHand.GetHandValue().second;
}
bool Player::IsBust() const	//check this out
{
	int handValue = mHand.GetHandValue().first;
	return handValue > 21;
}
const std::string& Player::GetName() const
{
	return mName;
}
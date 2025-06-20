#pragma once

// Global enus of card type and card suit
enum class Suit 
{
	Hearts,
	Diamonds,
	Clubs,
	Spades
};
enum class CardType
{
	Ace,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King
};
// Card struct 
struct Card
{
	Suit suit;
	char number;	// card number as char
	int value;		// actual card value
	int altValue;	//alternative value for A (1 or 11)

	Card(Suit suit, char number, int value, int altValue = 0)
		:suit(suit), number(number), value(value), altValue(altValue)
	{
	}
};
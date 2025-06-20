#pragma once
#include <vector>
#include <iostream>
#include "Card.h"

// singleton with unique_ptr as instance and shared_ptrs for vectors

class BlackJack
{
public:
	static BlackJack* Get();	// access fuction for singleton

	// delete: 1. copy constructor, 2. move constructor, 3. copy operator, 4. move operator
	BlackJack(BlackJack&) = delete;		//1
	BlackJack(BlackJack&&) = delete;	//2
	BlackJack& operator=(BlackJack&) = delete;	//3
	BlackJack& operator=(BlackJack&&) = delete;	//4

	//initialize and terminate methods:
	void Initialize();
	void Terminate();

	//functions:
	void AddDeck(const std::vector<std::shared_ptr<Card>>& newDeck);	//add a deck of cards
	const std::vector<std::shared_ptr<Card>>& GetCards() const;			//get all cards from deck
	std::vector<std::shared_ptr<Card>>& GetCards(); // not constant method for us to call and modify the vector without restrictions 
private:
	BlackJack() = default;	// private constructor
	static std::unique_ptr<BlackJack> mInstance;	//singleton instance with unique_ptr
	std::vector<std::shared_ptr<Card>> mCards;		//vector of shared pointers to card stuct
};
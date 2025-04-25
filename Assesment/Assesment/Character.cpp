#include "Character.h"
#include <iostream>
#include <string>
#include <time.h>;
#include <stdlib.h>

using namespace Assesment;

Character::Character()
{
}

Character::Character(std::string name, int def, int atk, int hlt, int lvl)
	: characterName(name), characterDefence(def), characterAttack(atk), characterHealth(hlt), characterLevel(lvl)
{
}

void Character::DisplayCharacterStats(Character& firstChar, Character& secondChar)
{
	// Character 1 stats
	std::cout << "First Character Stats:\n";
	std::cout << "Name: " << firstChar.characterName;
	std::cout << "\nDefence: " << firstChar.characterDefence;
	std::cout << "\nAttack: " << firstChar.characterAttack;
	std::cout << "\nHealth: " << firstChar.characterHealth;
	std::cout << "\nLevel: " << firstChar.characterLevel;

	// Character 2 stats
	std::cout << "\n\nSecond Character Stats:\n";
	std::cout << "\nName: " << secondChar.characterName;
	std::cout << "\nDefence: " << secondChar.characterDefence;
	std::cout << "\nAttack: " << secondChar.characterAttack;
	std::cout << "\nHealth: " << secondChar.characterHealth;
	std::cout << "\nLevel: " << secondChar.characterLevel;
	std::cout << "\n\n";
}

void Character::BattleLogic(Character& firstChar, Character& secondChar)
{
	int battleRounds;
	int whoStarts = rand() % 2;
	int randomXP = rand() % 5 + 1;
	int randomXP2 = rand() % 5 + 1;
	int randomStatSelector = rand() % 3;
	int randomStatSelector2 = rand() % 3;
	int firstCharXP = 0;
	int secondCharXP = 0;
	int charFirstDamage = firstChar.characterAttack - firstChar.characterDefence;
	int charSecondDamage = secondChar.characterAttack - secondChar.characterDefence;

	system("cls");
	DisplayCharacterStats(firstChar, secondChar);

	std::cout << "Please input a number of iterations (battle rounds): ";
	std::cin >> battleRounds;

	for (int i = 0; i <= battleRounds; i++)
	{
		if (whoStarts == 0)	// first character starts
		{
			std::cout << firstChar.characterName << "'s turn:\n";
			std::cout << firstChar.characterName << " just attacked " << secondChar.characterName << " dealing " << charFirstDamage << "\n";
			secondChar.characterHealth -= charFirstDamage;
			std::cout << firstChar.characterName << " has just earned " << randomXP << " xp" << "\n";
			firstCharXP += randomXP;
			if (firstCharXP >= 5)
			{
				firstCharXP -= 5;
				firstChar.characterLevel++;
				std::cout << firstChar.characterName << " has leveled up!\n";
				if (randomStatSelector == 0)
				{
					std::cout << "Increasing " << firstChar.characterName << "'s attack by 3 points...\n";
					firstChar.characterAttack += 3;
				}
				else if (randomStatSelector == 1)
				{
					std::cout << "Increasing " << firstChar.characterName << "'s defence by 3 points...\n";
					firstChar.characterDefence += 3;
				}
				else
				{
					std::cout << "Increasing " << firstChar.characterName << "'s health by 3 points...\n";
					firstChar.characterHealth += 3;
				}
			}
			if (secondChar.characterHealth <= 0)
			{
				std::cout << "\nCongratualations " << firstChar.characterName << " has won the battle!\n";
				break;
			}

			std::cout << "\n\n" << secondChar.characterName << "'s turn:\n";
			std::cout << secondChar.characterName << " just attacked " << firstChar.characterName << " dealing " << charSecondDamage << "\n";
			firstChar.characterHealth -= charSecondDamage;
			std::cout << secondChar.characterName << " has just earned " << randomXP2 << " xp\n";
			secondCharXP += randomXP2;
			if (secondCharXP >= 5)
			{
				secondCharXP -= 5;
				secondChar.characterLevel++;
				std::cout << secondChar.characterName << " has leveled up!\n";
				if (randomStatSelector2 == 0)
				{
					std::cout << "Increasing " << secondChar.characterName << "'s attack by 3 points...\n";
					secondChar.characterAttack += 3;
				}
				else if (randomStatSelector2 == 1)
				{
					std::cout << "Increasing " << secondChar.characterName << "'s defence by 3 points...\n";
					secondChar.characterDefence += 3;
				}
				else
				{
					std::cout << "Increasing " << secondChar.characterName << "'s health by 3 points...\n";
					secondChar.characterHealth += 3;
				}
			}
			if (firstChar.characterHealth <= 0)
			{
				std::cout << "\nCongratualations " << secondChar.characterName << " has won the battle!\n";
				break;
			}
		}
		else // else second character starts
		{
			std::cout << "\n\n" << secondChar.characterName << "'s turn:\n";
			std::cout << secondChar.characterName << " just attacked " << firstChar.characterName << " dealing " << charSecondDamage << "\n";
			firstChar.characterHealth -= charSecondDamage;
			std::cout << secondChar.characterName << " has just earned " << randomXP2 << " xp\n";
			secondCharXP += randomXP2;
			if (secondCharXP >= 5)
			{
				secondCharXP -= 5;
				secondChar.characterLevel++;
				std::cout << secondChar.characterName << " has leveled up!\n";
				if (randomStatSelector2 == 0)
				{
					std::cout << "Increasing " << secondChar.characterName << "'s attack by 3 points...\n";
					secondChar.characterAttack += 3;
				}
				else if (randomStatSelector2 == 1)
				{
					std::cout << "Increasing " << secondChar.characterName << "'s defence by 3 points...\n";
					secondChar.characterDefence += 3;
				}
				else
				{
					std::cout << "Increasing " << secondChar.characterName << "'s health by 3 points...\n";
					secondChar.characterHealth += 3;
				}
			}
			if (firstChar.characterHealth <= 0)
			{
				std::cout << "\nCongratualations " << secondChar.characterName << " has won the battle!\n";
				break;
			}

			std::cout << firstChar.characterName << "'s turn:\n";
			std::cout << firstChar.characterName << " just attacked " << secondChar.characterName << " dealing " << charFirstDamage << "\n";
			secondChar.characterHealth -= charFirstDamage;
			std::cout << firstChar.characterName << " has just earned " << randomXP << " xp\n";
			firstCharXP += randomXP;
			if (firstCharXP >= 5)
			{
				firstCharXP -= 5;
				firstChar.characterLevel++;
				std::cout << firstChar.characterName << " has leveled up!\n";
				if (randomStatSelector == 0)
				{
					std::cout << "Increasing " << firstChar.characterName << "'s attack by 3 points...\n";
					firstChar.characterAttack += 3;
				}
				else if (randomStatSelector == 1)
				{
					std::cout << "Increasing " << firstChar.characterName << "'s defence by 3 points...\n";
					firstChar.characterDefence += 3;
				}
				else
				{
					std::cout << "Increasing " << firstChar.characterName << "'s health by 3 points...\n";
					firstChar.characterHealth += 3;
				}
			}
			if (secondChar.characterHealth <= 0)
			{
				std::cout << "\nCongratualations " << firstChar.characterName << " has won the battle!\n";
				break;
			}
		}
	}
	system("pause");
	system("cls");
	std::cout << "Final Stats:\n\n";
	DisplayCharacterStats(firstChar, secondChar);
	std::cout << "\n\nThank You For Playing :)\n\n";
}

void Character::CreateCharacter()
{
	// variables
	srand(time(NULL));
	std::string name;
	int attack;
	int defence;
	int health;
	int level;

	//Logic
	std::cout << "Please provide the first character name: ";
	std::cin >> name;

	std::cout << "Next, provide the first character defence stats: ";
	std::cin >> defence;

	std::cout << "Next, provide the first character attack stats (please make it higher than the defence): ";
	std::cin >> attack;

	std::cout << "Next, provide the first character health points: ";
	std::cin >> health;

	std::cout << "Finally, provide the first character level: ";
	std::cin >> level;

	Character character1(name, defence, attack, health, level);
	std::cout << "\nFirst character created succesfully!\n\n";
	
	std::cout << "Please provide the second character name: ";
	std::cin >> name;

	std::cout << "Next, provide the second character defence stats: ";
	std::cin >> defence;

	std::cout << "Next, provide the second character attack stats (please make it higher than the defence): ";
	std::cin >> attack;

	std::cout << "Next, provide the second character health points: ";
	std::cin >> health;

	std::cout << "Finally, provide the second character level: ";
	std::cin >> level;
	
	Character character2(name, defence, attack, health, level);
	std::cout << "\nSecond character created succesfully!\n\n";
	
	system("pause");

	BattleLogic(character1, character2);
}
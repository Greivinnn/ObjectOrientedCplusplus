#pragma once
#include <string>
#include <iostream>

namespace Assesment
{
	class Character
	{
	public:
		Character();
		Character(std::string name, int def, int atk, int hlt, int lvl);
		void CreateCharacter();
		void DisplayCharacterStats(Character& firstChar, Character& secondChar);
		void BattleLogic(Character& firstChar, Character& secondChar);
	private:
		std::string characterName;
		int characterDefence;
		int characterAttack;
		int characterHealth;
		int characterLevel;
	};
}

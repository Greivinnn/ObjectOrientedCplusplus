#include "PetRegistry.h"
#include <iostream>

// convert pet type to display it
std::string PetTypeToString(Pet::PetType type)
{
	switch (type)
	{
	case Pet::Dog: return "Dog";
	case Pet::Cat: return "Cat";
	case Pet::Bird: return "Bird";
	case Pet::Bunny: return "Bunny";
	case Pet::Fish: return "Fish";
	default: return "Invalid";
	}
}

// private constructor
PetRegistry::PetRegistry() : nextId(1){}

// get singleton instance
PetRegistry& PetRegistry::GetInstance()
{
	static PetRegistry instance;
	return instance;
}

// register a new pet and return its ID
int PetRegistry::RegisterPet(Pet::PetType type, const std::string& name, int age)
{
	// register the new pet here
	Pet newPet;
	newPet.petId = nextId++;
	newPet.petType = type;
	newPet.petName = name;
	newPet.petAge = age;
	pets.push_back(newPet);

	// print the pet added here
	std::cout << "Added pet:\nID->" << newPet.petId
		<< "\nType->" << newPet.petType <<
		"\nName->" << newPet.petName << "\nAge->"
		<< newPet.petAge;
	
	return newPet.petId;
}
#include "PetRegistry.h"
#include <iostream>

int PetRegistry::_petId = 1;	// pet id that increases when called +1

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

PetRegistry* PetRegistry::Get()
{
	static PetRegistry instance;
	return &instance;
}

// register a new pet and return its ID
int PetRegistry::RegisterPet(Pet::PetType type, std::string name, int age)
{
	// register the new pet here
	Pet newPet;
	newPet.petId = _petId++;
	newPet.petType = type;
	newPet.petName = name;
	newPet.petAge = age;
	_registeredAnimals.push_back(newPet);

	// print the pet added here
	std::cout << "Added pet:\nID->" << newPet.petId
		<< "\nType->" << PetTypeToString(newPet.petType) <<
		"\nName->" << newPet.petName << "\nAge->"
		<< newPet.petAge << "\n\n";
	
	return newPet.petId;
}

std::vector<int> PetRegistry::GetPetIdsOfType(Pet::PetType animal)
{
	std::vector<int> petIds;

	if (animal == Pet::Invalid)	// if invalid print everything
	{
		for (auto pet : _registeredAnimals)
		{
			petIds.push_back(pet.petId);	// this pushes all existing ids inside _registeredAnimals and puts into our petIds vector so we can return it
		}
	}
	else // else get the animal type and print the ids of that animal 
	{
		for (auto pet : _registeredAnimals)
		{
			if (pet.petType == animal)
			{
				petIds.push_back(pet.petId);
			}
		}
	}
	return petIds;
}

Pet PetRegistry::GetPet(int id)
{
	for (auto pet : _registeredAnimals)
	{
		if (pet.petId == id)
		{
			return pet;
		}
	}
	throw std::runtime_error("Pet with the given ID not found.\n");
}
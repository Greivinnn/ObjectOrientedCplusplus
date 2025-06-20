#include "PetRegistry.h"
#include "PetStore.h"
#include "time.h"
#include <iostream>

void PetStore::SellPet()
{
	PetRegistry* registry = PetRegistry::Get(); // acces the singleton instace of PetRegistry, this is only done in singleton classes

	std::vector<int> allPetIds = registry->GetPetIdsOfType(Pet::Invalid);	// gets all the pet ids from the function GetPetIdsOfType

	if (allPetIds.empty()) // if no animals
	{
		std::cout << "No pets available for sale, so sorry!\n";
		return;
	}

	int randomIndex = std::rand() % allPetIds.size();
	int petIdToSell = allPetIds[randomIndex];

	try
	{
		Pet pet = registry->GetPet(petIdToSell);
		//print the info of the pet we are selling
		std::cout << "Pet Sold!\n" << "ID: " << pet.petId
			<< "\nType: " << PetTypeToString(pet.petType)
			<< "\nName: " << pet.petName
			<< "\nAge: " << pet.petAge << "\n\n";
	}
	catch (std::runtime_error e)
	{
		std::cout << "Error: " << e.what() << "\n\n";
	}
}
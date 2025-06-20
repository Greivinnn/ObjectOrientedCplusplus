#include "PetVet.h"
#include "PetRegistry.h"
#include <iostream>

void PetVet::DoCheckUp(int id)
{
	PetRegistry* registry = PetRegistry::Get();

	try
	{
		Pet pet = registry->GetPet(id);
		std::cout << "This pet has been to the vet!\n" << "ID: " << pet.petId
			<< "\nType: " << PetTypeToString(pet.petType)
			<< "\nName: " << pet.petName
			<< "\nAge: " << pet.petAge << "\n\n";
	}
	catch (std::runtime_error e)
	{
		std::cout << "Error: " << e.what() << "\n\n";
	}
}
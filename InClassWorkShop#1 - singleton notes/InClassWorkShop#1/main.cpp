#include <iostream>
#include <string>
#include "PetRegistry.h"
#include "PetStore.h"
#include "PetVet.h"

int main()
{
    // Access the singleton instance of PetRegistry
    PetRegistry* registry = PetRegistry::Get();

    // Register a few pets
    registry->RegisterPet(Pet::Dog, "Buddy", 3);
    registry->RegisterPet(Pet::Cat, "Whiskers", 2);
    registry->RegisterPet(Pet::Bird, "Tweety", 1);
    registry->RegisterPet(Pet::Dog, "Max", 4);
    registry->RegisterPet(Pet::Fish, "Goldie", 1);
    registry->RegisterPet(Pet::Bunny, "Thumper", 2);
    registry->RegisterPet(Pet::Dog, "Charlie", 5);
    registry->RegisterPet(Pet::Cat, "Mittens", 3);
    registry->RegisterPet(Pet::Bird, "Polly", 2);
    registry->RegisterPet(Pet::Fish, "Nemo", 1);

    // Create a PetStore and sell 10 random pets
    PetStore store;
    store.SellPet();
    store.SellPet();
    store.SellPet();
    store.SellPet();
    store.SellPet();
    store.SellPet();
    store.SellPet();
    store.SellPet();
    store.SellPet();
    store.SellPet();

    // Create a PetVet and perform checkups by type
    PetVet vet;
    vet.DoCheckUp(Pet::Dog);
    vet.DoCheckUp(Pet::Cat);
    vet.DoCheckUp(Pet::Bird);
    vet.DoCheckUp(Pet::Fish);
    vet.DoCheckUp(Pet::Bunny);

    return 0;
}

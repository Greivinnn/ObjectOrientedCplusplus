#pragma once
#include <string>
#include <vector>

struct Pet
{
    enum PetType { Invalid, Dog, Cat, Bird, Bunny, Fish };
    PetType petType;
    std::string petName;
    int petAge;
    int petId;
};

// convert PetType to string to print
std::string PetTypeToString(Pet::PetType type);

class PetRegistry
{
public:
    static PetRegistry* Get();

    PetRegistry(PetRegistry&) = delete;     // copy constructor delete
    PetRegistry(PetRegistry&&) = delete;    // move constructor delete
    PetRegistry& operator=(PetRegistry&) = delete;      // copy operator
    PetRegistry& operator=(PetRegistry&&) = delete;     // move operator

    // singleton functions
    int RegisterPet(Pet::PetType, std::string name, int petAge);
    std::vector<int> GetPetIdsOfType(Pet::PetType);
    Pet GetPet(int id);
private:
    PetRegistry() = default;    // must have private constructor
    std::vector<Pet> _registeredAnimals;
    static int _petId;
};

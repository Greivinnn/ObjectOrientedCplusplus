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
private:
    // vector to store all registered pets
    std::vector<Pet> pets;

    //current ID counter for assigning unique IDs
    int nextId;

    // private constructor for singleton pattern
    PetRegistry();

    //delete copy constructor and assignment operator
    PetRegistry(const PetRegistry&) = delete;
    PetRegistry& operator=(const PetRegistry&) = delete;

public:
    //get singleton instance
    static PetRegistry& GetInstance();

    //register a new pet and return its ID
    int RegisterPet(Pet::PetType type, const std::string& name, int age);

    //get IDs of pets of a specific type (or all pets if type is invalid)
    std::vector<int> GetPetIdsOfType(Pet::PetType type);

    // get pet id by ID (returns nullptr if invalid)
    const Pet* GetPet(int id) const;
};

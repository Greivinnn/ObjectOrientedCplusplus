#pragma once

#include "Weapon.h"
#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>

class FindByNameFunctor
{
public:
    FindByNameFunctor(const std::string& name) : mName(name) {}

    bool operator()(const Weapon& weapon) const
    {
        return weapon.name == mName;
    }

private:
    std::string mName = "";
};

class WeaponContainer
{
public:
    // adding the GetWeaponType method
    std::string GetWeaponTypeName(Weapon::WeaponType weaponType);
    // confirms if a weapon with the name exists
    bool HasWeaponName(const std::string& name);
    // adds weapon to the container
    bool AddWeapon(const Weapon& weapon);
    // removes weapon from the container with the specified name
    bool RemoveWeapon(const std::string& name);
    // get the weapon data with the specified name
    Weapon GetWeapon(const std::string& name);
    // update the weapon with the weapon data
    bool UpdateWeapon(const Weapon& data);
    // prints all the weapons of the specific type (prints all if weapon type is Invalid)
    void Print(Weapon::WeaponType weaponType = Weapon::Invalid);

private:
    using WeaponTypeCollection = std::vector<Weapon>;
    std::unordered_map<Weapon::WeaponType, WeaponTypeCollection> mWeaponCollection;
};
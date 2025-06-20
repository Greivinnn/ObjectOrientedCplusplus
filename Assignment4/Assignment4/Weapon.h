#pragma once

#include <string>

struct Weapon
{
    enum WeaponType
    {
        Invalid,
        Sword,
        Bow,
        Staff,
        Spear,
        Hammer,
        Axe,
        Count
    };

    WeaponType weaponType = Invalid;
    std::string name = "";
    int damage = 0;
    int range = 0;
    int maxAmmo = 0;
    bool starter = false;
};
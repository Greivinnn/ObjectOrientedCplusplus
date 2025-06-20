// Assignment4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "WeaponContainer.h"

Weapon CreateWeapon(Weapon::WeaponType weaponType, const std::string& name, int damage, int range, int maxAmmo, bool starter)
{
    Weapon newWeapon;
    newWeapon.weaponType = weaponType;
    newWeapon.name = name;
    newWeapon.damage = damage;
    newWeapon.range = range;
    newWeapon.maxAmmo = maxAmmo;
    newWeapon.starter = starter;
    return newWeapon;
}

void ViewAllWeapons(WeaponContainer& weaponContainer)
{
    system("cls");
    weaponContainer.Print();
}

void ViewWeaponsOfType(WeaponContainer& weaponContainer)
{
    std::string response = "";
    bool exit = false;
    while (!exit)
    {
        system("cls");
        std::cout << "View Weapons Of Type\n";
        std::cout << "Specify Weapon Type (q to go back):\n";

        std::cin >> response;

        if (response == "q")
        {
            exit = true;
            continue;
        }

        //create a weapontype and set it to invalid
        Weapon::WeaponType weaponType = Weapon::Invalid;

        if (response == "Sword")
        {
            weaponType = Weapon::Sword;
        }
        else if (response == "Bow")
        {
            weaponType = Weapon::Bow;
        }
        else if (response == "Staff")
        {
            weaponType = Weapon::Staff;
        }
        else if (response == "Spear")
        {
            weaponType = Weapon::Spear;
        }
        else if (response == "Hammer")
        {
            weaponType = Weapon::Hammer;
        }
        else if (response == "Axe")
        {
            weaponType = Weapon::Axe;
        }
        else
        {
            std::cout << "Invalid weapon type. Please try again.\n";
            system("pause");
            continue;
        }
        // if the type is valid print the weapons under that type
        std::cout << "\n";
        weaponContainer.Print(weaponType);

        system("pause");
    }
}

void ViewWeapon(WeaponContainer& weaponContainer)
{
    std::string response = "";
    bool exit = false;

    while (!exit)
    {
        system("cls");
        std::cout << "Search and View Weapons From Your Container\n";
        std::cout << "Specify Weapon Name (q to go back):\n";

        std::cin >> response;

        if (response == "q")
        {
            exit = true;
            continue;
        }

        if (weaponContainer.HasWeaponName(response))
        {
            Weapon weapon = weaponContainer.GetWeapon(response);
            std::cout << "\nWeapon Found in Container:\n";
            std::cout << "Name: " << weapon.name << "\n";
            std::cout << "Type: " << weaponContainer.GetWeaponTypeName(weapon.weaponType) << "\n";
            std::cout << "Damage: " << weapon.damage << "\n";
            std::cout << "Range: " << weapon.range << "\n";
            std::cout << "Max Ammo: " << weapon.maxAmmo << "\n";
            std::cout << "Starter: " << (weapon.starter ? "Yes" : "No") << "\n";
        }
        else
        {
            std::cout << "Weapon not found. Please try again!\n";
            system("pause");
            continue;
        }

        system("pause");
    }
}

void AddWeapon(WeaponContainer& weaponContainer)
{
    
    bool exit = false;
    std::string newName = "";
    int chooseType = 0;
    int newDamage = 0;
    int newRange = 0;
    int newMaxAmmo = 0;
    std::string newStarter = "";
    bool newStarterBool = false;
    while (!exit)
    {
        system("cls");
        try
        {
            std::cout << "Add any weapon you'd like (no repeated names)\n\n";
            std::cout << "Please choose the type of weapon you want to create (0 to exit):\n";
            std::cout << "1. Sword || 2. Bow || 3. Staff || 4. Spear || 5. Hammer || 6. Axe ||\n";
            std::cout << "Choice: ";
            std::cin >> chooseType;

            if (std::cin.fail()) // Check if input is invalid
            {
                throw std::invalid_argument("Invalid input. Please retry again!");
            }

            if (chooseType == 0)
            {
                exit = true;
                continue;
            }
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "Error: " << e.what() << "\n";
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input from the stream to prevent infinite loops 
            system("pause");
            continue; // Restart the loop
        }

        if (chooseType < 1 || chooseType > 6)
        {
            std::cout << "Error, number of type not found!\n";
            system("pause");
            continue;
        }

        Weapon::WeaponType weaponType = Weapon::Invalid;
        switch (chooseType)
        {
        case 1: weaponType = Weapon::Sword; break;
        case 2: weaponType = Weapon::Bow; break;
        case 3: weaponType = Weapon::Staff; break;
        case 4: weaponType = Weapon::Spear; break;
        case 5: weaponType = Weapon::Hammer; break;
        case 6: weaponType = Weapon::Axe; break;
        }

        std::cout << "Enter new weapon name (no spaces): ";
        std::cin >> newName;

        if (weaponContainer.HasWeaponName(newName) == true)
        {
            std::cout << "Sorry that weapon name already exist!\n";
            system("pause");
            continue;
        }
        
        std::cout << "Enter the damage of new weapon (1-100): ";
        std::cin >> newDamage;

        if (newDamage < 1 || newDamage > 100)
        {
            std::cout << "Error, damage amount passed allowed limit!\n";
            system("pause");
            continue;
        }

        std::cout << "Enter the range of new weapon (1-7): ";
        std::cin >> newRange;

        if (newRange < 1 || newRange > 7)
        {
            std::cout << "Error, range amount passed allowed limit!\n";
            system("pause");
            continue;
        }

        std::cout << "Enter the max ammo of new weapon (cannot be less than 1): ";
        std::cin >> newMaxAmmo;

        if (newMaxAmmo < 1)
        {
            std::cout << "Error, Max Ammo cannot be negative!\n";
            system("pause");
            continue;
        }

        std::cout << "Do you want to make this weapon a starter? (y/n): ";
        std::cin >> newStarter;

        if (newStarter == "y")
        {
            newStarterBool = true;
        }
        else if (newStarter == "n")
        {
            newStarterBool = false;
        }
        else
        {
            std::cout << "Error, Invalid choice defaulting to no starter!\n";
            newStarterBool = false;
        }

        Weapon newWeapon = CreateWeapon(weaponType, newName, newDamage, newRange, newMaxAmmo, newStarterBool);

        if (weaponContainer.AddWeapon(newWeapon))
        {
            std::cout << "Succesfully added a new weapon to container!\n\n";
            std::cout << "Name: " << newWeapon.name << "\n";
            std::cout << "Type: " << weaponContainer.GetWeaponTypeName(newWeapon.weaponType) << "\n";
            std::cout << "Damage: " << newWeapon.damage << "\n";
            std::cout << "Range: " << newWeapon.range << "\n";
            std::cout << "Max Ammo: " << newWeapon.maxAmmo << "\n";
            std::cout << "Starter: " << (newWeapon.starter ? "Yes" : "No") << "\n";
        }
        else
        {
            std::cout << "Failed to add weapon to container. Please try again\n";
        }

        break;
    }
    
}

void EditWeapon(WeaponContainer& weaponContainer)
{
    bool exit = false;
    int choice = 0;
    std::string weaponName = "";

    while (!exit)
    {
        system("cls");
        std::cout << "Weapon Editor\n\n";
        std::cout << "Enter the name of the weapon you want to edit (q to go back): ";
        std::cin >> weaponName;

        if (weaponName == "q")
        {
            exit = true;
            continue;
        }

        if (!weaponContainer.HasWeaponName(weaponName))
        {
            std::cout << "Weapon not found. Please try again!\n";
            system("pause");
            continue;
        }

        Weapon weapon = weaponContainer.GetWeapon(weaponName);

        try
        {
            std::cout << "Please choose a value to edit:\n";
            std::cout << "|| 1. Weapon Damage || 2. Weapon Range || 3. Weapon MaxAmmo || 4. Waepon starter ||\n";
            std::cout << "Choice: ";
            std::cin >> choice;

            if (std::cin.fail()) // Check if input is invalid
            {
                throw std::invalid_argument("Invalid input. Please retry again!");
            }
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "Error: " << e.what() << "\n";
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input from the stream to prevent infinite loops 
            system("pause");
            continue; // Restart the loop
        }

        if (choice < 1 || choice > 4)
        {
            std::cout << "Error, number of type not found!\n";
            system("pause");
            continue;
        }

        if (choice == 1)
        {
            int newDamage;
            std::cout << "Enter new damage (1-100): ";
            std::cin >> newDamage;

            if (newDamage < 1 || newDamage > 100)
            {
                std::cout << "Error: Damage must be between 1 and 100.\n";
                system("pause");
                continue;
            }

            weapon.damage = newDamage;
        }
        else if (choice == 2)
        {
            int newRange;
            std::cout << "Enter new range (1-7): ";
            std::cin >> newRange;

            if (newRange < 1 || newRange > 7)
            {
                std::cout << "Error: Range must be between 1 and 7.\n";
                system("pause");
                continue;
            }

            weapon.range = newRange;
        }
        else if (choice == 3)
        {
            int newMaxAmmo;
            std::cout << "Enter new max ammo (must be 1 or greater): ";
            std::cin >> newMaxAmmo;

            if (newMaxAmmo < 1)
            {
                std::cout << "Error: Max ammo must be 1 or greater.\n";
                system("pause");
                continue;
            }

            weapon.maxAmmo = newMaxAmmo;
        }
        else if (choice == 4)
        {
            std::string newStarter;
            std::cout << "Set as starter weapon? (y/n): ";
            std::cin >> newStarter;

            if (newStarter == "y")
            {
                weapon.starter = true;
            }
            else if (newStarter == "n")
            {
                weapon.starter = false;
            }
            else
            {
                std::cout << "Invalid input. Defaulting to 'no'.\n";
                weapon.starter = false;
            }
        }

        if (weaponContainer.UpdateWeapon(weapon))
        {
            std::cout << "Weapon updated successfully!\n\n";
            std::cout << "Name: " << weapon.name << "\n";
            std::cout << "Type: " << weaponContainer.GetWeaponTypeName(weapon.weaponType) << "\n";
            std::cout << "Damage: " << weapon.damage << "\n";
            std::cout << "Range: " << weapon.range << "\n";
            std::cout << "Max Ammo: " << weapon.maxAmmo << "\n";
            std::cout << "Starter: " << (weapon.starter ? "Yes" : "No") << "\n";
        }
        else
        {
            std::cout << "Failed to update weapon. Please try again.\n";
        }

        system("pause");
    }
}

void RemoveWeapon(WeaponContainer& weaponContainer)
{
    bool exit = false;
    int choice = 0;
    std::string weaponName = "";

    while (!exit)
    {
        system("cls");
        std::cout << "Delete Weapon\n\n";
        std::cout << "Please enter the weapon you wish to delete (q to exit): ";
        std::cin >> weaponName;

        if (weaponName == "q")
        {
            exit = true;
            continue;
        }

        if (!weaponContainer.HasWeaponName(weaponName))
        {
            std::cout << "Weapon not found. Please try again!\n";
            system("pause");
            continue;
        }

        if (weaponContainer.RemoveWeapon(weaponName))
        {
            std::cout << "\n\nWeapon has successfully been remove from the container\n\n";
        }
        else
        {
            std::cout << "\n\nError: something went wrong. Please try again!\n\n";
        }
        
        system("pause");
    }
}

int main()
{
    WeaponContainer weaponContainer;

    std::string response = "";
    bool running = true;

    //Add to container & create 2 weapon of each type
    //Sword type weapons
    weaponContainer.AddWeapon(CreateWeapon(Weapon::Sword, "SteelBlade", 50, 2, 0, false));
    weaponContainer.AddWeapon(CreateWeapon(Weapon::Sword, "BronzeSword", 20, 2, 0, false));
    //Bow type weapons
    weaponContainer.AddWeapon(CreateWeapon(Weapon::Bow, "FireBow", 30, 5, 15, false));
    weaponContainer.AddWeapon(CreateWeapon(Weapon::Bow, "LongBow", 50, 6, 10, false));
    //Staff type weapons
    weaponContainer.AddWeapon(CreateWeapon(Weapon::Staff, "WoodenStaff", 20, 4, 0, false));
    weaponContainer.AddWeapon(CreateWeapon(Weapon::Staff, "MetalStaff", 35, 4, 0, false));
    //Spear type weapons
    weaponContainer.AddWeapon(CreateWeapon(Weapon::Spear, "BronzeSpear", 15, 4, 0, false));
    weaponContainer.AddWeapon(CreateWeapon(Weapon::Spear, "GoldSpear", 30, 4, 0, false));
    //Hammer type weapons
    weaponContainer.AddWeapon(CreateWeapon(Weapon::Hammer, "SteelHammer", 20, 2, 0, false));
    weaponContainer.AddWeapon(CreateWeapon(Weapon::Hammer, "ShortHammer", 55, 1, 0, false));
    //Axe type weapons
    weaponContainer.AddWeapon(CreateWeapon(Weapon::Axe, "WoodenAxe", 5, 2, 0, false));
    weaponContainer.AddWeapon(CreateWeapon(Weapon::Axe, "BronzeAxe", 10, 2, 0, false));

    while (running)
    {
        system("cls");
        std::cout << "Weapon Editor\n";
        std::cout << "Pick An Option:\n";
        std::cout << "[1] View All Weapons\n";
        std::cout << "[2] View All Weapons Of Type\n";
        std::cout << "[3] View Weapon\n";
        std::cout << "[4] Add Weapon\n";
        std::cout << "[5] Edit Weapon\n";
        std::cout << "[6] Remove Weapon\n";
        std::cout << "[q] Quit\n";

        std::cin >> response;

        if (response == "q")
        {
            running = false;
            continue;
        }

        if (response == "1")
        {
            ViewAllWeapons(weaponContainer);
        }
        else if (response == "2")
        {
            ViewWeaponsOfType(weaponContainer);
        }
        else if (response == "3")
        {
            ViewWeapon(weaponContainer);
        }
        else if (response == "4")
        {
            AddWeapon(weaponContainer);
        }
        else if (response == "5")
        {
            EditWeapon(weaponContainer);
        }
        else if (response == "6")
        {
            RemoveWeapon(weaponContainer);
        }

        system("pause");
    }
}


// Assignment 4
// The Weapon Editor
// Finish up the program
//  - Weapon should not need to be modified
//  - WeponContainer should not need to be updated, but has return values that can help handle errors
// Add 2-3 weapons manually for each type
// Ask the user to make a selection (view all weapons, view weapons of type, view weapon, add weapon, edit weapon, remove weapon)
// When user makes a selection, display should show the mode
// MODES:
//      - View All Weapons
//          - display all the weapons (use weaponContainer.Print()) ✓
//      - View All Weapons Of Type
//          - ask user for a weapon type ✓
//          - display all the weapons for the specified type (use weaponContainer.Print(weaponType)) ✓
//      - View Weapon
//          - ask user for a weapon name ✓
//          - find the weapon and display the info ✓
//          - if not found, let user know it was not found ✓
//      - Add Weapon
//          - ask user for a weapon name (it must be unique, no other weapon can have this name) ✓
//          - ask user for each other weapon stat (weapon type, damage, range, maxAmmo, starter) ✓
//          - ensure all inputs are valid ✓
//          - display if the weapon was added successfully ✓
//      - Edit Weapon
//          - ask user for the weapon name ✓
//          - if found, ask what value to update ✓
//          - get the value from the player, apply to the weapon data, add it back to the weapon container ✓
//          - ensure all inputs are valid ✓
//          - display if the edit was made successfully ✓
//      - Remove Weapon
//          - ask user for the weapon name ✓
//          - if the weapon name is found, remove the weapon ✓
//          - display if the weapon was removed successfully ✓
// When player inputs information, ensure the information is valid (int should be an int, float should be a float, bool should be a bool, string should be a string)
// if the input is invalid, let the user know the information was incorrect and repeat the request until the expected information is inputed
//      - damage must be more than 0 and less than 100 ✓
//      - range must be more than 0 and less than 7 ✓
//      - name can't be the same as another weapon ✓

//Mark Breakdown :
//Application builds and runs :               50
//Application functions as described :        20
//Build includes handles errors each state :  20
//Coding standards, minor errors :            10
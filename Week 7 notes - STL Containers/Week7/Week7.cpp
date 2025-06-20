// Week7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <set>
#include <vector>

enum class WeaponType
{
    Sword,
    Staff,
    Spear,
    Hammer
};

struct Weapon
{
    int att;
};

void DoMapExample()
{

    std::map<WeaponType, Weapon> weapons;

    if (weapons.empty())
    {
        std::cout << "Weapons container is empty\n";
    }

    // INSERT
    // insert or add to the container
    // [] will override if key already exists
    weapons[WeaponType::Sword] = Weapon();
    // insert will not override if key already exists
    weapons.insert({ WeaponType::Sword, Weapon() });
    //auto ret = weapons.insert({ WeaponType::Sword, Weapon() });
    //if(ret.second) // if true, insert was successful, it was a new key, if false, key already exists

    // FIND
    //  works, but if it doesnt exist, will add a new value
    if (weapons[WeaponType::Hammer].att > 0)
    {
        std::cout << "We have a hammer\n";
    }
    // find returns iterator if key is found
    if (weapons.find(WeaponType::Spear) != weapons.end())
    {

    }

    // looping through the map
    for (std::map<WeaponType, Weapon>::iterator iter = weapons.begin(); iter != weapons.end(); ++iter)
    {
        //iter.first is the key value
        //iter.second is the data
        //weapons.erase(iter); // removes value from the map
    }

    enum KeyValues { Hello, World, Im, Here };
    std::map<int, std::string> stringMap;
    stringMap.insert({ Hello, "Hello" });
    stringMap.insert({ World, "World" });
    stringMap.insert({ Im, "I'm" });
    stringMap.insert({ Here, "Here" });

    if ("Hello" != "World")
        if (strcmp("Hello", "World") != 0)
        {

        }
    if (Hello != World)
    {
        std::cout << "The value is " << stringMap[Hello] << "\n";
    }

    std::cout << "No Hammer\n";
}

class Student
{
public:
    Student(const std::string& name, int mark)
        : mName(name)
        , mMark(mark)
    {
    }

    bool operator<(const Student& other) const
    {
        if (mMark == other.mMark)
        {
            return mName < other.mName;
        }
        return mMark > other.mMark;
    }

    void Print() const
    {
        std::cout << "Student: " << mName << " - Mark: " << mMark << "\n";
    }
private:
    std::string mName;
    int mMark;
};
void DoSetExample()
{
    std::set<int> setNumbers;
    setNumbers.insert(8);
    setNumbers.insert(2);
    setNumbers.insert(7);
    setNumbers.insert(10);
    setNumbers.insert(4);
    setNumbers.insert(5);
    setNumbers.insert(6);
    setNumbers.insert(1);
    setNumbers.insert(3);
    setNumbers.insert(9);

    std::cout << "8 2 7 10 4 5 6 1 3 9 \n";
    for (std::set<int>::iterator iter = setNumbers.begin(); iter != setNumbers.end(); ++iter)
    {
        std::cout << (*iter) << " ";
    }
    std::cout << "\n";

    for (std::set<int>::iterator iter = setNumbers.lower_bound(4); iter != setNumbers.upper_bound(8); ++iter)
    {
        std::cout << (*iter) << " ";
    }
    //auto range = setNumbers.equal_range(4); // more for multi sets, only returns next value
    std::cout << "\n";


    std::set<Student> students;
    students.insert(Student("Bob", 10));
    students.insert(Student("Jayden", 50));
    students.insert(Student("Ryan", 2));
    students.insert(Student("Steve", 75));
    students.insert(Student("Alli", 100));
    students.insert(Student("Jesse", 80));
    students.insert(Student("Lilli", 95));
    students.insert(Student("Lorri", 100));

    for (auto iter = students.begin(); iter != students.end(); ++iter)
    {
        iter->Print();
    }

    auto newMark = students.find(Student("Lorri", 100));
    if (newMark != students.end())
    {
        students.erase(newMark);
        students.insert(Student("Lorri", 95));
    }
    std::cout << "\n\n";
    for (auto iter = students.begin(); iter != students.end(); ++iter)
    {
        iter->Print();
    }
}

void DoMultiMapExample()
{
    std::multimap<WeaponType, Weapon> weapons;
    weapons.insert({ WeaponType::Sword, { 10 } });
    weapons.insert({ WeaponType::Sword, { 5 } });
    weapons.insert({ WeaponType::Sword, { 12 } });
    weapons.insert({ WeaponType::Sword, { 3 } });
    weapons.insert({ WeaponType::Spear, { 4 } });
    weapons.insert({ WeaponType::Spear, { 4 } });
    weapons.insert({ WeaponType::Spear, { 6 } });
    weapons.insert({ WeaponType::Staff, { 1 } });
    weapons.insert({ WeaponType::Staff, { 12 } });
    weapons.insert({ WeaponType::Staff, { 5 } });

    for (auto iter = weapons.begin(); iter != weapons.end(); ++iter)
    {
        std::cout << (int)iter->first << " : " << iter->second.att << "\n";
    }
    std::cout << "\n\n";
    auto swords = weapons.equal_range(WeaponType::Sword);
    for (auto iter = swords.first; iter != swords.second; ++iter)
    {
        std::cout << (int)iter->first << " : " << iter->second.att << "\n";
        if (iter->second.att == 10)
        {
            weapons.erase(iter);
            break;
        }
    }
    std::cout << "\n\n";
    for (auto iter = weapons.begin(); iter != weapons.end(); ++iter)
    {
        std::cout << (int)iter->first << " : " << iter->second.att << "\n";
    }

    // typically what is seen in games, but there is a memory overhead for this use
    // if adding/removing a lot, this is inefficient
    //std::map<WeaponType, std::vector<Weapon>> weaponsVector;
    //weaponsVector[WeaponType::Sword].size();
}

int main()
{
    std::cout << "Hello World!\n";
    //DoMapExample();
    //DoSetExample();
    DoMultiMapExample();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#include "VolleyballLeague.h"
#include <iostream>

Tier gCurrentTier = Tier::Tier1;
int gNumTeams = 0;
void VolleyballLeague::AddTeam(const std::string& name)
{
    mSchedules[gCurrentTier].AddTeam(name);
    ++gNumTeams;
    if (gNumTeams % 4 == 0 && gCurrentTier != Tier::Tier4)
    {
        gCurrentTier = (Tier)((int)gCurrentTier + 1);
    }
}

void VolleyballLeague::PlayMatch()
{
    for (auto& schedules : mSchedules)
    {
        for (int i = 0; i < 3; ++i)
        {
            schedules.second.PlayMatch();
        }
    }
}

void VolleyballLeague::Print()
{
    std::cout << "Final Results\n";
    for (auto& schedules : mSchedules)
    {
        std::cout << "Tier " << (int)schedules.first + 1 << ":\n";
        schedules.second.Print();
    }
}

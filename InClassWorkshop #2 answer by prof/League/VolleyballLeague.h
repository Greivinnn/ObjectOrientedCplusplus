#pragma once

#include "Tier.h"
#include "Schedule.h"
#include <map>

class VolleyballLeague
{
public:
    void AddTeam(const std::string& name);
    void PlayMatch();

    void Print();

private:
    std::map<Tier, Schedule> mSchedules;
};
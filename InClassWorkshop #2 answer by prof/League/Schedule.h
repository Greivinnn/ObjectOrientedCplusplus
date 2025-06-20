#pragma once

#include "Team.h"
#include <set>

class Schedule
{
public:
    void PlayMatch();
    void AddTeam(const std::string& name);

    void Print();

private:
    std::set<Team> mTeams;
};
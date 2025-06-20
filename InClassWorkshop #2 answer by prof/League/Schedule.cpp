#include "Schedule.h"
#include <vector>

void Schedule::PlayMatch()
{
    std::vector<Team> temp;
    for (auto iter = mTeams.begin(); iter != mTeams.end(); ++iter)
    {
        temp.push_back((*iter));
    }
    mTeams.clear();
    for (Team& team : temp)
    {
        team.score += rand() % 3;
        mTeams.insert(team);
    }
}

void Schedule::AddTeam(const std::string& name)
{
    Team newTeam;
    newTeam.name = name;
    mTeams.insert(newTeam);
}

void Schedule::Print()
{
    for (auto iter = mTeams.begin(); iter != mTeams.end(); ++iter)
    {
        std::cout << "Team: " << iter->name << " : " << iter->score << "\n";
    }
    std::cout << "\n";
}

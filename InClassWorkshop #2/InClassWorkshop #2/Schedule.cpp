#include "Schedule.h"
#include "Team.h"
#include <vector>
#include <iostream>

Schedule::Schedule()
    :team(nullptr), mTeams()
{
}

void Schedule::PlayMatch()
{
    // temp set to store the information we want to add
    std::set<Team> tempTems;   
    for (auto team : mTeams)
    {
        int randomPoints = rand() % 3; // 0-2 random points generator
        team.sScore += randomPoints;    // add the points to the team
        tempTems.insert(team);  // add the team with the new points to the temp set
    }
    mTeams = tempTems; //set the Teams set original set to be equal to the tempTeams
}

void Schedule::AddTeam(const std::string& name)
{
    Team newTeam;
    newTeam.sTeamName = name;
    mTeams.insert(newTeam);
}

std::set<Team> Schedule::GetTeams() const
{
    return mTeams;
}

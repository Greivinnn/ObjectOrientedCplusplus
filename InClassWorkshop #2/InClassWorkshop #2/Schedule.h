#pragma once
#include <set>

struct Team;

class Schedule
{
public:
	Schedule();
	Team* team;
	void PlayMatch();
	void AddTeam(const std::string& name);
	std::set<Team> GetTeams() const;
private:
	std::set<Team> mTeams;
};
#pragma once
#include <map>
#include "Schedule.h"
#include "Tier.h"

class VolleyballLeague
{
public:
	VolleyballLeague();
	void AddTeam();
private:
	std::map<Tier, Schedule> mLeagueMap;
};
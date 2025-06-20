#pragma once
#include <string>

struct Team
{
	std::string sTeamName;
	int sScore = 0;

	// overload operator< to let the set know we are comparing based by score
	bool operator<(const Team& other) const
	{
		if (sScore == other.sScore)
		{
			return sTeamName < other.sTeamName;
		}
		return sScore > other.sScore;
	}
};
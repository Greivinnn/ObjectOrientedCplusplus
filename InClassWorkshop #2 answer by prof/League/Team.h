#pragma once

#include <iostream>
#include "Tier.h"

struct Team
{
    std::string name;
    int score = 0;

    // arrow points to front of the set
    bool operator<(const Team& other) const
    {
        if (score == other.score)
        {
            return name < other.name;
        }
        return score > other.score;
    }
    bool operator<(const Team* other) const
    {
        if (score == other->score)
        {
            return name < other->name;
        }

        return score > other->score;
    }
};
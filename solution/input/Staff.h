#pragma once

#include <vector>
#include "Qualification.h"

class Staff {
public:
    using Id = int;

private:
    Id id;
    int level;
    int maxHours;
    std::vector<std::string> qualifications;
    int minStart;
    int maxStart;


    std::vector<Qualification> quals;
    std::vector<int> maxFlyInMonth;
    std::vector<int> restReqs;
    std::vector<int> restPriors;
};
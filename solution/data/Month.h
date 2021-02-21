#pragma once

#include <vector>
#include <map>
#include "Staff.h"

class Month {
public:

private:
    bool isTop;
    int maxVacationSize;
    std::map<Qualification::Id, int> hoursNeed;
    std::map<Staff::Id, int> staffRequests;
};

#pragma once

#include "Staff.h"
#include "Request.h"

#include <vector>
#include <map>

class Month {
public:
    Month(bool isTop_, int maxVacationSize_, std::map<Qualification::Id, int> hoursNeed_)
        : isTop(isTop_), maxVacationSize(maxVacationSize_), hoursNeed(move(hoursNeed_)) { }

    void addRequest(Request request) {
        staffRequests[request.getStaff()];
    }

private:
    bool isTop;
    int maxVacationSize;
    std::map<Qualification::Id, int> hoursNeed;
    std::map<Staff::Id, Request> staffRequests;
};

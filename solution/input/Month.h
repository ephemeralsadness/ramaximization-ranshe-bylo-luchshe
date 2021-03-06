#pragma once

#include "Staff.h"
#include "Request.h"

#include <vector>
#include <map>

class Month {
public:
    Month() = default;

    Month(bool isTop_, int maxVacationSize_, std::map<Qualification::Id, int> hoursNeed_)
        : isTop(isTop_), maxVacationSize(maxVacationSize_), hoursNeed(move(hoursNeed_)) { }

    void addRequest(Request request) {
        staffRequests[request.getStaffId()];
    }

    bool isTop = false;
    int maxVacationSize = 0;
    std::map<Qualification::Id, int> hoursNeed;
    std::map<Staff::Id, Request> staffRequests;
};

#pragma once

#include "Staff.h"

class Request {
public:
    Request() {}
    double calculateRating() {}
    Staff::Id getStaff() {}
private:
    Staff::Id staffId;
    int priority;
};
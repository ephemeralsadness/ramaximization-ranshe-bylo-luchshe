#pragma once

#include "Staff.h"

class Request {
public:
    Request();
    calculateRating();



private:
    Staff::Id staffId;
    int priority;
};
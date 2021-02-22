#pragma once

#include "Staff.h"

class Request {
public:
    Request();
    int calculateRating() {
        // TODO calculate rating.
    }

private:
    Staff::Id staffId;
    int priority;
};
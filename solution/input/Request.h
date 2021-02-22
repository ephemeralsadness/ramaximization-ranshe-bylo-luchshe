#pragma once

#include "Staff.h"

class Request {
public:
    Request(Staff::Id staffId_, int priority_) : staffId(staffId_), priority(priority_) {}

    Staff::Id getStaffId() {
        return staffId;
    }

    int getPriority() {
        return priority;
    }

private:
    Staff::Id staffId;
    int priority;
};
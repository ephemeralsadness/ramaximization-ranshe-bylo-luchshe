#pragma once

#include "Staff.h"

class Request {
public:
    Request(Staff::Id staffId_, int priority_, int month_, int hours_)
        : staffId(staffId_), priority(priority_), month(month_), hours(hours_) { }

    Staff::Id getStaff() {
        return staffId;
    }

    int getPriority() {
        return priority;
    }

    int getMonth() {
        return month;
    }

    int getHours() {
        return hours;
    }

private:
    Staff::Id staffId;
    int priority;
    int month;
    int hours;
};
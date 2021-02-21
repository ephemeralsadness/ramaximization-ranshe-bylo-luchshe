#pragma once

#include <vector>
#include "Qual.h"

class Person {
    int priority,
        minStart,
        maxStart;

    std::vector<Qual> quals;
    std::vector<int> maxFlyInMonth;
    std::vector<int> restReqs;
    std::vector<int> restPriors;
};
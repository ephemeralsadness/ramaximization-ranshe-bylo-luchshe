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
    std::vector<Qualification::Id> qualifications;
    int minStart;
    int maxStart;
};
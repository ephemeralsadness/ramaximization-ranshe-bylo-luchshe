#pragma once

#include <vector>
#include "Qualification.h"

class Staff {
public:
    using Id = int;

    int getLevel() {
        return level;
    }

private:
    Id id;
    int level;
    int maxHours;
    std::vector<Qualification::Id> qualifications;
    int minStart;
    int maxStart;
};
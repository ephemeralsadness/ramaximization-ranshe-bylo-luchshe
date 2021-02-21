#pragma once

#include <vector>
#include <map>

class Month {
    int number,
        maxSize;
    bool isPriority;
    std::map<Qual, int> requestsNeed;
};

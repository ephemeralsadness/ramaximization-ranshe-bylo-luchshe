#pragma once

#include <string>

class Qualification {
public:
    Qualification() {};

    using Id = std::string;

    Id name;
    int level;
};
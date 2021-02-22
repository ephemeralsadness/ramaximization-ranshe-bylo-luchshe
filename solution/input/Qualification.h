#pragma once

#include <string>


// TODO сделать компаратор объектов Qualification

class Qualification {
public:
    Qualification() {};

    using Id = std::string;

    Id name;
    int level;
    int priority;
};
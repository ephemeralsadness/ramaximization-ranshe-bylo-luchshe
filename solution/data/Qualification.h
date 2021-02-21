#pragma once

#include <string>


// TODO сделать компаратор объектов Qualification

class Qualification {
public:
    using Id = std::string;
private:
    Id name;
    int level;
    int priority;
};
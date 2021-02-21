#pragma once

#include "Qual.h"
#include "Month.h"
#include "Person.h"

#include <vector>

class InputData {
public:

private:
    std::vector<Qual> quals;
    std::vector<Month> month;
    std::vector<Person> persons;
};

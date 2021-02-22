#pragma once

#include <vector>
#include <string>
#include <map>

struct constants {
    static const std::vector<std::string> CSV_TABLE_NAMES;

    static const std::vector<std::string> REST_CONSTANT_NAMES;

    static std::map<std::string, int> REST_CONSTANTS;

    static const std::string CSV;

    static int MAX_PERSONAL_LEVEL;
};


#pragma once

#include <vector>
#include <string>

class Reader {
public:


private:
    static std::vector<std::vector<std::string>> readFromCSV(const std::string& filename);
};
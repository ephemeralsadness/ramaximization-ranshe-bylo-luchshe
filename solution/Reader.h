#pragma once

#include "data/InputData.h"

#include <vector>
#include <string>
#include <map>

class Reader {
public:
    using StringTable = std::vector<std::vector<std::string>>;

    static InputData readInputData(const std::string& folderName);
private:
    static std::map<std::string, StringTable> makeCSVMap(const std::string& folderName);
    static StringTable readFromCSV(const std::string& filename);
};
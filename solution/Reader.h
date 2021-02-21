#pragma once

#include <vector>
#include <string>
#include <map>

class Reader {
public:
    using StringTable = std::vector<std::vector<std::string>>;

    void readInputData(const std::string& folderName);
private:
    std::map<std::string, StringTable> makeCSVMap(const std::string& folderName);
    static StringTable readFromCSV(const std::string& filename);
};
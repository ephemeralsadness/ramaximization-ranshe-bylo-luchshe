#include "Reader.h"
#include "constants.h"

#include <fstream>
#include <sstream>

using namespace std;

map<string, Reader::StringTable> Reader::makeCSVMap(const std::string& folderName) {
    map<string, Reader::StringTable> csvMap;
    for (const string& name : constants::CSV_TABLE_NAMES) {
        const string filePath = folderName + "/" + name + constants::CSV;
        Reader::StringTable table = readFromCSV(filePath);
        csvMap[name] = move(table);
    }

    return csvMap;
}


Reader::StringTable Reader::readFromCSV(const string& filename) {
    ifstream ifs(filename);

    vector<vector<string>> data;

    while (!ifs.eof()) {
        data.emplace_back();
        string s;
        getline(ifs, s);
        istringstream iss(s);
        while (!iss.eof()) {
            string t;
            getline(iss, t, ',');
            data.back().emplace_back(t);
        }
    }

    if (!data.empty() && data.back().empty())
        data.pop_back();
    data.shrink_to_fit();

    return data;
}

InputData Reader::readInputData(const std::string& folderName) {

}
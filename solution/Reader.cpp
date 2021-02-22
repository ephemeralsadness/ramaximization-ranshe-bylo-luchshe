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

InputData Reader::getInputData(const std::string& folderName) {
    year = std::vector<Month>(12, Month());

    for (const auto& fileName : constants::CSV_TABLE_NAMES) {
        fileName == "max_fly" ? readMaxFly() :
        fileName == "max_starts" ? readMaxStarts() :
        fileName == "months" ? readMonths() :
        fileName == "params" ? readParams() :
        fileName == "personal_levels" ? readPersonalLevels() :
        fileName == "qualified" ? readQualified() :
        fileName == "qual_levels" ? readQualLevels() :
        fileName == "quals" ? readQuals() :
        fileName == "required_personal" ? readRequiredPersonal() :
        fileName == "rest_prior" ? readRestPrior() :
        fileName == "rest_req" ? rest_req() :
        fileName == "starts" ? starts() : nothing();
    }

    return InputData(year, staff, qualifications, requests);
}

void Reader::readMaxFly() {
    Reader::StringTable table = readFromCSV("max_fly");

}

void Reader::readMaxStarts() {
    Reader::StringTable table = readFromCSV("max_starts");
};

void Reader::readMonths() {
    Reader::StringTable table = readFromCSV("months");
};

void Reader::readParams() {
    Reader::StringTable table = readFromCSV("params");
};

void Reader::readPersonalLevels() {
    Reader::StringTable table = readFromCSV("personal_levels");
};

void Reader::readQualified() {
    Reader::StringTable table = readFromCSV("qualified");
};

void Reader::readQualLevels() {
    Reader::StringTable table = readFromCSV("qual_levels");
};

void Reader::readQuals() {
    Reader::StringTable table = readFromCSV("quals");
};

void Reader::readRequiredPersonal() {
    Reader::StringTable table = readFromCSV("required_personal");
};

void Reader::readRestPrior() {
    Reader::StringTable table = readFromCSV("rest_prior");
};

void Reader::rest_req() {
    Reader::StringTable table = readFromCSV("rest_req");
};

void Reader::starts() {
    Reader::StringTable table = readFromCSV("starts");
};

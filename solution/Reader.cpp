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
    Reader::StringTable idTable = readFromCSV("personal_levels");
    for (int i = 0; i < table.size(); ++i) {
        Staff::Id id = stoi(idTable[i][0]);
        staff[id] = Staff();
        staff[id].maxHours = stoi(table[i][0]);
    }
}

void Reader::readMaxStarts() {
    Reader::StringTable table = readFromCSV("max_starts");
    for (int i = 0; i < table.size(); ++i) {
        staff[i].maxStart = stoi(table[i][0]);
    }
};

void Reader::readMonths() {
    Reader::StringTable table = readFromCSV("months");
    for (int i = 0; i < table.size(); ++i) {
        int month = stoi(table[i][0]) - 1;
        int isTop = stoi(table[i][1]);
        int maxRest = stoi(table[i][2]);
        year[month].isTop = isTop;
        year[month].maxVacationSize = maxRest;
    }
};

void Reader::readParams() {
    Reader::StringTable table = readFromCSV("params");
    for (int i = 0; i < table.size(); ++i) {
        constants::REST_CONSTANTS[table[i][0]] = stoi(table[i][1]);
    }
};

void Reader::readPersonalLevels() {
    Reader::StringTable table = readFromCSV("personal_levels");
    for (int i = 0; i < table.size(); ++i) {
        Staff::Id id = stoi(table[i][0]);
        int level = stoi(table[i][1]);
        staff[id].level = level;
    }
};

void Reader::readQualLevels() {
    Reader::StringTable table = readFromCSV("qual_levels");
    Reader::StringTable idTable = readFromCSV("quals");
    for (int i = 0; i < table.size(); ++i) {
        Qualification::Id id = idTable[i][0];
        qualifications[id] = Qualification();
        qualifications[id].name = id;
        qualifications[id].level = stoi(table[i][0]);
    }
};

void Reader::readQualified() {
    Reader::StringTable table = readFromCSV("qualified");
    Reader::StringTable idTable = readFromCSV("quals");
    for (int i = 0; i < table.size(); ++i) {
        Qualification::Id id = idTable[i][0];
        qualifications[id]
    }
};


void Reader::readQuals() {
    Reader::StringTable table = readFromCSV("quals");
    Reader::StringTable idPersonalTable = readFromCSV("personal_levels");
    Reader::StringTable idQualTable = readFromCSV("quals");
    for (int i = 0; i < idPersonalTable.size(); ++i) {
        Staff::Id id = stoi(idPersonalTable[i][0]);
        for (int j = 0; j < idQualTable.size(); ++j) {
            Qualification::Id qualId = idQualTable[j][0];
            if (stoi(table[j][i]) == 1) {
                staff[id].qualifications.push_back(qualId);
            }
        }
    }
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

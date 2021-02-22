#pragma once

#include "input/InputData.h"

#include <vector>
#include <string>
#include <map>

class Reader {
public:
    using StringTable = std::vector<std::vector<std::string>>;
    InputData getInputData(const std::string& folderName);

private:
    std::vector<Month> year;
    std::map<Staff::Id, Staff> staff;
    std::map<Qualification::Id, Qualification> qualifications;
    std::vector<Request> requests;

    static std::map<std::string, StringTable> makeCSVMap(const std::string& folderName);
    static StringTable readFromCSV(const std::string& filename);

    void readMaxFly();
    void readMaxStarts();
    void readMonths();
    void readParams();
    void readPersonalLevels();
    void readQualLevels();
    void readQualified();
    void readQuals();
    void readRequiredPersonal();
    void readRestPrior();
    void rest_req();
    void starts();
    void nothing();
};
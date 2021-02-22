#include "InputData.h"

using namespace std;

Month& InputData::getMonth(int monthNumber) {
    return year.at(monthNumber);
}

Staff& InputData::getStaff(Staff::Id id) {
    return staff.at(id);
}

Qualification& InputData::getQualification(const Qualification::Id& id) {
    return qualifications.at(id);
}

vector<Request>& InputData::getRequests() {
    return requests;
}

int InputData::GetRestYear() const {
    return constants::REST_CONSTANTS[constants::REST_CONSTANT_NAMES[0]];
}

int InputData::GetMinRestSize() const {
    return constants::REST_CONSTANTS[constants::REST_CONSTANT_NAMES[1]];
}

int InputData::GetMinLag() const {
    return constants::REST_CONSTANTS[constants::REST_CONSTANT_NAMES[2]];
}

int InputData::GetTotalRests() const {
    return constants::REST_CONSTANTS[constants::REST_CONSTANT_NAMES[3]];
}

int InputData::GetPriorRests() const {
    return constants::REST_CONSTANTS[constants::REST_CONSTANT_NAMES[4]];
}

int InputData::GetNoPriorRests() const {
    return constants::REST_CONSTANTS[constants::REST_CONSTANT_NAMES[5]];
}

int InputData::GetRestHigh() const {
    return constants::REST_CONSTANTS[constants::REST_CONSTANT_NAMES[6]];
}

int InputData::GetRestLow() const {
    return constants::REST_CONSTANTS[constants::REST_CONSTANT_NAMES[7]];
}

int InputData::GetNMonth() const {
    return constants::REST_CONSTANTS[constants::REST_CONSTANT_NAMES[8]];
}

int InputData::GetNQ() const {
    return constants::REST_CONSTANTS[constants::REST_CONSTANT_NAMES[9]];
}

#include "InputData.h"

Month& InputData::getMonth(int monthNumber) {
    return year.at(monthNumber);
}

Staff& InputData::getStaff(Staff::Id id) {
    return staff.at(id);
}

Qualification& InputData::getQualification(const Qualification::Id& id) {
    return qualifications.at(id);
}

std::vector<Request>& InputData::getRequests() {
    return requests;
}
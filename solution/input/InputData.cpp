#include "InputData.h"

using namespace std;

Staff& InputData::getStaff(Staff::Id id) {
    return staff.at(id);
}

std::map<Staff::Id, Staff>& InputData::getAllStaff() {
    return staff;
}

Qualification& InputData::getQualification(const Qualification::Id& id) {
    return qualifications.at(id);
}

vector<Request>& InputData::getRequests() {
    return requests;
}

Month& InputData::getMonth(int monthNumber) {
    return year.at(monthNumber);
}

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
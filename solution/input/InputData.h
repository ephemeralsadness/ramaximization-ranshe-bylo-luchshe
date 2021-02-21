#pragma once

#include "Qualification.h"
#include "Month.h"
#include "Staff.h"
#include "Request.h"

#include <vector>

class InputData {
public:
    InputData(std::array<Month, 12> year_, std::map<Staff::Id, Staff> staff_,
              std::map<Qualification::Id, Qualification> qualifications_, std::vector<Request> requests_)
              : year(move(year_))
              , staff(move(staff_))
              , qualifications(move(qualifications_))
              , requests(move(requests_)) { }

    Month& getMonth(int monthNumber);
    Staff& getStaff(Staff::Id id);
    Qualification& getQualification(const Qualification::Id& id);
    std::vector<Request>& getRequests();
private:
    std::array<Month, 12> year;
    std::map<Staff::Id, Staff> staff;
    std::map<Qualification::Id, Qualification> qualifications;
    std::vector<Request> requests;
};

#pragma once

#include "Qualification.h"
#include "Month.h"
#include "Staff.h"
#include "Request.h"
#include "../constants.h"


#include <vector>

class InputData {
public:
    InputData(std::vector<Month> year_, std::map<Staff::Id, Staff> staff_,
              std::map<Qualification::Id, Qualification> qualifications_, std::vector<Request> requests_)
              : year(move(year_))
              , staff(move(staff_))
              , qualifications(move(qualifications_))
              , requests(move(requests_)) { }

    Month& getMonth(int monthNumber);
    Staff& getStaff(Staff::Id id);
    std::map<Staff::Id, Staff>& getAllStaff();
    Qualification& getQualification(const Qualification::Id& id);
    std::vector<Request>& getRequests();
    int GetRestYear() const; //возвращает параметр REST_YEAR
    int GetMinRestSize() const; //возвращает MIN_REST_SIZE
    int GetMinLag() const; // возвращает MIN_REST_LAG
    int GetTotalRests() const; // возвращает TOTAL_RESTS
    int GetPriorRests() const;// возвращает PRIOR_RESTS
    int GetNoPriorRests() const;// возвращает ..
    int GetRestHigh() const;// возвращает..
    int GetRestLow() const;// возвращает..
    int GetNMonth() const;// возвращает..
    int GetNQ() const;// возвращает..

private:
    std::vector<Month> year;
    std::map<Staff::Id, Staff> staff;
    std::map<Qualification::Id, Qualification> qualifications;
    std::vector<Request> requests;
};

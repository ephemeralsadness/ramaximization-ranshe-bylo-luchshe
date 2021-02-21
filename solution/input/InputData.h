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
    std::vector<std::vector<int>> GetWantedRests() const; // возвращает запрошенные часы отдыха каждым работником по месяцам (упорядоченные по id)
    std::vector<int> GetRequestsRates() const; //должно возвращать вектор пощитанных векторов заявок для каждого работника (упорядоченный по id)
    std::vector<std::vector<int>> GetWantedWorkHours() const; //возвращает необходимое каждый месяц число часов работы
    int GetRestYear() const; //возвращает параметр REST_YEAR
private:
    std::array<Month, 12> year;
    std::map<Staff::Id, Staff> staff;
    std::map<Qualification::Id, Qualification> qualifications;
    std::vector<Request> requests;
};

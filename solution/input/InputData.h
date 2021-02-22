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
    Qualification& getQualification(const Qualification::Id& id);
    std::vector<Request>& getRequests();
    std::vector<std::vector<int>> GetWantedRests() const; // возвращает запрошенные часы отдыха каждым работником по месяцам (упорядоченные по id)
    std::vector<int> GetRequestsRates() const; //должно возвращать вектор пощитанных векторов заявок для каждого работника (упорядоченный по id)
    std::vector<std::vector<int>> GetWantedWorkHours() const; //возвращает необходимое каждый месяц число часов работы
    std::vector<bool> GetCoolMonth() const; //возвращает вектор в котором 1 значит что месяц классный, а 0 - обычный
    std::vector<int> GetMaxFlies() const; //возвращает максимальные допустиме часы работы у работников
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

#pragma once
#include <map>
#include <vector>
#include "../input/Qualification.h"
#include "PersonalRest.h"
#include "TotalRest.h"
#include "MonthResult.h"

class OutputData {
public:
    OutputData() {
        qualDeficits = std::vector<std::vector<int>>(12, std::vector<int>(10));
        workingHours = std::vector<std::vector<int>>(12, std::vector<int>(10));
    }

    std::vector<PersonalRest> personalRests;
    std::vector<TotalRest> totalRests;

    // [месяц][квалификация] = количество дифицита
    std::vector<std::vector<int>> qualDeficits;

    // [месяц][квалификация] =  количество проработанных часов
    std::vector<std::vector<int>> workingHours;

    //[месяъ]
    std::vector<MonthResult> monthResults;
};
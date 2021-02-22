#pragma once
#include <map>
#include <vector>
#include "../input/Qualification.h"
#include "PersonalRest.h"
#include "TotalRest.h"
#include "MonthResult.h"

class OutputData {
public:
    std::vector<PersonalRest> personalRests;
    std::vector<TotalRest> totalRests;

    // [месяц][квалификация] = количество дифицита
    std::vector<std::vector<int>> qualDeficits;

    // [месяц][квалификация] =  количество проработанных часов
    std::vector<std::vector<int>> workingHours;

    //[месяъ]
    std::vector<MonthResult> monthResults;
};
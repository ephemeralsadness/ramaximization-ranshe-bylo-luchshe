#pragma once

#include <map>
#include <vector>
#include "../input/Qualification.h"
#include "PersonalRest.h"
#include "TotalRest.h"
#include "MonthResult.h"

class OutputData {
    std::vector<PersonalRest> personalRests;
    std::vector<TotalRest> totalRests;

    // [месяц][квалификация] = количество дифицита
    std::vector<std::map<Qualification, int>> qualDeficits;

    // По квалификации получаем вектор (месяц, количество проработанных часов)
    std::map<Qualification, std::vector<int>> workingHours;

    std::vector<MonthResult> monthResults;
};
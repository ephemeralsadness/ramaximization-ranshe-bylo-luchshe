#pragma once

#include <map>
#include <vector>
#include "Qual.h"
#include "PersonalRest.h"
#include "TotalRest.h"

class OutputData {
    std::vector<PersonalRest> personalRests;
    std::vector<TotalRest> totalRests;

    // [месяц][квалификация] = количество дифицита
    std::vector<std::map<Qual, int>> qualDeficits;

    // По квалификации получаем вектор (месяц, количество проработанных часов)
    std::map<Qual, std::vector<int>> workingHours;

    std::vector<MonthResult> monthResults;
};
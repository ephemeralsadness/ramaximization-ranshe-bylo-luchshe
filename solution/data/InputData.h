//
// Created by lanco on 21.02.2021.
//

#ifndef RAMAXIMIZATION_RANSHE_BYLO_LUCHSHE_INPUTDATA_H
#define RAMAXIMIZATION_RANSHE_BYLO_LUCHSHE_INPUTDATA_H


#include <vector>
#include "Qual.h"
#include "Mounth.h"

class InputData {
    int REST_YEAR,
    MIN_REST_SIZE,
    MIN_REST_LAG,
    TOTAL_RESTS,
    PRIOR_RESTS,
    NOPRIOR_RESTS,
    REST_HIGH,
    REST_LOW,
    nMonths,
    nQuals;

    std::vector<Qual> quals;
    std::vector<Mounth> mounth;
    std::vector<Personal> personals;
    std::vector<Request> requests;

};


#endif //RAMAXIMIZATION_RANSHE_BYLO_LUCHSHE_INPUTDATA_H

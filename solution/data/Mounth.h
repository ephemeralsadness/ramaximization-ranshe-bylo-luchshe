//
// Created by lanco on 21.02.2021.
//

#ifndef RAMAXIMIZATION_RANSHE_BYLO_LUCHSHE_MOUNTH_H
#define RAMAXIMIZATION_RANSHE_BYLO_LUCHSHE_MOUNTH_H


#include <vector>
#include <map>

class Mounth {
    int number;
    bool isPriority;
    int maxSize;
    std::map<Mounth, int> requestsNeed;
};


#endif //RAMAXIMIZATION_RANSHE_BYLO_LUCHSHE_MOUNTH_H

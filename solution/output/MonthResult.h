#pragma once

class MonthResult {
public:
    int needHours;
    int workHours;
    int numberOfRest;
    int restInHour;

    MonthResult(int needHours, int workHours, int numberOfRest, int restInHour)
            : needHours(needHours),
              workHours(workHours),
              numberOfRest(numberOfRest),
              restInHour(restInHour) {}
};


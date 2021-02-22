#pragma once

class PersonalRest {
public:
    const int personalId;
    const int month;
    const int restSize;
    const int requestRate;

    PersonalRest(int personalId,
                 int month,
                 int restSize,
                 bool requestRate):
                    personalId(personalId),
                    month(month),
                    restSize(restSize),
                    requestRate(requestRate) {}
};

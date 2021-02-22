#pragma once


class PersonalRest {
public:
    int personalId;
    int month;
    int restSize;
    int requestRate;

    PersonalRest() {}

    PersonalRest(int personalId,
                 int month,
                 int restSize,
                 bool requestRate):
                    personalId(personalId),
                    month(month),
                    restSize(restSize),
                    requestRate(requestRate) {}
};

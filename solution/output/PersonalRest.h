#pragma once

class PersonalRest {
    const int personalId;
    const int month;
    const int restSize;
    const bool isAccepted;

    PersonalRest(int personalId,
                 int month,
                 int restSize,
                 bool isAccepted):
                    personalId(personalId),
                    month(month),
                    restSize(restSize),
                    isAccepted(isAccepted) {}
};

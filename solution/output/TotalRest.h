class TotalRest {
public:
    const int personalId;
    const int nRest;
    const int nHour;
    const int deficitRest;

    TotalRest(int personalId,
                int nRest,
                int nHour,
                int deficitRest):
            personalId(personalId),
            nRest(nRest),
            nHour(nHour),
            deficitRest(deficitRest) {}
};
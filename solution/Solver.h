#pragma once

#include <vector>
#include "data/InputData.h"
#include "data/OutputData.h"

class Solver {
private:
    const InputData inputData;

    struct Result {
        double sumRating,
               chillTime,
               deficit;
    };

    Result solve(const std::vector<double>& args) {
        OutputData data;
        evaluateRequest(data, args);
        fullFill(data, args);
        return getCost(data);
    }

    void evaluateRequest(OutputData& data, const std::vector<double>& args) {
        //data как-то заполняется
    }

    void fullFill(OutputData& data, const std::vector<double>& args) {
        //
    }

    Result getCost(const OutputData& data) {
        // тут формула
    }


public:

    Solver(const InputData& data) : inputData(data) {}

//    OutputData get() {
//        std::vector<double> args(8, 1); // начальные данные
//        const int N_ITERATION = 1e3;
//        for (int i = 0; i < N_ITERATION; ++i) {
//            Result res = solve(args);
//            // args =
//            // Как-то изменить args, тут делает Лёха
//        }
//    }

    OutputData get() {
        inputData;
    }
};

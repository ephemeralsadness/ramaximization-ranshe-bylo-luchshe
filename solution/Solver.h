#pragma once

#include <vector>
#include <algorithm>
#include "input/InputData.h"
#include "output/OutputData.h"

int calculateRating(InputData& input, Request& req) {
    Staff& s = input.getStaff(req.getStaff());
    return (4 - req.getPriority()) * (MAX_PERSONAL_LEVEL + 1) + s.getLevel();
}

class Solver {
private:
    InputData inputData;

    struct Result {
        double sumRating,
               chillTime,
               deficit;
    };

    Result solve(const std::vector<double>& args) {
        InputData input = inputData;
        OutputData output;
        evaluateRequests(input, output, args);
        fullFill(output, args);

        return getCost(output);
    }

    void evaluateRequests(InputData& input, OutputData& output, const std::vector<double>& args) {
        std::vector<Request> requests = input.getRequests();
        std::sort(requests.begin(), requests.end(), [this](Request& lhs, Request& rhs) {
            return calculateRating(this->inputData, lhs) > calculateRating(this->inputData, rhs);
        });

        for
    }

    void fullFill(OutputData& data, const std::vector<double>& args) {
        //
    }

    Result getCost(const OutputData& data) {
        // тут формула
    }


public:

    Solver(InputData data) : inputData(std::move(data)) {}

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

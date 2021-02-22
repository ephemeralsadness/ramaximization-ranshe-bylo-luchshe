#pragma once

#include <vector>
#include <algorithm>
#include "input/InputData.h"
#include "output/OutputData.h"
#include "constants.h"



class Solver {
private:
    InputData inputData;
    std::map<int, std::map<Qualification::Id, int>> possibilities;
    std::map<Staff::Id, std::vector<Request*>> staffIdToRequests;

    int calculateRating(Request& req) {
        Staff& s = inputData.getStaff(req.getStaffId());
        return (4 - req.getPriority()) * (constants::MAX_PERSONAL_LEVEL + 1) + s.getLevel();
    }

    struct Result {
        double sumRating,
               chillTime,
               deficit;
    };

    Result solve(const std::vector<double>& args) {
        InputData input = inputData;
        auto possible = possibilities;
        OutputData output;
        evaluateRequests(input, possible, output, args);
        fullFill(possible, output, args);

        return getCost(output);
    }

    void evaluateRequests(InputData& input, std::map<int, std::map<Qualification::Id, int>>& possible, OutputData& output, const std::vector<double>& args) {
        staffIdToRequests.clear();
        auto comp_req_pointers = [](Request* lhs, Request* rhs) -> bool {
            return lhs->getMonth() < rhs->getMonth();
        };

        std::vector<Request> requests = input.getRequests();
        std::sort(requests.begin(), requests.end(), [this](Request& lhs, Request& rhs) {
            return this->calculateRating(lhs) > this->calculateRating(rhs);
        });

        auto& cs = constants::REST_CONSTANTS;

        for (auto& req : requests) {
            auto& v = staffIdToRequests[req.getStaffId()];

            if (v.size() >= cs["TOTAL_RESTS"]) continue;
            if (req.getHours() < cs["MIN_REST_SIZE"]) continue;

            int sm = req.getHours();
            for (auto r : v)
                sm += r->getHours();

            if (sm > cs["MAX_REST_SIZE"]) continue;

            {
                bool alpha = false;
                for (auto r : v) {
                    alpha |= (abs(r->getMonth() - req.getMonth()) < cs["MIN_REST_LAG"]);
                }
                if (alpha) continue;
            }

            {
                int topc = 0;
                int notopc = 0;
                int toph = 0;
                int notoph = 0;
                for (auto r : v) {
                    if (inputData.getMonth(r->getMonth()).isTop) {
                        ++topc;
                        toph += r->getHours();
                    } else {
                        ++notopc;
                        notoph += r->getHours();
                    }
                }

                if (inputData.getMonth(req.getMonth()).isTop) {
                    if (topc == cs["PRIOR_RESTS"] || toph > cs["REST_HIGH"]) {
                        continue;
                    }
                } else {
                    if (notopc == cs["NOPRIOR_RESTS"] || notoph > cs["REST_LOW"]) {
                        continue;
                    }
                }
            }

            {
                // check if it will ne deficit. If it will be, than all is bad;

                Month& m = inputData.getMonth(req.getMonth());
                Staff& s = inputData.getStaff(req.getStaffId());
                if (!s.qualifications.empty()) {
                    Qualification& q = input.getQualification(s.qualifications.front());
                    int& needHours = m.hoursNeed[q.name];
                    if (possible[req.getMonth()][s.qualifications.front()] - needHours
                            >= m.hoursNeed[q.name]) {
                        possible[req.getMonth()][s.qualifications.front()] -= needHours;
                    } else {
                        continue;
                    }
                }
            }

            v.push_back(&req);
            std::sort(v.begin(), v.end(), comp_req_pointers);
        }
    }

    void fullFill(std::map<int, std::map<Qualification::Id, int>>& possible, OutputData& data, const std::vector<double>& args) {
        auto comp_req_pointers = [](Request* lhs, Request* rhs) -> bool {
            return lhs->getMonth() < rhs->getMonth();
        };
        auto& cs = constants::REST_CONSTANTS;

        // TODO make MIN_START AND MAX_START work
        for (auto& [id, human] : inputData.getAllStaff()) {
            auto& v = staffIdToRequests[id];

            if (human.qualifications.empty()) {
                // TODO make rest to people who does not have qualifications
            }

            for (int i = 0; i < 12; ++i) {
                // TODO simulate if we have a request for month = i and hours = min(max_fly, сколько можно)

                int am = possible[i][human.qualifications.front()];
                Request req(id, 3, i, std::min(inputData.getStaff(id).maxHours,
                        std::max(possible[i][human.qualifications.front()] - inputData.getMonth(i).hoursNeed[human.qualifications.front()], 0)));

                if (req.getHours() == 0) continue;

                if (v.size() >= cs["TOTAL_RESTS"]) continue;
                if (req.getHours() < cs["MIN_REST_SIZE"]) continue;

                int sm = req.getHours();
                for (auto r : v)
                    sm += r->getHours();

                if (sm > cs["MAX_REST_SIZE"]) continue;

                {
                    bool alpha = false;
                    for (auto r : v) {
                        alpha |= (abs(r->getMonth() - req.getMonth()) < cs["MIN_REST_LAG"]);
                    }
                    if (alpha) continue;
                }

                {
                    int topc = 0;
                    int notopc = 0;
                    int toph = 0;
                    int notoph = 0;
                    for (auto r : v) {
                        if (inputData.getMonth(r->getMonth()).isTop) {
                            ++topc;
                            toph += r->getHours();
                        } else {
                            ++notopc;
                            notoph += r->getHours();
                        }
                    }

                    if (inputData.getMonth(req.getMonth()).isTop) {
                        if (topc == cs["PRIOR_RESTS"] || toph > cs["REST_HIGH"]) {
                            continue;
                        }
                    } else {
                        if (notopc == cs["NOPRIOR_RESTS"] || notoph > cs["REST_LOW"]) {
                            continue;
                        }
                    }
                }

                {
                    // check if it will ne deficit. If it will be, than all is bad;

                    Month& m = inputData.getMonth(req.getMonth());
                    Staff& s = inputData.getStaff(req.getStaffId());
                    if (!s.qualifications.empty()) {
                        Qualification& q = inputData.getQualification(s.qualifications.front());
                        int& needHours = m.hoursNeed[q.name];
                        if (possible[req.getMonth()][s.qualifications.front()] - needHours
                            >= m.hoursNeed[q.name]) {
                            possible[req.getMonth()][s.qualifications.front()] -= needHours;
                        } else {
                            continue;
                        }
                    }
                }

                v.push_back(&req);
                std::sort(v.begin(), v.end(), comp_req_pointers);

            }

        }
    }

    Result getCost(const OutputData& data) {
        // тут формула
    }


public:

    Solver(InputData data) : inputData(std::move(data)) {
        for (auto& [x, y] : inputData.getAllStaff()) {
            for (int i = 0; i < 12; ++i) {
                if (!y.qualifications.empty()) {
                    possibilities[i][y.qualifications.front()] += y.maxHours;
                }
            }
        }
    }

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

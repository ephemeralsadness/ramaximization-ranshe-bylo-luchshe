#pragma once

#include <vector>
#include <numeric>
#include <algorithm>
#include "input/InputData.h"
#include "output/OutputData.h"
#include "constants.h"
#include <iostream>


class Solver {
public:
    OutputData get() {
        return solve();
    }
private:
    InputData inputData;
    std::map<int, std::map<Qualification::Id, int>> possibilities;
    std::map<Staff::Id, std::vector<Request>> staffIdToRequests;

    int calculateRating(Request& req) {
        Staff& s = inputData.getStaff(req.getStaffId());
        return (4 - req.getPriority()) * (constants::MAX_PERSONAL_LEVEL + 1) + s.getLevel();
    }

    OutputData solve() {
        InputData input = inputData;
        auto possible = possibilities;
        OutputData output;
        evaluateRequests(input, possible, output);
        fullFill(possible, output);

        for (auto& pp : staffIdToRequests) {
            auto& id = pp.first;
            auto& vv = pp.second;

            int sm = 0;
            for (auto x : vv) {
                sm += x.getHours();
            }

            int need = input.getStaff(id).maxHours * 2;

            output.totalRests.emplace_back(id, vv.size(), sm, std::max(need - sm, 0));
        }

        for (int i = 0; i < 12; ++i) {
            Month& m = input.getMonth(i);
            for (auto&& pp : m.hoursNeed) {
                auto& q = pp.first;
                auto& am = pp.second;

                auto& sth = output.qualDeficits[i][std::stoi(q.substr(1)) - 1];
                auto& ss = possible[i][q];

                output.qualDeficits[i][std::stoi(q.substr(1)) - 1] = std::max(0, am - possible[i][q]);
                output.workingHours[i][std::stoi(q.substr(1)) - 1] = possible[i][q];
            }
        }

        std::vector<int> othours(12, 0);
        std::vector<int> otamount(12, 0);

        for (auto& pp : staffIdToRequests) {
            auto& vv = pp.second;
            for (auto x : vv) {
                othours[x.getMonth()] += x.getHours();
                otamount[x.getMonth()] += 1;
            }
        }

        for (int i = 0; i < 12; ++i) {
            Month& m = input.getMonth(i);
            int potr = std::accumulate(output.qualDeficits[i].begin(), output.qualDeficits[i].end(), 0);
            int smwo = std::accumulate(output.workingHours[i].begin(), output.workingHours[i].end(), 0);
            output.monthResults.emplace_back(potr, smwo, othours[i], otamount[i]);
        }

        return output;
    }

    void evaluateRequests(InputData& input, std::map<int, std::map<Qualification::Id, int>>& possible, OutputData& output) {
        staffIdToRequests.clear();
        auto comp_req_pointers = [](Request lhs, Request rhs) -> bool {
            return lhs.getMonth() < rhs.getMonth();
        };

        std::vector<Request>& requests = input.getRequests();
        std::sort(requests.begin(), requests.end(), [this](Request& lhs, Request& rhs) {
            return this->calculateRating(lhs) > this->calculateRating(rhs);
        });

        auto& cs = constants::REST_CONSTANTS;
        std::vector<char> accepted(requests.size());

        for (int i = 0; i < (int)requests.size(); ++i) {
            accepted[i] = false;
            auto& req = requests[i];
            auto& v = staffIdToRequests[req.getStaffId()];

            if (v.size() >= cs["TOTAL_RESTS"]) continue;
            if (req.getHours() < cs["MIN_REST_SIZE"]) continue;

            int sm = req.getHours();
            for (auto r : v)
                sm += r.getHours();

            if (sm > cs["REST_YEAR"]) continue;

            {
                bool alpha = false;
                for (auto r : v) {
                    alpha |= (abs(r.getMonth() - req.getMonth()) < cs["MIN_REST_LAG"]);
                }
                if (alpha) continue;
            }

            {
                int topc = 0;
                int notopc = 0;
                int toph = 0;
                int notoph = 0;
                for (auto r : v) {
                    if (inputData.getMonth(r.getMonth()).isTop) {
                        ++topc;
                        toph += r.getHours();
                    } else {
                        ++notopc;
                        notoph += r.getHours();
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
                    int needHours = req.getHours();
                    if (possible[req.getMonth()][s.qualifications.front()] - needHours >= m.hoursNeed[q.name]) {
                        possible[req.getMonth()][s.qualifications.front()] -= needHours;
                    } else {
                        continue;
                    }
                }
            }

            if (req.getMonth() > 12 || req.getMonth() < 0)
                std::cout << req.getMonth();

            accepted[i] = true;
            v.push_back(req);
            std::sort(v.begin(), v.end(), comp_req_pointers);
        }

        for (int i = 0; i < (int)requests.size(); ++i) {
            output.personalRests.emplace_back(requests[i].staffId, requests[i].getMonth(), requests[i].getHours(), accepted[i]);
        }
    }

    void fullFill(std::map<int, std::map<Qualification::Id, int>>& possible, OutputData& data) {

        auto comp_req_pointers = [](Request lhs, Request rhs) -> bool {
            return lhs.getMonth() < rhs.getMonth();
        };
        auto& cs = constants::REST_CONSTANTS;

        for (int iter = 0; iter < cs["TOTAL_RESTS"]; ++iter) {
            for (auto& pp : inputData.getAllStaff()) {
                auto id = pp.first;
                auto human = pp.second;
                auto& v = staffIdToRequests[id];

                if (human.qualifications.empty()) {
                    // (rand() % 12)
                    continue;
                }

                for (int i = 0; i < 12; ++i) {
                    Request req(id, 3, i, std::min(inputData.getStaff(id).maxHours,
                                                   std::max(possible[i][human.qualifications.front()] - inputData.getMonth(i).hoursNeed[human.qualifications.front()], 0)));

                    if (v.size() != iter)
                        continue;

                    if (req.getHours() == 0) continue;

                    if (v.size() >= cs["TOTAL_RESTS"]) continue;
                    if (req.getHours() < cs["MIN_REST_SIZE"]) continue;

                    int sm = req.getHours();
                    for (auto r : v)
                        sm += r.getHours();

                    if (sm > cs["REST_YEAR"]) continue;

                    {
                        bool alpha = false;
                        for (auto r : v) {
                            alpha |= (abs(r.getMonth() - req.getMonth()) < cs["MIN_REST_LAG"]);
                        }
                        if (alpha) continue;
                    }

                    {
                        int topc = 0;
                        int notopc = 0;
                        int toph = 0;
                        int notoph = 0;
                        for (auto r : v) {
                            if (inputData.getMonth(r.getMonth()).isTop) {
                                ++topc;
                                toph += r.getHours();
                            } else {
                                ++notopc;
                                notoph += r.getHours();
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
                            int needHours = req.getHours();
                            if (possible[req.getMonth()][s.qualifications.front()] - needHours
                                >= m.hoursNeed[q.name]) {
                                possible[req.getMonth()][s.qualifications.front()] -= needHours;
                            } else {
                                continue;
                            }
                        }
                    }

                    if (req.getMonth() > 12 || req.getMonth() < 0)
                        std::cout << req.getMonth();

                    v.push_back(req);
                    std::sort(v.begin(), v.end(), comp_req_pointers);

                }

            }
        }


    }
public:

    Solver(InputData data) : inputData(std::move(data)) {
        for (auto& pp : inputData.getAllStaff()) {
            auto x = pp.first;
            auto y = pp.second;
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

};

//
// Created by Alex on 22.02.2021.
//

#include "Genetic.h"


Score EvaluateGen(const InputData& data, std::vector<Person> answer){

    std::vector<std::vector<int>> result_work_hours;//фактическое количество часов каждый месяц по каждой квалификации
    result_work_hours.resize(12);
    for(auto& x: result_work_hours)
        x.resize(10); //делаем размер каждому вектору в соответствии с количеством квалификаций

    std::vector<int> RequestRates = data.GetRequestsRates();
    std::vector<std::vector<int>> RquestedHours = data.GetWantedRests();
    std::vector<std::vector<int>> WantedWorkHours = data.GetWantedWorkHours();
    Score res{0,0,0};

    for(auto p: answer){

    }


    for(auto p: answer){
        for(int i = 0; i < 12; i++){
            result_work_hours[i][p.work_hours[i].second]+=p.work_hours[i].first;
        }
    }

    for(int i =0 ; i <answer.size(); i++){
        for(int j =0; j<12; j++){
            if(answer[i].rest_hours[j] < RquestedHours[i][j]){
                res.req_rest_score+=(RequestRates[i]*(RquestedHours[i][j] - answer[i].rest_hours[j] )); //Штрафуем за невыполненные заявки на отпуск
            }
        }
    }

    int REST_YEAR = data.GetRestYear();
    for(int i =0 ; i <answer.size(); i++) {
        int sum_rest = 0;
        for(int j =0; j<12; j++){
            sum_rest+=answer[i].rest_hours[j];
        }
        if(sum_rest<REST_YEAR){
            res.def_rest_score+=(REST_YEAR-sum_rest); //Штрафуем просто за неполный отпуск сотруднику за год
        }
    }

    for(int i = 0; i <result_work_hours.size(); i++){
        for(int j = 0; j < result_work_hours[i].size(); j++){
            if(result_work_hours[i][j]<WantedWorkHours[i][j]){
                res.work_score+=(WantedWorkHours[i][j]-result_work_hours[i][j]); //штрафуем за невыполненные часы работы
            }
        }
    }

    res.sum_score = res.req_rest_score+res.def_rest_score*10 + res.work_score*1000;

    return res;
}
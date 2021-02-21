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

void RandomGenChange(const InputData& data, std::vector<Person>& gen, const Params& p , int multiplier){
    std::vector<bool> PriorMonth = data.GetCoolMonth();
    std::vector<int> MaxFly = data.GetMaxFlies();

    int j =0;
    for(auto worker: gen){
        int sum_rest = 0, sum_work = 0;
        int work_limit = MaxFly[j]*10;
        for(int i =0; i < p.nMonth; i++){
            sum_work+=worker.work_hours[i].first;
            sum_rest+=worker.rest_hours[i];
        }





        j++;
    }

}

void RunSelection(const InputData& data,
                  std::vector<Person> start, //задаем началную выборку
                  int epoch_size, //размер каждого следующего поколения
                  int survived_part, //какая часть от всех выживает 1/survived_part
                  bool isIntersection, //делать ли скрещиания лучших
                  int verbose) //подробность отчётов о работе в консоли от 0 до 5
{
    std::cout<<"Running selection"<<std::endl<<std::endl;


    Params p;
    p.REST_YEAR = data.GetRestYear();
    p.MIN_LAG = data.GetMinLag();
    p.MIN_SIZE = data.GetMinRestSize();
    p.TOTAL_RESTS = data.GetTotalRests();
    p.PRIOR_RESTS = data.GetPriorRests();
    p.NOPRIOR_RESTS = data.GetNoPriorRests();
    p.REST_HIGH = data.GetRestHigh();
    p.REST_LOW = data.GetRestLow();
    p.nMonth = data.GetNMonth();
    p.nQ = data.GetNQ();


    std::vector<std::pair<std::vector<Person>, Score>> generations;
    generations.push_back(std::pair<std::vector<Person>, Score>(start, EvaluateGen(data, start)));
    std::cout<<"Input generation"<<std::endl<<"work_score: "<< generations[0].second.work_score<<std::endl;
    std::cout<<"def_rest_score: "<< generations[0].second.def_rest_score<<std::endl;
    std::cout<<"req_rest_score: "<< generations[0].second.req_rest_score<<std::endl;
    std::cout<<"sum_score: "<< generations[0].second.sum_score<<std::endl<<std::endl;


}
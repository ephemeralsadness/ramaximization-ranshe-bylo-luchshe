//
// Created by Alex on 22.02.2021.
//
#include<vector>
#include"input/InputData.h"
#include<numeric>
#include<algorithm>

#ifndef RAMAXIMIZATION_RANSHE_BYLO_LUCHSHE_GENETIC_H
#define RAMAXIMIZATION_RANSHE_BYLO_LUCHSHE_GENETIC_H

/*
 * Структура для хранения данных о решении для каждого работника
 * work_hours - данные о часах работы в каждый месяц
 * work_hours[i].first - количество часов, i - месяц
 * work_hours[i].second - квалификация
 * rest_hours - данные о часах отдыха каждый месяц
 * rest_hours[i] - количетво часов, i - месяц
 */
struct Person{
    std::vector<std::pair<int,int>> work_hours;
    std::vector<int> rest_hours;
};

/*
 * Штрафные баллы за невыполненные рабочие часы
 * За невыполненные запросы на отпуск
 * За невыполненные отпуска просто
 * Сумма которая считается с некоторыми коэффицентами
 */
struct Score{
    long long work_score;
    long long req_rest_score;
    long long def_rest_score;
    long long sum_score;
};

/*
 * Оцениваем конкретное решение задачи
 * и озвращаем число
 */
Score EvaluateGen(const InputData& data, std::vector<Person> answer);



#endif //RAMAXIMIZATION_RANSHE_BYLO_LUCHSHE_GENETIC_H

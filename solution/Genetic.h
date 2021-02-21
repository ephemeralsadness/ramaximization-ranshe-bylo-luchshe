//
// Created by Alex on 22.02.2021.
//
#include<vector>
#include"input/InputData.h"
#include<numeric>
#include<algorithm>
#include<iostream>

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

struct Params{
    int REST_YEAR;
    int MIN_LAG;
    int MIN_SIZE;
    int TOTAL_RESTS;
    int PRIOR_RESTS ;
    int NOPRIOR_RESTS ;
    int REST_HIGH ;
    int REST_LOW ;
    int nMonth;
    int nQ = ;
};

/*
 * Изменяем какую то генерацию с указанным показателем multiplier, который определяет
 * степень изменения того или иного параметра 1/multiplier
 * Также передаются параметры - p - которые заданы в первом листе входной таблицы
 */
void RandomGenChange(const InputData& data, std::vector<Person>& gen, const Params& p, int multiplier = 10);

/*
 * Оцениваем конкретное решение задачи
 * и озвращаем число
 */
Score EvaluateGen(const InputData& data, std::vector<Person> answer);

/*
 * Запускаем поиск решения
 */
void RunSelection(const InputData& data,
                  std::vector<Person> start, //задаем началную выборку
                  int epoch_size = 100, //размер каждого следующего поколения
                  int survived_part = 10, //какая часть от всех выживает 1/survived_part
                  bool isIntersection = false, //делать ли скрещиания лучших
                  int verbose = 5, //подробность отчётов о работе в консоли от 0 до 5
                  int num_generations_to_stop = 1); //количество генераций до запроса остановки


#endif //RAMAXIMIZATION_RANSHE_BYLO_LUCHSHE_GENETIC_H

//
// Created by lanco on 22.02.2021.
//

#include "Writer.h"


void Writer::writeToCSV() {
    std::ofstream personalRests, totalRests, qualDeficits, workingHours, monthResults;
    std::string path = "outputCSV/";
    personalRests.open(path+"personalRests.csv");
    totalRests.open(path+"totalRests.csv");
    qualDeficits.open(path+"qualDeficits.csv");
    workingHours.open(path+"workingHours.csv");
    monthResults.open(path+"monthResults.csv");

    if(personalRests.is_open()){
        personalRests<<"Сотрудник,Месяц,Размер отпуска,Заявка\n";
        for(auto x: outputData.personalRests)
            personalRests<<x.personalId<<','<<x.restSize<<','<<x.month<<','<<x.requestRate<<'\n';
    }
    personalRests.close();

    if(totalRests.is_open()){
        totalRests<<"Сотрудник,Кол-во отпусков,Всего часов,Недобор отпусков\n";
        for(auto x: outputData.totalRests)
            totalRests<<x.personalId<<','<<x.nRest<<','<<x.nHour<<','<<x.deficitRest<<'\n';
    }
    totalRests.close();

    ou
}
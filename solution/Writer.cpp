//
// Created by lanco on 22.02.2021.
//

#include "Writer.h"


void Writer::writeToCSV(std::string outPutFolder) {
    std::ofstream personalRests, totalRests, qualDeficits, workingHours, monthResults;
    std::string path = outPutFolder;
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

    if(qualDeficits.is_open()){
        qualDeficits<<"Квалификация,1,2,3,4,5,6,7,8,9,10,11,12\n";
        for(int i =0; i < 10;i++){
            qualDeficits<<"Q"<<i+1;
            for(int j = 0; j<12;j++){
                qualDeficits<<','<<outputData.qualDeficits[j][i];
            }
            qualDeficits<<'\n';
        }
    }
    qualDeficits.close();


    if(workingHours.is_open()){
        workingHours<<"Квалификация,1,2,3,4,5,6,7,8,9,10,11,12\n";
        for(int i =0; i < 10;i++){
            workingHours<<"Q"<<i+1;
            for(int j = 0; j<12;j++){
                workingHours<<','<<outputData.workingHours[j][i];
            }
            workingHours<<'\n';
        }
    }
    workingHours.close();

    if(monthResults.is_open()){
        monthResults<<",1,2,3,4,5,6,7,8,9,10,11,12\nПотребность (часы)";

        for(int i =0; i <12;i++){
        monthResults<<','<<outputData.monthResults[i].needHours;
        }
        monthResults<<"\nРабочее время (часы)";
        for(int i =0; i <12;i++){
            monthResults<<','<<outputData.monthResults[i].workHours;
        }
        monthResults<<"\nОтпуска (часы)";
        for(int i =0; i <12;i++){
            monthResults<<','<<outputData.monthResults[i].restInHour;
        }
        monthResults<<"\nОтпуска (шт)";
        for(int i =0; i <12;i++){
            monthResults<<','<<outputData.monthResults[i].numberOfRest;
        }
    }
    monthResults.close();
}
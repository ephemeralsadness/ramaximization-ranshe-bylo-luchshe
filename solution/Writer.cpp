//
// Created by lanco on 22.02.2021.
//

#include "Writer.h"


void Writer::writeToCSV(OutputData outputData, std::string outPutFolder) {
    std::ofstream personalRests, totalRests, qualDeficits, workingHours, monthResults;
    std::string path = outPutFolder + "/";
    personalRests.open(path+"personalRests.csv");
    totalRests.open(path+"totalRests.csv");
    qualDeficits.open(path+"qualDeficits.csv");
    workingHours.open(path+"workingHours.csv");
    monthResults.open(path+"monthResults.csv");

    if(personalRests.is_open()){
        personalRests<<"Employee,Rest Size,Month,Request\n";
        for(auto x: outputData.personalRests)
            personalRests<<x.personalId<<','<<x.restSize<<','<<x.month<<','<<x.requestRate<<'\n';
    }
    personalRests.close();

    if(totalRests.is_open()){
        totalRests<<"Employee,Rests amount,All hours,Shortage of vacations\n";
        for(auto x: outputData.totalRests)
            totalRests<<x.personalId<<','<<x.nRest<<','<<x.nHour<<','<<x.deficitRest<<'\n';
    }
    totalRests.close();

    if(qualDeficits.is_open()){
        qualDeficits<<"Qualification,1,2,3,4,5,6,7,8,9,10,11,12\n";
        for(int i =0; i < 10;i++){
            qualDeficits << "Q" << i+1;
            for(int j = 0; j < 12;j++){
                qualDeficits << ',' << outputData.qualDeficits[j][i];
            }
            qualDeficits<<'\n';
        }
    }
    qualDeficits.close();


    if(workingHours.is_open()){
        workingHours<<"Qualification,1,2,3,4,5,6,7,8,9,10,11,12\n";
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
        monthResults<<",1,2,3,4,5,6,7,8,9,10,11,12\nNeed (hours)";

        for(int i =0; i <12;i++){
        monthResults<<','<<outputData.monthResults[i].needHours;
        }
        monthResults<<"\nWorking time (hours)";
        for(int i =0; i <12;i++){
            monthResults<<','<<outputData.monthResults[i].workHours;
        }
        monthResults<<"\nHolidays (hours)";
        for(int i =0; i <12;i++){
            monthResults<<','<<outputData.monthResults[i].restInHour;
        }
        monthResults<<"\nHolidays (pcs)";
        for(int i =0; i <12;i++){
            monthResults<<','<<outputData.monthResults[i].numberOfRest;
        }
    }
    monthResults.close();
}
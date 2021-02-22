#pragma once

#include "output/OutputData.h"
#include <fstream>

class Writer {
public:
    void writeToCSV(OutputData outputData, std::string outPutFolder="outputCSV/");
};

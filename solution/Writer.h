#include "output/OutputData.h"
#include <fstream>
#include "constants.h"
class Writer {
public:
    void writeToCSV(OutputData outputData, std::string outPutFolder="outputCSV/");
};

#include "output/OutputData.h"
#include <fstream>
#include "constants.h"
class Writer {
private:
    OutputData outputData;
public:
    Writer(OutputData outputData) : outputData(outputData) {}

    void writeToCSV(std::string outPutFolder="outputCSV/");
};

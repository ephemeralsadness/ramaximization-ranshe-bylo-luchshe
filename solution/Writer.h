#include "output/OutputData.h"
#include <fstream>
class Writer {
private:
    OutputData outputData;
public:
    Writer(OutputData outputData) : outputData(outputData) {}

    void writeToCSV();
};

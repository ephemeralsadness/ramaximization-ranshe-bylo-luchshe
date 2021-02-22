#include "output/OutputData.h"

class Writer {
private:
    OutputData outputData;
public:
    Writer(OutputData outputData) : outputData(outputData) {}

    void writeToCSV(std::string fileName) {
        // w r i t e t o c s v
    }
};

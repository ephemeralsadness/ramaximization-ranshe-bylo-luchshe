#include "Reader.h"
#include "Solver.h"
#include "input/InputData.h"
#include "output/OutputData.h"
#include "Writer.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2)
        throw invalid_argument("Need two file names (input folder and output table)!");
    const string INPUT_FOLDER_NAME = argv[0];
    const string OUTPUT_FILE_NAME = argv[1];

    Reader reader;
    InputData inputData = reader.getInputData(INPUT_FOLDER_NAME);

    Solver solver(inputData);
    OutputData outputData = solver.get();

    Writer writer;
    writer.writeToCSV(outputData, OUTPUT_FILE_NAME);
    return 0;
}
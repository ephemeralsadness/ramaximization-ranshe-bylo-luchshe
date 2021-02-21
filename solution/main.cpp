#include "Reader.h"
#include "Solver.h"
#include "data/InputData.h"
#include "data/OutputData.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2)
        throw invalid_argument("Need two file names (input folder and output table)!");
    const string INPUT_FOLDER_NAME = argv[0];
    const string OUTPUT_FILE_NAME = argv[1];

    InputData inputData = Reader::readInputData(INPUT_FOLDER_NAME);
    Solver solver(inputData);
    OutputData outputData = solver.get();
    // TODO output outputData
    // TODO make writer

    return 0;
}
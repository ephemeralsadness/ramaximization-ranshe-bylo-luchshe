#include "Reader.h"
#include "Solver.h"
#include "input/InputData.h"
#include "output/OutputData.h"
#include "Writer.h"

#include <iostream>

using namespace std;

int main() {
    const string INPUT_FOLDER_NAME = "csv_tables";
    const string OUTPUT_FILE_NAME = "output_folder";

    Reader reader;
    InputData inputData = reader.getInputData(INPUT_FOLDER_NAME);

    Solver solver(inputData);
    OutputData outputData = solver.get();

    Writer writer;
    writer.writeToCSV(outputData, OUTPUT_FILE_NAME);
    return 0;
}
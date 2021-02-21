#include "Reader.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2)
        throw invalid_argument("Need two file names (input folder and output table)!");
    const string INPUT_FILE_NAME = argv[0];
    const string OUTPUT_FILE_NAME = argv[1];

    return 0;
}
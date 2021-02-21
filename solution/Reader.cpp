#include "Reader.h"

#include <fstream>
#include <sstream>

using namespace std;

vector<vector<string>> Reader::readFromCSV(const string& filename) {
    ifstream ifs(filename);

    vector<vector<string>> data;

    while (!ifs.eof()) {
        data.emplace_back();
        string s;
        getline(ifs, s);
        istringstream iss(s);
        while (!iss.eof()) {
            string t;
            getline(iss, t);
            data.back().emplace_back(t);
        }
    }

    if (!data.empty() && data.back().empty())
        data.pop_back();
    data.shrink_to_fit();

    return data;
}
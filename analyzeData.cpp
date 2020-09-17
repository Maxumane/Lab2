//
// Created by Max on 2020-09-16.
//

#include "analyzeData.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

void analyzeData() {
    const char *filename = "readings.txt";
    std::ifstream inFile(filename);
    double median;
    double min;
    double max;

// Make sure the file stream is good
    if (!inFile) {
        cout << endl << "Failed to open file " << filename;
        exit(1);
    }

    int i = 0;
    double d = 0;
    while (!inFile.eof()) {

        inFile >> i >> d;
        cout << setprecision(3) << fixed << d << endl;

    }

}
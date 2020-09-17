//
// Created by Max on 2020-09-15.
//
//open file in method that does writing
#include "randomNum.hpp"
#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
#include <iomanip>



using namespace std;

void randomNum(double rmin, double rmax, string location) {

    fstream f;
    f.open("readings.txt", ios_base::out | ios_base::trunc);
    if (!f.is_open()) {
        cerr << "Unable to open file" << endl;
        exit(1);
    }

    f << setprecision(3) << fixed;
    random_device rd; // Random int generator
    mt19937 entryGen(rd()); // Calls operator
    uniform_int_distribution<> distribution(512, 1024);
    int numberOfEntries = distribution(entryGen);


    default_random_engine generator(time(0));
    for (int i = 0; i <= numberOfEntries; i++) {
        uniform_real_distribution<double> distribution(rmin, rmax);
        double my_random = distribution(generator);
        f << i << " " << my_random << endl;
    }
    f.close();
}

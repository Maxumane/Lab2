//
// Created by Max on 2020-09-16.
//

#include "analyzeData.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "randomNum.hpp"
using namespace std;
const char *targetfile = "readings.txt";
std::ifstream analInFile(targetfile);

double findMedian(double a[], int n) {
    //INFO FOUND ON https://www.geeksforgeeks.org/median/

    // First we sort the array
    sort(a, a + getEntries());

    // check for even case
    if (n % 2 != 0)
        return (double)a[getEntries() / 2];

    return (a[(getEntries() - 1) / 2] + a[getEntries() / 2]) / 2.0;
}

double findMax(double a[], int n) {
    double max = 0;
    int arrSize = n;
    for(int i = 0; i <= arrSize; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

double findMin(double a[], int n) {
    double min = a[0];
    int arrSize = n;
    for(int i = 0; i <= arrSize; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

double findAvg(double a[], int n) {
    double avg = 0;
    int arrSize = n;
    for(int i = 0; i <= arrSize; i++) {
        avg += a[i];
    }
    avg /= n;
    return avg;
}

void fillandSortArray() {


    double outputArray[getEntries()];
    int n = 0;
    int i = 0;
    double d = 0;
    while (!analInFile.eof()) {
        analInFile >> i >> d;
        outputArray[n] = d;
        n++;
    }

    cout << "There are " << getEntries() << " Entries" << endl;
    cout << setprecision(3) << fixed <<  findMedian(outputArray, getEntries()) << " This is the median" << endl;
    cout << setprecision(3) << fixed <<  findMax(outputArray, getEntries()) << " This is the max" << endl;
    cout << setprecision(3) << fixed <<  findAvg(outputArray, getEntries()) << " This is the avg" << endl;
    cout << setprecision(3) << fixed <<  findMin(outputArray, getEntries()) << " This is the min" << endl;
}



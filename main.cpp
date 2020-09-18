#include <iostream>
#include "randomNum.hpp"
#include "analyzeData.hpp"
#include <fstream>

using namespace std;

int main() {

    randomNum(50, 90, "readings.txt");
    fillandSortArray();
    return 0;
}

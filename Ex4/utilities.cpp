#include <iostream>
#include "utilities.h"

using namespace std;

// Task 1b
int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

void incrementByValueNumTimesRef(int& startValue, int& increment, int& numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
}
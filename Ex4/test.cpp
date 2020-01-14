#include <iostream>
#include "test.h"
#include "utilities.h"

using namespace std;

void testCallByValue(void) {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0 
         << " increment: " << increment
         << " iterations: " << iterations
         << " result: " << result << endl;
}

void testCallByReference(void) {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "v0: " << v0 
         << " increment: " << increment
         << " iterations: " << iterations << endl;
}
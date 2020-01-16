#include <iostream>
#include <vector>
#include "test.h"
#include "utilities.h"

using namespace std;
// global (iknow, bad practise...):
bool threeA = false;
bool threeB = false;

// task 1c)
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

// task 1d)
void testCallByReference(void) {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "v0: " << v0 
         << " increment: " << increment
         << " iterations: " << iterations << endl;
}

// task 2a)
void testVectorSorting(void) {
    // task 2b)
    vector<int> percentages (0,0);

    // task 2c)
    int n = 10;
    randomizeVector(percentages, n);
    printVector(percentages);

    if (threeA) {
        cout << endl;
        sortVector(percentages);
        printVector(percentages);
    }
    else if (threeB) {
        cout << "median before: " << medianOfVector(percentages) << endl << endl;
        sortVector(percentages);
        printVector(percentages);
        cout << "median after:  " << medianOfVector(percentages) << endl;
    }
}

// task 2a)
void testSortVect(void) {
    threeA = true;   // Toggle extra module in testVectorSorting
    testVectorSorting();
    threeA = false;
}

void testMedian(void) {
    threeB = true;
    testVectorSorting();
    threeB = false;
}
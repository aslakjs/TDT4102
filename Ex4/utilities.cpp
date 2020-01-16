#include <iostream>
#include "utilities.h"

using namespace std;

void initRando(void) {
    srand(static_cast<unsigned int>(time(nullptr)));
}

void printVector(vector<int> vect) {
    cout << "Your vector =\n{ ";
    for (int i = 0; i < vect.size(); i++) {
        cout << vect[i] << " ";
    }
    cout << "}" << endl;
}

// Task 1b
int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

// Task 1d)
void incrementByValueNumTimesRef(int& startValue, int& increment, int& numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
}

// Task 1e)
void swapNumbers(int& dA, int& dB) {
    //cout << "\n~~Swapping data:~~\n" << endl;
    int temp = 0;
    temp = dA;
    dA = dB;
    dB = temp;
}

// Task 2c)
void randomizeVector(vector<int>& percentages, int n) {
    for (int i = 0; i < n; i++) {
        percentages.push_back(rand() % 100);
    }
}

// Task 3a)
void sortVector(vector<int>& vect) {
    cout << "~~Sorting vector~~" << endl << endl;
    int i = 1; 
    while (i < vect.size()) {
        int j = i;
        while ((j > 0) && (vect[j-1] > vect[j])) {
            swapNumbers(vect[j], vect[j-1]);
            j--;
        }
        i++;
    }
}

// Task 3b)
double medianOfVector(vector<int> vect) {
    // Using int vector (no ref) to make sure the values won't change.
    double median = 0;
    //double mid1 = 0;
    //double mid2 = 0;
    if ((vect.size() % 2) != 0) {
        median = vect[vect.size()/2];
    }
    else {
        median = (vect[(vect.size() - 1) / 2] + vect[(vect.size() + 1) / 2] )/2.0;
    }
    return median;
}
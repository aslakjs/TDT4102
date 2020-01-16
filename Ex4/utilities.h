#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>

// Declarations:
void initRando(void);
void printVector(std::vector<int> vect);
int incrementByValueNumTimes(int startValue = 0, int increment = 0, int numTimes = 0);
void incrementByValueNumTimesRef(int& startValue, int& increment, int& numTimes);
void swapNumbers(int& dA, int& dB);
void randomizeVector(std::vector<int>& percentages, int n);
void sortVector(std::vector<int>& vect);
double medianOfVector(std::vector<int> vect);

#endif /* !UTILITIES_H */
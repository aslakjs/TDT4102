#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>

// Declarations of structs:
struct Student {
    std::string name;
    std::string studyProgram;
    int age;
};

// Declarations of functions:
void initRando(void);
void printVector(std::vector<int> vect);
int incrementByValueNumTimes(int startValue = 0, int increment = 0, int numTimes = 0);
void incrementByValueNumTimesRef(int& startValue, int& increment, int& numTimes);
void swapNumbers(int& dA, int& dB);
void randomizeVector(std::vector<int>& percentages, int n);
void sortVector(std::vector<int>& vect);
double medianOfVector(std::vector<int> vect);
void printStudent(Student* stud);

#endif /* !UTILITIES_H */
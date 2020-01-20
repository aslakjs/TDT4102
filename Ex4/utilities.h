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
void randomizeVector(std::vector<int>& percentages, int n, int upper = 100, int lower = 0);
void sortVector(std::vector<int>& vect);
double medianOfVector(std::vector<int> vect);
void printStudent(Student* stud);
std::string randomizeString(int n, char upper, char lower);
std::string readInputToString(char upper, char lower, int n);
int countChar(std::string str = "qwerty", char ch = 'q');

#endif /* !UTILITIES_H */
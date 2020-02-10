#ifndef TASK4AND5_H
#define TASK4AND5_H

#include <fstream>
#include <vector>

struct Temps {
    double min;
    double max;
};

// Functions:
std::vector<Temps> addTemp(Temps t,std::vector<Temps> tempVector);
void getTemp(std::vector<Temps> tempVector);
void testOperator(void);
std::istream& operator>>(std::istream& is, Temps& t);

#endif /* TASK4AND5_H */
/*----------------------------------------------------
TITLE:  Assignment 6: Task 4
COURSE: TDT4102 - Programming
AUTHOR: Aslak J. Strand (c)

Notes:
    - 
---------------------------------------------------*/

#include "task4and5.h"
#include "def.h"
#include <iostream>
#include <fstream>

using namespace std;

istream& operator>>(istream& is, Temps& t) {
    is >> t.max;
    is >> t.min;
    return is;
}

vector<Temps> addTemp(Temps t, vector<Temps> tempVector) {
    tempVector.push_back(t);
    return tempVector;
}

void getTemp(vector<Temps> tempVector) {
    for (int i = 0; i < tempVector.size(); i++) {
        cout << "Max: " << tempVector[i].max << " \tMin: " << tempVector[i].min << endl;
    }
}

void testOperator(void) {
    vector<Temps>tempVector;
    ifstream temp_file(PATH_T);
    Temps t;
    while (!temp_file.eof()) {
        temp_file >> t;
        tempVector = addTemp(t, tempVector);
    }
    getTemp(tempVector);
    cout << "Size of vector: " << tempVector.size() << endl;
}


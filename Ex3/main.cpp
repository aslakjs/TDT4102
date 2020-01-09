/*----------------------------------------------------
TITLE:  Assignment 3
COURSE: TDT4102 - Programming
AUTHOR: Aslak J. Strand (c)
---------------------------------------------------*/

#include <iostream>
#include <stdio.h>
#include "time.h"
#include <vector>
#include "main.h"

using namespace std;

int main(void) {
#if T_DEBUG
    // Toggle debug in "main.h": <0,1> or <false,true>
    // Test parameters below:
    double testOfFunction = posX(0.0,50.0,5.0);
    string nameOfFunction = "posX(0.0,50.0,5.0)";
    double maxError = 0.0001;
    double toOperand = 250.0;

    // ~~Do not change ~~
    testDeviation(testOfFunction, toOperand, maxError, nameOfFunction);
#else
    // ~~~ Main-function content below: ~~~
    char mm;
    while (true) {
        cout << "\n---------------------------" << endl;
        cout << "~~~~~~~~ Main-Menu ~~~~~~~~" << endl;
        cout << "---------------------------" << endl;
        cout << "[0] - Exit   | [i] - Info  " << endl;
        cout << "[1] - TBD    | [2] - TBD" << endl;
        cout << "---------------------------" << endl;
        cout << "Select task: ";
        cin >> mm;
    
    switch (mm) {
    case 'i': info(); break;
    case '0': cout << endl << endl; return 0;
    default: cout << "Unvalid input, try again!" << endl; break;
    }

    
#endif
    return 0;
}

void info(void) {
    cout << "\n\n---------------------------" << endl;
    cout << "TITLE:  Assignment 2" << endl;
    cout << "COURSE: TDT4102-Programming" << endl;
    cout << "AUTHOR: Aslak J. Strand" << endl;
    cout << "  (c)   Aslak J. Strand";
}

void testDeviation(double compareOperand, double toOperand, double maxError, string name) {

}
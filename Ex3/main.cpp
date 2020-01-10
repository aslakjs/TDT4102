/*----------------------------------------------------
TITLE:  Assignment 3
COURSE: TDT4102 - Programming
AUTHOR: Aslak J. Strand (c)

Note:
    ~posY yields wrong position~
---------------------------------------------------*/

#include <iostream>
#include <stdio.h>
#include "time.h"
#include <vector>
#include "main.h"
#include <cmath>

using namespace std;

int main(void) {
#if T_DEBUG
    // Toggle debug in "main.h": <0,1> or <false,true>
    // Enter max error below:
    double maxError = 0.0001;
    
    // ~~Do not change ~~
    testDeviation(maxError);
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

// Task 3b)
void testDeviation(double maxError) {
    cout << "\n~~~Initiating complete test~~~" << endl;
    cout << "Maximum error in function: " << maxError << endl;
    // --- Time = 0.0 s ---------------------------
    double time = 0.0;
    // posX
    string nameOfFunction = "posX(0.0, 50.0, 0.0)";
    double testOfFunction = posX(0.0, 50.0, 0.0);
    double toOperand = 0.0; 
    double givenError = abs(abs(toOperand)-abs(testOfFunction));
    testPrint(nameOfFunction, maxError, testOfFunction, givenError, toOperand, time);
    // posY
    nameOfFunction = "posY(0.0, 25.0, 0.0)";
    testOfFunction = posY(0.0, 25.0, 0.0);
    toOperand = 0.0; 
    givenError = abs(abs(toOperand)-abs(testOfFunction));
    testPrint(nameOfFunction, maxError, testOfFunction, givenError, toOperand, time);
    // velY
    nameOfFunction = "velY(25.0, 0.0)";
    testOfFunction = velY(25.0, 0.0);
    toOperand = 25.0; 
    givenError = abs(abs(toOperand)-abs(testOfFunction));
    testPrint(nameOfFunction, maxError, testOfFunction, givenError, toOperand, time);

    // --- Time = 2.5 s --------------------
    time = 2.5;
    // posX
    nameOfFunction = "posX(0.0, 50.0, 2.5)";
    testOfFunction = posX(0.0, 50.0, 2.5);
    toOperand = 125.0; 
    givenError = abs(abs(toOperand)-abs(testOfFunction));
    testPrint(nameOfFunction, maxError, testOfFunction, givenError, toOperand, time);
    // posY
    nameOfFunction = "posY(0.0, 0.475, 2.5)";
    testOfFunction = posY(0.0, 0.475, 2.5);
    toOperand = 31.84; 
    givenError = abs(abs(toOperand)-abs(testOfFunction));
    testPrint(nameOfFunction, maxError, testOfFunction, givenError, toOperand, time);
    // velY
    nameOfFunction = "velY(25.0, 2.5)";
    testOfFunction = velY(25.0, 2.5);
    toOperand = 0.475; 
    givenError = abs(abs(toOperand)-abs(testOfFunction));
    testPrint(nameOfFunction, maxError, testOfFunction, givenError, toOperand, time);

    // --- Time = 5.0 s --------------------
    time = 5.0;
    // posX
    nameOfFunction = "posX(0.0, 50.0, 5.0)";
    testOfFunction = posX(0.0, 50.0, 5.0);
    toOperand = 250.0; 
    givenError = abs(abs(toOperand)-abs(testOfFunction));
    testPrint(nameOfFunction, maxError, testOfFunction, givenError, toOperand, time);
    // posY
    nameOfFunction = "posY(0.0, -24.05, 5.0)";
    testOfFunction = posY(0.0, -24.05, 5.0);
    toOperand = 2.375; 
    givenError = abs(abs(toOperand)-abs(testOfFunction));
    testPrint(nameOfFunction, maxError, testOfFunction, givenError, toOperand, time);
    // velY
    nameOfFunction = "velY(25.0, 5.0)";
    testOfFunction = velY(25.0, 5.0);
    toOperand = -24.05; 
    givenError = abs(abs(toOperand)-abs(testOfFunction));
    testPrint(nameOfFunction, maxError, testOfFunction, givenError, toOperand, time);
}   

void testPrint(string nameOfFunction, double maxError, double testOfFunction, double givenError, double toOperand, double time) {
    cout << endl << "~~~Initiating test~~~" << endl;
    cout << "Running test:  " << nameOfFunction << endl;
    cout << "At time:       " << time << endl;
    cout << "Allowed error: " << maxError << endl;
    cout << "Target value:  " << toOperand << endl;
    cout << "Return value:  " << testOfFunction << endl;
    cout << "Return error:  " << abs(givenError) << endl;
    if (givenError < maxError) {cout << "Test result:   Successful." << endl << endl << endl << endl;}
    else {cout << "Test result:   Failed." << endl << endl << endl << endl;}
    waitForEnter();
}

// Wait for enter-key
inline void waitForEnter() {
    do {cout << "Press Enter To Continue..";
    } while (cin.get()!='\n');
    for (int i = 0; i < 100; i++) {cout << endl;}
}
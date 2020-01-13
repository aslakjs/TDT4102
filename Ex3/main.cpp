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
    double maxError = 0.01;
    double initVelX = 50.0;
    double initVelY = 25.0;
    double initPosX = 0.0;
    double initPosY = 0.0;
    vector<double> time = {0.0, 2.5, 5.0};
    // ToOperands for errer:   {posx   posY   velY};
    vector<double> t1operand = {0.0,   0.0,   25.0};
    vector<double> t2operand = {125.0, 31.84, 0.475};
    vector<double> t3operand = {250.0, 2.375, -24.05};
    
    // ~~Do not change ~~
    // Task 4~
    testDeviation(maxError, initVelX, initVelY, initPosX, initPosY, time, t1operand, t2operand, t3operand);
    // Task 5b)
    //initRando(); cout << randomWithLimits(10,0) << endl;

#else
    // ~~~ Main-function content below: ~~~
    char mm;
    initRando();    // initiate rand()
    while (true) {  // Main menu
        cout << "\n----------------------------" << endl;
        cout << "~~~~~~~~ Main-Menu ~~~~~~~~~" << endl;
        cout << "----------------------------" << endl;
        cout << "[0] - Exit    | [i] - Info  " << endl;
        cout << "[1] - Task 4d | [2] - Task 5" << endl;
        cout << "----------------------------" << endl;
        cout << "Select task: ";
        cin >> mm;
    
        switch (mm) {
        case 'i': info(); break;
        case '0': cout << endl << endl; return 0;
        case '1': _task4d(); break;
        case '2': _task5(); break;
        default: cout << "Unvalid input, try again!" << endl; break;
        }
    }
#endif
    return 0;
}

// Task 3b)
void testDeviation(double maxError, double initVelX, double initVelY, double initPosX, double initPosY, vector<double> time, vector<double> t1operand, vector<double> t2operand, vector<double> t3operand) {
    cout << "\n~~~Initiating complete test~~~" << endl;
    cout << "Maximum error in function: " << maxError << endl;
    // --- Time = 0.0 s ---------------------------
    // posX
    string nameOfFunction = "posX(" + to_string(initPosX) + ", " + to_string(initVelX) + ", " + to_string(time[0]) + ")";
    double testOfFunction = posX(initPosX, initVelX, time[0]);
    double toOperand = t1operand[0]; 
    double givenError = abs(abs(toOperand)-abs(testOfFunction));
    testPrint(nameOfFunction, maxError, testOfFunction, givenError, toOperand, time[0]);
    // posY
    nameOfFunction = "posY("+ to_string(initPosY) + ", " + to_string(initVelY) + ", " + to_string(time[0]) + ")";
    testOfFunction = posY(initPosY, initVelY, time[0]);
    toOperand = t1operand[1]; 
    givenError = abs(abs(toOperand)-abs(testOfFunction));
    testPrint(nameOfFunction, maxError, testOfFunction, givenError, toOperand, time[0]);
    // velY
    nameOfFunction = "velY(" + to_string(initVelY) + ", " + to_string(time[0]) + ")";
    testOfFunction = velY(initVelY, time[0]);
    toOperand = t1operand[2]; 
    givenError = abs(abs(toOperand)-abs(testOfFunction));
    testPrint(nameOfFunction, maxError, testOfFunction, givenError, toOperand, time[0]);

    // --- Time = 2.5 s --------------------
    // posX
    nameOfFunction = "posX(" + to_string(initPosX) + ", " + to_string(initVelX) + ", " + to_string(time[1]) + ")";
    testOfFunction = posX(initPosX, initVelX, time[1]);
    toOperand = t2operand[0]; 
    givenError = abs(abs(toOperand)-abs(testOfFunction));
    testPrint(nameOfFunction, maxError, testOfFunction, givenError, toOperand, time[1]);
    // posY
    nameOfFunction = "posY("+ to_string(initPosY) + ", " + to_string(initVelY) + ", " + to_string(time[1]) + ")";
    testOfFunction = posY(initPosY, initVelY, time[1]);
    toOperand = t2operand[1]; 
    givenError = abs(abs(toOperand)-abs(testOfFunction));
    testPrint(nameOfFunction, maxError, testOfFunction, givenError, toOperand, time[1]);
    // velY
    nameOfFunction = "velY(" + to_string(initVelY) + ", " + to_string(time[1]) + ")";
    testOfFunction = velY(initVelY, time[1]);
    toOperand = t2operand[2]; 
    givenError = abs(abs(toOperand)-abs(testOfFunction));
    testPrint(nameOfFunction, maxError, testOfFunction, givenError, toOperand, time[1]);

    // --- Time = 5.0 s --------------------
    // posX
    nameOfFunction = "posX(" + to_string(initPosX) + ", " + to_string(initVelX) + ", " + to_string(time[2]) + ")";
    testOfFunction = posX(initPosX, initVelX, time[2]);
    toOperand = t3operand[0]; 
    givenError = abs(abs(toOperand)-abs(testOfFunction));
    testPrint(nameOfFunction, maxError, testOfFunction, givenError, toOperand, time[2]);
    // posY
    nameOfFunction = "posY("+ to_string(initPosY) + ", " + to_string(initVelY) + ", " + to_string(time[2]) + ")";
    testOfFunction = posY(initPosY, initVelY, time[2]);
    toOperand = t3operand[1]; 
    givenError = abs(abs(toOperand)-abs(testOfFunction));
    testPrint(nameOfFunction, maxError, testOfFunction, givenError, toOperand, time[2]);
    // velY
    nameOfFunction = "velY(" + to_string(initVelY) + ", " + to_string(time[2]) + ")";
    testOfFunction = velY(initVelY, time[2]);
    toOperand = t3operand[2]; 
    givenError = abs(abs(toOperand)-abs(testOfFunction));
    testPrint(nameOfFunction, maxError, testOfFunction, givenError, toOperand, time[2]);
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

void _task4d(void) {
    double distTarg;
    cout << "\n\nLength to target [m]: ";
    cin >> distTarg;
    double vel = getUserInputAbsVelocity();
    double deg = getUserInputTheta();
    double rad = degToRad(deg);
    //cout << "\nDegrees = " << rad << " radians." << endl;
    vector<double> velXY = getVelocityVector(rad, vel);
    //cout << "Velocities: x=" << velXY[0] << " and y=" << velXY[1] << endl;
    double goal = targetPractise(distTarg, velXY[0], velXY[1]);
    cout << "\n\nDistance to target [m]: " << distTarg << endl;
    cout << endl;
    if (goal == 0) {cout << "FFS, that's spot on. WOW!" << endl;}
    else if (abs(goal) <= 10) {cout << "Close enough!" << endl;}
    else if (abs(goal) <= 50) {cout << "You can do better than that!" << endl;}
    else {cout << "Waaaay off target." << endl << endl;} 

    waitForEnter();
}

void _task5(void) {
    playTargetPractise();   // Run gamemodule from utilities.cpp
    waitForEnter();         // wait for enter key to continue
}




// Wait for enter-key
inline void waitForEnter() {
    fseek(stdin,0,SEEK_END); // Clear input buffer
    do {cout << "Press Enter To Continue..";
    } while (cin.get()!='\n');
    for (int i = 0; i < 100; i++) {cout << endl;}
}

// Get info
void info(void) {
    for (int i = 0; i<50; i++) {cout << endl;}
    cout << "---------------------------" << endl;
    cout << "TITLE:  Assignment 3" << endl;
    cout << "COURSE: TDT4102-Programming" << endl;
    cout << "AUTHOR: Aslak J. Strand" << endl;
    cout << "  (c)   Aslak J. Strand";
}
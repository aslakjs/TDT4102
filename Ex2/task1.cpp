#include <iostream>
#include <stdio.h>
#include <iomanip>
//#include "../head/task1.h"
#include "task1.h"
using namespace std;

// Task 1a)
void inputAndPrintInteger(void) {
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    cout << "Your integer was: " << num << endl;
}

// Task 1b)
int inputInteger(void) {
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    return num;
}

// Task 1c)
void inputIntegersAndPrintSum(void) {
    int num1, num2;
    num1 = inputInteger();
    num2 = inputInteger();
    cout << "The sum: " << num1 << " + " << num2 << " = " << num1+num2 << endl;
}

// Task 1d = Theory -> See main.cpp

// Task 1e)
bool isOdd(int odd) {
    if ((odd % 2) == 0) {
        return false;
    }
    return true;
}

// Task 1f)
void printHumanReadableTime(int long time) {
    int iTime = static_cast<int>(time);
    int hh, mm, ss;
    double ds = 0;
    string ht = " hours";
    string mt = " minutes";
    string st = " seconds";
    string tt = " seconds";

    hh = iTime / 3600;          // get hours by deviding seconds into number of seconds in hour
    mm = (iTime % 3600) / 60;   // get hours by deviding the rest of previous calc with number of seconds in minute
    ss = iTime % 60;            // get seconds from rest of previous
    ds = ss + (time - static_cast<int>(time)); // adding mili-seconds just to be sure

    // Change text with regards to single/plural
    if (hh == 1) {ht = " hour";}
    if (mm == 1) {mt = " minute";}
    if (ss == 1) {st = " second";}
    if (iTime == 1) {tt = " second";}

    // print flight time
    cout << hh << ht << ", " << mm << mt << " and " << fixed << setprecision(2) << ds << st << endl;
}
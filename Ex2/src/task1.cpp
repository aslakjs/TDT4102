#include <iostream>
#include <stdio.h>
#include "../head/task1.h"
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
    int hh, mm, ss;
    string ht = " hours";
    string mt = " minutes";
    string st = " seconds";
    string tt = " seconds";

    hh = time / 3600;
    mm = (time % 3600) / 60;
    ss = time % 60;

    if (hh == 1) {ht = " hour";}
    if (mm == 1) {mt = " minute";}
    if (ss == 1) {st = " second";}
    if (time == 1) {tt = " second";}

    cout << time << tt << " equals:" << endl;
    cout << hh << ht << ", " << mm << mt << " and " << ss << st << endl;
    

}
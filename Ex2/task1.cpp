#include <iostream>
#include <stdio.h>
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
     
    

}
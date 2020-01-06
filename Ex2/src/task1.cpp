#include <iostream>
#include <stdio.h>
#include "../head/task1.h"
using namespace std;


void inputAndPrintInteger(void) {
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    cout << "Your integer was: " << num << endl;
}

int inputInteger(void) {
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    return num;
}
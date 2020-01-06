#include <iostream>
#include <stdio.h>
#include "../head/main.h"
#include "../head/task1.h"
using namespace std;

int main(void) {
    int mm;
    while (true) {
        cout << "\n-------------------------" << endl;
        cout << "[0] - Exit | [1] - Task 1" << endl;
        cout << "[2] - TBD  | [3] - TBD" << endl;
        cout << "-------------------------" << endl;
        cout << "Select task: ";
        cin >> mm;

        switch (mm) {
            case 0: return 0;
            case 1: _task1(); break;
        }
    }
}

void _task1(void) {
    inputAndPrintInteger();
}
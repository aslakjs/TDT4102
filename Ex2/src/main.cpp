#include <iostream>
#include <stdio.h>
#include "../head/main.h"

using namespace std;

int main(void) {
    int mm;
    while (true) {
        cout << "\n---------------------------" << endl;
        cout << "[0] - Exit   | [1] - Task 1" << endl;
        cout << "[2] - Task 2 | [3] - Task 3" << endl;
        cout << "[4] - Task 4 | [5] - TBD" << endl;
        cout << "[6] - TBD |" << endl;
        cout << "---------------------------" << endl;
        cout << "Select task: ";
        cin >> mm;

        switch (mm) {
            case 0: return 0;
            case 1: _task1(); break;
            case 2: _task2(); break;
            case 3: multiTable(); break;
            case 4: _task4(); break;
        }
    }
}

void _task1(void) {
    cout << "\nTask 1a)" << endl;
    inputAndPrintInteger();

    cout << "\nTask 1b)" << endl;
    int num = inputInteger();
    cout << "Your integer was: " << num << endl;

    cout << "\nTask 1c)" << endl;
    inputIntegersAndPrintSum();

    cout << "\nTask 1d)" << endl;
    cout << "inputInteger was used in order to skip the unnessesary 'cout' in input&print.." << endl;

    cout << "\nTask 1e)" << endl;    
    cout << boolalpha;
    for (int odd = 0; odd <= 15; odd++) {
        cout << " " << odd << "\t";
    }
    cout << endl;
    for (int odd = 0; odd <= 15; odd++) {
        cout << isOdd(odd) << "\t";
    }
    cout << endl;

    cout << "\nTask 1f)" << endl; 
    int long time;
    cout << "Input time in seconds: ";
    cin >> time;
    printHumanReadableTime(time);
}

void _task2(void) { // Task 3a = create menu-system for Task 2
    int m2;
    double num;
    while (m2 != 0) {
        cout << "\n---------------------------------------" << endl;
        cout << "[0] - Exit        | [1] - intSum"        << endl;
        cout << "[2] - infSum      | [3] - for vs. while" << endl;
        cout << "[4] - inputDouble | [5] - nok2eur"       << endl;
        cout << "[6] - double vs. integer "               << endl;
        cout << "---------------------------------------" << endl;
        cout << "Take your pick (0-6): ";
        cin >> m2;

        switch (m2) {
            case 0: break;
            case 1: 
                cout << "\nTask 2a)" << endl;
                intSum();
                break;
            case 2:
                cout << "\nTask 2b)" << endl;
                infSum();
                break;
            case 3:
                cout << "\nTask 2c)" << endl;
                cout << "1st: Use for-loop;   You have a fixed number of loops, will increment untill final loop" << endl;
                cout << "2nd: Use while-loop; You've got unknown number of loops, will continue to statement is true" << endl;
                break;
            case 4:
                cout << "\nTask 2d)" << endl;
                num = inputDouble();
                cout << "Your float was: " << num << endl;
                break;
            case 5:
                cout << "\nTask 2e)" << endl;
                nok2Eur();
                break;
            case 6:
                cout << "\nTask 2f)" << endl;
                cout << "You should use inputDouble as you rearly use integers for prices etc." << endl;
                cout << "By using double you get a higher precition on both input and calculation." << endl;
                break;
            default:
                cout << "Wrong input. Try again." << endl;
                break;
        }
    }
}

void _task4(void) {
    cout << "\nTask 4a)" << endl;
    cout << "The discriminant is: " << discriminant();

    cout << "\n\nTask 4b)" << endl;
    printRealRoots();

    cout << "\nTask 4c)" << endl;
    solveQuadraticEquation();

    cout << "\nTask 4d)" << endl;
    cout << "Task 4 can be found in main manu, will however go through all of task 4." << endl;

    cout << "\nTask 4e)" << endl;
    cout << " x^2 + 2x + 4 = 0 yields no real roots" << endl;
    cout << "4x^2 + 4x + 1 = 0 yields one real root x = -0.5" << endl;
    cout << "8x^2 + 4x - 1 = 0 yields two real roots: x1 = 0.183 and x2 = -0.683" << endl;
}
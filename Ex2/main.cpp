/*----------------------------------------------------
TITLE:  Assignment 2
COURSE: TDT4102 - Programming
AUTHOR: Aslak J. Strand

REQUIRED FILES:
- /Library/tdt4102/..

- .vscode/:
    - c_cpp_properties.json
    - extensions.json
    - launch.json
    - tasks.json

- /src/:            - /head/:
    - main.cpp          - main.h
    - task1.cpp         - task1.h
    - task2.cpp         - task2.h
    - task3.cpp         - task3.h
    - task4.cpp         - task4.h
    - task5.cpp         - task5.h
---------------------------------------------------*/


#include <iostream>
#include <stdio.h>
#include "time.h"
#include <vector>
//#include "../head/main.h"
#include "main.h"

using namespace std;

int main(void) {
#if DEBUG
    // Toggle DEBUG in main.h: <0,1> / <true/false>
    // Enter the function to test below:
    printLoan();
#else
    char mm;
    while (true) {
        cout << "\n---------------------------" << endl;
        cout << "~~~~~~~~ Main-Menu ~~~~~~~~" << endl;
        cout << "---------------------------" << endl;
        cout << "[0] - Exit   | [i] - Info  " << endl;
        cout << "[1] - Task 1 | [2] - Task 2" << endl;
        cout << "[3] - Task 3 | [4] - Task 4" << endl;
        cout << "[5] - Task 5 | [6] - Task 6" << endl;
        cout << "---------------------------" << endl;
        cout << "Select task: ";
        cin >> mm;

        switch (mm) {
            case '0': return 0;
            case '1': _task1(); break;
            case '2': _task2(); break;
            case '3': multiTable(); break;
            case '4': _task4(); break;
            case '5': pythagoras(); break;
            case '6': _task6(); break;
            case 'i':
                cout << "\n\n---------------------------" << endl;
                cout << "TITLE:  Assignment 2" << endl;
                cout << "COURSE: TDT4102-Programming" << endl;
                cout << "AUTHOR: Aslak J. Strand" << endl;
                cout << "  (c)   Aslak J. Strand";
                break;
        }
    }
#endif
    return 0;
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
    int m2 = 1;
    double num;
    while (m2 != 0) {
        cout << "\n---------------------------------------" << endl;
        cout << "~~~~~~~~~ Task 2,3 & 4: Loops ~~~~~~~~~" << endl;
        cout << "---------------------------------------" << endl;
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

void _task6(void) {
    int loan = 0;
    int rate = 0;
    int year = 0;
    int m6 = 0;
    vector<int> pay1;
    vector<int> pay2;

    while (true) {
        cout << "\n---------------------------------------" << endl;
        cout << "~~~~~~~~~~ Task 6: Loan-menu ~~~~~~~~~~" << endl;
        cout << "~~~~~ Input loan=0 to run example ~~~~~" << endl;
        cout << "---------------------------------------" << endl;
        cout << "[0] - Exit        | [1] - Task 6c      " << endl;
        cout << "[2] - Task 6a     | [3] - Task 6b      " << endl;
        cout << "---------------------------------------" << endl;
        cout << "Take your pick (0-3): ";
        cin >> m6;

        switch (m6) {
            case 0: return;
            case 1:
                cout << "\nTask 6a)" << endl;
                cout << "Enter your values:" << endl;
                cout << "Loan:  ";
                cin >> loan;
                if (loan == 0) {printLoan();} // Input 0 to run basic setup with given values
                else {
                    cout << "Rate:  ";
                    cin >> rate;
                    cout << "Years: ";
                    cin >> year;
                    printLoan(loan, rate, year);
                }
                
                break;
            case 2:
                // Task 6a)
                cout << "\nTask 6a)" << endl;
                cout << "Enter your values:" << endl;
                cout << "Loan:  ";
                cin >> loan;
                if (loan == 0) {pay1 = calculateSeries();} // Input 0 to run basic setup with given values
                else {
                    cout << "Rate:  ";
                    cin >> rate;
                    cout << "Years: ";
                    cin >> year;
                    pay1 = calculateSeries(loan, rate, year);
                }
                cout << "Year:\tPayment" << endl;
                for (int i = 0; i < pay1.size(); i++) {
                    cout << i+1 << "\t" << pay1[i] << endl;
                }
                break;
            case 3:
                // Task 6b)
                cout << "\nTask 6b)" << endl;
                cout << "Enter your values:" << endl;
                cout << "Loan:  ";
                cin >> loan;
                if (loan == 0) {pay2 = calcAnnuity();} // Input 0 to run basic setup with given values
                else {
                    cout << "Rate:  ";
                    cin >> rate;
                    cout << "Years: ";
                    cin >> year;
                    pay2 = calcAnnuity(loan, rate, year);
                }
                cout << "\nYear:\tPayment" << endl;
                for (int i = 0; i < pay2.size(); i++) {
                    cout << i+1 << "\t" << pay2[i] << endl;
                }
                break;
            default:
                cout << "\nWrong input." << endl;
                cout << "Please try again.";
        }
    }
}


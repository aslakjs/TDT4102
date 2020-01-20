/*----------------------------------------------------
TITLE:  Assignment 4
COURSE: TDT4102 - Programming
AUTHOR: Aslak J. Strand (c)

Notes:
    - N/A
---------------------------------------------------*/

#include <iostream>
#include <vector>
#include "main.h"
using namespace std;

int main(void) {
    char mm = 'a';
    initRando();
    for (int i = 0; i<50; i++) {cout << endl;}  // Adding whitespace at start of program
    while (true) {
        _mmText();
        cin >> mm;
        switch (mm) {
            case '0': cout << "\n\n"; return 0;
            case 'i': _info(); waitForEnter(); break;
            case '1': _task1(); break;
            case '2': _task2(); break;
            case '3': _task3(); break;
            case '4': testStruct(); waitForEnter(); break;
            case '5': _task5(); break;
            default: cout << "Invalid choice, try again.";
        }
        for (int i = 0; i<50; i++) {cout << endl;}  // Adding whitespace at start of program
    }
    return 0;
}


// Tasks 1:
void _task1(void) {
    char m1 = '0';
    while (true) {
        for (int i = 0; i<50; i++) {cout << endl;}
        cout << "-----------------------------" << endl;
        cout << "~~~~~~~~~~ Task 1 ~~~~~~~~~~~" << endl;
        cout << "-----------------------------" << endl;
        cout << "[0] - Exit    | [a] - Task 1a" << endl;
        cout << "[b] - Task 1b | [c] - Task 1c" << endl;
        cout << "[d] - Task 1d | [e] - Task 1e" << endl;
        cout << "-----------------------------" << endl;
        cout << "Your choice: ";
        cin >> m1;

        switch (m1) {
            case '0': return;
            case 'a': cout << "\nThe value for v0 = 5" << endl; break;
            case 'b': cout << "\nSee source-code.." << endl; break;
            case 'c': testCallByValue(); break;
            case 'd': testCallByReference(); break;
            case 'e': 
                int dA, dB;
                cout << endl << "Enter digit A: ";
                cin >> dA;
                cout << "Enter digit B: ";
                cin >> dB;
                swapNumbers(dA, dB);

                cout << "Digit A is now: " << dA << endl;
                cout << "Digit B is now: " << dB << endl;

                cout << endl << "Theory:" << endl;
                cout << "Funksjonen kan godt bruke referanser, da slipper man å opprette 'nye' verdier og endrer bare de originale verdiene." << endl;
                cout << "Man skal derimot være forsiktig med bruk av referanser til verdier som _ikke_ skal endres i funksjonen." << endl; break;
                break;
            default: cout << endl << "Wrong input, try again." << endl; break;
        }
        waitForEnter();
    }
}

// Tasks 2:
void _task2(void) {
    char m2 = '0';
    vector<int> task2d (0,0);
    int n = 0;
    while (true) {
        for (int i = 0; i<50; i++) {cout << endl;}
        cout << "-----------------------------" << endl;
        cout << "~~~~~~~~~~ Task 2 ~~~~~~~~~~~" << endl;
        cout << "-----------------------------" << endl;
        cout << "[0] - Exit    |              " << endl;
        cout << "[a] - Task 1a | [b] - Task 1b" << endl;
        cout << "[c] - Task 1c | [d] - Task 1d" << endl;
        cout << "-----------------------------" << endl;
        cout << "Your choice: ";
        cin >> m2;

        switch (m2) {
            case '0': return;
            case 'a': cout << "\nSee cource-code" << endl; break;
            case 'b': cout << "\nSee cource-code" << endl; break;
            case 'c': testVectorSorting(); break;
            case 'd': 
                cout << "\nEnter number of digits in vector:";
                cin >> n;
                randomizeVector(task2d, n);
                printVector(task2d);
                swapNumbers(task2d[0], task2d[1]);
                printVector(task2d);
                break;
            default: cout << endl << "Wrong input, try again." << endl; break;
        }
        waitForEnter();
    }
}

// Tasks 3:
void _task3(void) {
    char m3 = '0';
    
    while (true) {
        for (int i = 0; i<50; i++) {cout << endl;}
        cout << "-----------------------------" << endl;
        cout << "~~~~~~~~~~ Task 3 ~~~~~~~~~~~" << endl;
        cout << "-----------------------------" << endl;
        cout << "[0] - Exit    |              " << endl;
        cout << "[a] - Task 3a | [b] - Task 3b" << endl;
        cout << "-----------------------------" << endl;
        cout << "Your choice: ";
        cin >> m3;

        switch (m3) {
            case '0': return;
            case 'a': testSortVect(); break;
            case 'b': testMedian(); break;
            default: cout << endl << "Wrong input, try again." << endl; break;
        }
        waitForEnter();
    }
}

void _task5(void) {
    char m5 = '0';
    
    while (true) {
        for (int i = 0; i<50; i++) {cout << endl;}
        cout << "-----------------------------" << endl;
        cout << "~~~~~~~~~~ Task 5 ~~~~~~~~~~~" << endl;
        cout << "-----------------------------" << endl;
        cout << "[0] - Exit    |              " << endl;
        cout << "[e] - Task 5e | [f] - Task 5f" << endl;
        cout << "[g] - Task 5g | [h] - Task 5h" << endl;
        cout << "-----------------------------" << endl;
        cout << "Your choice: ";
        cin >> m5;

        switch (m5) {
            case '0': return;
            case 'e': testString(); break;
            case 'f': testInputString(); break;
            case 'g': testCountChar(); break;
            case 'h': task5h(); break;
            default: cout << endl << "Wrong input, try again." << endl; break;
        }
        waitForEnter();
    }
}



// --------------------------------------------------
// Main menu text: Display choices
void _mmText(void) {
    cout << "---------------------------" << endl;
    cout << "~~~~~~~~ Main Menu ~~~~~~~~" << endl;
    cout << "---------------------------" << endl;
    cout << "[0] - Exit   | [i] - Info  " << endl;
    cout << "[1] - Task 1 | [2] - Task 2" << endl;
    cout << "[3] - Task 3 | [4] - Task 4" << endl;
    cout << "[5] - Task 5 | [6] - Task 6" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
}
void _info(void) {
    for (int i = 0; i<50; i++) {cout << endl;}
    cout << "---------------------------" << endl;
    cout << "TITLE:  Assignment 3       " << endl;
    cout << "COURSE: TDT4102-Programming" << endl;
    cout << "AUTHOR: Aslak J. Strand    " << endl;
    cout << "  (c)   Aslak J. Strand    " << endl;
    cout << "---------------------------" << endl << endl;
}
// Wait for enter-key
inline void waitForEnter() {
    cout << endl;
    fseek(stdin,0,SEEK_END); // Clear input buffer
    do {cout << "Press Enter To Continue..";
    } while (cin.get()!='\n');
    for (int i = 0; i < 100; i++) {cout << endl;}
}
/*----------------------------------------------------
TITLE:  Assignment 4
COURSE: TDT4102 - Programming
AUTHOR: Aslak J. Strand (c)

Notes:
    - N/A
---------------------------------------------------*/

#include <iostream>
#include "main.h"
using namespace std;

int main(void) {
    char mm = 'a';
    for (int i = 0; i<50; i++) {cout << endl;}  // Adding whitespace at start of program
    while (true) {
        _mmText();
        cin >> mm;
        switch (mm) {
            case '0': cout << "\n\n"; return 0;
            case 'i': _info(); waitForEnter(); break;
            case '1': _task1(); break;

            default: cout << "Invalid choice, try again.";
        }
        for (int i = 0; i<50; i++) {cout << endl;}  // Adding whitespace at start of program
    }
    return 0;
}


// Tasks-menu:
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
            case 'a': task1a(); break;
            case 'b': cout << "\nSee source-code.." << endl; break;
            case 'c': testCallByValue(); break;
            case 'd': testCallByReference(); break;
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
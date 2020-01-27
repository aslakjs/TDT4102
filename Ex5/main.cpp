/*----------------------------------------------------
TITLE:  Assignment X
COURSE: TDT4102 - Programming
AUTHOR: Aslak J. Strand (c)

Notes:
    - N/A
---------------------------------------------------*/

#include <iostream>
#include "std_lib_facilities.h"
#include "Card.h"
#include "deb.h"

#if TEST 		// IF test-mode TRUE, change in deb.h
#include "test.h"
#endif /* !TEST */

using namespace std;

// Internal declarations:
void _mm(void);
void _info(void);
inline void waitForEnter(void);
void _task1(void);
void _task2(void);


// Code start below:
int main() {
	char mm;
#if TEST	// Test functions:
	testSuitAndRankPrint(Rank::ace, Suit::spades);
#else		// Main code below:
	while (true) {
		_mm();
		cin >> mm;
		switch (mm) {
			case '0': cout << "\n\nBye!"; waitForEnter(); return 0;
			case 'i': _info(); waitForEnter(); break;
			case '1': _task1(); waitForEnter(); break;
			case '2': _task2(); waitForEnter(); break;
			default: cout << "\n\nWrong input, try again.. \n\n"; break;
		}
	}
#endif /* !TEST */
	return 0;
}

void _task1(void) { // Task 1e only, a-d can be seen in source-code.
	cout << endl << endl;
	cout << "Task 1e)" << endl;
	cout << "#1: Easy to spot in code, yields less coding error." << endl;
	cout << "#2: Saving variable-names for other useage." << endl << endl;
}

void _task2(void) {	// Task 2...
	char m2;
	Card c(Suit::spades, Rank::ace);
	while (true) {
        for (int i = 0; i<50; i++) {cout << endl;}
        cout << "------------------------------" << endl;
        cout << "~~~~~~~~~~~ Task 2 ~~~~~~~~~~~" << endl;
        cout << "------------------------------" << endl;
        cout << "[0] - MainMenu |              " << endl;
        cout << "[a] - Task 1a  | [b] - Task 1b" << endl;
        cout << "[c] - Task 1c  | [d] - Task 1d" << endl;
		cout << "[e] - Task 1c  | [f] - Task 1d" << endl;
        cout << "------------------------------" << endl;
        cout << "Your choice: ";
        cin >> m2;

        switch (m2) {
            case '0': return;
            case 'a': cout << endl << "See Card.h" << endl << endl; break;
            case 'b': cout << endl << "See Card.cpp" << endl << endl; break;
            case 'c': 
				cout << endl << "Suit = " << c.getSuit() << endl;
				break;
            case 'd': 
				cout << endl << "Rank = " << c.getRank() << endl;
				break;
			case 'e': break;
			case 'f': break;
            default: cout << endl << "Wrong input, try again." << endl; break;
        }
        waitForEnter();
	}
}


void _mm(void) {
	for (int i = 0; i<50; i++) {cout << endl;}
	cout << "---------------------------" << endl;
    cout << "~~~~~~~~ Main Menu ~~~~~~~~" << endl;
    cout << "---------------------------" << endl;
    cout << "[0] - Exit   | [i] - Info  " << endl;
    cout << "[1] - Task 1 | [2] - Task 2" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
}
void _info(void) {
    for (int i = 0; i<50; i++) {cout << endl;}
    cout << "---------------------------" << endl;
    cout << "TITLE:  Assignment 5       " << endl;
    cout << "COURSE: TDT4102-Programming" << endl;
    cout << "AUTHOR: Aslak J. Strand    " << endl;
    cout << "  (c)   Aslak J. Strand    " << endl;
    cout << "---------------------------" << endl << endl;
}
// Wait for enter-key
inline void waitForEnter(void) {
    cout << endl;
    fseek(stdin,0,SEEK_END); // Clear input buffer
    do {cout << "Press Enter To Continue..";
    } while (cin.get()!='\n');
    for (int i = 0; i < 100; i++) {cout << endl;}
}
/*----------------------------------------------------
TITLE:  Assignment 6
COURSE: TDT4102 - Programming
AUTHOR: Aslak J. Strand (c)

Notes:
    - N/A
---------------------------------------------------*/

#include <iostream>
#include "std_lib_facilities.h"
#include "task1.h"
using namespace std;

// Declarations
void _mm(void);		// Main Menu text
void _task1(void);	// Task 1 menu

int main() {
	char mm = 'a';
	while (true) {
		_mm();
		cin >> mm;

		switch (mm) {
			case '0': return 0;
			case '1': _task1();
			default: cout << "Wrong input, try again."; break;
		}
	}
}


void _mm(void) {
	for (int i = 0; i<50; i++) {cout << endl;}
	cout << "-----------------------------" << endl;
    cout << "~~~~~~~~~ Main Menu ~~~~~~~~~" << endl;
    cout << "-----------------------------" << endl;
    cout << "[0] - Exit    |    " << endl;
    cout << "[1] - Task 1  | [2] - Task 2 " << endl;
	cout << "[3] - Task 3  | [4] - Task 4 " << endl;
    cout << "-----------------------------" << endl;
    cout << "Your choice: ";
}
void _task1(void) {
	char m1 = 'a';
	while (m1 != '0') {
		for (int i = 0; i<50; i++) {cout << endl;}
		cout << "-----------------------------" << endl;
		cout << "~~~~~~~~~~~ Task1 ~~~~~~~~~~~" << endl;
		cout << "-----------------------------" << endl;
		cout << "[0] - Exit    |   " << endl;
		cout << "[a] - Task 1a | [2] - Task 2a" << endl;
		cout << "-----------------------------" << endl;
		cout << "Your choice: ";
		cin >> m1;

		switch (m1) {
			case '0': return;
			case 'a': cinToFile();
		}
	}
}
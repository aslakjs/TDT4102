/*----------------------------------------------------
TITLE:  Assignment 6
COURSE: TDT4102 - Programming
AUTHOR: Aslak J. Strand (c)

Notes:
    - All .txt files will be created at:
		- {workplaceRoot}/txtFiles/
---------------------------------------------------*/

#include <iostream>
#include "std_lib_facilities.h"
#include "task1.h"	// Task 1 code
#include "task2.h"	// Task 2 code
using namespace std;

// Declarations
void _mm(void);		// Main Menu text
void _task1(void);	// Task 1 menu
void _task2(void);	// Task 2 menu

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
		cout << "[a] - Task 1a | [b] - Task 1b" << endl;
		cout << "-----------------------------" << endl;
		cout << "Your choice: ";
		cin >> m1;

		switch (m1) {
			case '0': return;
			case 'a': cinToFile(); break;
			case 'b': fileToFile(); break;
		}
		cout << endl;
		keep_window_open();
	}
}
void _task2(void) {
	char m2 = 'a';
	while (m2 != '0') {
		for (int i = 0; i<50; i++) {cout << endl;}
		cout << "-----------------------------" << endl;
		cout << "~~~~~~~~~~~ Task2 ~~~~~~~~~~~" << endl;
		cout << "-----------------------------" << endl;
		cout << "[0] - Exit    |   " << endl;
		cout << "[a] - Task 2a | [b] - Task 2b" << endl;
		cout << "-----------------------------" << endl;
		cout << "Your choice: ";
		cin >> m2;

		switch (m2) {
			case '0': return;
			case 'a':  break;
			case 'b':  break;
		}
		cout << endl;
		keep_window_open();
	}
}
/*----------------------------------------------------
TITLE:  Assignment 6
COURSE: TDT4102 - Programming
AUTHOR: Aslak J. Strand (c)

Notes:
	- Select OS in def.h
		- Creating and reading is slightly different in UNIX vs. Windows
    - All .txt files will be created at:
		- {workplaceRoot}/txtFiles/
	- All given files (temp & laws) shall be added to:
		- {workplaceRoot}/givenFiles/
---------------------------------------------------*/

#include <iostream>		// Used for cin, cout, and whatnot
#include "sys/stat.h"	// used for mkdir (Create directory of not exist)
#include "def.h"		// Hard definitions
#include "task1.h"		// Task 1 code
#include "task2.h"		// Task 2 code
#include "task3.h" 		// Task 3 code
#include "task4and5.h"	// Task 4 and 5 code
using namespace std;

// Declarations
void _cc(void);		// Copyright-info
void _mm(void);		// Main Menu text
void _task1(void);	// Task 1 menu
void _task3(void);	// Task 3 menu
void _task45(void); 	// Task 4 menu

int main() {
	char mm = 'a';

#if _UNIX_	// Only do this if UNIX
	mkdir(BASE_PATH, 0777);	// Creates directory for usable txt-files if not exist
	mkdir(GIVN_PATH, 0777);	// Creates directory for given files if not exist
#else		// Only do this if Windows
	_mkdir(BASE_PATH);		// Creates directory for usable txt-files if not exist
	_mkdir(GIVN_PATH);		// Creates directory for given files if not exist
#endif /* _UNIX_ */

	while (true) {
		_mm();
		cin >> mm;
		switch (mm) {
			case '0': return 0;
			case 'i': _cc(); break;
			case '1': _task1(); break;
			case '2': countChar(); waitForEnter(); break;
			case '3': _task3(); break;
			case '4': _task45(); break;
			default: cout << "Wrong input, try again." << endl; waitForEnter(); break;
		}
	}
}

// Wait for enter-key
inline void waitForEnter(void) {
    cout << endl;
    fseek(stdin,0,SEEK_END); // Clear input buffer
    do {cout << "Press Enter To Continue..";
    } while (cin.get()!='\n');
    for (int i = 0; i < 100; i++) {cout << endl;}
}
void _cc(void) {
	cout << "-----------------------------" << endl;
	cout << "  Written & Copyrighted by:" << endl;
	cout << "      Aslak J. Strand" << endl;
	cout << "-----------------------------" << endl << endl;
	waitForEnter();
}
void _mm(void) {
	for (int i = 0; i<50; i++) {cout << endl;}
	cout << "---------------------------------" << endl;
    cout << "~~~~~~~~~~~ Main Menu ~~~~~~~~~~~" << endl;
    cout << "---------------------------------" << endl;
    cout << "[0] - Exit    | [i] - Info       " << endl;
    cout << "[1] - Task 1  | [2] - Task 2     " << endl;
	cout << "[3] - Task 3  | [4] - Task 4 & 5 " << endl;
    cout << "---------------------------------" << endl;
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
			default: cout << "Wrong input, try again." << endl; break;
		}
		cout << endl;
		waitForEnter();
	}
}
void _task3(void) {
	char m3 = 'a';
	CourseCatalog *CC = new CourseCatalog;
	while (m3 != '0') {
		for (int i = 0; i<50; i++) {cout << endl;}
		cout << "-----------------------------" << endl;
		cout << "~~~~~~~~~~~ Task3 ~~~~~~~~~~~" << endl;
		cout << "-----------------------------" << endl;
		cout << "[0] - Exit    | [i] - Info  " << endl;
		cout << "[a] - Add     | [r] - Remove" << endl;
		cout << "[c] - Test    | [p] - Print  " << endl;
		cout << "-----------------------------" << endl;
		cout << "Your choice: ";
		cin >> m3;

		switch (m3) {
			case '0': return;
			case 'i': cout << "\nTask 3a, b, d & e can be seen in source code." << endl; break;
			case 'a': CC->addCource(); break;
			case 'r': CC->removeCource(); break;
			case 'c': testCatalog(CC); break;
			case 'p': CC->getCource("-1"); break;
			default: cout << "Wrong input, try again." << endl; break;
		}
		cout << endl;
		CC->mapOut(); 
		waitForEnter();
	}
}
void _task45(void) {
	char m4 = 'a';
	while (m4 != '0') {
		for (int i = 0; i<50; i++) {cout << endl;}
		cout << "-----------------------------" << endl;
		cout << "~~~~~~~ Task 4 and 5 ~~~~~~~~" << endl;
		cout << "-----------------------------" << endl;
		cout << "[0] - Exit    |   " << endl;
		cout << "[a] - Task 4a | [b] - Task 4b" << endl;
		cout << "[c] - Task 4c | [5] - Task 5 " << endl;
		cout << "-----------------------------" << endl;
		cout << "Your choice: ";
		cin >> m4;

		switch (m4) {
			case '0': return;
			case 'a': cout << "See task4and5.h" << endl; break;
			case 'b': cout << "See task4and5.cpp" << endl; break;
			case 'c': testOperator(); break;
			case '5': graphData(); break;
			default: cout << "Wrong input, try again." << endl; break;
		}
		cout << endl;
		waitForEnter();
	}
}
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
#include "def.h"	// Hard definitions
#include "task1.h"	// Task 1 code
#include "task2.h"	// Task 2 code
#include "task3.h" 	// Task 3 code
using namespace std;

// Declarations
void _mm(void);		// Main Menu text
void _task1(void);	// Task 1 menu
void _task3(void);	// Task 3 menu

int main() {
	char mm = 'a';
	while (true) {
		_mm();
		cin >> mm;

		switch (mm) {
			case '0': return 0;
			case '1': _task1(); break;
			case '2': countChar(); waitForEnter(); break;
			case '3': _task3(); break;
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
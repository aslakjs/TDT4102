/*----------------------------------------------------
TITLE:  Assignment 7
COURSE: TDT4102 - Programming
AUTHOR: Aslak J. Strand (c)

Notes:
    - N/A
---------------------------------------------------*/

#include <iostream>
#include "test.h"

using namespace std;

void _mm(void);
void _cc(void);
inline void waitForEnter(void);
void _task1(void);

int main() {
	char mm = 'a';

	while (true) {
		_mm();
		cin >> mm;
		switch (mm) {
			case '0': return 0;
			case 'i': _cc(); break;
			case '1': _task1(); break;
			default: cout << "Wrong input, try again." << endl; waitForEnter(); break;
		}
	}
}

void _task1(void) {
	char m1 = 'a';

	while (true) {
		for (int i = 0; i<50; i++) {cout << endl;}
		cout << "---------------------------------" << endl;
		cout << "~~~~~~~~~~~~~ Task 1 ~~~~~~~~~~~~" << endl;
		cout << "---------------------------------" << endl;
		cout << "[0] - Exit    | [a] - Task 1a    " << endl;
		cout << "[b] - Task 1b | [c] - Task 1c    " << endl;
		cout << "[d] - Task 1d | [e] - Task 1e    " << endl;
		cout << "---------------------------------" << endl;
		cout << "Your choice: ";
		cin >> m1;

		switch (m1) {
			case '0': return;
			case 'a': 
				cout << "\nPublic:    accessible outside class" << endl;
				cout << "Private:   ONLY accessible inside class" << endl;
				cout << "Protected: Accessible in hiarchy-classes bound to the spesific class." << endl << endl;
				waitForEnter();
				break;
			case 'b': cout << "\nSee animal.h" << endl; break;
			case 'c': cout << "\nSee animal.h" << endl; break;
			case 'd': testAnimal(); break;
			case 'e': break;
			default: cout << "Wrong input, try again." << endl; waitForEnter(); break;
		}

		waitForEnter();
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
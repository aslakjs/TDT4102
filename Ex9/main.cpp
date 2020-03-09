/*----------------------------------------------------
TITLE:  Assignment X
COURSE: TDT4102 - Programming
AUTHOR: Aslak J. Strand (c)

Notes:
    - N/A
---------------------------------------------------*/

#include <iostream>
#include "task1.h"

void _task1(void);
void _cc(void);
void _mm(void);
inline void waitForEnter(void);

using namespace std;

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
		cout << "~~~~~~~~~~~~ Task: 1 ~~~~~~~~~~~~" << endl;
		cout << "---------------------------------" << endl;
		cout << "[0] - Exit    |        " << endl;
		cout << "[a] - Task 1a | [b] - Task 1b    " << endl;
		cout << "[c] - Task 1c |     " << endl;
		cout << "---------------------------------" << endl;
		cout << "Your choice: ";
		cin >> m1;
		switch (m1) {
			case '0': return;
			case 'a': {
				int result[10];
				cout << endl << endl;
				fillInFibonacciNumbers(result, 10);
				break;
				}
			case 'b': {int arr[] = {1, 2, 3, 4, 5}; printArray(arr, 5); break;}
			case 'c': createFibonacci(); break;
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
	cout << "---------------------------------" << endl;
	cout << "    Written & Copyrighted by:" << endl;
	cout << "        Aslak J. Strand" << endl;
	cout << "---------------------------------" << endl << endl;
	waitForEnter();
}
void _mm(void) {
	for (int i = 0; i<50; i++) {cout << endl;}
	cout << "---------------------------------" << endl;
    cout << "~~~~~~~~~~~ Main Menu ~~~~~~~~~~~" << endl;
    cout << "---------------------------------" << endl;
    cout << "[0] - Exit    | [i] - Info       " << endl;
    cout << "[1] - Task 1  | [2] - Task 2     " << endl;
    cout << "---------------------------------" << endl;
    cout << "Your choice: ";
}
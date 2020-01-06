#include <iostream>
#include <stdio.h>
#include "../head/main.h"

using namespace std;

int main(void) {
    int mm;
    while (true) {
        cout << "\n-------------------------" << endl;
        cout << "[0] - Exit | [1] - Task 1" << endl;
        cout << "[2] - TBD  | [3] - TBD" << endl;
        cout << "-------------------------" << endl;
        cout << "Select task: ";
        cin >> mm;

        switch (mm) {
            case 0: return 0;
            case 1: _task1(); break;
        }
    }
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
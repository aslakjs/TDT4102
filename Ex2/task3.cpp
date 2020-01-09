#include <iostream> // cout/cin etc,
#include <iomanip>  // setw
//#include "../head/task3.h"
#include "task3.h"
using namespace std;

// Task 3a) menu-setup -> see _task2 @ main.cpp

// Task 3b)
void multiTable(void) {
    double width, height;
    int base;
    cout << "Multiplication table for base integer: ";
    cin >> base;

    cout << "Set width of table: ";
    cin >> width;

    cout << "Set height of table (number of multiplications): ";
    cin >> height;
    
    for (int i = 1; i <= height; i++) {
        cout << setw(width) << i*base << endl;
    }
}
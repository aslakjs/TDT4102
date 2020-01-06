#include <iostream> // cout/cin etc,
#include <iomanip> // SetPrecition
#include "../head/task2.h"
using namespace std;

// Task 2a)
void intSum(void) {
    int size = 0;
    int sum = 0;
    int temp = 0;
    cout << "Number of integers to be used: ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        cout << "Input integer #" << i+1 << ": ";
        cin >> temp;
        sum += temp;
    }
    cout << "Total sum = " << sum << endl;
}

// Task 2b)
void infSum(void) {
    int sum = 0;
    int temp = 1;
    int i = 1;
    cout << "Add integers, [0] - sum & continue." << endl;
    while (temp != 0) {
        cout << "Input integer #" << i << ": ";
        cin >> temp;
        sum += temp;
        i++;
    }
    cout << "Total sum = " << sum << endl;
}

// Task 2c) Theory -> see main.cpp

// Task 2d)
double inputDouble(void) {
    double num;
    cout << "Enter a float: ";
    cin >> num;
    return num;
}

// Task 2e)
void nok2Eur(void) {
    double nok, eur;
    double eur2nok = 9.75;
    cout << "Calc Euro from NOK float price:" << endl;
    nok = inputDouble();
    while (nok < 0){
        cout << "Price has to be positive." << endl;
        nok = inputDouble();
    }
    eur = nok*eur2nok;
    cout << nok << " NOK = " << fixed << setprecision(2) << eur << " Euro." << endl;
}
#include <iostream> // cout/cin etc,
#include <cmath>
//#include "../head/task4.h"
#include "task4.h"
using namespace std;

// Task 4a)
double discriminant(double a, double b, double c) {
    return static_cast<double>(pow(b,2) - (4*a*c));
}

// Task 4b)
void printRealRoots(double a, double b, double c) {
    double x1, x2;
    double disc = discriminant(a, b, c);
    if (disc > 0) {
        x1 = (-b + sqrt(disc)) / (2*a);
        x2 = (-b - sqrt(disc)) / (2*a);
        cout << "Real root:\nx1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else if (disc == 0) {
        x1 = (-b) / (2*a);
        cout << "Real root:\nx = " << x1 << endl;
    }
    else {
        cout << "No real roots exists." << endl;
    }
}

// Task 4c)
void solveQuadraticEquation(void) {
    double A, B, C;
    cout << "For the expression:" << endl;
    cout << "Ax^2 + Bx + C = 0" << endl;
    cout << "Input the following parameters:" << endl;
    cout << "A: ";
    cin >> A;
    cout << "B: ";
    cin >> B;
    cout << "C: ";
    cin >> C;

    cout << "Your expression: " << A << "x^2 + " << B << "x + " << C << " = 0" << endl;
    printRealRoots(A, B, C);
}
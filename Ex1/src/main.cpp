#include "../head/main.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


int main(void) {
    int mtask;
    while (true) {
        cout << "\n--------------------------" << endl;
        cout << "[0] - Exit  | [1] - Task 1" << endl;
        cout << "--------------------------" << endl;

        cout << "\nSelect main task: ";
        cin >> mtask;
        switch (mtask) {
            case 0: return 0;
            case 1:
                cout << "\n\nOppgave 1: Python2C++" << endl;
                _task1();
                break;
            default:
                cout << "Not a valid option." << endl;
                break;
        }
        cout << "\n\n";
    }
}


void _task1(void) {
    double a, b;
    int n = 0;
    char task;

    while (task != 0) {
        cout << "\n--------------------------------------------" << endl;
        cout << "[0] - Exit        | [a] - Største tall" << endl;
        cout << "[b] - Fibonacci   | [c] - Squared Number Sum" << endl;
        cout << "[d] - Trekanttall | [e] - Primtall 1" << endl;
        cout << "[f] - Primtall 2  | [g] - Største nevner" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "\nSelect a task: ";
        cin >> task;

        switch (task) {
            case '0': return;

            case 'a': // Største tall:
                cout << "Oppgave 1a:\n\nEnter digit A: ";
                cin >> a;
                cout << "Enter digit B: ";
                cin >> b;
                maxOfTwo(a,b);
                break;

            case 'b': // Fibonacci:
                cout << "\n\nOppgave 1b:\nEnter number of fibonacci numbers to be printed: ";
                cin >> n;
                fibonacci(n);
                break;

            case 'c': // SquareNumberSum
                cout << "\n\nOppgave 1c:\nEnter number of squared numbers to be used: ";
                cin >> n;
                squareNumberSum(n);
                break;

            case 'd': // Trekanttall
                cout << "\n\nOppgave 1d:\nEnter number to be used: ";
                cin >> n;
                triangleNumbersBelow(n);
                break;

            case 'e': // Primtall 1
                cout << "\n\nOppgave 1e:\nEnter number to be checked: ";
                cin >> n;
                cout << isPrime(n);
                break;

            case 'f': // Primtall 2
                cout << "\n\nOppgave 1f:\nEnter number to be checked: ";
                cin >> n;
                cout << "final number: ";
                naivePrimeNumberSearch(n);
                break;

            case 'g': // Største nevner
                cout << "\n\nOppgave 1g:\nEnter number to be checked: ";
                cin >> n;
                cout << "final number: " << findGreatestDivisor(n);
                break;

            default: // False input
                cout << "Not a valid option." << endl;
                break;
        }
    }
}


double maxOfTwo(double a, double b) {
    if (a > b) {
        cout << "A is grater than B" << endl;
        return a;
    }
    else {
        cout << "B is greater than or equal to A" << endl;
        return b;
    }
}

double fibonacci(int n) {
    int a = 0;
    int b = 1;
    int temp;
    int fib;

    cout << "\n---------------------------------------------" << endl;
    cout << "[0] - exit | [1] - Original | [2] - Corrected" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Select your preffered Fibonacci-sequence: ";
    cin >> fib;
    cout << "Fibonacci numbers:" << endl;
    switch (fib) {
        case 0: break;
        case 1: // Original fibbonaci-sequence:
            for (int x = 1; x < (n+1); x++) {
                cout << x << b << "\t";
                temp = b;
                b += a;
                a = temp;
            }
            break;
        case 2: // Corrected fibbonaci-sequence:
            for (int x = 1; x < (n+1); x++) {
                cout << a << "\t";
                temp = b;
                b += a;
                a = temp;
                
            }
            break;
    } 
    cout << "\n\n-----";
    return b;
}

double squareNumberSum(int n) {
    double totalSum = 0;
    cout << endl;
    for (int i = 0; i<n; i++) {
        totalSum += (i * i);
        cout << "sum #" << i+1 << ": " << totalSum << endl;
    } 
    cout << "Total sum: " << totalSum << endl;
    return totalSum;
}

void triangleNumbersBelow(int n) {
    int acc = 1;
    int num = 2;
    cout << "Triangle numbers below " << n << ":" << endl;
    do {
        cout << acc;
        acc += num;
        num += 1;
    } while (acc < n);
    cout << "";
}

bool isPrime(int n) {
    for (int j = 2; j < n; j++) {
        if ((n % j) == 0) {
            return false;
        }
    }
    return true;
}

void naivePrimeNumberSearch(int n) {
    for (double num = 2; num < n; num++) {
        if (isPrime(num)) {
            cout << num << " is a prime";
        }
    }
}

double findGreatestDivisor(int n) {
    for (int div = (n-1); div > 0; div--) {
        if (n % div == 0) {
            return div;
        }
    }
}
#include <iostream>
#include "task1.h"
using namespace std;

void fillInFibonacciNumbers(int result[], int length) {
    for (int i = 0; i < length; i++) {
        if (i == 0) {
            result[i] = 0;
        }
        else if (i == 1) {
            result[i] = 1;
        }
        else {
            result[i] = result[i-1] + result[i-2];
        }
    }
    //printArray(result, length);
}

void printArray(int arr[], int length) {
    cout << endl << endl;
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}

void createFibonacci(void) {
    int len = 0;
    int *result;

    // 1. Ask for length of Fib array:
    cout << endl << "Enter length of fib.array: ";
    cin >> len;

    // 2. Alloc memory for array:
    result = (int*) malloc(len);

    // 3. Fill array with len*fib-numbers:
    fillInFibonacciNumbers(result, len);
    
    // 4. Print array:
    printArray(result, len);
    
    // 5. Free allocated memory:
    free(result);
}
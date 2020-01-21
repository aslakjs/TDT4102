#include <iostream>
#include <vector>
#include <iomanip>
#include "test.h"
#include "utilities.h"

using namespace std;
// global (iknow, bad practise...):
bool threeA = false;
bool threeB = false;
bool fiveH = false;

// task 1c)
void testCallByValue(void) {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0 
         << " increment: " << increment
         << " iterations: " << iterations
         << " result: " << result << endl;
}

// task 1d)
void testCallByReference(void) {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "v0: " << v0 
         << " increment: " << increment
         << " iterations: " << iterations << endl;
}

// task 2a)
void testVectorSorting(void) {
    // task 2b)
    vector<int> percentages (0,0);

    // task 2c)
    int n = 10;
    randomizeVector(percentages, n);
    printVector(percentages);

    if (threeA) {
        cout << endl;
        sortVector(percentages);
        printVector(percentages);
    }
    else if (threeB) {
        cout << "median before: " << medianOfVector(percentages) << endl << endl;
        sortVector(percentages);
        printVector(percentages);
        cout << "median after:  " << medianOfVector(percentages) << endl;
    }
}

// task 2a)
void testSortVect(void) {
    threeA = true;   // Toggle extra module in testVectorSorting
    testVectorSorting();
    threeA = false;
}

void testMedian(void) {
    threeB = true;
    testVectorSorting();
    threeB = false;
}

// task 4)
void testStruct(void) {
    char names[200];
    char fos[300];
    Student* stud = new Student;

    // Clear input cache
    fseek(stdin,0,SEEK_END);    

    // Using getline to counter posible spaces in input
    cout << "Enter name: ";
    cin.getline(names, 200);    
    stud->name = names;

    // Using getline to counter posible spaces in input
    cout << "Enter study program: ";
    cin.getline(fos,300);       
    stud->studyProgram = fos;

    // Low posibillity of spaces in age: 
    //      hence directly pointer to struct
    cout << "Enter age: ";
    cin >> stud->age;            
    cout << endl;

    printStudent(stud);
}

// task 5a)
void testString(void) {
    int n = 10;  // Number of grades~~
    vector<int> grade = {'A','B','C','D','E','F'};
    vector<int> gradeCount(grade.size(),0);
    string grades = randomizeString(n, 'A', 'F');
    double snitt = 0;
    
    // task 5e)
    cout << endl << "Grades: " << grades << endl;

    if (fiveH) {
        // task 5h)
        for (int i = 0; i < gradeCount.size(); i++) {
            gradeCount[i] = countChar(grades, static_cast<char>(grade[i]));
            cout << "Grade:  " << static_cast<char>(grade[i]) << ": " << gradeCount[i] << endl;
        }
        int j = 5;
        for (int i = 0; i < gradeCount.size(); i++) {
            snitt += j*gradeCount[i];
            j--;
        }
        snitt /= static_cast<double>(n);
        cout << endl << "Average grade = " << fixed << setprecision(2) << snitt << endl;
    }
}

// task 5f)
void testInputString(void) {
    string test = "";
    while (test != "0000") {
        test = readInputToString('f', 'a', 4);
        cout << endl << "Final string: " << test << endl;
    }
}

// task 5g)
void testCountChar(void) {
    string str = "aabbadscaa";
    char ch = 'a';
    int c = countChar(str, ch);

    cout << endl << "String = " << str << endl;
    cout << "Number(s) of " << ch << ": " << c << endl;
}

void task5h(void) {
    fiveH = true;
    testString();
    fiveH = false;
}
#include <iostream>
#include "utilities.h"

using namespace std;

void initRando(void) {
    srand(static_cast<unsigned int>(time(nullptr)));
}

void printVector(vector<int> vect) {
    cout << "Your vector =\n{ ";
    for (int i = 0; i < vect.size(); i++) {
        cout << vect[i] << " ";
    }
    cout << "}" << endl;
}

// Task 1b
int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

// Task 1d)
void incrementByValueNumTimesRef(int& startValue, int& increment, int& numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
}

// Task 1e)
void swapNumbers(int& dA, int& dB) {
    //cout << "\n~~Swapping data:~~\n" << endl;
    int temp = 0;
    temp = dA;
    dA = dB;
    dB = temp;
}

// Task 2c)
void randomizeVector(vector<int>& percentages, int n, int upper, int lower) {
    for (int i = 0; i < n; i++) {
        percentages.push_back( lower + (rand() % (upper-lower)));
    }
}

// Task 3a)
void sortVector(vector<int>& vect) {
    cout << "~~Sorting vector~~" << endl << endl;
    int i = 1; 
    while (i < vect.size()) {
        int j = i;
        while ((j > 0) && (vect[j-1] > vect[j])) {
            swapNumbers(vect[j], vect[j-1]);
            j--;
        }
        i++;
    }
}

// Task 3b)
double medianOfVector(vector<int> vect) {
    // Using int vector (no ref) to make sure the values won't change.
    double median = 0;
    if ((vect.size() % 2) != 0) {
        median = vect[vect.size()/2];
    }
    else {
        median = (vect[(vect.size() - 1) / 2] + vect[(vect.size() + 1) / 2] )/2.0;
    }
    return median;
}


// Task 4a)
struct Student stud;

// Task 4b)
void printStudent(Student* stud) {
    cout << endl;
    cout << "Name: " << stud->name << endl;
    cout << "Age:  " << stud->age << endl;
    cout << "FoS:  " << stud->studyProgram << endl;
}

// Task 5b)
string randomizeString(int n, char lower, char upper) {
    string result;
    vector<int>values (0,0);
    
    // task 5d) (get numbers from randovector function -> static-cast to char)
    randomizeVector(values, n, static_cast<int>(upper), static_cast<int>(lower));

    for (int i = 0; i < values.size(); i++) {
        result += static_cast<char>(values[i]);
    }

    return result;
}

// Task 5f)
string readInputToString(char upper, char lower, int n) {
    string result = "";
    char temp[10];
    cout << endl;
    for (int i = 0; i < n; i++) {
        fseek(stdin,0,SEEK_END);
        cout << "Enter charchter #" << i+1 << ": ";
        cin >> temp;
        if ((temp[0] != '0') && ((tolower(temp[0]) < tolower(lower)) || (tolower(temp[0]) > tolower(upper)))) {
            cout << "\nWrong input. Must be within: " << lower << "-" << upper << endl << endl;
            i--;
        }
        else {
            result += temp[0];
        }
    }
    return result;
}

// Task 5g)
int countChar(string str, char ch) {
    int c = 0;
    for (int i = 0; i < str.size(); i++) {
        if (tolower(ch) == tolower(static_cast<char>(str[i]))) {
            c++;
        }
    }
    return c;
}
#include "task2.h"
#include "def.h"
#include <iostream>
#include <fstream>

using namespace std;

void countChar(void) {
    vector<int>stats('z'-'a',0);
    fstream fileHandler;
    char temp;
    bool choice;
    try {
        cout << "\nUse file from task 1 or grunnlovs-data?" << endl;
        cout << "[1] = Grunnlov, [0] = task1: ";
        cin >> choice;
        if (choice) {fileHandler.open(PATH_G, ios_base::in);}
        else {fileHandler.open(PATH_1, ios_base::in);}
        while (!fileHandler.eof()) {
            fileHandler >> temp;
            //temp = tolower(temp);
            if ((temp >= 'a') && (temp <= 'z')) {
                stats[temp-'a']++;
#if DEB_TXT // Print every char if debug = on
                cout << temp << " and " << stats[temp-'a'] << endl;
#endif /* DEB_TXT */
                if (fileHandler.eof()) {break;}
            }
        }
        stats[temp-'a']--; // reads final value twise somehow
        printVect(stats);
    }
    catch (ios_base::failure error) {
        cout << "\nUnable to write to file:\n" << error.what() << endl;
    }

    // If still open: close
    if (fileHandler.is_open()) {fileHandler.close();}
}
void printVect(vector<int>& vect){
    cout << endl;
    cout << "a: " << vect[0] << "\tb: " << vect[1] << "\tc: " << vect[2] << endl;
    cout << "d: " << vect[3] << "\te: " << vect[4] << "\tf: " << vect[5] << endl;
    cout << "g: " << vect[6] << "\th: " << vect[7] << "\ti: " << vect[8] << endl;
    cout << "j: " << vect[9] << "\tk: " << vect[10] << "\tl: " << vect[11] << endl;
    cout << "m: " << vect[12] << "\tn: " << vect[13] << "\to: " << vect[14] << endl;
    cout << "p: " << vect[15] << "\tq: " << vect[16] << "\tr: " << vect[17] << endl;
    cout << "s: " << vect[18] << "\tt: " << vect[19] << "\tu: " << vect[20] << endl;
    cout << "v: " << vect[21] << "\tw: " << vect[22] << "\tx: " << vect[23] << endl;
    cout << "y: " << vect[24] << "\tz: " << vect[25] << endl << endl;
}
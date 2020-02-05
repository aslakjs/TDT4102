#include "deb.h"
#include "task1.h"
#include "fstream"
#include <iostream>
#include <vector>



using namespace std;

// Task 1a)
void cinToFile(void) {
    bool newFile;
    string input;
    fstream toFile;
    try {
        // Trying to open file (new/old file)
        cout << "Open new file, or continue with old? [1] - new, [0] - old: ";
        cin >> newFile;
        if (newFile) {
            remove("txtFiles/task1.txt");
            cout << "File successfully removed." << endl;
        }
        toFile.close();
        toFile.open("txtFiles/task1.txt", fstream::out | fstream::app);
    }
    catch (ios_base::failure err) {
        // If unable to open file for whatever reason:
        cout << "\nUnable to open file:\n" << err.what() << endl;
    }
    // Run loop only if file was opened
    while (toFile.is_open()) {
        cout << "Enter a word ('quit' = exit): ";
        cin >> input;
        if (input == "quit") {break;}
        try {
            // Trying to write to file:
            toFile << input << endl;
        }
        catch(ios_base::failure writeErr) {
            // Unable to write for whatever reason
            cout << "\nUnable to write to file:\n" << writeErr.what() << endl;
        }
    }
    if (toFile.is_open()) {
        // Closing file to make it accessible for other programs
        toFile.close();
    }
}

// Task 1b)
void fileToFile(void) {
    fstream fileHandeler;
    string temp;
    vector<string>fileData;
    // Read from file:
    try {
        fileHandeler.open("txtFiles/task1.txt", ios_base::in);
    }
    catch(ios_base::failure error) {
        cout << "\nUnable to write to file:\n" << error.what() << endl;
    }
    while (!fileHandeler.eof()) {
        getline(fileHandeler,temp,'/');
        fileData.push_back(temp);
    }
    fileHandeler.close();
#if DEB_TXT // Check data before cout to new file
    for (int i = 0; i < fileData.size(); i++) {
        cout << endl << fileData[i];
    }
#endif

    // Write to new file:
    try {
        fileHandeler.open("txtFiles/task1_new.txt", ios_base::out | ios_base::trunc);
    }
    catch(ios_base::failure error) {
        cout << "\nUnable to write to file:\n" << error.what() << endl;
    }
    for (int i = 0; i < fileData.size(); i++) {
        fileHandeler << fileData[i] << endl;
    }
}
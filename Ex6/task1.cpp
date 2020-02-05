#include "task1.h"
#include <iostream>
#include "fstream"

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
            remove("task1.txt");
            cout << "File successfully removed." << endl;
        }
        toFile.open("task1.txt", fstream::in | fstream::app);
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
    
}
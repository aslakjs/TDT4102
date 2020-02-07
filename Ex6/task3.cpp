#include "task3.h"
#include "def.h"
#include <iostream>

using namespace std;

CourseCatalog::CourseCatalog(){
    mapIn();
}
CourseCatalog::~CourseCatalog(){
    cources.empty();
}

// Add new listing to the catalog:
// If inputs are empty:
//      -> Prompt for information
void CourseCatalog::addCource(string cCode, string cName, int test) {
    if (cources.find(cCode) != cources.end()) {
        cout << cCode << " already in catalog..." << endl;
        // Just for the purpose of testing different methods in ..
        //    ..task 3d)
        if (test == 0) {
            cout << "Testing operand-mode []:" << endl;    
            cources[cCode] = cName;
        }
        else {
            cout << "Testing .insert()-mode:" << endl;
            cources.insert(pair<string,string> (cCode,cName));
        }
    }
    else {
        if ((cCode == "") && (cName == "")) {
            cout << "Enter cource code: ";
            cin.ignore();
            getline(cin, cCode);
            cout << "Enter cource name: ";
            getline(cin, cName);
        }
        else if (cCode == "") {
            cout << "Enter cource code: ";
            cin.ignore();
            getline(cin, cCode);
        }
        else if (cName == "") {
            cout << "Enter cource name: ";
            cin.ignore();
            getline(cin, cName);
        }
        if (cources.find(cCode) != cources.end()) {
            cources[cCode] = cName;
        }
        else {
            cources.insert(pair<string,string> (cCode,cName));
        }
    }  
}

// Remove listing from catalog
// If input is empty:
//      -> Prompt for information
void CourseCatalog::removeCource(string cCode) {
#if DEB_TXT
    cout << cCode << ": will be deleted~~~~~" << endl;
#endif /* DEB_TXT */
    if (cCode == "") {
        cout << "Enter cource code to be deleted: ";
        cin >> cCode;
    }
    cout << endl << cCode << " " << cources[cCode] << " will be deleted." << endl << endl;
    cources.erase(cCode);
}

// Print listing from catalog
// If input is empty:
//      -> Prompt for information
void CourseCatalog::getCource(string cCode) {
    string key;
    if (cCode == "") {
        cout << "Enter your cource code: ";
        cin >> cCode;
        cout << cCode << " " << cources[cCode] << endl;
    }
    else if (cCode == "-1") { // Print all
        cout << "\nAll cources: ~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        for (auto const& print: cources) {
            cout << print.first << " " << print.second << endl;
        }
    }
    else {
        cout << cCode << " " << cources[cCode] << endl;
    }
}

// Write map to file:
void CourseCatalog::mapOut(void) {
    fileHandler.open(PATH_3, ios_base::out | ios_base::trunc);
    for (auto const& write: cources) {
        fileHandler << write.first << ":" << write.second << endl;
    }
    fileHandler.close();
}

// Read map from file:
void CourseCatalog::mapIn(void) {
    string temp, test, key, value;
    fileHandler.open(PATH_3, ios_base::out | ios_base::app);
    fileHandler.close();
    fileHandler.open(PATH_3, ios_base::in);
    while (getline(fileHandler,temp,'\n')) {
        key = "";
        value = "";
        if (temp != "") {   // Exclude final empty line
#if DEB_TXT
            cout << temp << endl;
#endif /* DEB_TXT */
            for (int i = 0; i < temp.find(":"); i++) {
                key += temp[i];
            }
            for (int i = temp.find(":") + 1; i < temp.size(); i++) {
                value += temp[i];
            }
            addCource(key,value);
#if DEB_TXT
            cout << "Key: " << key << " and Value: " << value << endl;
            waitForEnter();
#endif /* DEB_TXT */
        }
    }
    fileHandler.close();
}




//----TEST-functions--------------------------------------------
void testCatalog(CourseCatalog* CC) {
    CC->getCource("-1");

    waitForEnter();

    CC->addCource("TDT4110", "Informasjonsteknologi grunnkurs");
    CC->addCource("TDT4102", "Prosedyre- og objektorientert programmering");
    CC->addCource("TMA4100", "Matematikk 1");
    CC->getCource("-1");    // Pass -1 to get all elements
    
    waitForEnter();

    CC->addCource("TDT4102", "C++");
    CC->getCource("-1");

    waitForEnter();

    CC->addCource("TDT4102", "C--?", 1);
    CC->getCource("-1");

    waitForEnter();

    CC->removeCource("TDT4102");
    CC->getCource("-1");
}

inline void waitForEnter(void) {
    cout << endl;
    fseek(stdin,0,SEEK_END); // Clear input buffer
    do {cout << "Press Enter To Continue..";
    } while (cin.get()!='\n');
    for (int i = 0; i < 100; i++) {cout << endl;}
}
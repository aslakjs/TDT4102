/*
~~ Mastermind Game ~~
Macros are defined in playMaster.h
    - DEB    true yields extra printout for developer purpose
    - THEORY true yields printout of theory questions
*/

#include "playMaster.h"
#include "utilities.h"
#include <iostream>
#include <string.h> // find()

using namespace std;

void play(void) {
    constexpr int size = 4;
    constexpr int letters = 6;
    constexpr int lim = 10;
    string code;
    string guess;
    int corrPos = 0;
    int corrChr = 0;
    int round = 1;

#if THEORY
    cout << endl << "Task 6a)" << endl;
    cout << "Using constexpr to make sure the data will not be corrupted" << endl;
    cout << "the constants will be placed in read-only-memory" << endl;
    cout << "Could use macros tho..." << endl;
    cout << "Const could be usefull if the constants should be user specified:" << endl;
    cout << "\tie. modified at runtime of the program." << endl;
#endif /* !THEORY */

    code = randomizeString(size, 'A', static_cast<char>('A' + (letters-1)));
    
    while ((corrPos < size) && (round <= lim)) {
#if DEB
        cout << "\nCode  = " << code << endl;
#endif /* !DEB */

        cout << "Round " << round << "/10" << endl;
        guess.clear();
        guess = readInputToString(static_cast<char>('A' + (letters-1)), 'A', size);
        cout << "\nGuess = " << guess << endl;

        corrPos = checkCharNPos(code, guess);
        corrChr = checkChar(code, guess);

        cout << endl << "Number of correct char and pos: " << corrPos << endl;
        cout << "Number of correct char only: " << corrChr << endl << endl;
        round++;
    }
    if (corrPos == size) {
        cout << "Yay, you won! =)" << endl;
    }
    else {
        cout << "You lost! =(" << endl;
    }
}

int checkCharNPos(string code, string guess) {
    int num = 0;
    for (int i = 0; i < code.size(); i++) {
        if (code[i] == toupper(guess[i])) {num++;}
    }
    return num;
}

int checkChar(string c, string g) {
    int num = 0;
    cout << "size: " << c.size() << endl;
    for (int i = 0; i < c.size(); i++) {
        if ( c.find(g[i] > 0) ) {
            num++; 
            c[c.find(g[i])] = '-';
            }
#if DEB
        cout << "Check: " << c << endl;
#endif /* !DEB */
    }
    return num;
}
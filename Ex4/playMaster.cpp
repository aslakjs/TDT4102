/*
~~ Mastermind Game ~~
Macros are defined in playMaster.h
    - DEB    true yields extra printout for developer purpose
    - THEORY true yields printout of theory questions
*/

#include "playMaster.h"
#include "utilities.h"
#include "masterVisual.h"
#include "Graph.h"
#include "Simple_window.h"
#include <iostream>
#include <string.h> // find()

using namespace std;
using namespace Graph_lib;

int play(void) {
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
    
#if TASK7
    MastermindWindow mwin{Point{900, 20}, winW, winH, "Mastermind"};
    addGuess(mwin, code, size, 'A', -1, code);
#endif /* !TASK7 */
#if TASK7 && !DEB
    hideSecret(mwin, size);
#endif /* !TASK7 && !DEB */

    while ((corrPos < size) && (round <= lim)) {
#if DEB
        cout << "\nCode  = " << code << endl;
#endif /* !DEB */
#if !TASK7
        cout << "Round " << round << "/10" << endl;
        guess.clear();
        guess = readInputToString(static_cast<char>('A' + (letters-1)), 'A', size);
        if (guess == "0000") {break;}
        cout << "\nGuess = " << guess << endl;
#else
        guess = mwin.getInput(4, 'A', 'F');
#endif /* !TASK7 */
        corrPos = checkCharNPos(code, guess);
        corrChr = checkChar(code, guess);
#if DEB
        cout << endl << "Your guess was: " << guess;
        cout << endl << "Num of cor.pos: " << corrPos;
        cout << endl << "Num of cor.chr: " << corrChr << endl << endl;
#endif /* !DEB */
#if TASK7
        addGuess(mwin, code, size, 'A', round, guess);
        addFeedback(mwin, corrPos, corrChr, size, round);
#endif /* !TASK7 */
#if !TASK7
        cout << endl << "Number of correct char and pos: " << corrPos << endl;
        cout << "Number of correct char only:    " << corrChr << endl << endl;
#endif /* !TASK7 */
        round++;
    }
#if TASK7
    addGuess(mwin, code, size, 'A', -1, code);
    mwin.redraw();
#endif /* !TASK7 */

    if (corrPos == size) {
        cout << "Yay, you won! =)" << endl;
    }
    else {
        cout << "You lost! =(" << endl;
    }

#if TASK7
    return gui_main();
#else
    return 0;
#endif /* !TASK7 */
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
    for (int i = 0; i < c.size(); i++) {
        if ( c.find(toupper(g[i])) != string::npos ) {
            num++; 
            c[c.find(toupper(g[i]))] = '-';
            }
#if DEB
        cout << "Check: " << c << endl;
#endif /* !DEB */
    }
    return num;
}

void playgraphics(void) {
    cout << "\n\n~~ Change task7-macro in playMaster.h, and run task 6 ~~" << endl << endl;
}
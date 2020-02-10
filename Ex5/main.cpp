/*----------------------------------------------------
TITLE:  Assignment X
COURSE: TDT4102 - Programming
AUTHOR: Aslak J. Strand (c)

Notes:
    - N/A
---------------------------------------------------*/

#include <iostream>
#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "Blackjack.h"
#include "playGame.h"

#if TEST 		// IF test-mode TRUE, change in deb.h
#include "test.h"
#endif /* TEST */

using namespace std;

// Internal declarations:
void _mm(void);
void _info(void);
inline void waitForEnter(void);
void _task1(void);
void _task2(void);
void _task3(void);
void newRankSuit(Card *c);
void initRando(void);


// Code start below:
int main() {
#if TEST	// Test functions:
	testSuitAndRankPrint(Rank::ace, Suit::spades);
    testSwapCards();
#else		// Main code below:
    initRando();
    char mm;
	while (true) {
		_mm();
		cin >> mm;
		switch (mm) {
			case '0': cout << "\n\nBye!"; waitForEnter(); return 0;
			case 'i': _info(); waitForEnter(); break;
			case '1': _task1(); waitForEnter(); break;
			case '2': _task2(); break;
			case '3': _task3(); break;
            case '4': playBlackJack(); break;
			default: cout << "\n\nWrong input, try again.. \n\n"; break;
		}
	}
#endif /* TEST */
	return 0;
}

void _task1(void) { // Task 1e only, a-d can be seen in source-code.
	cout << endl << endl;
	cout << "Task 1e)" << endl;
	cout << "#1: Easy to spot in code, yields less coding error." << endl;
	cout << "#2: Saving variable-names for other useage." << endl << endl;
}

void _task2(void) {	// Task 2...
	char m2;
	Card *c = new Card(Suit::spades, Rank::ace); // Using pointer to Card
	while (true) {
        for (int i = 0; i<50; i++) {cout << endl;}
        cout << "------------------------------" << endl;
        cout << "~~~~~~~~~~~ Task 2 ~~~~~~~~~~~" << endl;
        cout << "------------------------------" << endl;
        cout << "[0] - MainMenu | [x] - NewVal " << endl;
        cout << "[a] - Task 1a  | [b] - Task 1b" << endl;
        cout << "[c] - Task 1c  | [d] - Task 1d" << endl;
		cout << "[e] - Task 1e  | [f] - Task 1f" << endl;
        cout << "------------------------------" << endl;
        cout << "Your choice: ";
        cin >> m2;

        switch (m2) {
            case '0': return;
            case 'a': cout << endl << "See Card.h" << endl << endl; break;
            case 'b': cout << endl << "See Card.cpp" << endl << endl; break;
            case 'c': 
				cout << endl << "Suit = " << c->getSuit() << endl;
				break;
            case 'd': 
				cout << endl << "Rank = " << c->getRank() << endl;
				break;
			case 'e': 
				cout << endl << "Your card is:" << endl;
				cout << c->toString() << endl << endl; 
				break;
			case 'f': 
				cout << endl << "Your card is:" << endl;
				cout << c->toStringShort() << endl << endl; 
				break;
			case 'x': newRankSuit(c); break; 
            default: cout << endl << "Wrong input, try again." << endl; break;
        }
        waitForEnter();
	}
}

void _task3(void) {
	char m3;
	CardDeck *cd = new CardDeck();
	while (true) {
        for (int i = 0; i<50; i++) {cout << endl;}
        cout << "------------------------------" << endl;
        cout << "~~~~~~~~~~~ Task 3 ~~~~~~~~~~~" << endl;
        cout << "------------------------------" << endl;
        cout << "[0] - MainMenu |  " << endl;
        cout << "[a] - Task 1a  | [b] - Task 1b" << endl;
        cout << "[c] - Task 1c  | [d] - Task 1d" << endl;
		cout << "[e] - Task 1e  | [f] - Task 1f" << endl;
		cout << "[g] - Task 1e  | [r] - RESET  " << endl;
        cout << "------------------------------" << endl;
        cout << "Your choice: ";
        cin >> m3;

        switch (m3) {
            case '0': return;
            case 'a': cout << "\n\nSee CardDeck.h" << endl; break;
            case 'b': cd->printDeck(); break;
            case 'c': 
#if THEORY
                cout << "\n\nThis function should be public,\nas swapping around cards is wastly used in any card-game." << endl << endl;
#endif /* THEORY */
                cout << "\nSee CardDeck.h og CardDeck.cpp" << endl;
                break;
            case 'd':
                cd->printDeck();
                cout << "\n\nSee CardDeck.h and CardDeck.cpp." << endl;
                break;
			case 'e':
                cd->printShort();
                cout << endl;
                break;
			case 'f': 
                cd->shuffle();
                cd->printDeck();
                break;
			case 'g': 
                cd->drawCard();
                cd->printDeck();
                break;
            case 'r':
                cd->reset();
                cd->printDeck();
                break;
            default: cout << endl << "Wrong input, try again." << endl; break;
        }
        waitForEnter();
	}
}


void newRankSuit(Card *c) {
	// Just to check if functions work as planned
    char su;
    int ra;
    for (int i = 0; i<50; i++) {cout << endl;}
    cout << "-----------------------------" << endl;
    cout << "~~~~~~~~ Select suit ~~~~~~~~" << endl;
    cout << "-----------------------------" << endl;
    cout << "[s] - Spades | [h] - Hearts  " << endl;
    cout << "[c] - Clubs  | [d] - Diamonds" << endl;
    cout << "-----------------------------" << endl;
    cout << "Your selection: ";
    cin >> su;
    cout << endl;
    cout << "-----------------------------" << endl;
    cout << "~~~~~~~~ Select rank ~~~~~~~~" << endl;
    cout << "-----------------------------" << endl;
    cout << "     [2-14] - Card rank      " << endl;
    cout << "  Ace = 14, King = 13 ...    " << endl;
    cout << "-----------------------------" << endl;
    cout << "Your selection: ";
    cin >> ra;

/*
	{1,Suit::clubs},
    {2,Suit::diamonds},
    {3,Suit::hearts},
    {4,Suit::spades}
*/

    switch(su) {
		case 'c': c->setSuit(1); break;
        case 'd': c->setSuit(2); break;
		case 'h': c->setSuit(3); break;
        case 's': c->setSuit(4); break;
        default: cout << "\nWrong input, standard definition will be applied." << endl; break;
    }
    if ((ra >= 2) && (ra <= 14)) {
        c->setRank(ra);
    }
    else {
        cout << "\nWrong input, standard definition will be applied." << endl;
    }
	cout << endl << "Your card is: " << c->toString() << endl << endl; 
}

void _mm(void) {
	for (int i = 0; i<50; i++) {cout << endl;}
	cout << "---------------------------" << endl;
    cout << "~~~~~~~~ Main Menu ~~~~~~~~" << endl;
    cout << "---------------------------" << endl;
    cout << "[0] - Exit   | [i] - Info  " << endl;
    cout << "[1] - Task 1 | [2] - Task 2" << endl;
	cout << "[3] - Task 3 | [4] - Task 4" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
}
void _info(void) {
    for (int i = 0; i<50; i++) {cout << endl;}
    cout << "---------------------------" << endl;
    cout << "TITLE:  Assignment 5       " << endl;
    cout << "COURSE: TDT4102-Programming" << endl;
    cout << "AUTHOR: Aslak J. Strand    " << endl;
    cout << "  (c)   Aslak J. Strand    " << endl;
    cout << "---------------------------" << endl << endl;
}
// Wait for enter-key
inline void waitForEnter(void) {
    cout << endl;
    fseek(stdin,0,SEEK_END); // Clear input buffer
    do {cout << "Press Enter To Continue..";
    } while (cin.get()!='\n');
    for (int i = 0; i < 100; i++) {cout << endl;}
}
void initRando(void) {
    // Initiate rand() with basic seed
    srand(static_cast<unsigned int>(time(nullptr))); 
}
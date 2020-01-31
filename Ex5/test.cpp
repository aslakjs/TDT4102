#include "test.h"
#include <iostream>

using namespace std;

// task 1c og d
void testSuitAndRankPrint(Rank rank, Suit suit) {
    cout << endl << rankToString(rank) << " of " << suitToString(suit) << endl << endl;
}

// task 3c)
void testSwapCards(void) {
    int a,b;
    CardDeck *cd = new CardDeck();

    cout << "\n\nEnter first card: ";
    cin >> a;
    cout << "Enter first card: ";
    cin >> b;
    cd->swap(a,b);
    cd->printDeck();
}
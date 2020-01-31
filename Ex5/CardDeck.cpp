#include <iostream>
#include "CardDeck.h"
using namespace std;

// Constructor
CardDeck::CardDeck() {
    Card c(Suit::spades, Rank::ace);
    for (int s = 1; s <= 4; s++) {
        for (int r = 2; r<=14; r++) {
            c.setSuit(s);
            c.setRank(r);
            deck.push_back(c);
        }
    }
}

void CardDeck::printDeck(void) {
    for (int i = 0; i < deck.size(); i++) {
        cout << "Card #" << i+1 << ": \t" << deck[i].toString() << endl;
    }
}
void CardDeck::swap(int a, int b) {
    Card temp = deck[a];
    deck[a] = deck[b];
    deck[b] = temp;
}
void CardDeck::printShort(void) {
    for (int i = 1; i <= deck.size(); i++) {
        cout << "Card #" << i << ": \t" << deck[i-1].toStringShort() << endl;
    }
}
void CardDeck::shuffle(void) {
    int max = deck.size();
    for (int i = 0; i < max; i++) {
        swap(i, (rand() % max));

#if DEB
        cout << "swap " << i+1 << " of " << deck.size() << " complete." << endl;
#endif /* !DEB */

    }
}
const Card CardDeck::drawCard(void) {
    const Card draw = deck[deck.size()-1];
    deck.pop_back();

#if DEB
    printDeck();
    cout << "\nYour card is: " << static_cast<Card>(draw).toString() << endl;
#endif /* !DEB */

    return draw;
}
void CardDeck::reset(void) {
    int max = deck.size();
    Card c(Suit::spades, Rank::ace);
#if DEB
    cout << "\nNumber of cards in deck: " << max << endl;
#endif /* !DEB */
    for (int i = 0; i < max; i++) {
        deck.pop_back();
#if DEB
        cout << "Popping card " << i+1 << " of " << max << endl;
#endif /* !DEB */
    }
    for (int s = 1; s <= 4; s++) {
        for (int r = 2; r<=14; r++) {
            c.setSuit(s);
            c.setRank(r);
            deck.push_back(c);
        }
    }
}
#ifndef CARDDECK_H
#define CARDDECK_H

#include "Card.h"
#include "std_lib_facilities.h"

class CardDeck {
private:
    vector<Card> deck;
public:
    CardDeck();
    void printDeck(void);
    void swap(int a, int b);
    void printShort(void);
    void shuffle(void);
    const Card drawCard(void);
};

#endif /* !CARDDECK_H */

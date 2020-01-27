#include <iostream>
#include "std_lib_facilities.h"
#include "Card.h"
using namespace std;

// Constructor for Card-class:
Card::Card(Suit suit, Rank rank):s{suit},r{rank} {}

// Functions: ------------------------------
// For Card-class:
string Card::getSuit(void) {
    return suitToString(s);
}
string Card::getRank(void) {
    return rankToString(r);
}
string Card::toString(void) {

}

// Stand-alone:
string suitToString(Suit card) {
    return SuitString.at(card);
}
string rankToString(Rank card) {
    return RankString.at(card);
}
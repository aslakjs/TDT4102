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
    return (getRank() + " of " + getSuit());
}
string Card::toStringShort(void) {
    string tempS = getSuit();
    return (tempS[0] + ShortRank.at(r));
}
void Card::setSuit(int su) {
    s = StringSuit.at(su);
}
void Card::setRank(int ra){
    r = IntRank.at(ra);
}

// Stand-alone:
string suitToString(Suit card) {
    return SuitString.at(card);
}
string rankToString(Rank card) {
    return RankString.at(card);
}
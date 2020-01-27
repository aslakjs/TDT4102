#ifndef CARD_H
#define CARD_H

#include <string>
#include <map>
#include "deb.h"

// Enum && map declarations:
enum class Suit {
    clubs,
    diamonds, 
    hearts, 
    spades
};

const std::map<const Suit, std::string> SuitString {
    {Suit::clubs, "Clubs"},
    {Suit::diamonds, "Diamonds"},
    {Suit::hearts, "Hearts"},
    {Suit::spades, "Spades"}
};

enum class Rank {
    two,
    three, 
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace
}; 

const std::map<const Rank, std::string> RankString {
    {Rank::ace, "Ace"},
    {Rank::two, "Two"},
    {Rank::three, "Three"},
    {Rank::four, "Four"},
    {Rank::five, "Five"},
    {Rank::six, "Six"},
    {Rank::seven, "Seven"},
    {Rank::eight, "Eight"},
    {Rank::nine, "Nine"},
    {Rank::ten, "Ten"},
    {Rank::jack, "Jack"},
    {Rank::queen, "Queen"},
    {Rank::king, "King"}
};

// Class decleration:
class Card {
private:
    Suit s;
    Rank r;
public:
    Card(Suit suit, Rank rank);
    std::string getSuit(void);
    std::string getRank(void);
    std::string toString(void);
};

// Function declarations:
std::string suitToString(Suit card);
std::string rankToString(Rank card);


#endif /* !CARD_H */
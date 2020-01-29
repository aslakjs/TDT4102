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

// Suit maps ----------------------------------------
const std::map<const Suit, std::string> SuitString {
    {Suit::clubs, "Clubs"},
    {Suit::diamonds, "Diamonds"},
    {Suit::hearts, "Hearts"},
    {Suit::spades, "Spades"}
};
const std::map<const int, Suit> StringSuit {
    {1,Suit::clubs},
    {2,Suit::diamonds},
    {3,Suit::hearts},
    {4,Suit::spades}
};

// Rank maps ----------------------------------------
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
const std::map<const int, Rank> IntRank {
    {2,Rank::two},
    {3,Rank::three},
    {4,Rank::four, },
    {5,Rank::five},
    {6,Rank::six},
    {7,Rank::seven},
    {8,Rank::eight},
    {9,Rank::nine},
    {10,Rank::ten},
    {11,Rank::jack, },
    {12,Rank::queen},
    {13,Rank::king},
    {14,Rank::ace}
};
const std::map<const Rank, std::string> ShortRank {
    {Rank::two, "2"},
    {Rank::three, "3"},
    {Rank::four, "4"},
    {Rank::five, "5"},
    {Rank::six, "6"},
    {Rank::seven, "7"},
    {Rank::eight, "8"},
    {Rank::nine, "9"},
    {Rank::ten, "10"},
    {Rank::jack, "11"},
    {Rank::queen, "12"},
    {Rank::king, "13"},
    {Rank::ace, "14"}
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
    std::string toStringShort(void);
    void setSuit(int su);
    void setRank(int ra);
};


// Function declarations:
std::string suitToString(Suit card);
std::string rankToString(Rank card);

#endif /* !CARD_H */
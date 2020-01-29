#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "CardDeck.h"

// Function declarations:
void playBlackJack(void);
inline void waitForEnter(void);

// Class declarations:
class BlackJack {
private:
    CardDeck *cd = new CardDeck();
    const int goal = 21;    // Goal
    const int dMAX = 17;
    double pot;             // game-pot
    vector<double>wallet;   // cash on hand by house, player 1 ... player n
    vector<int>sum;         // Accumulated sum of cards
    int getValue(Card c);   // Get integer-value from card
    void addToSum(int val, int p);     // Add to card sum
    void addToPot(int cash);    // Add money to pot

public:
    BlackJack(int np);          // Constructor
    vector<int>player;          // player-number, 0=dealer, 1=player 1, .., n=player n
    vector<bool>inGame;         // true = in game, false = loss
    void wantToContinue(int p); // See if player wish to continue.

    void startWallet();         // Initiate startup value
    void newCard(int p);        // Draw new card
    void placeBet(int p);       // Place new bet
    void dealerBet(void);       // Randomized dealer bet
    
    double getPot(void);        // return current pot
    void getSum(int p);         // Print current sum

    void checkIfOver(int p);    // Check if player sum > 21
    bool checkIfGoal(int p);    // Check if sum = 21 -> victory
    void dealerContinue(void);  // Check if dealer should continue
    void addToWallet(double cash, int p);  // Add winnings to wallet
    double getWallet(int p);    // Get money in wallet
};



#endif /* BLACKJACK_H */
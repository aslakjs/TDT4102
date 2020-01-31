#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "CardDeck.h"

// Class declarations:
class BlackJack {
private:
    // Private Variables:
    CardDeck *cd = new CardDeck();
    const int goal = 21;    // Goal=21
    const int dMAX = 17;    // Dealer max
    double pot;             // game-pot
    double buyIn;           // Buy-in, set by House
    vector<int>timesReBuy;  // Number of times dealer has bought in after start
    vector<double>wallet;   // cash on hand by house, player 1 ... player n
    vector<int>sum;         // Accumulated sum of cards

    // Private Functions
    int getValue(Card c, int p);    // Get integer-value from card
    void addToSum(int val, int p);  // Add to card sum
    void addToPot(int cash);        // Add money to pot

public:
    // Public Variables:
    vector<int>player;          // player-number, 0=dealer, 1=player 1, .., n=player n
    vector<bool>inGame;         // true = in game, false = folded
    vector<bool>remaining;      // 1 = true, 0 = false

    // Public Functions:
    // Initiation:
    BlackJack(int np);          // Constructor
    void startWallet();         // Initiate startup value

    // Game mechanics
    double getWallet(int p);    // Get money in wallet
    double getPot(void);        // return current pot
    void getSum(int p);         // Print current sum
    void newCard(int p);        // Draw new card
    void prepareNewRound(void); // clear sum for next round

    // Points-check:
    void checkIfOver(int p);    // Check if player sum > 21
    bool checkIfGoal(int p);    // Check if sum = 21 -> victory

    // Player choice:
    void wantToContinue(int p); // See if player wish to continue.
    void placeBet(int p);       // Place new bet

    // Dealer choice:
    void dealerContinue(void);  // Check if dealer should continue
    void dealerBet(void);       // Randomized dealer bet
    
    // Victory:
    int findWinner(void);       // Find a winner
    bool remainingPlayers(void);// Find whom are still in game
    void addToWallet(int p);    // Add winnings to wallet
    void victoryScreen(void);   // Print final message after game is finished
};



#endif /* BLACKJACK_H */
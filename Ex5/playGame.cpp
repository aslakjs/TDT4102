#include "Blackjack.h"
#include "playGame.h"
#include "deb.h"
using namespace std;

//---------------------------------------------------------------------------------------
// TASK 4: BlackJack
//---------------------------------------------------------------------------------------
void playBlackJack(void) {
    for (int i = 0; i<50; i++) {cout << endl;}
	int np = 0;
    bool keepPlaying = true;

    cout << "--------------------------------" << endl;
    cout << " Welcome to a game of BlackJack " << endl;
    cout << "--------------------------------" << endl;
    cout << "How many players: ";
    cin >> np;
    BlackJack *game = new BlackJack(np);
    game->startWallet();

    while (keepPlaying) {
        int round = 1;
        int winner;
        bool wFlag = false;
        bool remaining = true;

        // Round 1: all get two cards:
        for (int i = 0; i<50; i++) {cout << endl;}
        cout << "\n\n--------------------------------" << endl;
        cout << "Round #" << round << endl;
        cout << "--------------------------------" << endl << endl;
        for (int p = 1; p < game->player.size(); p++) {
            cout << "Player " << p << ":-----------------------" << endl;
            game->placeBet(p);
            game->newCard(p); game->newCard(p); // Draw two new card
            game->getSum(p);    // Print current sum
            game->checkIfOver(p);
            wFlag = game->checkIfGoal(p);
            waitForEnter();
        }
        cout << "\nDealers turn:-------------------" << endl;
        game->dealerBet();
        game->newCard(0); game->newCard(0);
        game->getSum(0);
        game->checkIfOver(0);
        wFlag = game->checkIfGoal(0);
        waitForEnter();

        remaining = game->remainingPlayers();

#if BJDEB || DEB
        cout << "Remaining = " << remaining;
#endif /* BJDEB || DEB */

        // Round 2->n: all get one card:
        while ((!wFlag) || (remaining)) {
            if (!remaining) {break;}

            round ++;
            cout << "\n\n--------------------------------" << endl;
            cout << "Round #" << round << endl;
            cout << "--------------------------------" << endl << endl;

            for (int p = 1; p < game->player.size(); p++) {
                cout << "Player " << p << ":-----------------------" << endl;
                if (game->inGame.at(p) == true) {
                    game->wantToContinue(p);
                    if (game->inGame.at(p) == true) {
                        game->placeBet(p);
                        game->newCard(p);
                        game->getSum(p);
                        game->checkIfOver(p);
                        wFlag = game->checkIfGoal(p);
                    }
                }
                else {
                    cout << "Player " << p << " is out of the game" << endl;
                }
                waitForEnter();
            }
            cout << "\nDealers turn:-------------------" << endl;
            if (game->inGame.at(0) == true) {
                game->dealerContinue();
                if (game->inGame.at(0) == true) {
                    game->dealerBet();
                    game->newCard(0);
                    game->getSum(0);
                    game->checkIfOver(0);
                    wFlag = game->checkIfGoal(0);
                }
            }
            else {
                cout << "Dealer has withdrawn." << endl;
            }
            waitForEnter();
            remaining = game->remainingPlayers();

#if BJDEB || DEB
        cout << "Remaining = " << remaining;
#endif /* BJDEB || DEB */

            if (wFlag) {cout << "21 = BlackJack" << endl; break;}
            if (!remaining) {cout << "No players remaining in game" << endl; break;}
        }

        // No more players eligble for playing -> finding a victor:
        // If a player has exactly 21:
        if (wFlag) {
            for (int i = 0; i < game->player.size(); i++) {
                if (game->remaining.at(i) == true) {
                    cout << "Player " << i << " has won!" << endl;
                    game->addToWallet(i);
                    cout << "Your wallet: " << game->getWallet(i);
                }
            }
        }
        // Find player closest to but below 21
        else {
            winner = game->findWinner();
            cout << "Player " << winner << " has won!" << endl;
            game->addToWallet(winner);
            cout << "Your wallet: " << game->getWallet(winner);
        }
        waitForEnter();

        cout << "Do you wish to continue playing? [1] = yes, [0] = no: ";
        cin >> keepPlaying;
        if (keepPlaying) {
            game->prepareNewRound();
            waitForEnter();
        }
    }
    game->victoryScreen();
    waitForEnter();
}



//-----------------------------------------------------------------------
inline void waitForEnter(void) {
    cout << endl;
    fseek(stdin,0,SEEK_END); // Clear input buffer
    do {cout << "Press Enter To Continue..";
    } while (cin.get()!='\n');
#if !BJDEB
    for (int i = 0; i < 100; i++) {cout << endl;}
#else
    for (int i = 0; i < 2; i++) {cout << endl;}
#endif /* !BJDEB */ 
}
#include "Blackjack.h"
using namespace std;

BlackJack::BlackJack(int np) {
    int num;
    pot = 0;
    for (int i = 0; i <= np; i++) {
        num = i+1;
        player.push_back(i);
        inGame.push_back(true);
        wallet.push_back(0);
        sum.push_back(0);
    }
}
// Get value(/rank) of card
int BlackJack::getValue(Card c) {
    string temp = c.getRank();
    int rank = 0;
    if (temp == "Ace") {
        cout << "Ace can be both 1 or 11\nWhich do you want: ";
        cin >> rank;
    }
    else {
        rank = RankInt.at(temp);
    }
    return rank;
}
// Att value to player-sum
void BlackJack::addToSum(int val, int p) {
    sum[p] += val;
}
void BlackJack::startWallet() {
    cd->shuffle();
    cout << "Enter amount of start-up money:" << endl;
    cout << "Dealer:  \t";
    cin >> wallet[0];
    for (int i = 1; i < player.size(); i++) {
        cout << "Player " << i << ":\t";
        cin >> wallet[i];
    }
}
void BlackJack::newCard(int p) {
    Card card = static_cast<Card>(cd->drawCard());
    cout << "Your card is: " << card.toString() << endl;
    
    int val = getValue(card);
    addToSum(val, p);
}
void BlackJack::placeBet(int p) {
    double bet = 0;
    bool allIN = false;
    cout << "Your balance:   " << getWallet(p) << " NOK." << endl;
    cout << "Place your bet: ";
    cin >> bet;
    while (bet > getWallet(p)) {
        cout << "Not enough money in your wallet." << endl;
        cout << "Your balance:   " << getWallet(p) << " NOK." << endl;
        cout << "Do you want to go all in? [0] = no, [1] = yes : ";
        cin >> allIN;
        if (allIN) {bet = getWallet(p);}
        else {
            cout << "Place your bet: ";
            cin >> bet;
        }
    }
    addToPot(bet);
    wallet[p] -= bet;
    cout << "Total pot is now: " << pot << " NOK." << endl;
    cout << "In your wallet:   " << wallet[p] << " NOK." << endl;
}
void BlackJack::dealerBet(void) {
    double dW = wallet[0];
    double bet = rand() % static_cast<int>(round(dW));
    addToPot(bet);
    wallet[0] -= bet;
    cout << "Dealers bet:      " << bet << " NOK." << endl;
    cout << "Total pot is now: " << pot << " NOK." << endl;
    cout << "Dealers wallet:   " << wallet[0] << " NOK." << endl;
}
double BlackJack::getWallet(int p) {return wallet[p];}
void BlackJack::addToPot(int cash) {pot += cash;}
void BlackJack::addToWallet(double cash, int p) {wallet[p] += cash;}
void BlackJack::getSum(int p) {cout << "Current sum: " << sum[p] << endl;}
double BlackJack::getPot(void) {return pot;}
void BlackJack::checkIfOver(int p) {
    int val = sum[p];
    if (val > goal) {
        inGame.at(p) = false;
        cout << "You have lost." << endl;
        }
}
bool BlackJack::checkIfGoal(int p) {
    int val = sum[p];
    if (val == goal) {
        for (int i = 0; i < p; i++) {inGame.at(i) = false;}
        for (int i = p+1; i < player.size(); i++) {inGame.at(i) = false;}
        return true;
    }
    return false;
}
void BlackJack::wantToContinue(int p) {
    bool cont = true;
    getSum(p);
    cout << "Do you wish to carry on? [1] = yes, [0] = no: ";
    cin >> cont;
    if (!cont) {inGame.at(p) = false;}
}
void BlackJack::dealerContinue(void) {
    if (sum[0] >= dMAX) {
        cout << "Dealer withdraws." << endl;
        inGame.at(0) = false;
    }
}


//-----------------------------------------------------------------------
// TASK 4: BlackJack
//-----------------------------------------------------------------------
void playBlackJack(void) {
    for (int i = 0; i<50; i++) {cout << endl;}
	int np = 0;
    int round = 1;
    bool wFlag = false;
    cout << "# of players: ";
    cin >> np;
    BlackJack *game = new BlackJack(np);
    game->startWallet();

    // Round 1: all get two cards:
    cout << "\n\nRound #" << round << endl << endl;
    for (int p = 1; p < game->player.size(); p++) {
        cout << "Player " << p << ":" << endl;
        game->placeBet(p);
        game->newCard(p); game->newCard(p); // Draw two new card
        game->getSum(p);    // Print current sum
        game->checkIfOver(p);
        wFlag = game->checkIfGoal(p);
        waitForEnter();
    }
    cout << "Dealers turn:" << endl;
    game->dealerBet();
    game->newCard(0); game->newCard(0);
    game->getSum(0);
    game->checkIfOver(0);
    wFlag = game->checkIfGoal(0);
    waitForEnter();


    // Round 2->n: all get one card:
    while (!wFlag) {
        int allFailed = 0;
        round ++;
        for (int i = 0; i<50; i++) {cout << endl;}
        cout << "\n\nRound #" << round << endl << endl;

        for (int p = 1; p < game->player.size(); p++) {
            cout << "Player " << p << ":" << endl;
            game->wantToContinue(p);
            if (game->inGame.at(p) == true) {
                game->placeBet(p);
                game->newCard(p);
                game->getSum(p);
                game->checkIfOver(p);
                wFlag = game->checkIfGoal(p);
            }
            else {
                cout << "Player " << p << " is out of the game" << endl;
            }
            waitForEnter();
        }
        cout << "Dealers turn:" << endl;
        game->dealerContinue();
        if (game->inGame.at(0) == true) {
            game->dealerBet();
            game->newCard(0);
            game->getSum(0);
            game->checkIfOver(0);
            wFlag = game->checkIfGoal(0);
        }
        else {
            cout << "Dealer has withdrawn." << endl;
        }
        waitForEnter();
        for (int i = 0; i < game->player.size(); i++) {
            if (game->inGame.at(i) == false) {allFailed++;}
        }
        if (allFailed == game->player.size()) {wFlag = true;}
    }

    if (wFlag) {
        for (int i = 0; i < game->player.size(); i++) {
            if (game->inGame.at(i) == true) {
                cout << "Player " << i << " has won!" << endl;
                game->addToWallet(game->getPot(), i);
                cout << "Your wallet: " << game->getWallet(i);
            }
        }
    }

}


inline void waitForEnter(void) {
    cout << endl;
    fseek(stdin,0,SEEK_END); // Clear input buffer
    do {cout << "Press Enter To Continue..";
    } while (cin.get()!='\n');
    for (int i = 0; i < 100; i++) {cout << endl;}
}
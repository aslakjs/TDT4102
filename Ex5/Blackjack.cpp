#include "Blackjack.h"
using namespace std;


// Constructor
BlackJack::BlackJack(int np) {
    int num;
    pot = 0;
    for (int i = 0; i <= np; i++) {
        num = i+1;
        player.push_back(i);
        inGame.push_back(true);
        wallet.push_back(0);
        sum.push_back(0);
        remaining.push_back(true);
        timesReBuy.push_back(1);
    }
}
// ----- PRIVATE ------------------------------------------------------------------------
// Game mechanics functions -------------------------------------------------------------
// Get value(/rank) of card
int BlackJack::getValue(Card c, int p) {
    string temp = c.getRank();
    int rank = 0;
    int dealerAce = 0;
    if ((temp == "Ace") && (p != 0)) {
        cout << "\nAce can be both 1 or 11\nWhich do you want: ";
        cin >> rank;
        cout << endl;
    }
    else if ((temp == "Ace") && (p == 0)) {
        dealerAce = rand() & 1;
        if (((sum[0]+11) > goal) || dealerAce == 1) {
            rank = 11;
            cout << "\nAce can be both 1 or 11\nDealer chose: 11\n" << endl;
        }
        else if (dealerAce == 0) {
            rank = 1;
            cout << "\nAce can be both 1 or 11\nDealer chose: 1\n" << endl;
        }
    }
    else {
        rank = RankInt.at(temp);
    }
    return rank;
}

// Att value to player-sum
void BlackJack::addToSum(int val, int p) {sum[p] += val;}

// Add bet to pot
void BlackJack::addToPot(int cash) {pot += cash;}


// ----- PUBLIC -------------------------------------------------------------------------
// Initiation functions -----------------------------------------------------------------
// Initiate house and player wallet
void BlackJack::startWallet() {
    cd->shuffle();
    cout << "\nEnter amount of start-up money:" << endl;
    cout << "Buy-in [NOK]: ";
    cin >> buyIn;
    for (int i = 0; i < player.size(); i++) {
        wallet[i] = buyIn;
    }
}

// Game mechanics functions -------------------------------------------------------------
// Return amount of money left in wallet
double BlackJack::getWallet(int p) {return wallet[p];}

// Return amount of money in the pot
double BlackJack::getPot(void) {return pot;}

// Print current card-sum
void BlackJack::getSum(int p) {cout << "Current sum:  " << sum[p] << endl;}

// Draw new card
void BlackJack::newCard(int p) {
    Card card = static_cast<Card>(cd->drawCard());
    cout << "Your card is: " << card.toString() << endl;
    
    int val = getValue(card,p);
    addToSum(val, p);
}

// Clear sum, inGame and remaining for new round
void BlackJack::prepareNewRound(void) {
    cout << "Preparing new round." << endl;
    bool addFounds = false;
    for (int p = 0; p < player.size(); p++) {
        sum[p] = 0;
        inGame.at(p) = true;
        remaining.at(p) = true;
        if (wallet[p] == 0) {
            if (p == 0) {
                cout << "Dealer adds " << buyIn << " NOK to his wallet." << endl;
                wallet[0] += buyIn;
                timesReBuy[0] += 1;
            }
            else {
                cout << "Player " << p << " has to add extra founds." << endl;
                wallet[p] += buyIn;
                timesReBuy[p] += 1;
                cout << "Player " << p << " adds " << buyIn << " NOK to his wallet." << endl;
            }
        }
        else if (wallet[p] <= ((buyIn/100)*20)) {
            if (p == 0) {
                cout << "Dealer adds " << buyIn << " NOK to his wallet." << endl;
                wallet[0] += buyIn;
                timesReBuy[0] += 1;
            }
            else {
                cout << "Does player " << p << " want to add extra founds? [1] = yes, [0] = no: ";
                cin >> addFounds;
                if (addFounds) {
                    wallet[p] += buyIn;
                    timesReBuy[p] += 1;
                    cout << "Player " << p << " adds " << buyIn << " NOK to his wallet." << endl;
                }
            }
        }
    }
}

// Points-check functions ---------------------------------------------------------------
// Check if over limit = 21
void BlackJack::checkIfOver(int p) {
    if (sum[p] > goal) {
        inGame.at(p) = false;
        remaining.at(p) = false;
        if (p == 0){
            cout << "Dealer has lost." << endl;
        }
        else {
            cout << "You have lost." << endl;
        }
    }
}

// Check if exactly goal = 21
bool BlackJack::checkIfGoal(int p) {
    int val = sum[p];
    if (val == goal) {
#if BJDEB || DEB
        cout << "sum = 21" << endl;
#endif /* BJDEB || DEB */
        for (int i = 0; i < p; i++) {inGame.at(i) = false; remaining.at(i) = false;}
        for (int i = p+1; i < player.size(); i++) {inGame.at(i) = false; remaining.at(i) = false;}
        return true;
    }
    return false;
}

// Players choice functions -------------------------------------------------------------
// Check if player wants to continue
void BlackJack::wantToContinue(int p) {
    bool cont = true;
    getSum(p);
    cout << "Do you wish to carry on? [1] = yes, [0] = no: ";
    cin >> cont;
    if ((!cont) && (sum[p] <= goal)) {
        cout << "Player " << p << " withdraws." << endl;
        inGame.at(p) = false;
    }
    else if ((!cont) && (sum[p] > goal)) {
        cout << "Player " << p << " has lost." << endl;
        inGame.at(p) = false;
        remaining.at(p) = false;
    }
}

// Place a bet
void BlackJack::placeBet(int p) {
    double bet = 0;
    bool allIN = false;
    cout << "Your balance:     " << getWallet(p) << " NOK." << endl;
    cout << "Place your bet:   ";
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
    cout << "In your wallet:   " << wallet[p] << " NOK." << endl << endl;
}

// Dealer functions ---------------------------------------------------------------------
// Auto dealer continue 
void BlackJack::dealerContinue(void) {
    if ((sum[0] >= dMAX) && (sum[0] <= goal)) {
        cout << "Dealer withdraws." << endl;
        inGame.at(0) = false;
    }
    else if (sum[0] > goal) {
        cout << "Dealer has lost." << endl;
        inGame.at(0) = false;
        remaining.at(0) = false;
    }
}

// Dealer places a bet
void BlackJack::dealerBet(void) {
    double dW = wallet[0];
    cout << "Dealer balance:   " << getWallet(0) << " NOK." << endl;
    double bet = rand() % static_cast<int>(round(dW));
    addToPot(bet);
    wallet[0] -= bet;
    cout << "Dealers bet:      " << bet << " NOK." << endl;
    cout << "Total pot is now: " << pot << " NOK." << endl;
    cout << "Dealers wallet:   " << wallet[0] << " NOK." << endl << endl;
}

// Victory functions --------------------------------------------------------------------
// Find a winner
int BlackJack::findWinner(void) {
    int temp = goal;
    int check = 0;
    int winner = 0;
    for (int p = 0; p < player.size(); p++) {
        check = goal-sum[p];
        if ((check >= 0) && (remaining.at(p) == true) && (check < temp)) {
            temp = goal - sum[p];
            winner = p;     // Not taking into account two or more equal sums
        }
    }
    return winner;
}

// Find players whom are eligble for victory
bool BlackJack::remainingPlayers(void) {
    bool remain = true;
    int temp = 0;
    for (int p = 0; p < player.size(); p++) {
        if (inGame.at(p) == false) {
            temp++;
        }
    }
    if (temp == player.size()) {remain = false;}
    else if ((temp == player.size() - 1) && (remaining.at(0) == false)) {remain = false;}
    return remain;
}

// Add pot to victors wallet
void BlackJack::addToWallet(int p) {
    wallet[p] += pot;
    pot = 0;
}

// Print victory-screen:
void BlackJack::victoryScreen(void) {
    int vinner = 0;
    double temp = 0;
    for (int i = 0; i<50; i++) {cout << endl;}
    cout << "---------------------------------" << endl;
    cout << " Thank you for playing BlackJack " << endl;
    cout << "---------------------------------" << endl;
    
    // Correct wallet and temp (incl. re-buyins)
    for (int p = 0; p < player.size(); p++) {
        wallet[p] = wallet[p] - (timesReBuy[p]*buyIn);
    }
    temp = wallet[0];

    // Present returns
    cout << "Returns from game:" << endl;
    if (wallet[0] >= 0) {
        cout << "Dealer: \t+" << wallet[0] << " NOK" << endl;
    }
    else {
        cout << "Dealer: \t" << wallet[0] << " NOK" << endl;
    }
    for (int p = 1; p < player.size(); p++) {
        if (wallet[p] >= 0) {
            cout << "Player " << p << ": \t+" << wallet[p] << " NOK" << endl;
        }
        else {
            cout << "Player " << p << ": \t" << wallet[p] << " NOK" << endl;
        }
    }
    
    // Find vinner
    for (int p = 0; p < player.size(); p++) {

#if DEB || BJDEB
        cout << "\n\nplayer " << p << ":\n";
        cout << "Times rebuy: " << timesReBuy[p] << endl;
        cout << "Total cost: " << wallet[p] - (timesReBuy[p]*buyIn) << endl << endl;
#endif /* DEB || BJDEB */

        if (wallet[p] > temp) {
            vinner = p; 
            temp = wallet[p];
        }
    }
    // Print total vinner:
    if (vinner == 0) {cout << "\n\nThe house";}
    else {cout << "\n\nPlayer " << vinner;}
    cout << " has left with the biggest gain." << endl;
}
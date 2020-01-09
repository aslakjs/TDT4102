#include <iostream> // cout/cin etc,
#include <iomanip>
#include <cmath>
#include <vector> // Feedback to TA?
//#include "../head/task6.h"
#include "task6.h"
using namespace std;

// Task 6a) 
vector<int> calculateSeries (int loan, int rate, int years) {
    double dLoan = static_cast<double>(loan);
    double dRate = static_cast<double>(rate);
    vector<int> res;    // Resultant vector
    double pay = 0;
    double remains = dLoan;
    
    cout << endl << "Your loan: " << loan << endl;
    cout << "Your rate: " << rate << endl;
    cout << "#of years: " << years << endl << endl;

    for (int i = 1; i <= years; i++) {
        pay = ( ( dLoan / years ) + ( dRate*remains / 100.0 ) );
        remains -= dLoan/years;
        res.push_back(static_cast<int>(pay));
    }

    return (res);
}

// Task 6b) 
vector<int> calcAnnuity(int loan, int rate, int years) {
    double pay = 0;
    pay = (loan * ( (rate/100.0) / (1- pow(1+(rate/100.0),-years) ) ));
    return (vector<int> (years,pay));
}

// Task 6c)
void printLoan(int loan, int rate, int years) {
    int diff = 0;
    int totAn = 0;
    int totSe = 0;
    vector<int> anPay = calcAnnuity(loan, rate, years);
    vector<int> sePay = calculateSeries(loan, rate, years);
    cout << setw(6) << "Year:" << setw(12) << "Annuitet:" << setw(12) << "Series:" << setw(14) << "Difference:" << endl;

    for (int i = 0; i < years; i++) {
        diff = anPay[i] - sePay[i];
        totAn += anPay[i];
        totSe += sePay[i];
        cout << setw(6) << i+1 << setw(12) << anPay[i] << setw(12) << sePay[i] << setw(14) << diff << endl;
    }
    cout << setw(6) << "Total:" << setw(12) << totAn << setw(12) << totSe << setw(14) << totAn-totSe << endl;
}
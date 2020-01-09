#include <iostream> // cout/cin etc,
#include <cmath>
#include <vector> // Feedback to TA?
//#include "../head/task6.h"
#include "task6.h"
using namespace std;


vector<int> calculateSeries (int loan, int rate, int years) {
    vector<int> res;
    double pay = 0;
    double remains = static_cast<double>(loan);
    
    cout << endl << "Your loan: " << loan << endl;
    cout << "Your rate: " << rate << endl;
    cout << "#of years: " << years << endl << endl;

    for (int i = 0; i < years; i++) {
        remains = loan - pay;
        pay = ((static_cast<double>(loan)/years) + ((rate/100.0)*static_cast<double>(remains))); // 100.0 yields float-calc
        res.push_back(static_cast<int>(pay));
    }

    return (res);
}
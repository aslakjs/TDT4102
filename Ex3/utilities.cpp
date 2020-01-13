#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include "stdlib.h"
#include "utilities.h"
#include "cannonball.h"


using namespace std;

void initRando(void) {
    srand(static_cast<unsigned int>(time(nullptr)));
}

int randomWithLimits(int upper, int lower) {
    if (upper < lower) {upper = lower+1;}
    return ( rand() % upper + lower );
}

void playTargetPractise(void) {
    double goal = 0;
    int dist = randomWithLimits(1000,100);          // Initiate target somewhere between 100-100 m

    for (int i = 1; i <= 10; i++) {
        cout << "\n\n~~~ Round " << i << "/10: ~~~" << endl;
        double rad = degToRad(getUserInputTheta());     // Get angle in radians
        double abs = getUserInputAbsVelocity();         // Get abs-velocity
        vector<double> velXY = getVelocityVector(rad, abs);
        goal = targetPractise(dist, velXY[0], velXY[1]);
        double time = flightTime(velXY[1]);
        cout << "Time traveled [s]: ";
        printTime(time);
        if (goal < 0.5) {break;}
    }
    if (goal < 0.5) {cout << "\n\nGoal!\nTarget was placed at " << dist << " meters." << endl;}
    else {cout << "\n\nYou failed." << endl;}


}
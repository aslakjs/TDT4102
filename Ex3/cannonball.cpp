#include "cannonball.h"
#include <iostream> // cout
#include <iomanip>  // Setprecition
#include <cmath>    // pow
#include <vector>

using namespace std;

// Task 2a)
double acclY(void) {
    // return the acceleration in y-direction
    return (-9.81);
}

// Task 2b)
double velY(double initVelocityY, double time) {
    // return y-velocity at given time
    return ( initVelocityY + (time * acclY()) );
}

// Task 2c)
double posX(double initPosition, double initVelocity, double time) {
    // get current position along x-axit at given time
    // * 0 due to no change in acceleration (ie. no friction)
    return ( initPosition + (initVelocity * time) + (( pow(time,2) * 0 ) / 2) );
}
double posY(double initPosition, double initVelocity, double time){
    // get current position along y-axit at given time
    // limit at y=0, can't go through the ground
    double pos = ( initPosition + (initVelocity * time) + (( pow(time,2) * acclY() ) / 2) );
    if (pos < 0) {return 0;}
    else {return pos;}
}

// Task 2d)
void printTime(double time) {
    int iTime = static_cast<int>(time);
    int hh, mm, ss;
    double ds = 0;
    string ht = " hours";
    string mt = " minutes";
    string st = " seconds";
    string tt = " seconds";

    hh = iTime / 3600;          // get hours by deviding seconds into number of seconds in hour
    mm = (iTime % 3600) / 60;   // get hours by deviding the rest of previous calc with number of seconds in minute
    ss = iTime % 60;            // get seconds from rest of previous
    ds = ss + (time - static_cast<int>(time));

    // Change text with regards to single/plural
    if (hh == 1) {ht = " hour";}
    if (mm == 1) {mt = " minute";}
    if (ss == 1) {st = " second";}
    if (iTime == 1) {tt = " second";}

    // print flight time
    cout << hh << ht << ", " << mm << mt << " and " << fixed << setprecision(2) << ds << st << endl;
}

// Task 2e)
double flightTime(double initVelocity) {
    // return time untill y=0 in seconds [s]
    return ( (-2*initVelocity) / (acclY()) );
}

// Task 4a)
double getUserInputTheta() {
    double theta = 0;
    cout << "Input Theta [deg]: ";
    cin >> theta;
    return theta;
}
double getUserInputAbsVelocity() {
    double absVel = 0;
    cout << "Input absolute velocity [m/s]: ";
    cin >> absVel;
    return absVel;
}
double degToRad(double deg) {
    // change degrees to radians for easy calculations
    return (deg * (PI/180.0));
}
double getVelocityX(double theta, double absVelocity) {
    // Get the x-component from initial velocity and angle of fire
    return (absVelocity*cos(theta));
}
double getVelocityY(double theta, double absVelocity) {
    // Get the y-component from initial velocity and angle of fire
    return (absVelocity * sin(theta));
}
vector<double> getVelocityVector(double theta, double absVelocity) {
    // Returning a vector with both velocity components:
    // vector = {x-velocity, y-velocity}
    vector<double> result(2,0);
    result[0] = getVelocityX(theta, absVelocity);
    result[1] = getVelocityY(theta, absVelocity);
    return result;
}

// Task 4b)
double getDistanceTraveled(double velocityX, double velocityY) {
    // get distance in x-axis
    // using flight time - and find x-pos at time where y=0
    double time = flightTime(velocityY);
    return (posX(0,velocityX, time));
}

// Task 4c)
double targetPractise(double distanceToTarget, double velocityX, double velocityY) {
    // By using a fixed distance as reference:
    // checking the distance to the final x-position
    // the goal of the game is to have 0-relative distance
    double distX = getDistanceTraveled(velocityX, velocityY);
    double hit = distanceToTarget - distX;
    cout << "Distance traveled [m]:      " << distX << endl;
    cout << "Missed by [m]:              " << hit << endl;
    return abs(hit);
}



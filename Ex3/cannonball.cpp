#include "cannonball.h"
#include <iostream> // cout
#include <iomanip>  // Setprecition
#include <cmath>    // pow
#include <vector>

using namespace std;

// Task 2a)
double acclY(void) {
    return (-9.81);
}

// Task 2b)
double velY(double initVelocityY, double time) {
    return ( initVelocityY + (time * acclY()) );
}

// Task 2c)
double posX(double initPosition, double initVelocity, double time) {
    return ( initPosition + (initVelocity * time) + (( pow(time,2) * 0 ) / 2) );
}
double posY(double initPosition, double initVelocity, double time){
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

    hh = iTime / 3600;
    mm = (iTime % 3600) / 60;
    ss = iTime % 60;
    ds = ss + (time - static_cast<int>(time));

    if (hh == 1) {ht = " hour";}
    if (mm == 1) {mt = " minute";}
    if (ss == 1) {st = " second";}
    if (iTime == 1) {tt = " second";}

    cout << hh << ht << ", " << mm << mt << " and " << fixed << setprecision(2) << ds << st << endl;
}

// Task 2e)
double flightTime(double initVelocity) {
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
    return (deg * (PI/180.0));
}
double getVelocityX(double theta, double absVelocity) {
    return (absVelocity*cos(theta));
}
double getVelocityY(double theta, double absVelocity) {
    return (absVelocity * sin(theta));
}
vector<double> getVelocityVector(double theta, double absVelocity) {
    vector<double> result(2,0);
    //cout << "Velocity vector created." << endl;
    result[0] = getVelocityX(theta, absVelocity);
    //cout << "Velocity x-component computed." << endl;
    result[1] = getVelocityY(theta, absVelocity);
    //cout << "Velocity y-component computed." << endl;
    return result;
}

// Task 4b)
double getDistanceTraveled(double velocityX, double velocityY) {
    double time = flightTime(velocityY);
    return (posX(0,velocityX, time));
}

// Task 4c)
double targetPractise(double distanceToTarget, double velocityX, double velocityY) {
    double distX = getDistanceTraveled(velocityX, velocityY);
    double hit = distanceToTarget - distX;
    cout << "Distance traveled [m]:      " << distX << endl;
    cout << "Missed by [m]:              " << hit << endl;
    return abs(hit);
}



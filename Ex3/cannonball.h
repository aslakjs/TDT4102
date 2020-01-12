#ifndef CANNONBALL_H
#define CANNONBALL_H
#include <vector>
// Global values:
#define PI 3.1415926535

// Task 1a)
double acclY(void);

// Task 1b)
double velY(double initVelocityY = 0, double time = 0);

// Task 1c)
double posX(double initPosition = 0, double initVelocity = 0, double time = 0);
double posY(double initPosition = 0, double initVelocity = 0, double time = 0);

// Task 1d)
void printTime(double time = 0);

// Task 1e)
double flightTime(double initVelocity = 0);

// Task 4a)
double getUserInputTheta();
double getUserInputAbsVelocity();
double degToRad(double deg = 0);
double getVelocityX(double theta = 0, double absVelocity = 0);
double getVelocityY(double theta = 0, double absVelocity = 0);
std::vector<double> getVelocityVector(double theta = 0, double absVelocity = 0);

// Task 4b)
double getDistanceTraveled(double velocityX = 0, double velocityY = 0);

// Task 4c)
double targetPractise(double distanceToTarget = 0, double velocityX = 0, double velocityY = 0);

#endif /* !CANNONBALL_H */
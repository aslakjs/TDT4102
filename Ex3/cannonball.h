#ifndef CANNONBALL_H
#define CANNONBALL_H

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

#endif /* !CANNONBALL_H */
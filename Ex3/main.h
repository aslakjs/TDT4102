#ifndef MAIN_H
#define MAIN_H

// External headerfiles used by main:
#include "cannonball.h"
#include "utilities.h"

// main.cpp function declarations:
void _task4d(void);
void _task5(void);
void info(void);
void testDeviation(double maxError = 0.01, double initVelX = 50.0, double initVelY = 25.0, double initPosX = 0, double initPosY = 0, std::vector<double> time = {0.0,2.5,5.0}, std::vector<double> t1operand = {0.0,   0.0,   25.0}, std::vector<double> t2operand = {125.0, 31.84, 0.475}, std::vector<double> t3operand = {250.0, 2.375, -24.05});
inline void waitForEnter();
void testPrint(std::string nameOfFunction = "0", double maxError = 0, double testOfFunction = 0, double givenError = 0, double toOperand = 0, double time = 0);

// Test-function at top of main-function
// Keep = <false> unless spesific test reqired
// ~~~~~~~ ¡NB! ~~~~~~~~~~~~~~~~~~~~~~~~
// Will disable all other funcionability 
// for quick test, Use with care!
#define T_DEBUG false   


#endif /* !MAIN_H */
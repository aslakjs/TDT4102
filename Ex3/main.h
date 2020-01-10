#ifndef MAIN_H
#define MAIN_H

// External headerfiles used by main:
#include "cannonball.h"

// main.cpp function declarations:
void testDeviation(double maxError = 0.0001);
inline void waitForEnter();
void testPrint(std::string nameOfFunction = "~Test of test-function~", double maxError = 0, double testOfFunction = 0, double givenError = 0, double toOperand = 0);

// Test-function at top of main-function
// Keep = <false> unless spesific test reqired
// ~~~~~~~ ¡NB! ~~~~~~~~~~~~~~~~~~~~~~~~
// Will disable all other funcionability 
// for quick test, Use with care!
#define T_DEBUG true   


#endif /* !MAIN_H */
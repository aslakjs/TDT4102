#ifndef MAIN_H
#define MAIN_H

// External headerfiles used by main:
#include "cannonball.h"

// main.cpp function declarations:
void testDeviation(double compareOperand, double toOperand, double maxError, string name);


// Test-function at top of main-function
// Keep = <false> unless spesific test reqired
// ~~~~~~~ ¡NB! ~~~~~~~~~~~~~~~~~~~~~~~~
// Will disable all other funcionability 
// for quick test, Use with care!
#define T_DEBUG true   


#endif /* !MAIN_H */
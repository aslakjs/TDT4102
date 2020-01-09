#ifndef MAIN_H
#define MAIN_H

// Standard folder setup:
// head/    .h-files
// src/     .cpp-files
//
// Change to 1 if includes in folders, else 0
#define FOLDER 0 

#if FOLDER
#include "../head/task1.h"
#include "../head/task2.h"
#include "../head/task3.h"
#include "../head/task4.h"
#include "../head/task5.h"
#include "../head/task6.h"
#endif /* !FOLDER == true */

// Use includes below if all files in one folder
#if FOLDER == 0 
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"
#include "task6.h"
#endif /* !FOLDER == false */

// Declarations
void _task1(void);
void _task2(void);
void _task4(void);
void _task6(void);

#endif /* !MAIN_H */
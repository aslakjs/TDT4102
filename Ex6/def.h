#ifndef DEB_H
#define DEB_H

// Select operating system BEFORE compilation
#define _UNIX_ true    // true = unix, false = windows

// Debugging options:
#define DEB_TXT true

// Usable paths:
#if _UNIX_  // if UNIX (mac/linux..)
#define BASE_PATH "txtFiles/"
#define GIVN_PATH "givenFiles/"
#define PATH_1 "txtFiles/task1.txt"
#define PATH_1N "txtFiles/task1_new.txt"
#define PATH_G "givenFiles/grunnlov.txt"
#define PATH_T "givenFiles/temperatures.txt"
#define PATH_3 "txtFiles/task3.txt"
#else       // If windows:
#define BASE_PATH "txtFiles\\"
#define GIVN_PATH "givenFiles\\"
#define PATH_1 "txtFiles\\task1.txt"
#define PATH_1N "txtFiles\\task1_new.txt"
#define PATH_G "givenFiles\\grunnlov.txt"
#define PATH_T "givenFiles\\temperatures.txt"
#define PATH_3 "txtFiles\\task3.txt"
#endif /* _UNIX_ */

#endif /* DEB_H */
#ifndef PLAYMASTER_H
#define PLAYMASTER_H

#include <string>

#define THEORY false
#define DEB true

// Function declarations:
void play(void);
int checkCharNPos(std::string code = "AAAA", std::string guess = "AAAA");
int checkChar(std::string code = "AAAA", std::string guess = "AAAA");


#endif /* !PLAYMASTER_H */
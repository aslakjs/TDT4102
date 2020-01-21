#ifndef PLAYMASTER_H
#define PLAYMASTER_H

#include <string>

#define THEORY false
#define DEB false
#define TASK7 true

// Function declarations:
int play(void);
int checkCharNPos(std::string code = "AAAA", std::string guess = "AAAA");
int checkChar(std::string code = "AAAA", std::string guess = "AAAA");
void playgraphics(void);

#endif /* !PLAYMASTER_H */
#ifndef TASK3_H
#define TASK3_H

#include <map>
#include <string>
#include <fstream>



// Class declarations:
class CourseCatalog {
private:
    std::map<std::string, std::string> cources;
    std::fstream fileHandler;
public:
    CourseCatalog(void);
    ~CourseCatalog(void);
    void addCource(std::string cCode = "", std::string cName = "", int test = 0);
    void removeCource(std::string cCode = "");
    void getCource(std::string cCode = "");
    void mapOut(void);
    void mapIn(void);
};

// Function declarations:
void testCatalog(CourseCatalog* CC);
inline void waitForEnter(void);


#endif /* TASK3_H */
#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
protected:
    std::string name;
    int age;
public:
    Animal(std::string str, int num);
    //virtual std::string toString(void) {return ("Animal: " + name + ", " + std::to_string(age));}
    virtual std::string toString(void) = 0; // Pure virtual version
};


class Cat : public Animal {
public:
    Cat(std::string str, int num);
    std::string toString(void) {return ("Cat: " + name + ", " + std::to_string(age));}
};

class Dog : public Animal {
public:
    Dog(std::string str, int num);
    std::string toString(void) {return ("Dog: " + name + ", " + std::to_string(age));}
};


#endif /* ANIMAL_H */
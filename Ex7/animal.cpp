#include "animal.h"

using namespace std;

// ---- Animal ---------------------------------------------------------------
Animal::Animal(std::string str, int num) {
    name = str;
    age = num;
}


// ---- CAT ------------------------------------------------------------------
Cat::Cat(std::string str, int num) :  Animal(str, num) {
}

// ---- DOG ------------------------------------------------------------------
Dog::Dog(std::string str, int num) : Animal(str, num) {
}



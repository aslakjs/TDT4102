/*----------------------------------------------------
TITLE:  Assignment 9: dummyTest.h
COURSE: TDT4102 - Programming
AUTHOR: (c) Someone from NTNU & Aslak J. Strand
----------------------------------------------------*/

#ifndef DUMMYTEST_H
#define DUMMYTEST_H

#include <utility>

class Dummy {
    public:
        int *num;
        Dummy();
        Dummy(const Dummy &i);
        ~Dummy();
        Dummy &operator=(Dummy old) {
            std::swap(num, old.num);
            return *this;
        }
};

void dummyTest(void);

#endif /* DUMMYTEST_H */
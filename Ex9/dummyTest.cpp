#include <iostream>
#include <utility>
#include "dummyTest.h"

using namespace std;

Dummy::Dummy() {
    num = new int{0};
}
Dummy::Dummy(const Dummy &i) : num{nullptr} {
    this->num = new int{0};
    *num = *i.num;
}
Dummy::~Dummy() {
    delete num;
}

void dummyTest(void) {
    Dummy a;
    *a.num = 4;
    Dummy b{a};
    Dummy c;
    c = a;

    cout << "a: " << *a.num << endl;
    cout << "b: " << *b.num << endl;
    cout << "c: " << *c.num << endl;

    *b.num = 3;
    *c.num = 5;

    cout << "a: " << *a.num << endl;
    cout << "b: " << *b.num << endl;
    cout << "c: " << *c.num << endl;
}
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
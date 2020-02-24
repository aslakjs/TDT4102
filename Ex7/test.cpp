#include "test.h"
#include "animal.h"
#include "Graph.h"
#include <iostream>
#include <vector>


using namespace std;

void testAnimal(void) {
    Graph_lib::Vector_ref<Animal> animales;

    Cat *cat1 = new Cat("Mia", 15);
    Cat *cat2 = new Cat("Leo", 5);
    Dog *dog1 = new Dog("Bobby", 10);
    Dog *dog2 = new Dog("Kaisa", 13);

    animales.push_back(cat1);
    animales.push_back(cat2);
    animales.push_back(dog1);
    animales.push_back(dog2);

    for (int i = 0; i < 20; i++) {cout << endl;}
    for (int i = 0; i < animales.size(); i++) {
        cout << animales[i].toString() << endl;
    }

    cout << endl << "By removing the 'virtual' from Animal::toString() you will end up with 'Animal' in front of the name instead of 'Cat' or 'Dog'." << endl << endl;
}
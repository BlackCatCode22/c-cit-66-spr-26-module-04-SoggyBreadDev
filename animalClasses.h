//
// Created by new user on 3/8/2026.
//

#ifndef TESTING_ANIMALCLASSES_H
#define TESTING_ANIMALCLASSES_H
#include <iostream>
#include <string>

class Animal {
protected:
    std::string name, species;
    int age;
public:
    // Constructor
    Animal(std::string n, int a, std::string s) : name(n), age(a), species(s) {}

    // Virtual Destructor
    virtual ~Animal() {}

    // Print details function
    virtual void printDetails() const {
        std::cout << name << " (" << species << ")" << ", Age: " << age << std::endl;
    }
    std::string getSpecies() const { return species; }
};

class Hyena : public Animal {
public:
    Hyena(std::string n, int a) : Animal(n, a, "Hyena") {}
};

class Lion : public Animal {
public:
    Lion(std::string n, int a) : Animal(n, a, "Lion") {}
};

class Bear : public Animal {
public:
    Bear(std::string n, int a) : Animal(n, a, "Bear") {}
};

class Tiger : public Animal {
public:
    Tiger(std::string n, int a) : Animal(n, a, "Tiger") {}
};


#endif //TESTING_ANIMALCLASSES_H
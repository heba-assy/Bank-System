#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include <cstdlib>
#include "Validation.h"

using namespace std;

class Person {
protected:
    int id;
    string name;
    string pass;
public:
    // Constructor
    Person(){};
    Person(int id, string name, string pass);

    // Setters & Getters
    void setId(int id);
    int getId();

    void setName(string name);
    string getName();

    void setPassword(string pass);
    string getPassword();

    // Display
    void Display();
};

#endif // PERSON_H

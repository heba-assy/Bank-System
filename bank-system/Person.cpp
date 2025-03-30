#include "Person.h"
#include <iostream>
using namespace std;

//Constructor
Person::Person(int id, string name, string pass) {
    while (!Validation::isValidName(name)) {
        cout<<"Invalid name! Please enter a valid name (5-20 letters, no numbers): ";
        getline(cin, name);
    }
    this->name = name;

        while (!Validation::isValidPassword(pass)) {
         cout << "Invalid password! Please enter a valid password (8-20 characters): ";
         getline(cin, pass);
        }

    this->pass=pass;
    this->id = id;
}

//Setters & Getters
void Person::setId(int id) {
    this->id = id;
}

int Person::getId() {
    return id;
}

void Person::setName(string name) {
    while (!Validation::isValidName(name)) {
        cout << "Invalid name! Please enter a valid name (5-20 letters, no numbers): ";
        getline(cin, name);
    }
    this->name = name;

}

string Person::getName() {
    return name;
}

void Person::setPassword(string pass) {
        while (!Validation::isValidPassword(pass)) {
          cout << "Invalid password! Please enter a valid password (8-20 characters): ";
          getline(cin, pass);
        }
    this->pass=pass;

}

string Person::getPassword() {
    return pass;
}

// Display Function
void Person::Display() {
    cout << "ID: " << getId() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Password: " << getPassword() << endl;
}

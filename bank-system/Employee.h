#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#pragma once
#include <vector>
#include "Person.h"
#include "Validation.h"
#include "FilesHelper.h"
#include "Client.h"

#include <iostream>
using namespace std;

class Admin;  // Forward declaration
class Parser; // Forward declaration

class Employee : public Person {
protected:
    double salary = 0;
public:
    Employee(){};
    // Constructor for creating a new Employee (ID is automatically assigned)
    Employee(string name, string pass, double salary);

    // Constructor for loading an existing Employee from a file (ID is passed explicitly)
    Employee(int id, string name, string pass, double salary);

    // Setter & Getter
    void setSalary(double salary);
    double getSalary();

    // Display
    void Display();

    //Methods
    void addClient(Client& client);
    static Client* searchClient(int id);
    void listClient();
    void editClient(int id, string name, string password, double balance);
};
static Client* searchClient(int id);

#endif // EMPLOYEE_H

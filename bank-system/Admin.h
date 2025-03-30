#ifndef ADMIN_H
#define ADMIN_H
#pragma once
#include <vector>
#include "Employee.h"
#include <string>

class Admin : public Employee {
public:
    // Constructor for creating a new Admin (ID is automatically assigned)
    Admin(string name, string pass, double salary);

    // Constructor for loading an existing Admin from a file (ID is passed explicitly)
    Admin(int id, string name, string pass, double salary);

    //Methods
    void addEmployee(Employee& employee);
    Employee* searchEmployee(int id);
    void editEmployee(int id, string name, string password, double salary);
    void listEmployee();
};

#endif // ADMIN_H

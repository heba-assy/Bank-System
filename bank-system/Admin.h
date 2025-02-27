#ifndef ADMIN_H
#define ADMIN_H
#include "Validation.h"
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include <fstream>
#include <iostream>

class Admin : public Employee
{
private:
    double salary = 0;

public:
    Admin(string name, string pass, double salary) : Employee(name, pass, salary) {}



    static Admin parseToAdmin(string line)
    {
        vector<string> data = Parser::split(line);
        // id=stoi(data[0]);
        // return Admin( data[1], data[2], stod(data[3]));

        Admin a(data[1], data[2], stod(data[3]));
        a.id = stoi(data[0]);
        return a;
    }
};

#endif // ADMIN_H

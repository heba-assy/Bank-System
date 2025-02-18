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

    void SaveAdminData(const Admin &admin)
    {
        ofstream file("Admin.txt", ios::app);
        if (file.is_open())
        {
            file << admin.toString() << endl;
            file.close();
            cout << "Data Saved!\n";
        }
        else
        {
            cout << "Failed to save Data!\n";
        }
    }
};

#endif // ADMIN_H

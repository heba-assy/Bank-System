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
    void addEmployee(Employee &e)
    {
        ofstream file("Data/Employees.txt", ios::app);
        if (file.is_open())
        {
            file << e.toString() << endl;
            file.close();
            cout << "Data Saved!\n";
        }
        else
        {
            cout << "Failed to save!\n";
        }

        ofstream file1("Data/LastIdEmployee.txt", ios::trunc);
        if (file1.is_open())
        {
            file1 << e.getId();
            file1.close();
        }
        else
        {
            cout << "Can't open file LastIdClient" << endl;
        }
    }
    void searchEmployee(int id)
    {
        ifstream file("Data/Empolyees.txt");
        if (!file)
        {
            cout << "The File isn't Exist" << endl;
            return;
        }
        vector<int> Ids;
        vector<Employee> Employees;
        string line;
        while (getline(file, line))
        {
            Employees.push_back(Employee::ParseToEmployee(line));
        }

        file.close();
        for (int i = 0; i < Employees.size(); i++)
        {
            Ids.push_back(Employees[i].getId());
        }

        for (int i = 0; i < Ids.size(); i++)
        {
            if (Ids[i] == id)
            {
                Employees[i].Display();
                return;
            }
        }
        cout << "Id not found" << endl;
    }
    void editEmployee(int id, string name, string pass, double salary)
    {
    }
    void listEmpolyee()
    {
        ifstream Efile("Data/Employees.txt");
        vector<Employee> Employees;
        string line;
        while (getline(Efile, line))
        {
            Employees.push_back(Employee::ParseToEmployee(line));
        }
        Efile.close();
        for (Employee &e : Employees)
        {
            e.Display();
        }
    }
};

#endif // ADMIN_H

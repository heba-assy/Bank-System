#ifndef ADMIN_H
#define ADMIN_H
#pragma once
#include "Client.h"
#include "Employee.h"
#include <fstream>
#include "Parser.h"

class Admin : public Employee
{
private:
    double salary = 0;

public:
    Admin() {}
    Admin(string name, string pass, double salary) : Employee(name, pass, salary) {}

    vector<Employee> allEmployees()
    {
        ifstream file("Data/Employees.txt");
        if (!file)
        {
            cout << "The File isn't Exist" << endl;
            return vector<Employee>();
        }
        vector<Employee> emps;
        string line;
        while (getline(file, line))
        {
            emps.push_back(Parser::parseToEmployee(line));
        }
        file.close();
        return emps;
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
    Employee *searchEmployee(int id)
    {
        vector<Employee> emps = allEmployees();
        for (int i = 0; i < emps.size(); i++)
        {
            if (emps[i].getId() == id)
            {
                Employee *p = new Employee(emps[i]);
                return p;
            }
        }
        return nullptr;
    }
    void listEmpolyee()
    {
        vector<Employee> emps = allEmployees();
        for (Employee &e : emps)
        {
            e.Display();
        }
    }
    void editEmployee(int id, string name, string pass, double salary)
    {
        vector<Employee> emps = allEmployees();
        if (Admin::searchEmployee(id) == 0)
        {
            cout << "Employee is not Exist!" << endl;
            return;
        }
        for (Employee &c : emps)
        {
            if (c.getId() == id)
            {
                c.setName(name);
                c.setPassword(pass);
                c.setSalary(salary);
                break;
            }
        }
        ofstream file("Data/Employees.txt");
        if (!file)
        {
            cout << "Error opening file!" << endl;
            return;
        }
        for (Employee &c : emps)
        {
            file << c.toString() << endl;
        }

        file.close();
        cout << "Employee Updated Successfully!\n";
    }
};

#endif // ADMIN_H
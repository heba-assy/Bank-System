#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Validation.h"
#include "Person.h"
#include "Client.h"

#include <iostream>

class Employee : public Person
{
private:
  double salary = 0;

public:
  Employee(string name, string pass, double salary) : Person(name, pass)
  {
    while (!validator::isValidSalary(salary))
    {
      cout << Invalid_Salary().what() << endl
           << "Please try again: ";
    }
    this->salary = salary;
  }

  string toString() const
  {
    return to_string(id) + "," + name + "," + pass + "," + to_string(salary);
  }

  void saveEmployeeData(const Employee &Employee)
  {
    ofstream file("Employees.txt",ios::app);
    if(file.is_open())
    {
      file<< Employee.toString()<<endl;
      file.close();
      cout<<"Data Saved!\n";
    }
    else
    {
      cout<<"Failed to save Data!\n";
    }
    

  }

  void setSalary(double salary)
  {
    while (!validator::isValidSalary(salary))
    {
      cout << Invalid_Salary().what() << endl
           << "Please try again: ";
      cin >> salary;
    }
    this->salary = salary;
  }
  double getSalary()
  {
    return salary;
  }
  // Display
  void Display()
  {
    Person::Display();
    cout << "Salary: " << getSalary() << endl
         << "---------------------" << endl;
  }
};

#endif // EMPLOYEE_H

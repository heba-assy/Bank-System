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
  Employee( string name, string pass, double salary) : Person( name, pass)
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
    cout << "Role: Employee" << endl;
    Person::Display();
    cout << "Salary: " << getSalary() << endl
         << "---------------------" << endl;
  }
  static Employee ParseToEmployee(string line)
  {
    vector<string> data = Parser::split(line);
    Employee emp(data[1], data[2], stod(data[3]));
    emp.id = stoi(data[0]);
    return emp;
  }


};

#endif // EMPLOYEE_H

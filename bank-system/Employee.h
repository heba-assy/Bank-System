#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Person.h"
#include <string>
#include <vector>

using namespace std;

class Person;
class Client;
class Admin;
class Employee : public Person
{
private:
  double salary = 0;

public:
  vector<Client> allClients();
  Employee() : Person() {};
  Employee(string name, string pass, double salary) : Person(name, pass)
  {
    while (!validator::isValidSalary(salary))
    {
      cout << Invalid_Salary().what() << endl
           << "Please try again: ";
      cin >> salary;
    }
    this->salary = salary;
  }

  string toString() const;

  void setSalary(double salary);
  double getSalary();
  // Display
  void Display();

  void addClient(Client &c);
  Client *SearchClient(int id);
  void listCilent();
  void editClient(int id, string name, string pass, double balance);
};

#endif // EMPLOYEE_H

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
  vector<Client> allClients()
  {
    ifstream file("Data/Clients.txt");
    if (!file)
    {
      cout << "The File isn't Exist" << endl;
      return vector<Client>();
    }
    vector<Client> clients;
    string line;
    while (getline(file, line))
    {
      clients.push_back(Client::parseToClient(line));
    }
    file.close();
    return clients;
  }

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

  void addClient(Client &c)
  {
    ofstream file("Data/Clients.txt", ios::app);
    if (file.is_open())
    {
      file << c.toStringC() << endl;
      file.close();
      cout << "Data Saved!\n";
    }
    else
    {
      cout << "Failed to save!\n";
    }

    ofstream file1("Data/LastIdClient.txt", ios::trunc);
    if (file1.is_open())
    {
      file1 << c.getId();
      file1.close();
    }
    else
    {
      cout << "Can't open file LastIdClient" << endl;
    }
  }

  Client *SearchClient(int id)
  {
    vector<Client> clients = allClients();
    for (int i = 0; i < clients.size(); i++)
    {
      if (clients[i].getId() == id)
      {
        Client *p = new Client(clients[i]);
        return p;
      }
    }
    return nullptr;
  }

  void listCilent()
  {
    vector<Client> clients = allClients();
    for (Client &c : clients)
    {
      c.Display();
    }
  }
  void editClient(int id, string name, string pass, double balance)
  {
    vector<Client> clients = allClients();
    if (Employee::SearchClient(id) == 0)
    {
      cout << "Client is not Exist!" << endl;
      return;
    }
    for (Client &c : clients)
    {
      if (c.getId() == id)
      {
        c.setName(name);
        c.setPassword(pass);
        c.setBalance(balance);
        break;
      }
    }
    ofstream file("Data/Clients.txt");
    if (!file)
    {
      cout << "Error opening file!" << endl;
      return;
    }
    for (const Client &c : clients)
    {
      file << c.toStringC() << endl;
    }

    file.close();
    cout << "Client Updated Successfully!\n";
  }
};

#endif // EMPLOYEE_H

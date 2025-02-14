#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Validation.h"
#include "Person.h"
#include "Client.h"

#include <iostream>

class Employee:public Person{
private:
    double salary=0;
public:
    Employee(string name, string pass, double salary):Person(name,pass){
      if(!validator::isValidSalary(salary)){
        throw Invalid_Salary();
      }
      this->salary=salary;
    }
    int getId(){
      return Person::getId();
    }
    string getName(){
      return Person::getName();
    }
    string getPassword(){
      return Person::getPassword();
    }
    void setName(string name){
      Person::setName(name);
    }
    void setPassword(string pass){
      Person::setPassword(pass);
    }
    void setSalary(double salary){
      if(!validator::isValidSalary(salary)){
        throw Invalid_Salary();
      }
      this->salary=salary;
    }
    double getSalary(){
      return salary;
    }
    //Display
    void Display(){
      Person::Display();
      cout << "Salary: " << getSalary()<<endl;
    }
    //Methods


};

#endif // EMPLOYEE_H

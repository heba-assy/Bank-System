#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include <cstdlib>
#include "Validation.h"

using namespace std;

class Person
{
protected:
   static int nextID;
   int id;
   string name;
   string pass;

public:
   Person(string name, string pass)
   {
      while (!validator::isValidName(name))
      {
         cout << Invalid_Name().what() << endl
              << "Please try again: ";
         cin >> name;
      }
      while (!validator::isValidPass(pass))
      {
         cout << Invalid_Pass().what() << endl
              << "Please try again: ";
         cin >> pass;
      }
      this->name = name;
      this->pass = pass;
      id = nextID;
      nextID += rand() % 100 + 1; // To make ID increase rand between 1 to 100
   }
   // Setters & Getter
   int getId()
   {
      return id;
   }
   void setName(string name)
   {
      while (!validator::isValidName(name))
      {
         cout << Invalid_Name().what() << endl
              << "Please try again: ";
         cin >> name;
      }
      this->name = name;
      cout << "Name set successfully!" << endl;
   }
   string getName()
   {
      return name;
   }
   void setPassword(string pass)
   {
      while (!validator::isValidPass(pass))
      {
         cout << Invalid_Pass().what() << endl
              << "Please try again: ";
         cin >> pass;
      }
      this->pass = pass;
      cout << "Password set successfully!" << endl;
   }
   string getPassword()
   {
      return pass;
   }
   // Display
   void Display()
   {
      cout << "ID: " << getId() << endl;
      cout << "Name: " << getName() << endl;
      cout << "Password: " << getPassword() << endl;
   }
};

#endif // PERSON_H

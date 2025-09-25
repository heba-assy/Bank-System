#ifndef CLIENT_H
#define CLIENT_H
#pragma once
#include "Person.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Client : public Person
{
private:
   double balance = 0;

public:
   Client() : Person() {}
   Client(string name, string pass, double balance) : Person(name, pass)
   {
      if (!validator::isValidBalance(balance))
      {
         throw Invalid_Balance();
      }
      this->balance = balance;
   }

   // Setters & Getters
   void setBalance(double balance);
   double getBalance();
   void deposit(double amount);
   void Withdraw(double amount);
   void transferTo(double amount, Client &recipient);
   void checkBalance();
   string toStringC() const;
   // Display
   void Display();

   friend std::ostream &operator<<(std::ostream &os, const Client &client); // to can use the operator (<<) in pointer client (*Client)
};

#endif // CLIENT_H

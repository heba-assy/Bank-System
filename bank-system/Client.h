#ifndef CLIENT_H
#define CLIENT_H
#include "Person.h"
#include "Validation.h"
#include <iostream>
#include <fstream>
#include <sstream>

class Client : public Person
{
private:
   double balance = 0;

public:
   Client(string name, string pass, double balance) : Person(name, pass)
   {
      if (!validator::isValidBalance(balance))
      {
         throw Invalid_Balance();
      }
      this->balance = balance;
   }

   // Setters & Getters
   void setBalance(double balance)
   {
      if (!validator::isValidBalance(balance))
      {
         throw Invalid_Balance();
         return;
      }
      else
      {
         this->balance = balance;
      }
   }
   double getBalance()
   {
      return balance;
   }
   void deposit(double amount)
   {
      if (amount > 0)
      {
         balance += amount;
         cout << "Deposit successful!" << endl;
      }
      else
      {
         cout << "Invalid deposit amount!" << endl;
      }
   }
   void Withdraw(double amount)
   {
      if (amount > 0 && amount <= balance)
      {
         balance -= amount;
      }
      cout << "Insufficient funds or invalid amount!" << endl;
   }
   void transferTo(double amount, Client &recipient)
   {
      if (amount > 0 && amount <= balance)
      {
         recipient.deposit(amount);
         balance -= amount;
         cout << "Transfer successful!" << endl;
      }
      else
      {
         cout << "Insufficient funds or invalid amount!" << endl;
      }
   }
   void checkBalance()
   {
      cout << "Your Balance is: " << balance << " Units." << endl;
   }

   string toStringC() const
   {
      return to_string(id) + "," + name + "," + pass + "," + to_string(balance);
   }

   static Client parseToClient(string line)
   {
      // if(!line.empty()){
      vector<string> data = Parser::split(line);

      Client c(data[1], data[2], stod(data[3])); // stoi string to intger --stod string to double
      c.id = stoi(data[0]);
      return c;
      // }
      // return Client(0,"0","0",0);
   }

   void checkId()
   {
      ifstream file("LastClientId.txt");
   }

   // Display
   void Display()
   {
      cout << "Role: Client" << endl;
      Person::Display();
      cout << "Balance: " << getBalance() << endl
           << "---------------------" << endl;
   }
};

#endif // CLIENT_H

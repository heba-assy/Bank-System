#ifndef CLIENT_H
#define CLIENT_H
#include "Person.h"
#include "Validation.h"
#include <iostream>
#include <fstream>

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

   string toString() const
   {
      return to_string(id) + "," + name + "," + pass + "," + to_string(balance);
   }

   void saveClientData(const Client &client)
   {
      ofstream file("Clients.txt", ios::app); 
      if (file.is_open())
      {
         file << client.toString() << endl; 
         file.close();
         cout << "Data Saved!\n";
      }
      else
      {
         cout << "Failed to save!\n";
      }
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
   // Display
   void Display()
   {
      Person::Display();
      cout << "Balance: " << getBalance() << endl
           << "---------------------" << endl;
   }
};

#endif // CLIENT_H

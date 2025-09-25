#include "Client.h"
#include "Person.h"

#include <fstream>
#include <iostream>
#include <string>


    // Setters & Getters
    void Client::setBalance(double balance)
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
    double Client::getBalance()
    {
        return balance;
    }
    void Client::deposit(double amount)
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
    void Client::Withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal successful!\n";
        }
        else
        {
            cout << "Insufficient funds or invalid amount!" << endl;
        }
    }
    void Client::transferTo(double amount, Client &recipient)
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
    void Client::checkBalance()
    {
        cout << "Your Balance is: " << balance << " Units." << endl;
    }
    string Client::toStringC() const
    {
        return to_string(id) + "," + name + "," + pass + "," + to_string(balance);
    }
    friend std::ostream &operator<<(std::ostream &os, const Client &client) // to can use the operator (<<) in pointer client (*Client)
    {
        os << "Name: " << client.name << endl
           << "ID: " << client.id << endl
           << "Balance: " << client.balance << endl;
        return os;
    }
    // Display
    void Client::Display()
    {
        Person::Display();
        cout << "Balance: " << getBalance() << endl
             << "---------------------" << endl;
    }

#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"
#include "Validation.h"
#include "FilesHelper.h"
#include <iostream>

using namespace std;

class Client : public Person {
protected:
    double balance = 0;

public:
    // Constructor for creating a new Client (ID is automatically assigned)
    Client(string name, string pass, double balance);

    // Constructor for loading an existing Client from a file (ID is passed explicitly)
    Client(int id, string name, string pass, double balance);

    // Setters & Getters
    void setBalance(double balance);
    double getBalance();

    // Methods
    void deposit(double amount);
    void Withdraw(double amount);
    void transferTo(double amount, Client& recipient);
    void checkBalance();

    // Display
    void Display();
};

#endif // CLIENT_H

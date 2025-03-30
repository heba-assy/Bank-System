#include "Client.h"
#include "FilesHelper.h"
#include "Validation.h"
#include <iostream>

using namespace std;

// Constructor for creating a new Client (ID is automatically assigned)
Client::Client(string name, string pass, double balance)
    : Person(FilesHelper::getLastID("LastClientID.txt") + 1, name, pass) {
    if (!Validation::isValidBalance(balance)) {
        cout << "Invalid balance! Setting balance to minimum allowed (1500)." << endl;
        this->balance = 1500;
    } else {
        this->balance = balance;
    }
    FilesHelper::saveLastID("LastClientID.txt", getId());
}

// Constructor for loading an existing Client from a file (ID is passed explicitly)
Client::Client(int id, string name, string pass, double balance)
    : Person(id, name, pass) {
    this->balance = balance;
}

// Setters & Getters
void Client::setBalance(double balance) {
    if (!Validation::isValidBalance(balance)) {
        cout << "Invalid balance! Balance must be at least 1500. Keeping the previous balance." << endl;
        return;
    }
    this->balance = balance;
}

double Client::getBalance() {
    return balance;
}

// Methods
void Client::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Deposit successful!" << endl;
    } else {
        cout << "Invalid deposit amount!" << endl;
    }
}

void Client::Withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Withdrawal successful!\n";
    }
    else{
        cout << "Insufficient funds or invalid amount!" << endl;
    }

}

void Client::transferTo(double amount, Client& recipient) {
    if (amount > 0 && amount <= balance) {
        recipient.deposit(amount);
        balance -= amount;
        cout<<"Amount transferred successfully to " <<recipient.getName()<<"!"<<endl;
    } else {
        cout<<"Insufficient funds or invalid amount!" << endl;
    }
}

void Client::checkBalance() {
    cout << "Your Balance is: " << balance << " Units." << endl;
}

// Display
void Client::Display() {
    Person::Display();
    cout << "Balance: " << getBalance() << endl << endl;
}

#ifndef CLIENT_H
#define CLIENT_H
#include "Person.h"
#include "Validation.h"
#include<iostream>



class Client:public Person{
protected:
    double balance=0;
public:
    Client(string name, string pass, double balance): Person(name,pass){
        if(!validator::isValidBalance(balance)){
            throw Invalid_Balance();
        }
        this->balance=balance;
    }
    //Setters & Getters
    int getId(){
      return Person::getId();
    }
    void setName(string name){
       Person::setName(name);
    }
    string getName(){
       return Person::getName();
    }
    void setPassword(string pass){
       Person::setPassword(pass);
    }
    string getPassword(){
       return Person::getPassword();
    }
    void setBalance(double balance){
       if(!validator::isValidBalance(balance)){
        throw Invalid_Balance();
        return;
       }
       else{
        this->balance=balance;
       }
    }
    double getBalance(){
       return balance;
    }
    void deposit(double amount){
       if(amount>0){
         balance +=amount;
         cout << "Deposit successful!" << endl;
       }
       else{
         cout << "Invalid deposit amount!" << endl;
       }
    }
    void Withdraw(double amount){
       if(amount>0 && amount<=balance){
        balance -= amount;
       }
        cout << "Insufficient funds or invalid amount!"<<endl;
    }
    void transferTo (double amount, Client& recipient){
      if(amount>0&&amount<=balance){
         recipient.deposit(amount);
         balance-=amount;
         cout << "Transfer successful!" << endl;
      }
      else{
        cout << "Insufficient funds or invalid amount!"<<endl;
      }
    }
    void checkBalance(){
      cout<<"Your Balance is: "<<balance<<" Units."<<endl;
    }
    //Display
    void Display(){
      Person::Display();
      cout << "Balance: " << getBalance()<<endl<<endl;
    }
};


#endif // CLIENT_H

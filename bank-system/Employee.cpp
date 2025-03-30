#include "Employee.h"
#include "FilesHelper.h"
#include "fileManager.h"
#include "Parser.h"
#include <iostream>

using namespace std;
// Constructor for creating a new Employee (ID is automatically assigned)
Employee::Employee(string name, string pass, double salary)
    : Person(FilesHelper::getLastID("LastEmployeeID.txt") + 1, name, pass) {
     if (!Validation::isValidSalary(salary)) {
        cout << "Invalid salary! Setting salary to minimum allowed (5000)." << endl;
        this->salary = 5000;
    } else {
        this->salary = salary;
    }
    FilesHelper::saveLastID("LastEmployeeID.txt", id);
}

// Constructor for loading an existing Employee from a file (ID is passed explicitly)
Employee::Employee(int id, string name, string pass, double salary)
    : Person(id, name, pass) {
    if (!Validation::isValidSalary(salary)) {
        cout << "Invalid salary! Setting salary to minimum allowed (5000)." << endl;
        this->salary = 5000;
    } else {
        this->salary = salary;
    }
}

//=============Setter============
void Employee::setSalary(double salary) {
    if (Validation::isValidSalary(salary)) {
        this->salary = salary;
    } else {
        cout << "Invalid salary! Must be at least 5000." << endl;
    }
}

//=============Getter=============
double Employee::getSalary() {
    return salary;
}

//==========Display function===========
void Employee::Display() {
    Person::Display();
    cout << "Salary: " << getSalary() << endl;
}

//=================Methods====================
void Employee::addClient(Client& client){
    FilesHelper::clients.push_back(client);// Add client in the vector
    FilesHelper::saveClient(client);//Add client in the file
    cout << "Client added successfully!" << endl;
}
void Employee::listClient(){
   for(Client&c : FilesHelper::clients){
    c.Display();
    cout<<"-----------------------------\n";
   }
}
Client* Employee::searchClient(int id){
       for(Client&c : FilesHelper::clients){
        if(c.getId()==id){
            return &c;
        }
       }
       return nullptr;
}

void Employee::editClient(int id, string name, string password, double balance){
        Client* client = searchClient(id);
        if(!(client)){
            cout<<"Error: Client not found!"<<endl;
            return;
        }
        client->setName(name);
        client->setPassword(password);
        client->setBalance(balance);

        // Writing updated clients back to the file
        ofstream outFile("Client.txt");
        for(Client&c : FilesHelper::clients){
            outFile<<c.getId()<<","
               <<c.getName()<<","
               <<c.getPassword()<<","
               <<c.getBalance()<<endl;
        }
        outFile.close();
}

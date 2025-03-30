#include "ClientManager.h"
#include "Client.h"
#include "Employee.h"
#include <vector>
#include <fstream>
#include "Parser.h"
#include "FilesHelper.h"


void ClientManager::printClientMenu(){

    cout << "\n=====Welcome to Your Account=====\n";
    cout << "1. View Account Details\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Transfer Money\n";
    cout << "5. Change Password\n";
    cout << "6. Logout\n";
    cout << "==============================\n";
    cout << "Enter your choice: ";
}
//==========Update Password For Client=============
void ClientManager::updatePassword(Person* person){
    string newPass;
    cout<<"Enter the new password: ";
    cin>>newPass;


    for(Client& client : FilesHelper::clients){
        if(client.getId() == person->getId()){
            client.setPassword(newPass);
            break;
        }
    }
    ofstream outFile("Client.txt");
    for (Client& c : FilesHelper::clients) {
        outFile << c.getId() << ","
                << c.getName() << ","
                << c.getPassword() << ","
                << c.getBalance() << endl;
    }
    outFile.close();

    cout<<"Password updated successfully!"<<endl;
}
//========== Login for Client =============
Client* ClientManager::login(int id, string password){
   for(Client& client : FilesHelper::clients){
    if(client.getId()== id && client.getPassword()== password){
        return &client; // return pointer to the found client
    }
   }
   return nullptr;
}
//========== Client Options =============
bool ClientManager::clientOptions(Client* client){
    int choice;
    double amount;
    int recipientID;
    Client* recipient = nullptr;


   do{
    printClientMenu();
    cin>>choice;

    switch(choice){
       case 1:
           client->Display();
           break;
       case 2:
           cout<<"Enter amount to deposit: ";
           cin>>amount;
           client->deposit(amount);
           FilesHelper::saveClientsToFile();//Update file after Deposit
           break;
       case 3:
           cout<<"Enter amount to withdraw: ";
           cin>>amount;
           client->Withdraw(amount);
           FilesHelper::saveClientsToFile();//Update file after Withdraw
           break;
       case 4:
           cout<<"Enter recipient ID: ";
           cin>>recipientID;
           recipient = Employee::searchClient(recipientID);
           if(recipient){
            cout<<"Enter amount to transfer: ";
            cin>>amount;
            client->transferTo(amount, *recipient);// Convert (*recipient) pointer to object by dereferencing before passing to transferTo
            FilesHelper::saveClientsToFile();//Update file after Trasferto
           }
           else{
            cout<<"Error: Recipient not found!";
           }
           break;
       case 5:
           updatePassword(client);
           break;
       case 6:
           cout<<"Logging out...\n";
           break;
       default:
           cout<<"Invalid choice! Please enter a number between 1 and 6.\n";
    }

   }while(choice!=6);

   return true;
}

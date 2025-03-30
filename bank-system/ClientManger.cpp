#include "ClientManger.h"
#include "Client.h"
#include "Employee.h"
#include <vector>
#include <fstream>
#include "Parser.h"


void ClientManger::printClientMenu(Client* client){
    int choice;
    double amount;
    int recipientID;
    Employee e;
    Client* recipient = nullptr;


   do{
    cout << "\n=====Welcome to Your Account=====\n";
    cout << "1. View Account Details\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Transfer Money\n";
    cout << "5. Change Password\n";
    cout << "6. Logout\n";
    cout << "==============================\n";
    cout << "Enter your choice: ";

    int choice;
    cin>>choice;

    double amount;
    int recipientID;
    switch(choice){
       case 1:
           client->Display();
           break;
       case 2:
           cout<<"Enter amount to deposit: ";
           cin>>amount;
           client->deposit(amount);
           break;
       case 3:
           cout<<"Enter amount to withdraw: ";
           cin>>amount;
           client->Withdraw(amount);
           break;
       case 4:
           cout<<"Enter recipient ID: ";
           cin>>recipientID;
           recipient = e.searchClient(recipientID);
           if(recipient){
            cout<<"Enter amount to transfer: ";
            cin>>amount;
            client->transferTo(amount, *recipient);// Convert (*recipient) pointer to object by dereferencing before passing to transferTo
            delete recipient;
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

}
//==========Update Password For Client=============
void ClientManger::updatePassword(Person* person){
    string newPass;
    cout<<"Enter the new password: ";
    cin>>newPass;

    try{
       person->setPassword(newPass);
    }
    catch(exception& e){
        cout<<e.what()<<endl;
    }

    vector<Client> clients;
    string line;
    ifstream inFile("Client.txt");

    while(getline(inFile, line)) {
        clients.push_back(Parser::parseToClient(line));
    }
    inFile.close();

    bool found = false;
    for (Client& c : clients) {
        if (c.getId() == person->getId()) {
            c.setPassword(newPass);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Error: Client not found!" << endl;
        return;
    }

    ofstream outFile("Client.txt");
    for (Client& c : clients) {
        outFile << c.getId() << ","
                << c.getName() << ","
                << c.getPassword() << ","
                << c.getBalance() << endl;
    }
    outFile.close();

    cout<<"Password updated successfully!"<<endl;
}

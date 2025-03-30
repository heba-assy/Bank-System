#include " EmployeeManager.h"

void EmployeeManager::printEmployeMenu(){
    cout << "\n===== Employee Menu =====\n";
    cout << "1. Add New Client\n";
    cout << "2. Search for Client\n";
    cout << "3. List All Clients\n";
    cout << "4. Edit Client Info\n";
    cout << "5. Logout\n";
    cout << "=========================\n";
    cout << "Enter your choice: ";
}
//========== Add New Client =============
void EmployeeManager::newClient(Employee* employee){
    string name,password;
    double balance;

    cout<<"Enter Client Name: ";
    cin>>name;
    cout<<"Enter Password: ";
    cin>>password;
    cout<<"Enter Initial Balance: ";
    cin>>balance;

    int newId = FilesHelper::getLastID("LastClientID.txt")+1;
    Client newClient(newId,name,password,balance);

    employee->addClient(newClient);

    cout<<"New client added successfully! ID: "<<newId<<endl;
}
//========== List All Clients =============
void EmployeeManager::listAllClients(Employee* employee){
   cout<<"\n===== List of All Clients =====\n";
   employee->listClient();
}
//========== Search For Client =============
void EmployeeManager::searchForClient(Employee* employee){
   int clientID;
   cout<<"Enter Client ID to search: ";
   cin>>clientID;
   Client* client = employee->searchClient(clientID);

   if(client){
    cout<<"\nClient found \n";
    client->Display();
   }
   else{
    cout<<"Error: Client with ID "<<clientID<<" not found.\n";
   }
}
//========== Edit Client =============
void EmployeeManager::editClientInfo(Employee* employee){
   int id;
   cout<<"Enter Client ID to edit: ";
   cin>>id;

   Client* client = employee->searchClient(id);

   if(!client){
    cout<<"Error: Client not found!"<<endl;
    return;
   }

   int choice;
   string newName,newPassword;
   double newBalance;

   do {
        cout<<"\n=== Edit Client Info ===\n";
        cout<<"1. Edit Name\n";
        cout<<"2. Edit Password\n";
        cout<<"3. Edit Balance\n";
        cout<<"4. Save & Exit\n";
        cout<<"Choose an option: ";
        cin>>choice;

        switch(choice){
           case 1:
              cout<<"Enter new name: ";
              cin>>newName;
              employee->editClient(id,newName,client->getPassword(),client->getBalance());
              cout << "Name set successfully!" << endl;
              break;
           case 2:
              cout<<"Enter new password: ";
              cin>>newPassword;
              employee->editClient(id,client->getName(),newPassword,client->getBalance());
              cout << "Password set successfully!" << endl;
              break;
           case 3:
              cout<<"Enter new balance: ";
              cin>>newBalance;
              employee->editClient(id,client->getName(),client->getPassword(),newBalance);
              break;
           case 4:
              cout<<"Changes saved!\n";
              break;
           default:
                cout<<"Invalid choice, try again.\n";
        }
   }while(choice != 4);
}
//========== Login for Employee =============
Employee* EmployeeManager::login(int id, string password){
   for(Employee& employee : FilesHelper::employees){
    if(employee.getId()== id && employee.getPassword()== password){
        return &employee; // return pointer to the found employee
    }
   }
   return nullptr;
}
//========== Employee Options =============
bool EmployeeManager::employeeOptions(Employee* employee){
   int choice;

   do{
     printEmployeMenu();
     cin>>choice;

     switch(choice){
        case 1:
            newClient(employee);
            break;
        case 2:
            searchForClient(employee);
            break;
        case 3:
            listAllClients(employee);
            break;
        case 4:
            editClientInfo(employee);
            break;
        case 5:
            cout<<"Logging out...\n";
            break;
        default:
            cout<<"Invalid choice! Please enter a number between 1 and 5.\n";
     }
   }while(choice != 5);
   return true;
}

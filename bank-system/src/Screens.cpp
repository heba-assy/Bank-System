#include "Screens.h"
#include "../ClientManager.h"
#include "../ EmployeeManager.h"
#include "../AdminManager.h"

void Screens::bankName(){
   cout<<"======================================== Assy Bank ============================================= \n";
}
void Screens::welcome(){
    cout<<"\nWelcome to Assy Bank System!\n\n";
}
void Screens::loginOptions(){
    cout << "Please choose an option:\n";
    cout << "1. Login as Client\n";
    cout << "2. Login as Employee\n";
    cout << "3. Login as Admin\n";
    cout << "4. Exit\n";
}
int Screens::loginAs(){
   int choice;
   cout<<"Enter your choice: ";
   cin>>choice;
   return choice;
}
void Screens::invalid(int c){
  cout<<"Error: '" << c << "' is not a valid option. Please try again.\n";
}
void Screens::logout(){
   cout<<"You have been logged out successfully.\n";
}
void Screens::loginScreen(int c){

   string password;
   int id;
   Client* client = nullptr;
   Employee* employee = nullptr;
   Admin* admin = nullptr;

   switch(c){
       case 1:
          while(!client){
            cout << "\n===== Client Login =====\n";
            cout << "Enter your ID: ";
            cin >> id;
            cout << "Enter your Password: ";
            cin >> password;

            client = ClientManager::login(id, password);
            if(!client){
                cout<<"Invalid ID or Password. Please try again!\n";
            }
          }
          cout<<"Login successful!\n";
          ClientManager::clientOptions(client);
          break;
       case 2:
          while(!employee){
            cout << "\n===== Employee Login =====\n";
            cout << "Enter your ID: ";
            cin >> id;
            cout << "Enter your Password: ";
            cin >> password;

            employee = EmployeeManager::login(id, password);
            if(!employee){
                cout<<"Invalid ID or Password. Please try again!\n";
            }
          }
          cout<<"Login successful!\n";
          EmployeeManager::employeeOptions(employee);
          break;
       case 3:
          while(!admin){
            cout << "\n===== Admin Login =====\n";
            cout << "Enter your ID: ";
            cin >> id;
            cout << "Enter your Password: ";
            cin >> password;

            admin = AdminManager::login(id, password);
            if(!admin){
                cout<<"Invalid ID or Password. Please try again!\n";
            }
          }
          cout<<"Login successful!\n";
          AdminManager::AdminOptions(admin);
          break;
        default:
          invalid(c);
          break;
   }
}
void Screens::runApp(){
   // Load data from files
   FilesHelper::getClients();
   FilesHelper::getEmployees();
   FilesHelper::getAdmins();
   //Welcome to Bank
   bankName();
   welcome();

   //Login Options(Client, Employee, Admin)
   loginOptions();
   int choice = loginAs();

   //Log Out
   if(choice == 4){
    logout();
   }

   loginScreen(choice);
}

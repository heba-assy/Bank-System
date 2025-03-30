#include "AdminManager.h"

void AdminManager::printEmployeeMenu(){
    cout << "\n===== Employee Menu =====\n";
    cout << "1. Add New Employee\n";
    cout << "2. Search for Employee\n";
    cout << "3. List All Employees\n";
    cout << "4. Edit Employee Info\n";
    cout << "5. Logout\n";
    cout << "=========================\n";
    cout << "Enter your choice: ";
}
//========== Add New Employee =============
void AdminManager::newEmployee(Admin* admin){
    string name,password;
    double salary;

    cout<<"Enter Client Name: ";
    cin>>name;
    cout<<"Enter Password: ";
    cin>>password;
    cout<<"Enter Initial Salary: ";
    cin>>salary;

    int newId = FilesHelper::getLastID("LastEmployeeID.txt")+1;
    Employee newEmployee(newId,name,password,salary);

    admin->addEmployee(newEmployee);

    cout<<"New employee added successfully! ID: "<<newId<<endl;
}
//========== List All Employees =============
void AdminManager::listAllEmployees(Admin* admin){
   cout<<"\n===== List of All Employees =====\n";
   admin->listEmployee();
}
//========== Search For Employee =============
void AdminManager::searchForEmployee(Admin* admin){
   int employeeID;
   cout<<"Enter Employee ID to search: ";
   cin>>employeeID;
   Employee* employee = admin->searchEmployee(employeeID);

   if(employee){
    cout<<"\nEmployee found \n";
    employee->Display();
   }
   else{
    cout<<"Error: Employee with ID "<<employeeID<<" not found.\n";
   }
}
//========== Edit Client =============
void AdminManager::editEmployeeInfo(Admin* admin){
   int id;
   cout<<"Enter Employee ID to edit: ";
   cin>>id;

   Employee* employee = admin->searchEmployee(id);

   if(!employee){
    cout<<"Error: Employee not found!"<<endl;
    return;
   }

   int choice;
   string newName,newPassword;
   double newSalary;

   do {
        cout<<"\n=== Edit Client Info ===\n";
        cout<<"1. Edit Name\n";
        cout<<"2. Edit Password\n";
        cout<<"3. Edit Salary\n";
        cout<<"4. Save & Exit\n";
        cout<<"Choose an option: ";
        cin>>choice;

        switch(choice){
           case 1:
              cout<<"Enter new name: ";
              cin>>newName;
              admin->editEmployee(id,newName,employee->getPassword(),employee->getSalary());
              cout << "Name set successfully!" << endl;
              break;
           case 2:
              cout<<"Enter new password: ";
              cin>>newPassword;
              admin->editEmployee(id,employee->getName(),newPassword,employee->getSalary());
              cout << "Password set successfully!" << endl;
              break;
           case 3:
              cout<<"Enter new Salary: ";
              cin>>newSalary;
              admin->editEmployee(id,employee->getName(),employee->getPassword(),newSalary);
              cout << "Salary set successfully!" << endl;
              break;
           case 4:
              cout<<"Changes saved!\n";
              break;
           default:
                cout<<"Invalid choice, try again.\n";
        }
   }while(choice != 4);
}
Admin* AdminManager::login(int id, string password){
   for(Admin& admin : FilesHelper::admins){
    if(admin.getId()== id && admin.getPassword()== password){
        return &admin; // return pointer to the found admin
    }
   }
   return nullptr;
}
//========== Admin Options =============
bool AdminManager::AdminOptions(Admin* admin){
   int choice;

   do{
     printEmployeeMenu();
     cin>>choice;

     switch(choice){
        case 1:
            newEmployee(admin);
            break;
        case 2:
            searchForEmployee(admin);
            break;
        case 3:
            listAllEmployees(admin);
            break;
        case 4:
            editEmployeeInfo(admin);
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

#include "Admin.h"
#include "FilesHelper.h"
#include "fileManager.h"
#include "Parser.h"
#include "Employee.h"

using namespace std;

// Constructor for creating a new Admin (ID is automatically assigned)
Admin::Admin(string name, string pass, double salary)
    : Employee(FilesHelper::getLastID("LastAdminID.txt") + 1, name, pass, salary) {
    FilesHelper::saveLastID("LastAdminID.txt", getId());
}

// Constructor for loading an existing Admin from a file (ID is passed explicitly)
Admin::Admin(int id, string name, string pass, double salary)
    : Employee(id, name, pass, salary) {}

//==========Methods==========
void Admin::addEmployee(Employee& employee){
    FilesHelper::employees.push_back(employee);
    fileManager fm;
    fm.addEmployee("Employee.txt", "LastEmployeeID.txt", employee); //Add the employee in file
}
Employee* Admin::searchEmployee(int id){
    for(Employee& e : FilesHelper::employees){
        if(e.getId()==id){
            return &e;
        }
    }
    return nullptr;
}
void Admin::editEmployee(int id, string name, string password, double salary){
     Employee* employee=searchEmployee(id);
     if(!employee){
        cout<<"";
        return;
     }
     employee->setName(name);
     employee->setPassword(password);
     employee->setSalary(salary);

     // Write the updated employee data back to the file
     ofstream outFile("Employee.txt");
        for(Employee& e: FilesHelper::employees){
            outFile<<e.getId()<<","
               <<e.getName()<<","
               <<e.getPassword()<<","
               <<e.getSalary()<<endl;
        }
        outFile.close();
}
 void Admin::listEmployee(){
     for(Employee&e : FilesHelper::employees){
        e.Display();
        cout<<"-----------------------------\n";
     }
 }

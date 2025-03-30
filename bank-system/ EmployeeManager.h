#ifndef  EMPLOYEEMANAGER_H
#define  EMPLOYEEMANAGER_H
#include "Employee.h"

class  EmployeeManager
{
public:
    static void printEmployeMenu();
    static void newClient(Employee* employee);
    static void listAllClients(Employee* employee);
    static void searchForClient(Employee* employee);
    static void editClientInfo(Employee* employee);
    static Employee* login(int id, string password);
    static bool employeeOptions(Employee* employee);
};

#endif //  EMPLOYEEMANAGER_H

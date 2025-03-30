#ifndef ADMINMANAGER_H
#define ADMINMANAGER_H
#include "Admin.h"


class AdminManager
{
public:
    static void printEmployeeMenu();
    static void newEmployee(Admin* admin);
    static void listAllEmployees(Admin* admin);
    static void searchForEmployee(Admin* admin);
    static void editEmployeeInfo(Admin* admin);
    static Admin* login(int id, string password);
    static bool AdminOptions(Admin* admin);
};

#endif // ADMINMANAGER_H

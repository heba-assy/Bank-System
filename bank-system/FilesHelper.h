#ifndef FILESHELPER_H
#define FILESHELPER_H
#include <string>
#include <vector>
#include <iostream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

using namespace std;

class FilesHelper
{
protected:
    static int lastid;

public:
    static int getlastid(string filename);
    static void saveLast(string filename, int id);
    static int getLast(string filename);
    static void saveClient(Client &c);
    static void saveEmployee(Employee &E);
    static void SaveAdmin(const Admin &admin);
    static vector<Client> getClients();
    static vector<Employee> getEmployees();
    static vector<Admin> getAdmins();
    static void ClearFile(string fileName, string lastidfile);
};

#endif // FILESHELPER_H
#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "DataSourceInterface.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include <fstream>
#include "FilesHelper.h"

using namespace std;

class fileManager:public DataSourceInterface{
public:
     void addClient(Client c);
     void addEmployee(string fileName, string lastIdFile, Employee e);
     void addAdmin(string fileName, string lastIdFile, Admin a);

     void getAllClients();
     void getAllEmployees();
     void getAllAdmins();

     void removeAllClients();
     void removeAllEmployees();
     void removeAllAdmins();
};

#endif // FILEMANAGER_H

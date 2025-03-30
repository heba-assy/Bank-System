#ifndef DATASOURCEINTERFACE_H
#define DATASOURCEINTERFACE_H
#include "../Client.h"
#include "../Employee.h"
#include "../Admin.h"

class DataSourceInterface{
public:
    virtual void addClient(Client)=0;
    virtual void addEmployee(string fileName, string lastIdFile, Employee e)=0;
    virtual void addAdmin(string fileName, string lastIdFile, Admin a)=0;

    virtual void getAllClients()=0;
    virtual void getAllEmployees()=0;
    virtual void getAllAdmins()=0;

    virtual void removeAllClients()=0;
    virtual void removeAllEmployees()=0;
    virtual void removeAllAdmins()=0;
};
#endif // DATASOURCEINTERFACE_H

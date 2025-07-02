#pragma once
#include "FilesHelper.h"
class DataSourceInterface
{
public:
    virtual void addClient(Client &c) = 0;
    virtual void addEmployee(Employee &e) = 0;
    virtual void addAdmin(Admin &a) = 0;

    virtual void getAllClients() = 0;
    virtual void getAllEmployees() = 0;
    virtual void getAllAdmin() = 0;

    virtual void removeAllClients() = 0;
    virtual void removeAllEmployees() = 0;
    virtual void removeAllAdmin() = 0;
};
class FileManager : public DataSourceInterface
{
public:
    void addClient(Client &c)
    {
        FilesHelper::saveClient(c);
    }
    void addEmployee(Employee &e)
    {
        FilesHelper::saveEmployee(e);
    }
    void addAdmin(Admin &a)
    {
        FilesHelper::SaveAdmin(a);
    }

    void getAllClients()
    {
        FilesHelper::getClients();
    }
    void getAllEmployees()
    {
        FilesHelper::getEmployees();
    }
    void getAllAdmin()
    {
        FilesHelper::getAdmins();
    }

    void removeAllClients()
    {
        FilesHelper::ClearFile("Data/Clients.txt", "Data/LastIdClient");
    }
    void removeAllEmployees()
    {
        FilesHelper::ClearFile("Data/Empolyees.txt", "Data/LastIdClient");
    }
    void removeAllAdmin()
    {
        FilesHelper::ClearFile("Data/Admins.txt", "Data/LastIdAdmin");
    }
    // static void updateClients() // not working
    // {
    //     Employee e;
    //     FilesHelper::ClearFile("Data/Clients.txt", "Data/LastIdClient");
    //     for (auto& c : e.allClients())
    //         e.addClient(c);
    // }
};

#include <iostream>
#include <fstream>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Validation.h"
#include "Admin.h"
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

int main()
{
    Client c("Heba Mohamed", "12345678", 2000);
    // FilesHelper::saveClient(c);
    Client c2("Mohamed", "910111213", 2500);
    // FilesHelper::saveClient(c2);
    Client c3("Marwan", "14151617", 3000);
    // FilesHelper::saveClient(c3);
    // Client c4("Moazz", "18192021", 3500);
    // Client c5("Ahmed", "22232425", 5000);
    FilesHelper::getClients();

    FilesHelper::ClearFile("Clients.txt", "LastIdClient.txt");

    // =====================================================
    // Employee e2(12, "mohamed", "15132115", 6000);
    // Employee::getEmployees();

    // =============================================================
    // Admin a(13,"moahmed","32326445",61112);
    // Admin::getAdmins();

    return 0;
}

using namespace std;

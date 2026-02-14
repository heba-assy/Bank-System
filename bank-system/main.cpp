#include "ClientManager.h"
#include "EmployeeManager.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"



int main()
{
    Client c("Heba Mohamed", "12345678", 2000);
    FilesHelper::saveClient(c);
    Client c2("Mohamed", "910111213", 2500);
    FilesHelper::saveClient(c2);
    // Client c3("Marwan", "14151617", 3000);
    // FilesHelper::saveClient(c3);

    // Client c4("Marwan", "14151617", 3000);
    // FilesHelper::saveClient(c4);
    // Client c5("Marwan", "14151617", 3000);
    // FilesHelper::saveClient(c5);
    // Client c6("Marwan", "14151617", 3000);
    // FilesHelper::saveClient(c6);

// Client c7 ("medo alla", "2929299292",3000);
// FilesHelper::saveClient(c7);
    // FilesHelper::getClients();
    // ClientManager::clientOptions(&c);

    // =====================================================
    // Employee e2("mohamed", "15132115", 6000);
    // FilesHelper::saveEmployee(e2);
    // Employee::getEmployees();
    // e2.editClient(1002, "heba mohamed", "0122334455", 2000);
    // =============================================================
    // Admin a("moahmed", "32326445", 61112);
    // FilesHelper::SaveAdmin(a);
    // Admin::getAdmins();

    return 0;
}

using namespace std;

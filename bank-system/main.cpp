#include <iostream>
#include <fstream>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Validation.h"
#include "Admin.h"
#include "FilesHelper.h"

int main()
{
    Client c("Heba Mohamed", "12345678", 2000);
    FilesHelper::saveClient(c);
    Client c2("Mohamed", "910111213", 2500);
    // FilesHelper::saveClient(c2);
    Client c3("Marwan", "14151617", 3000);
    // FilesHelper::saveClient(c3);
    // Client c4("Moazz", "18192021", 3500);
    // Client c5("Ahmed", "22232425", 5000);
    // FilesHelper::getClients();

    // =====================================================
    Employee e2("mohamed", "15132115", 6000);
    // cout<<*e2.SearchClient(1001);
    // FilesHelper::getClients();
    // =============================================================
    Admin a("moahmed", "32326445", 61112);

    // FilesHelper::SaveAdmin(a);
    // FilesHelper::ClearFile("Data/Admins.txt","Data/LastIdAd.txt");
    // a.editEmployee(1004,"eosososo","0125565665",7000);
    // FilesHelper::getEmployees();

    return 0;
}

using namespace std;

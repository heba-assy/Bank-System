#include "FilesHelper.h"

class FileManager : public DataSourceInterface
{
    void addClient(Client &c){
        FilesHelper::saveClient(c);
    }
    void addEmployee(Employee &e){
        FilesHelper::saveEmployee(e);
    }
    void addAdmin(Admin &a){
        FilesHelper::SaveAdmin(a);
    }

    void getAllClients(){
        FilesHelper::getClients();
    }
    void getAllEmployees(){
        FilesHelper::getEmployees();
    }
    void getAllAdmin(){
        FilesHelper::getAdmins();
    }

    void removeAllClients(){
        FilesHelper::ClearFile("Data/Clients.txt", "Data/LastIdClient");
    }
    void removeAllEmployees() {
        FilesHelper::ClearFile("Data/Empolyees.txt", "Data/LastIdClient");
    }
    void removeAllAdmin() {
        FilesHelper::ClearFile("Data/Admins.txt","Data/LastIdAdmin");
    }
};

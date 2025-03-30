#include "fileManager.h"
//=============Add All====================
void fileManager::addClient(Client c){
    FilesHelper::saveClient(c);
}
void fileManager::addEmployee(string fileName, string lastIdFile, Employee e){
    FilesHelper::saveEmployee(fileName,lastIdFile,e);
}
void fileManager::addAdmin(string fileName, string lastIdFile, Admin a){
    FilesHelper::saveEmployee(fileName,lastIdFile,a);
}

//============Get All================
void fileManager::getAllClients(){
  FilesHelper::getClients();
}
void fileManager::getAllEmployees(){
   FilesHelper::getEmployees();
}
void fileManager::getAllAdmins(){
   FilesHelper::getAdmins();
}

//============Remove All ================
void fileManager::removeAllClients(){
   FilesHelper::clearFile("Client.txt","LastClientID.txt");
}
void fileManager::removeAllEmployees(){
   FilesHelper::clearFile("Employee.txt","LastEmployeeID.txt");
}
void fileManager::removeAllAdmins(){
   FilesHelper::clearFile("Admin.txt","LastAdminID.txt");
}

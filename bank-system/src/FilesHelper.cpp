#include "FilesHelper.h"
#include "../Client.h"
#include <fstream>
#include <vector>
#include "Parser.h"

vector<Client> FilesHelper::clients;
vector<Employee> FilesHelper::employees;
vector<Admin> FilesHelper::admins;

void FilesHelper::saveLastID(string fileName, int id){
   ofstream outFile(fileName);
   outFile<<id;
   outFile.close();
}
int FilesHelper::getLastID(string fileName){
   ifstream inFile(fileName);
   int lastID=1000;
   if(!inFile){//if file does not exist
    return lastID;
   }
   inFile>>lastID;
   inFile.close();
   return lastID;
}
//======== Save new Clients & Save new Employees============
void FilesHelper::saveClient(Client c){
   int lastID=getLastID("LastClientID.txt");
   c.setId(lastID+1);

   ofstream outFile("Client.txt", ios::app);
   outFile<<c.getId()<<","
          <<c.getName()<<","
          <<c.getPassword()<<","
          <<c.getBalance()<<endl;
   outFile.close();

   saveLastID("LastClientID.txt", c.getId());
}
//===== Update to client file=========
void FilesHelper::saveClientsToFile() {
    ofstream outFile("Client.txt");

    for (Client& c : FilesHelper::clients) {
        outFile << c.getId() << ","
                << c.getName() << ","
                << c.getPassword() << ","
                << c.getBalance() << endl;
    }

    outFile.close();
}
void FilesHelper::saveEmployee(string fileName, string lastIdFile, Employee e){
   int lastId=getLastID(lastIdFile)+1;
   e.setId(lastId);

   ofstream outFile(fileName, ios::app);
   outFile<<e.getId()<<","
          <<e.getName()<<","
          <<e.getPassword()<<","
          <<e.getSalary()<<endl;
   outFile.close();

   saveLastID(lastIdFile, e.getId()+1);
}
//========== Get Clients & Employees & Admins===============
void FilesHelper::getClients(){
    ifstream inFile("Client.txt");
    string line;
    while(getline(inFile, line)){
        clients.push_back(Parser::parseToClient(line));
    }
    inFile.close();
}
void FilesHelper::getEmployees(){
    ifstream inFile("Employee.txt");
    string line;
    while(getline(inFile, line)){
        employees.push_back(Parser::parseToEmployee(line));
    }
    inFile.close();
}
void FilesHelper::getAdmins(){
    ifstream inFile("Admin.txt");
    string line;
    while(getline(inFile, line)){
        admins.push_back(Parser::parseToAdmin(line));
    }
    inFile.close();
}
//=============== Clear File=================
void FilesHelper::clearFile(string fileName, string lastIdFile){
     ofstream outFile(fileName,ios::trunc);
     outFile.close();

     saveLastID(fileName,1000);
}

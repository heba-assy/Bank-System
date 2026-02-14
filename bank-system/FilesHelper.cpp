#include "FilesHelper.h"
#include <vector>
#include "Client.h"
#include "Admin.h"
#include "Parser.h"

using namespace std;

int FilesHelper::lastid = 1000;

int FilesHelper::getlastid(string filename)
{
    ifstream file(filename);
    int maxid = 1000;
    string line;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line.empty())
            {
                continue;
            }
            Client c = Parser::parseToClient(line);
            if (c.getId() > maxid)
            {
                maxid = c.getId();
            }
        }
        file.close();
    }
    else
    {
        cout << "Failed to open Clients.txt\n";
    }
    return maxid;
}
void FilesHelper::saveLast(string filename, int id)
{
    ofstream file(filename, ios::trunc);
    if (file.is_open())
    {
        file << id;
        file.close();
    }
    else
    {
        cout << "Can't open file" << filename << endl;
    }
}
int FilesHelper::getLast(string filename)
{
    ifstream file(filename);
    if (file.is_open() && file >> lastid) //----------------------------
    {
        file.close();
    }
    return lastid;
}
void FilesHelper::saveClient(Client &c) // to Create file -- ios ::app to save all data
{
    Employee e;
    if (!e.SearchClient(c.getId()) == 0)
    {
        cout << "The Client Already Exists!" << endl;
        return;
    }

    ofstream file("Data/Clients.txt", ios::app);
    if (file.is_open())
    {
        file << c.toStringC() << endl;
        file.close();
        cout << "Data Saved!\n";

        FilesHelper::saveLast("Data/LastIdClient.txt", c.id);
    }
    else
    {
        cout << "Failed to save!\n";
    }
}
void FilesHelper::saveEmployee(Employee &E)
{
    Admin a;
    if (a.searchEmployee(E.getId()) != 0)
    {
        cout << "The Employee Already Exists!" << endl;
        return;
    }

    ofstream file("Data/Employees.txt", ios::app);
    if (file.is_open())
    {
        file << E.toString() << endl;
        file.close();
        cout << "Data Saved!\n";
        FilesHelper::saveLast("Data/LastIdEmp.txt", E.id);
    }
    else
    {
        cout << "Failed to save Data!\n";
    }
}
void FilesHelper::SaveAdmin(const Admin &admin)
{
    ofstream file("Data/Admins.txt", ios::app);
    if (file.is_open())
    {
        file << admin.toString() << endl;
        file.close();
        cout << "Data Saved!\n";
        FilesHelper::saveLast("Data/LastIdAd.txt", admin.id);
    }
    else
    {
        cout << "Failed to save Data!\n";
    }
}
// static vector<Client> AllClients;
vector<Client> FilesHelper::getClients()
{
    vector<Client> clients;
    ifstream file("Data/Clients.txt");
    if (!file)
    {
        cout << "The File isn't Exist" << endl;
        return clients;
    }
    
    string line;
    while (getline(file, line))
    {
        Client c = Parser::parseToClient(line);
        clients.push_back(c);
    }

    file.close();
    return clients;
}
vector<Employee> FilesHelper::getEmployees()
{
    vector<Employee> Employees;
    ifstream Efile("Data/Employees.txt");
    if (!Efile)
    {
        cout << "The Employee File doesn't exist" << endl;
        return Employees;
    }
    
    string line;
    while (getline(Efile, line))
    {
        Employees.push_back(Parser::parseToEmployee(line));
    }
    Efile.close();
    return Employees;
}

vector<Admin> FilesHelper::getAdmins()
{
    vector<Admin> Admins;
    ifstream Afile("Data/Admins.txt");
    if (!Afile)
    {
        cout << "The Admin File doesn't exist" << endl;
        return Admins;
    }
    
    string line;
    while (getline(Afile, line))
    {
        Admins.push_back(Parser::parseToAdmin(line));
    }
    Afile.close();
    return Admins;
}
void FilesHelper::ClearFile(string fileName, string lastidfile)
{
    ofstream file(fileName, ios::trunc);
    FilesHelper::saveLast(lastidfile, FilesHelper::getLast(fileName) - FilesHelper::getLast(fileName));
    file.close();
    cout << "Data Cleared!" << endl;
}
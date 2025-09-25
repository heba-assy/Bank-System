#include "FilesHelper.h"
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"

using namespace std;

int FilesHelper::getlastid(string filename)
{
    ifstream file(filename);
    int maxid = 999; // Start at 999 so first ID will be 1000
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
int FilesHelper::lastid = 1000;
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
    // Get the last used ID and increment it
    int newId = getlastid("Data/Clients.txt") + 1;
    c.setId(newId);

    ofstream file("Data/Clients.txt", ios::app);
    if (file.is_open())
    {
        file << c.toStringC() << endl;
        file.close();
        cout << "Data Saved!\n";

        FilesHelper::saveLast("Data/LastIdClient.txt", c.getId());
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
                FilesHelper::saveLast("Data/LastIdEmp.txt", E.getId());
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
        FilesHelper::saveLast("Data/LastIdAd.txt", admin.getId());
    }
    else
    {
        cout << "Failed to save Data!\n";
    }
}
// static vector<Client> AllClients;
void FilesHelper::getClients()
{
    ifstream file("Data/Clients.txt");
    if (!file)
    {
        cout << "The File isn't Exist" << endl;
        return;
    }
    // AllClients.clear();
    vector<Client> clients;
    string line;
    while (getline(file, line))
    {
        Client c = Parser::parseToClient(line);
        clients.push_back(c);
    }
    // AllClients = clients;

    file.close();

    for (Client &c : clients)
    {
        c.Display();
    }
}
void FilesHelper::getEmployees()
{
    ifstream Efile("Data/Employees.txt");
    vector<Employee> Employees;
    string line;
    while (getline(Efile, line))
    {
        Employees.push_back(Parser::parseToEmployee(line));
    }
    Efile.close();
    for (Employee &e : Employees)
    {
        e.Display();
    }
}
void FilesHelper::getAdmins()
{
    ifstream Afile("Data/Admins.txt");
    vector<Admin> Admins;
    string line;
    while (getline(Afile, line))
    {
        Admins.push_back(Parser::parseToAdmin(line));
    }
    for (Admin &a : Admins)
    {
        a.Display();
    }
}
void FilesHelper::ClearFile(string fileName, string lastidfile)
{
    ofstream file(fileName, ios::trunc);
    if (!file.is_open()) {
        cout << "Failed to clear file: " << fileName << endl;
        return;
    }
    file.close();
    
    FilesHelper::saveLast(lastidfile, 999); // Reset ID counter to start fresh at 1000
    cout << "Data Cleared in " << fileName << endl;
}

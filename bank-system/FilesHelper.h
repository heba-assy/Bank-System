#include <iostream>
#include <fstream>
#include <vector>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

using namespace std;

class FilesHelper
{
protected:
    static int lastid;

public:
    static void saveLast(string filename, int id)
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
    static int getLast(string filename)
    {
        ifstream file(filename);
        int lastid = 0;
        if (file.is_open() && file >> lastid)
        {
            file.close();
        }
        return lastid;
    }

    static void saveClient(const Client &client) // to Create file -- ios ::app to save all data
    {
        ofstream file("Clients.txt", ios::app);
        if (file.is_open())
        {
            file << client.toStringC() << endl;
            file.close();
            cout << "Data Saved!\n";

            FilesHelper::saveLast("LastIdClient.txt", FilesHelper::getLast("LastIdClient.txt") + 1);
        }
        else
        {
            cout << "Failed to save!\n";
        }
    }

    static void saveEmployee(const Employee &Employee)
    {
        ofstream file("Employees.txt", ios::app);
        if (file.is_open())
        {
            file << Employee.toString() << endl;
            file.close();
            cout << "Data Saved!\n";
            FilesHelper::saveLast("LastIdEmp.txt", FilesHelper::getLast("LastIdEmp.txt") + 1);
        }
        else
        {
            cout << "Failed to save Data!\n";
        }
    }

    static void SaveAdmin(const Admin &admin)
    {
        ofstream file("Admins.txt", ios::app);
        if (file.is_open())
        {
            file << admin.toString() << endl;
            file.close();
            cout << "Data Saved!\n";
            FilesHelper::saveLast("LastIdAd.txt", FilesHelper::getLast("LastIdAd.txt") + 1);
        }
        else
        {
            cout << "Failed to save Data!\n";
        }
    }

    static void getClients()
    {
        ifstream file("Clients.txt");
        if (!file)
        {
            cout << "The File isn't Exist" << endl;
            return;
        }
        vector<Client> clients;
        string line;
        while (getline(file, line))
        {
            clients.push_back(Client::parseToClient(line));
        }

        file.close();

        for (Client &c : clients)
        {
            c.Display();
        }
    }

    static void getEmployees()
    {
        ifstream Efile("Employees.txt");
        vector<Employee> Employees;
        string line;
        while (getline(Efile, line))
        {
            Employees.push_back(Employee::ParseToEmployee(line));
        }
        Efile.close();
        for (Employee &e : Employees)
        {
            e.Display();
        }
    }

    static void getAdmins()
    {
        ifstream Afile("Admin.txt");
        vector<Admin> Admins;
        string line;
        while (getline(Afile, line))
        {
            Admins.push_back(Admin::parseToAdmin(line));
        }
        for (Admin &a : Admins)
        {
            a.Display();
        }
    }
    static void ClearFile(string fileName, string lastidfile)
    {
        ofstream file(fileName, ios::trunc);
        FilesHelper::saveLast(lastidfile, FilesHelper::getLast(fileName) - FilesHelper::getLast(fileName));
        file.close();
        cout<<"Data Cleared!"<<endl;

    }
};
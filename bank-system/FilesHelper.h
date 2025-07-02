#pragma once
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
    static int getlastid(string filename)
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
                Client c = Client::parseToClient(line);
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
        int lastid = 1000;
        if (file.is_open() && file >> lastid) //----------------------------
        {
            file.close();
        }
        return lastid;
    }

    static void saveClient(Client &c) // to Create file -- ios ::app to save all data
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

            FilesHelper::saveLast("Data/LastIdClient.txt", FilesHelper::getlastid("Data/Clients.txt"));
        }
        else
        {
            cout << "Failed to save!\n";
        }
    }

    static void saveEmployee(Employee &E)
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
            FilesHelper::saveLast("Data/LastIdEmp.txt", FilesHelper::getlastid("Data/Employees.txt"));
        }
        else
        {
            cout << "Failed to save Data!\n";
        }
    }

    static void SaveAdmin(const Admin &admin)
    {
        ofstream file("Data/Admins.txt", ios::app);
        if (file.is_open())
        {
            file << admin.toString() << endl;
            file.close();
            cout << "Data Saved!\n";
            FilesHelper::saveLast("Data/LastIdAd.txt", FilesHelper::getlastid("Data/Admins.txt"));
        }
        else
        {
            cout << "Failed to save Data!\n";
        }
    }
    // static vector<Client> AllClients;
    static void getClients()
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
            Client c = Client::parseToClient(line);
            clients.push_back(c);
        }
        // AllClients = clients;

        file.close();

        for (Client &c : clients)
        {
            c.Display();
        }
    }

    static void getEmployees()
    {
        ifstream Efile("Data/Employees.txt");
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
        ifstream Afile("Data/Admins.txt");
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
        cout << "Data Cleared!" << endl;
    }
};

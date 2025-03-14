#include <iostream>
#include <fstream>
#include <vector>
#include "Person.h"
#include "Client.h"

// #include "Admin.h"

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
        int lastid = 1000;
        if (file.is_open() && file >> lastid) //----------------------------
        {
            file.close();
        }
        return lastid;
    }

    static void saveClient(const Client &client) // to Create file -- ios ::app to save all data
    {
        ofstream file("Data/Clients.txt", ios::app);
        if (file.is_open())
        {
            file << client.toStringC() << endl;
            file.close();
            cout << "Data Saved!\n";

            FilesHelper::saveLast("Data/LastIdClient.txt", FilesHelper::getLast("Data/LastIdClient.txt") + 1);
        }
        else
        {
            cout << "Failed to save!\n";
        }
    }

    static void saveEmployee(const Employee &Employee)
    {
        ofstream file("Data/Employees.txt", ios::app);
        if (file.is_open())
        {
            file << Employee.toString() << endl;
            file.close();
            cout << "Data Saved!\n";
            FilesHelper::saveLast("Data/LastIdEmp.txt", FilesHelper::getLast("Data/LastIdEmp.txt") + 1);
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
            FilesHelper::saveLast("Data/LastIdAd.txt", FilesHelper::getLast("Data/LastIdAd.txt") + 1);
        }
        else
        {
            cout << "Failed to save Data!\n";
        }
    }

    static void getClients()
    {
        ifstream file("Data/Clients.txt");
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
        cout<<"Data Cleared!"<<endl;

    }
};

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

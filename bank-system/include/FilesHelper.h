#ifndef FILESHELPER_H
#define FILESHELPER_H
#include <string>
#include <vector>


class Client;   // Forward Declaration
class Employee;
class Admin;
using namespace std;

class FilesHelper{
public:
    // These variables are declared as static to be shared across all instances of FilesHelper
    // This allows us to store and retrieve data easily throughout the program
    // They are used to store client, employee, and admin data while the program is running

    static vector<Client> clients;
    static vector<Employee> employees;
    static vector<Admin> admins;

    static void saveLastID(string fileName, int id);
    static int getLastID(string fileName);
    static void saveClient(Client c);
    static void saveClientsToFile();
    static void saveEmployee(string fileName, string lastIdFile, Employee e);
    static void getClients();
    static void getEmployees();
    static void getAdmins();
    static void clearFile(string fileName, string lastIdFile);
};

#endif // FILESHELPER_H

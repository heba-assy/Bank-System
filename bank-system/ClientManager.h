#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H
#include <string>
#include <vector>
#include <iostream>

class Client;
class Employee;
class Admin;
class Person;
using namespace std;
class ClientManager
{
public:
    static void back(Client *client);
    static void printClientMenu();
    static void updatePass(Person *P);
    static Client *login(int id, string pass);
    static bool clientOptions(Client *c);
};
#endif // CLIENTMANAGER_H
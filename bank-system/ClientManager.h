#ifndef CLIENTMANGER_H
#define CLIENTMANGER_H
#include "Person.h"
#include "Client.h"


class ClientManager
{
public:
    static void printClientMenu();
    static void updatePassword(Person* person);
    static Client* login(int id, string password);
    static bool clientOptions(Client* client);
};

#endif // CLIENTMANGER_H

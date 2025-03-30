#ifndef CLIENTMANGER_H
#define CLIENTMANGER_H
#include "Person.h"
#include "Client.h"


class ClientManger
{
public:
    static void printClientMenu(Client* client);
    static void updatePassword(Person* person);
    static Client* login(int id, string password);
    static bool clientOptions(Client* client);
};

#endif // CLIENTMANGER_H

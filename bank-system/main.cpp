#include <iostream>
#include "Person.cpp"
#include "Client.cpp"
#include "Employee.cpp"
#include "Validation.cpp"
#include "Admin.h"

int main()
{
    Client c("Heba Mohamed", "12345678", 2000);
    Client c2("Mohamed", "910111213", 2500);
    Client c3("Marwan", "14151617", 3000);
    Client c4("Moazz", "18192021", 3500);
    Client c5("Ahmed", "22232425", 5000);

    c.saveClientData(c);
    c.Display();

    c2.saveClientData(c2);
    c2.Display();

    c3.saveClientData(c3);
    c3.Display();

    c4.saveClientData(c4);
    c4.Display();

    c5.saveClientData(c5);
    c5.Display();

    return 0;
}

using namespace std;

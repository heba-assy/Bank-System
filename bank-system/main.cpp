#include <iostream>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include <Validation.h>

int main() {
    try {
        Client c("Heba Mohamed", "12345678", 2000);
        Client c2("Mohamed", "910111213", 2500);
        Client c3("Marwan", "14151617", 3000);
        Client c4("Moazz", "18192021", 3500);
        Client c5("Ahmed", "22232425", 5000);
        c.Display();
        c2.Display();
        c3.Display();
        c4.Display();
        c5.Display();
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}


using namespace std;

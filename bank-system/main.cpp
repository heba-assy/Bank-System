#include <iostream>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include <Validation.h>

int main() {
    try {
        Client c("Heba Mohamed", "12345678", 1000);
        c.Display();
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}


using namespace std;

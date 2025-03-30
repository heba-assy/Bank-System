#include "Validation.h"
#include <cctype>

bool Validation::isValidName(string& name) {
    if (name.empty()) return false;
    for (char c : name) {
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return name.size() >= 5 && name.size() <= 20;

}

bool Validation::isValidPassword(string& password) {
    return password.size()>=8&&password.size()<=20;
}

bool Validation::isValidBalance(double balance) {
    return balance>=1500;
}
bool Validation::isValidSalary(double salary) {
    return salary>=5000;
}

#ifndef PARSER_H
#define PARSER_H
#include <sstream>
#include <vector>
#include "../Client.h"
#include "../Employee.h"
#include "../Admin.h"

class Admin;

using namespace std;
class Parser{
public:
    static vector<string> split(string line);
    static Client parseToClient(string line);
    static Employee parseToEmployee(string line);
    static Admin parseToAdmin(string line);
};

#endif // PARSER_H

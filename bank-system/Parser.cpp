#include "Parser.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include <sstream>

vector<string> Parser::split(string &line)
{
    vector<string> res;
    stringstream ss(line);
    string item;
    while (getline(ss, item, ','))
    {
        res.push_back(item);
    }
    return res;
}
Client Parser::parseToClient(string line)
{
    vector<string> data = Parser::split(line);
    Client c(data[1], data[2], stod(data[3]));
    c.id = stoi(data[0]);
    return c;
}
Employee Parser::parseToEmployee(string line)
{
    vector<string> data = Parser::split(line);
    Employee emp(data[1], data[2], stod(data[3]));
    emp.id = stoi(data[0]);
    return emp;
}
Admin Parser::parseToAdmin(string line)
{
    vector<string> data = Parser::split(line);
    Admin a(data[1], data[2], stod(data[3]));
    a.id = stoi(data[0]);
    return a;
}
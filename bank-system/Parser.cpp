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
    Client c;
    c.setName(data[1]);
    c.setPassword(data[2]);
    c.setBalance(stod(data[3]));
    c.setId(stoi(data[0]));
    return c;
}
Employee Parser::parseToEmployee(string line)
{
    vector<string> data = Parser::split(line);
    Employee emp;
    emp.setName(data[1]);
    emp.setPassword(data[2]);
    emp.setSalary(stod(data[3]));
    emp.setId(stoi(data[0]));
    return emp;
}
Admin Parser::parseToAdmin(string line)
{
    vector<string> data = Parser::split(line);
    Admin a;
    a.setName(data[1]);
    a.setPassword(data[2]);
    a.setSalary(stod(data[3]));
    a.setId(stoi(data[0]));
    return a;
}
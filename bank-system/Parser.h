#pragma once
#ifndef PARSER_H
#define PARSER_H
#include <vector>
#include <string>

using namespace std;
class Client;
class Employee;
class Admin;

class Parser {
public:
    static vector<string> split(string& line);
    static Client parseToClient(string line);
    static Employee parseToEmployee(string line);
    static Admin parseToAdmin(string line);
};
#endif // PARSER_H
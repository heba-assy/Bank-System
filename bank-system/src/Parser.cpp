#include "Parser.h"
#include <vector>
//============Split================
vector<string>Parser::split(string line){
    vector<string> result;

    stringstream ss(line);
    string object;
    while(getline(ss,object,',')){
        result.push_back(object);
    }
    return result;
}
//==============Parse To Client=========
Client Parser::parseToClient(string line){
     vector<string>info=split(line);
     int id=stoi(info[0]);
     string name=info[1];
     string pass=info[2];
     double balance=stod(info[3]);

     return Client(id,name,pass,balance);
}
//==============Parse To Employee=========
Employee Parser::parseToEmployee(string line){
     vector<string> info=split(line);
     int id=stoi(info[0]);
     string name=info[1];
     string pass=info[2];
     double salary=stod(info[3]);
     return Employee(id,name,pass,salary);
}
//==============Parse To Admin=========
Admin Parser::parseToAdmin(string line){
     Employee emp=parseToEmployee(line);
     return Admin(emp.getId(),emp.getName(),emp.getPassword(),emp.getSalary());
}

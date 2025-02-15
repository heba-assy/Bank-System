#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include <cstdlib>
#include "Validation.h"

using namespace std;

class Person{
protected:
    static int nextID;
    int id;
    string name;
    string pass;
public:
    Person(string name, string pass){
       string allErrors="";
       if(!validator::isValidName(name)){
        allErrors+= Invalid_Name().what();
       }
       if(!validator::isValidPass(pass)){
        allErrors+= Invalid_Pass().what();
       }
       if(!allErrors.empty()){
        throw runtime_error(allErrors);
       }
       this->name=name;
       this->pass=pass;
       this->id=nextID;
       nextID += rand() % 100 + 1; //To make ID increase rand between 1 to 100
    }
    //Setters & Getter
    int getId(){
       return id;
    }
    void setName(string name){
         if(!validator::isValidName(name)){
           throw Invalid_Name();
           return;
         }
         else{
            this->name=name;
            cout<<"Name set successfully!"<<endl;
         }
    }
    string getName(){
       return name;
    }
    void setPassword(string pass){
       if(!validator::isValidPass(pass)){
        throw Invalid_Pass();
        return;
       }
       else{
        this->pass=pass;
        cout<<"Password set successfully!"<<endl;
       }
    }
    string getPassword(){
       return pass;
    }
    //Display
    void Display(){
      cout<<"ID: "<<getId()<<endl;
      cout<<"Name: "<<getName()<<endl;
      cout<<"Password: "<<getPassword()<<endl;
    }
};




#endif // PERSON_H

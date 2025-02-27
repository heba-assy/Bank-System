#ifndef VALIDATION_H
#define VALIDATION_H
#include <string>
#include <cctype>
#include <exception>

using namespace std;
//===================Exception=============
class Invalid_Name : public exception
{
public:
  const char *what() const noexcept override
  {
    return "Invalid Name: The Name Must Be Alphabet and Single Space Only, Min Size 5 and Max Size 20.\n";
  }
};
class Invalid_Pass : public exception
{
public:
  const char *what() const noexcept override
  {
    return "Invalid Pass: : The Password must be with min size 8 and max size 20.\n";
  }
};
class Invalid_Balance : public exception
{
public:
  const char *what() const noexcept override
  {
    return "Invalid Balance: Min balance is 1500.\n";
  }
};
class Invalid_Salary : public exception
{
public:
  const char *what() const noexcept override
  {
    return "Invalid Salary: Min Salary 5000.\n";
  }
};
//=============Validation================
class validator
{
public:
  static bool isValidName(string &name)
  {
    if (name.empty())
      return false;
    for (char c : name)
    {
      if (!isalpha(c) && c != ' ')
      { // only Alphabet and spaces
        return false;
      }
    }
    return name.size() >= 5 && name.size() <= 20;
  }

  static bool isValidPass(string &pass)
  {
    return pass.size() >= 8 && pass.size() <= 20;
  }

  static bool isValidBalance(double balance)
  {
    return balance >= 1500;
  }

  static bool isValidSalary(double salary)
  {
    return salary >= 5000;
  }
};

#endif // VALIDATION_H

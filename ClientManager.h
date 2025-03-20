#include "Client.h"
#include "Employee.h"

class ClientManager
{
private:
    int num = 0;

public:
    static void printClientMenu()
    {
        cout << "1- Set Balance\n"
             << "2- Get Balance\n"
             << "3- Deposit\n"
             << "4- Withdraw\n"
             << "5- TransferTo\n"
             << "6- CheckBalance\n"
             << "7- Your Account info\n\n\n"
             << "Please Enter number from 1 to 7: \n";
        cin >> num;
        switch (num)
        {
        case 1:
            int n = 0;
            cout << "Enter ur money pls: ";
            cin >> n;
            Client ::setBalance(n);
            break;

        case 2:
            cout << "ur Balance: " << Client::getBalance() << endl;
            break;

        case 3:
            double a = 0;
            cout << "Enter ur money u want to Deposit it: ";
            cin >> a;
            Client::deposit(a);
            break;

        case 4:
            double a = 0;
            cout << "Enter ur money u want to Withdraw it: ";
            cin >> a;
            Client::deposit(a);
            break;

        case 5:
        int id=0;
        cout<<"Please Enter ID u want to Transfer to: ";
        cin>>id;
        while (Employee::SearchClient(id)==nullptr)
        {
            cout<<"this ID didn't found!\n"<<"pls Enter correct ID:";
            cin>>id;
        }

        default:
            break;
        }
    }
};
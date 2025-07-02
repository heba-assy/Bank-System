#include "FileManager.h"

class ClientManager
{
public:
    static void back(Client *client)
    {
        clientOptions(client);
    }
    static void printClientMenu()
    {
        cout << "1- Set Balance\n"
             << "2- Get Balance\n"
             << "3- Deposit\n"
             << "4- Withdraw\n"
             << "5- TransferTo\n"
             << "6- CheckBalance\n"
             << "7- Your Account info\n"
             << "8- Logout\n\n\n"
             << "Please Enter number from 1 to 8: \n";
    }
    static void updatePass(Person *P)
    {
        string newPass;
        cout << "Enter new password: ";
        cin >> newPass;
        P->setPassword(newPass);
    }
    static Client *login(int id, string pass)
    {
        Employee e;
        if ((e.SearchClient(id))->getId() == id && (e.SearchClient(id))->getPassword() == pass)
        {
            return e.SearchClient(id);
        }
        return nullptr;
    }
    static bool clientOptions(Client *c)

    {
        int num = 0;
        Employee e;
        double amount;
        ClientManager::printClientMenu();
        cin >> num;
        switch (num)
        {
        case 1:
        {
            int n = 0;
            cout << "Enter ur money pls: ";
            cin >> n;
            c->setBalance(n);
            cout << "set Balance Successful!\n";
            return true;
        }

        case 2:
        {
            cout << "ur Balance: " << c->getBalance() << endl;
            return true;
        }

        case 3:
        {
            double a = 0;
            cout << "Enter ur money u want to Deposit it: ";
            cin >> a;
            c->deposit(a);
            return true;
        }

        case 4:
        {
            double a = 0;
            cout << "Enter ur money u want to Withdraw it: ";
            cin >> a;
            c->Withdraw(a);
            return true;
        }

        case 5:
        {
            int id = 0;
            cout << "Please Enter ID u want to Transfer to: ";
            cin >> id;
            while (e.SearchClient(id) == nullptr)
            {
                cout << "this ID didn't found!\n"
                     << "pls Enter correct ID:";
                cin >> id;
            }
            double amount = 0;
            cout << "Enter Amaount to transfer: ";
            cin >> amount;
            Client *p = e.SearchClient(id);
            double m = p->getBalance();
            c->transferTo(amount, *p);

            return true;
        }
        case 6:
        {
            c->checkBalance();
            return true;
        }
        case 7:
        {
            c->Display();
            return true;
        }
        case 8:
        {
            return false;
        }
        default:
            clientOptions(c);
            return true;
        }
        back(c);
        return true;
    }
};
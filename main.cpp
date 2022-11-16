#include <iostream>

using namespace std;
#include "BankApplication.h"

int main()
{
    Client C1;
    int phoneNum, typ;
    double Balance,amount;
    string name, address, id;
    int option;

    while (true) {
        cout << "Welcome to FCAI Banking Application \n"
                "1. Create a New Account \n"
                "2. List Clients and Accounts \n"
                "3. Withdraw Money \n"
                "4. Deposit Money \n"
                "5. Exit \n";

        cin >> option;
        cin.ignore();
        if (option == 1) {
            cout << "----------------------------------------" << endl;
            cout << "Enter Client Name: ";
            getline(cin, name);

            cout << "Enter Client Address: ";
            getline(cin, address);

            cout << "Enter Client Phone Number: ";
            cin >> phoneNum;

            cout << "Enter Client Account Type: \n"
                    "1. Basic \n"
                    "2. Saving \n";
            cin >> typ;

            cout << "Starting balance: ";
            cin >> Balance;

            C1.addClient(name, address, phoneNum, Balance, typ);
        }
        if (option == 2) {
            cout << "Enter Client ID: FCAI-0";
            cin >> id;
            C1.client_data(id);
        }
        if (option == 3) {
            if (typ == 1) {
                BankAccount A1;
                cout << "Enter your id : FCAI-0";
                cin >> id;
                cout << "Enter amount you want to withdraw :";
                cin >> amount;
                A1.Withdraw(amount, id);
            }
            if (typ == 2) {
                SavingsBankAccount A1;
                cout << "Enter your id : FCAI-0";
                cin >> id;
                cout << "Enter amount you want to withdraw :";
                cin >> amount;
                A1.Withdraw(amount, id);
            }
        }
        if (option == 4) {
            if (typ == 1) {
                BankAccount A1;
                cout << "Enter your id : FCAI-0";
                cin >> id;
                cout << "Enter amount you want to Deposit :";
                cin >> amount;
                A1.deposit(amount, id);
            }
            if (typ == 2) {
                SavingsBankAccount A1;
                cout << "Enter your id : FCAI-0";
                cin >> id;
                cout << "Enter amount you want to Deposit :";
                cin >> amount;
                A1.deposit(amount, id);
            }
        }

        if (option == 5) {
            break;
        }
    }
}


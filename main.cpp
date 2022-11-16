#include <iostream>
#include <fstream>
using namespace std;
#include "BankApplication.h"

void Account_tyep(string& id,int& typ){
    fstream file,file2;
    string line;
    file.open("Basic.txt", ios::in);
    while (getline(file, line)) {
        if (line == "FCAI-0" + id) {
            typ = 1;
        }
    }
    file2.open("Saving.txt", ios::in);
    while (getline(file, line)) {
        if (line == "FCAI-0" + id) {
            typ = 2;
        }
    }
}

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
            cout << "------------------------------------------------------- \n"
                 << "Enter Client ID: FCAI-0";
            cin >> id;
            C1.client_data(id);
        }
        if (option == 3) {
            cout << "------------------------------------------------------- \n"
                 << "Enter your id : FCAI-0";
            cin >> id;
            Account_tyep(id,typ);
            if (typ == 1) {
                BankAccount A1;
                cout << "Enter amount you want to withdraw :";
                cin >> amount;
                A1.Withdraw(amount, id);
                cout << "------------------------------------------------------- \n";
            }
            if (typ == 2) {
                SavingsBankAccount A1;
                cout << "Enter amount you want to withdraw :";
                cin >> amount;
                A1.Withdraw(amount, id);
                cout << "------------------------------------------------------- \n";
            }
        }
        if (option == 4) {
            cout << "------------------------------------------------------- \n"
                 << "Enter your id : FCAI-0";
            cin >> id;
            Account_tyep(id,typ);
            if (typ == 1) {
                BankAccount A1;
                cout << "Enter amount you want to Deposit :";
                cin >> amount;
                A1.deposit(amount, id);
                cout << "------------------------------------------------------- \n";
            }
            if (typ == 2) {
                SavingsBankAccount A1;
                cout << "Enter amount you want to Deposit :";
                cin >> amount;
                A1.deposit(amount, id);
                cout << "------------------------------------------------------- \n";
            }
        }

        if (option == 5) {
            break;
        }
        cout << " Another Operation ? (y/n)" << endl;
        char option2;
        cin >> option2;
        if(option2 == 'y')
            continue;
        if(option2 == 'n')
            cout << "------- << thanks for your time :) >> -------" << endl;
        break;
    }
}


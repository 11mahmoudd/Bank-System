#include <iostream>

using namespace std;
#include "BankApplication.h"

int main()
{
    Client C1;
    int phoneNum, typ;
    double Balance;
    string name, address;
    int option;
    cin >> option;
    cin.ignore();
    if (option == 1) {
        cout << "Name: ";
        getline(cin, name);

        cout << "Address: ";
        getline(cin, address);

        cout << "Phone Number: ";
        cin >> phoneNum;

        cout << "Account Type: ";
        cin >> typ;

        cout << "Starting balance: ";
        cin >> Balance;

        C1.addClient(name, address, phoneNum, Balance, typ);
    }
    if (option == 2){
        cout << "Name: ";
        getline(cin, name);
        C1.client_data(name,typ);
    }
}

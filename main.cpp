#include <iostream>

using namespace std;
#include "BankApplication.h"

int main()
{
    BankApplication ob;
    int phoneNum, typ;
    double Balance;
    string name, address;

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

    ob.addClient(name, address, phoneNum, Balance, typ);
}

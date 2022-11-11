#include <iostream>
#include <fstream>
using namespace std;

#include "BankApplication.h"

BankApplication::BankApplication()
{

}

Client ::Client() {

}
void BankApplication::addClient(string Name, string addrs, int phnNum, double blnc, int typ){
    int lines = 0;
    string line;

    if (typ == 1){
        fstream infoFile("Basic.txt", ios_base::app | ios_base::out |ios_base::in);

        infoFile <<  Name << "\n";

        while (getline(infoFile, line)){
            lines++;
        }

        fstream clientInfo("Basic - " + Name + ".txt", ios::out);
        clientInfo << "Name : " <<Name   << "\n"
                   << "Address : " << addrs  << "\n"
                   << "Phone : " << phnNum << "\n"
                   << "Account Type : Saving Account" << "\n"
                   << "Balance : " << blnc   << "\n"
                   << "Account ID : FCAI" << "-00" << lines + 1 << "\n";
        clientInfo.close();
    }
    if (typ == 2){
        fstream infoFile("Saving.txt", ios_base::app | ios_base::out);
        infoFile << Name << "\n";

        while (getline(infoFile, line)){
            lines++;
        }

        fstream clientInfo("Saving - " + Name +".txt", ios::out);
        clientInfo << "Name : " <<Name   << "\n"
                   << "Address : " << addrs  << "\n"
                   << "Phone : " << phnNum << "\n"
                   << "Account Type : Saving Account" << "\n"
                   << "Balance : " << blnc   << "\n"
                   << "FCAI" << "-00" << lines + 1 << "\n";
        clientInfo.close();
    }
}

void Client::client_data(string& name,int typ) {
    fstream file;
    string line;
    file.open("Basic.txt", ios::in);
    while (getline(file, line)) {
        if (line == name) {
            fstream clientInfo;
            clientInfo.open("Basic - " + name + ".txt", ios::in);
            while (getline(clientInfo, line)) {
                cout << line << endl;
            }
            break;
        }
        fstream file2;
        string line2;
        file2.open("Saving.txt", ios::in);
        while (getline(file2, line2)) {
            if (line2 == name) {
                fstream clientInfo;
                clientInfo.open("Saving - " + name + ".txt", ios::in);
                while (getline(clientInfo, line2)) {
                    cout << line2 << endl;
                }
                break;
            }
        }
    }
}
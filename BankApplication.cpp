#include <iostream>
#include <fstream>
using namespace std;

#include "BankApplication.h"

BankApplication::BankApplication()
{

}

void BankApplication::addClient(string Name, string addrs, int phnNum, double blnc, int typ){
    int lines = 0;
    string line;

    if (typ == 1){
        fstream infoFile("Basic.txt", ios_base::app | ios_base::out);

        infoFile << "\n" <<  Name << endl;

        while (getline(infoFile, line)){
            lines++;
        }

        fstream clientInfo("Basic - " + Name + ".txt", ios::out);
        clientInfo << Name   << "\n"
                 << addrs  << "\n"
                 << phnNum << "\n"
                 << blnc   << "\n"
                 << "FCAI" << "-" << lines + 1 << "\n";
        clientInfo.close();
    }
    if (typ == 2){
        fstream infoFile("Basic.txt", ios_base::app | ios_base::out);
        infoFile << "\n" << Name << endl;

        while (getline(infoFile, line)){
            lines++;
        }

        fstream clientInfo("Saving - " + Name +".txt", ios::out);
        clientInfo << Name   << "\n"
                 << addrs  << "\n"
                 << phnNum << "\n"
                 << blnc   << "\n"
                 << "FCAI" << "-" << lines + 1 << "\n";
        clientInfo.close();
    }
}

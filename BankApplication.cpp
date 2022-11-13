#include <iostream>
#include <fstream>
using namespace std;

#include "BankApplication.h"

BankApplication::BankApplication()
{

}

BankAccount :: BankAccount()
{
    accountID="";
    balance=0;
}


BankAccount:: BankAccount(string id, double bal)
{
    accountID = id;
    balance = bal;
}

double BankAccount:: setbalance(double num)
{
    cin>>num;
    if(num>=0)
    {
        balance=num;
    }
    else
    {
        cout<<endl<<"Wrong input"<<endl;
    }

}

double BankAccount:: getbalance()
{
    return balance;
}

string BankAccount :: getID()
{
    return accountID;
}


double BankAccount :: Withdraw(double amount, string name)
{
    const int LINE = 5;
    fstream clientInfo("Basic - " + name + ".txt", ios::in);
    fstream clientclone;
    clientclone.open("temp.txt",ios::out);
    string line,temp,remain;
    for (int i = 1; i <= LINE; i++)
    {
        getline(clientInfo, line);
    }
    clientInfo.close();
    balance=stod(line);
    cout<<"Please Enter account name : ";
    cin>>name;
    cout<<"Please Enter The Amount to Withdraw : ";
    cin>>amount;
    if(amount <= balance)
    {
        remain=to_string(balance-amount);
        clientInfo.open("Basic - " + name + ".txt", ios::in);
        while (!clientInfo.eof())
        {
            getline(clientInfo,temp);
            cout<<temp<<endl;
            if (temp==line)
            {
                temp.replace(temp.find(line), line.length(), remain);
                cout<<temp<<endl;
            }
            clientclone<<temp<<endl;
        }
        clientclone.close();
        clientInfo.close();
        string filename="Basic - " + name + ".txt";
        remove( filename.c_str());
        rename("temp.txt",filename.c_str());
        cout<<"New Balance : ";
        return balance-=amount;
    }
    else
    {
        cout<<"Sorry. This is more than what you can withdraw \n ";
    }

}

double BankAccount :: deposit(double amount,string name)
{
    const int LINE = 5;
    fstream clientInfo("Basic - " + name + ".txt", ios::in);
    fstream clientclone;
    clientclone.open("temp.txt",ios::out);
    string line,temp,remain;
    for (int i = 1; i <= LINE; i++)
    {
        getline(clientInfo, line);
    }
    clientInfo.close();
    balance=stod(line);
    cout<<"Please Enter account name : ";
    cin>>name;
    cout<<"Please Enter The Amount to deposit : ";
    cin>>amount;
    remain=to_string(balance+=amount);
    clientInfo.open("Basic - " + name + ".txt", ios::in);
    while (!clientInfo.eof())
    {
        getline(clientInfo,temp);
        cout<<temp<<endl;
        if (temp==line)
        {
            temp.replace(temp.find(line), line.length(), remain);
            cout<<temp<<endl;
        }
        clientclone<<temp<<endl;
    }
    clientclone.close();
    clientInfo.close();
    string filename="Basic - " + name + ".txt";
    remove( filename.c_str());
    rename("temp.txt",filename.c_str());
    cout<<"New Balance : ";
    return balance+=amount;

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
        clientInfo  << "Name : " <<Name   << "\n"
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

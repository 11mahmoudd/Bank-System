#include <iostream>
#include <fstream>
using namespace std;

#include "BankApplication.h"

BankApplication::BankApplication()
{

}

BankAccount :: BankAccount()
{
    accountID = "";
    balance = 0;
}


BankAccount:: BankAccount(string id, double bal)
{
    accountID = id;
    balance = bal;
}

double BankAccount:: setbalance(double num)
{
    cin>>num;
    if(num >= 0)
    {
        balance = num;
    }
    else
    {
        cout << endl <<"Wrong input" << endl;
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


double BankAccount :: Withdraw(double amount, string id)
{
    const int LINE = 5;
    fstream clientInfo(id + ".txt", ios::in);
    fstream clientclone;
    clientclone.open("temp.txt",ios::out);
    string line,temp,remain;
    for (int i = 1; i <= LINE; i++)
    {
        getline(clientInfo, line);
    }
    clientInfo.close();
    balance=stod(line);

    if(amount <= balance)
    {
        remain = to_string(balance-amount);
        clientInfo.open(id + ".txt", ios::in);
        while (!clientInfo.eof())
        {
            getline(clientInfo,temp);
            cout << temp << endl;
            if (temp == line)
            {
                temp.replace(temp.find(line), line.length(), remain);
                cout << temp << endl;
            }
            clientclone << temp << endl;
        }
        clientclone.close();
        clientInfo.close();
        string filename = id  + ".txt";
        remove( filename.c_str());
        rename("temp.txt",filename.c_str());
        cout<<"New Balance : ";
        return balance -= amount;
    }
    else
    {
        cout <<"Sorry. This is more than what you can withdraw" << endl;
    }

}

double BankAccount :: deposit(double amount,string id)
{
    const int LINE = 5;
    fstream clientInfo(id + ".txt", ios::in);
    fstream clientclone;
    clientclone.open("temp.txt",ios::out);
    string line, temp, remain;
    for (int i = 1; i <= LINE; i++)
    {
        getline(clientInfo, line);
    }
    clientInfo.close();
    balance=stod(line);

    remain=to_string(balance += amount);
    clientInfo.open(id + ".txt", ios::in);
    while (!clientInfo.eof())
    {
        getline(clientInfo,temp);
        cout << temp << endl;
        if (temp == line)
        {
            temp.replace(temp.find(line), line.length(), remain);
            cout << temp << endl;
        }
        clientclone << temp << endl;
    }
    clientclone.close();
    clientInfo.close();
    string filename = id + ".txt";
    remove( filename.c_str());
    rename("temp.txt",filename.c_str());
    cout << "New Balance : ";
    return balance += amount;

}

Client ::Client() {

}
void BankApplication::addClient(string Name, string addrs, int phnNum, double blnc, int typ){
    int lines;
    string line;

    ifstream infoFile("Accounts.txt");
    while (getline(infoFile, line)){
        lines++;
    }
    lines++;
    infoFile.close();
    if (typ == 1){
        fstream Basicfile("Basic.txt", ios::app | ios::out |ios::in);

        ofstream infoFile("Accounts.txt", ios::app);
        infoFile << "FCAI-0" << lines << "\n";
        Basicfile << "FCAI-0" << lines << "\n";

        fstream clientInfo("FCAI-0" + to_string(lines) + ".txt", ios::out);
        clientInfo  << "Name : " << Name << "\n"
                    << "Address : " << addrs  << "\n"
                    << "Phone : " << phnNum << "\n"
                    << "Account Type : Basic Account" << "\n"
                    << "Balance : " << blnc << "\n"
                    << "Account ID : FCAI-0" << lines << "\n";
        clientInfo.close();
        Basicfile.close();
        infoFile.close();
    }
    if (typ == 2){
        fstream Savingfile("Saving.txt", ios::app | ios::out |ios::in);
        ofstream infoFile("Accounts.txt", ios::app);
        infoFile << "FCAI-0" << lines << "\n";
        Savingfile << "FCAI-0" << lines << "\n";

        fstream clientInfo("FCAI-0" + to_string(lines) + ".txt", ios::out);
        clientInfo  << "Name : " <<Name   << "\n"
                    << "Address : " << addrs  << "\n"
                    << "Phone : " << phnNum << "\n"
                    << "Account Type : Saving Account" << "\n"
                    << "Balance : " << blnc   << "\n"
                    << "Account ID : FCAI-0" << lines << "\n";
        clientInfo.close();
        Savingfile.close();
        infoFile.close();
    }
}

void Client::client_data(string& id) {
    fstream file;
    string line;
    file.open("Accounts.txt", ios::in);
    while (getline(file, line)) {
        if (line == "FCAI-0" + id) {
            fstream clientInfo;
            clientInfo.open(id + ".txt", ios::in);
            while (getline(clientInfo, line)) {
                cout << line << endl;
            }
            break;
        }
    }
}

SavingsBankAccount :: SavingsBankAccount()
{
    balance = minimumBalance;
}

double SavingsBankAccount :: Withdraw(double amount, string id)
{
    const int LINE = 5;
    fstream clientInfo(id + ".txt", ios::in);
    fstream clientclone;
    clientclone.open("temp.txt",ios::out);
    string line,temp,remain;
    for (int i = 1; i <= LINE; i++)
    {
        getline(clientInfo, line);
    }
    clientInfo.close();
    balance=stod(line);
    if (amount >= minimumBalance){
        if(amount <= balance)
        {
            remain = to_string(balance-amount);
            clientInfo.open(id + ".txt", ios::in);
            while (!clientInfo.eof())
            {
                getline(clientInfo,temp);
                cout << temp << endl;
                if (temp == line)
                {
                    temp.replace(temp.find(line), line.length(), remain);
                    cout << temp << endl;
                }
                clientclone << temp << endl;
            }
            clientclone.close();
            clientInfo.close();
            string filename = id  + ".txt";
            remove( filename.c_str());
            rename("temp.txt",filename.c_str());
            cout<<"New Balance : ";
            return balance -= amount;
        }
        else
        {
            cout <<"Sorry. This is more than what you can withdraw" << endl;
        }
    }
    else {
        cout << "Sorry. You can't withdraw less than the minimum balance" << endl;
    }

}

double SavingsBankAccount ::deposit(double amount, string id)
{
    const int LINE = 5;
    if (amount >= 100){
        fstream clientInfo(id + ".txt", ios::in);
        fstream clientclone;
        clientclone.open("temp.txt",ios::out);
        string line, temp, remain;
        for (int i = 1; i <= LINE; i++)
        {
            getline(clientInfo, line);
        }
        clientInfo.close();
        balance=stod(line);

        remain=to_string(balance += amount);
        clientInfo.open(id + ".txt", ios::in);
        while (!clientInfo.eof())
        {
            getline(clientInfo,temp);
            cout << temp << endl;
            if (temp == line)
            {
                temp.replace(temp.find(line), line.length(), remain);
                cout << temp << endl;
            }
            clientclone << temp << endl;
        }
        clientclone.close();
        clientInfo.close();
        string filename = id + ".txt";
        remove( filename.c_str());
        rename("temp.txt",filename.c_str());
        cout << "New Balance : ";
        return balance += amount;
    }
    else {
        cout << "Sorry. You can't deposit less than 100" << endl;
    }

}

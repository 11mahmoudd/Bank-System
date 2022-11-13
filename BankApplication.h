//
// Created by Malik on 11/10/2022.
//

#ifndef BANKAPPLICATION_BANKAPPLICATION_H
#define BANKAPPLICATION_BANKAPPLICATION_H

#include <string>

using namespace std;

class BankApplication {
private:
    string Name;
    string addrs;
    int phnNum;
    double blnc;
public:
    BankApplication();
    void addClient(string Name, string addrs, int phnNum, double blnc, int typ);
};

class Client : public BankApplication{
public:
    Client();
    void client_data(string &name,int typ);
};

class BankAccount : public BankApplication{
private:
    string accountID;
    double balance;
public:
    BankAccount();
    BankAccount(string id, double bal);
    double setbalance(double num);
    double getbalance();
    string getID();
    double Withdraw(double amount, string name);
    double deposit(double amount,string name);
};

class SavingsBankAccount : public BankAccount{
private:
    double minimumBalance;
public:
    SavingsBankAccount();
    int Withdraw(double amount);
    int deposit(double amount);
};

#endif //BANKAPPLICATION_BANKAPPLICATION_H


#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "accountsfile.h"
#include "transactionsfile.h"
#include<string>
using namespace std;
class Account
{
    accountsFile *af = new accountsFile;
    transactionsFile *tf = new transactionsFile;
protected:
    char accType[20];
    string name;
    string accNumber;
    string residentialAddress;
public:
    virtual void createAccount();
    void removeAccount();
    void editAccountDetails();
    void displayAccountDetails();
    void printMiniStatement();
};

#endif // ACCOUNT_H

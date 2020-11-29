#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H
#include "account.h"
#include "accountsfile.h"
#include "transactionsfile.h"

class currentAccount : public Account
{
private:
    static const float minimumBalance=5000;
    float balance;
    float withdrawAmt;
    float depositAmt;
    static const float interestRate=0;
    accountsFile *af = new accountsFile;
    transactionsFile *tf = new transactionsFile;

public:

    void createAccount();
    void withdraw(string);
    void deposit(string);
    void transferAmount(string,string);


};

#endif // CURRENTACCOUNT_H

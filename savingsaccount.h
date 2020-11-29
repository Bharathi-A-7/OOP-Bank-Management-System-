#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "account.h"


class savingsAccount : public Account
{
private :
    accountsFile *af=new accountsFile;
    float balance;
    float withdrawAmt;
    float depositAmt;
    float interestRate;
public:
    savingsAccount()
    {
        interestRate =5.5;
    }

    void createAccount();
    void withdraw(string);
    void deposit(string);
    void depositLoan(float);
    void transferAmount(string,string);
    void displayAccountDetails();
};

#endif // SAVINGSACCOUNT_H

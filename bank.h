#ifndef BANK_H
#define BANK_H
#include "account.h"
#include "accountsfile.h"
#include "transactionsfile.h"
#include "transaction.h"

class Bank
{
private:
    Account *A = new Account;
    accountsFile *af=new accountsFile;
    transaction *T = new transaction;
    char name[20];
    char city[20];
public:
    void manageAccounts(char);
    void seekLoan();
    void performTransactions(char);

};

#endif // BANK_H

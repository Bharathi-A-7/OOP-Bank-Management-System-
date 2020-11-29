#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "transactionsfile.h"
#include "accountsfile.h"
#include<sys/time.h>
#include<ctime>

class transaction
{
private:
    accountsFile *af = new accountsFile;
    char transactionType[20];
    string DateAndTime[90];
    float transactAmt;
    transactionsFile *tf = new transactionsFile;
public:
    void setDateAndTime();
    void getDateAndTime();
    void withdraw();
    void deposit();
    void depositLoan(float, string);
    void transfer();

};

#endif // TRANSACTION_H

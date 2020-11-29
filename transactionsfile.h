#ifndef TRANSACTIONSFILE_H
#define TRANSACTIONSFILE_H
#include<string>
#include <fstream>
#include <sstream>
#include <vector>
#include "functions.h"

using namespace std;

class transactionsFile
{
    string accNumber;
    string DateAndTime;
    char transactionType[20];
    float Amount;
    float Balance;
    ofstream outfile;

    functions *f=new functions;

public:
    void addTransaction(string accNum,char transactionType[],float transactAmt,float bal, string transDescription);
    int  numberOfWithdrawals(string accNum);
    int  numberOfTransactions(string accNum);
    void printMiniStatement(string accNum);
    void displayAllTransactions(string accNum);
    vector<string> getAllTransactions(string accNum);
    void printStatement(string accNum,int nrecords);

};

#endif // TRANSACTIONSFILE_H

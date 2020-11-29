#ifndef ACCOUNTSFILE_H
#define ACCOUNTSFILE_H
#include<string>
#include <fstream>
#include <sstream>
#include "functions.h"
#include "transactionsfile.h"

using namespace std;

class accountsFile
{
    string name;
    string accNumber;
    string residentialAddress;
    char accountType[20];
    float balance;
    ofstream outfile;

    transactionsFile *tf = new transactionsFile;
    functions *f=new functions;

public:
    void addAccount(string accNum,string name,string residentialAddress,float balance,char accType[]);
    void removeRecord(string accNum);
    float checkBalance(string accNum);
    char checkType(string accNum);
    void editDetails(string accNum);
    void editAccType(string accNum);
    void editAddress(string accNum);
    void editBalance(string accNum,float amount,char transactionType[]);
    void displayAccDetails(string accNum);
    string getAccoutDetail(string accNum);
    void editUpdate(string accNum, string field);

};

#endif // ACCOUNTSFILE_H

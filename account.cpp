#include "account.h"
#include<cstdlib>
#include "savingsaccount.h"
#include "currentaccount.h"
#include<iostream>
using namespace std;
// function to create a new account
void Account::createAccount()
{
    savingsAccount s;
    currentAccount c;
    string accType;
    cout<<"\n"<<" Enter the type of account you want to create : ( Savings / Current)";
    cin>>accType;
    if(accType=="Savings")
        s.createAccount();
    else if(accType=="Current")
        c.createAccount();
}
void Account::editAccountDetails()
{
    string  accNum;
    cout<<"\n"<<"Enter the number of the account whose details you want to edit :";
    cin>>accNum;
    af->editDetails(accNum);
}
void Account::removeAccount()
{
    char accNum[20];
    cout<<"\n"<<"\t\t Enter the number of the account you want to delete :\t\t";
    cin>>accNum;
    af->removeRecord(accNum);
}
void Account::printMiniStatement()
{
    string accNum;
    cout<<"\n"<<"\t\tEnter the account number to receive the mini statement :\t\t";
    cin>>accNum;
    tf->printMiniStatement(accNum);
}
void Account::displayAccountDetails()
{
    string accNum;
    cout<<"\n"<<"\t\t Enter the account number :\t\t";
    cin>>accNum;
    af->displayAccDetails(accNum);
}



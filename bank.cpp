#include "bank.h"
#include "account.h"
#include<iostream>
using namespace std;

void Bank::manageAccounts(char option)
{

    if(option=='c')
    {
        A->createAccount();
    }
    else if(option=='e')
    {
        A->editAccountDetails();
    }
    else if(option=='d')
    {
        A->removeAccount();
    }
    else if(option=='p')
    {
        A->displayAccountDetails();
    }
}
void Bank::seekLoan()
{

    string accNum;
    float avlBal;
    float loanAmt;
    cout<<"\n"<<" Enter the account number :";
    cin>>accNum;
    cout<<"\n"<<" Enter your required loan amount :";
    cin>>loanAmt;
    avlBal=af->checkBalance(accNum);
    if(avlBal==-1)
        return;

    if(avlBal <= 100000)
        cout<<" Sorry ! Your balance is too low to sanction loan ";
    else if(avlBal > 100000 && loanAmt < 2000000)
        T->depositLoan(loanAmt,accNum);
    else if (avlBal > 1000000 && loanAmt < 10000000)
        T->depositLoan(loanAmt,accNum);
    else if ( avlBal > 5000000)
        T->depositLoan(loanAmt,accNum);
    else
        cout<<"\n"<<"Sorry! Your loan amount is too large to be sanctioned";

}
void Bank::performTransactions(char option)
{
    if(option=='w')
        T->withdraw();
    else if(option=='d')
        T->deposit();
    else if(option=='t')
        T->transfer();
    else if(option=='p')
        A->printMiniStatement();

}

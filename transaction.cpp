#include "transaction.h"
#include "transactionsfile.h"
#include<ctime>
#include "strings.h"
#include<cstdlib>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
/*
void transaction::setDateAndTime()
{
    time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
  string str(buffer);
  cout<<str;
  strcpy(DateAndTime,str);
} */
/*
string transaction::getDateAndTime()
{
    return DateAndTime;
} */
void transaction::withdraw()
{
    strcpy(transactionType,"Debit");
    //setDateAndTime();
    float bal;
    string accNum;
    cout<<"\n"<<"\t\t Enter the Account Number :\t\t";
    cin>>accNum;
    if(af->checkType(accNum)=='s' && tf->numberOfWithdrawals(accNum)> 4)
    {
        cout<<"\n"<<"\t\t Sorry!  You are trying to exceed the withdrawal limit per month . No Withdrawals allowed !\t\t";
        return;
    }
label :
    cout<<"\n"<<" Enter the amount to be withdrawn :";
    cin>>transactAmt;
    bal = af->checkBalance(accNum);
    if(transactAmt > bal )
    {
        cout<<"\n"<<"\t\t Withdrawal amount cannot be greater than balance :\t\t";
        goto label;
    }
    else
    {
        af->editBalance(accNum,transactAmt,transactionType);
        bal=af->checkBalance(accNum);
        tf->addTransaction(accNum,transactionType,transactAmt,bal,"Withdraw");
    }
    cout<<"\n"<<"\t\t AMOUNT WITHDRAWN "<< transactAmt <<"\t\t";
}
void transaction::deposit()
{
    strcpy(transactionType,"Credit");
    //setDateAndTime();
    float bal;
    string accNum;
    cout<<"\n"<<"\t\t Enter the account number :\t\t";
    cin>>accNum;
    string line=af->getAccoutDetail(accNum);
    if(line=="")
    {

        cout << "Account Number Not Exist";
        return;
    }

    cout<<"\n"<<"\t\t Enter the amount to be deposited :\t\t";
    cin>>transactAmt;
    af->editBalance(accNum,transactAmt,transactionType);
    bal=af->checkBalance(accNum);
    tf->addTransaction(accNum,transactionType,transactAmt,bal,"Deposit");
    cout<<"\n"<<"\t\t AMOUNT DEPOSITED "<< transactAmt <<"\t\t";
}
void transaction::transfer()
{
    string accNum1;
    string accNum2;
    char type1[] ="Debit";
    char type2[] = "Credit";
    strcpy(transactionType,"Transfer");
    //setDateAndTime();
    float bal1,bal2;
    char facc,tacc;
label1:
    cout<<"\n"<<"\t\t Enter the Account Number :";
    cin>>accNum1;
    facc=af->checkType(accNum1);
    if(facc==' ')
        goto label1;
label2:
    cout<<"\n"<<"\t\t Enter the Account Number to transfer money to :";
    cin>>accNum2;
    tacc=af->checkType(accNum2);
    if(tacc==' ')
        goto label2;

    if(facc=='c' && tacc=='c')
    {
        cout<<"\n"<<"Enter the amount to be transacted :\t\t";
        cin>>transactAmt;
        af->editBalance(accNum1,transactAmt,type1);
        af->editBalance(accNum2,transactAmt,type2);
        bal1=af->checkBalance(accNum1);
        bal2=af->checkBalance(accNum2);
        if(bal1==-1 || bal2==-1)
            return;
        tf->addTransaction(accNum1,type1,transactAmt,bal1,"Money Transfer to " + accNum2);
        tf->addTransaction(accNum2,type2,transactAmt,bal2,"Money Transfer from " + accNum1);
    }
    else if(facc=='s' || facc=='s')
        cout<<"\n"<<"\t\t Sorry! No Transaction is allowed from/to Savings Accounts \t\t";


}
void transaction::depositLoan(float loanAmt,string accNum)
{
    strcpy(transactionType,"Credit");
    //setDateAndTime();
    float bal;
    transactAmt=loanAmt;
    af->editBalance(accNum,transactAmt,transactionType);
    bal=af->checkBalance(accNum);
    tf->addTransaction(accNum,transactionType,transactAmt,bal,"Loan Amount");
}


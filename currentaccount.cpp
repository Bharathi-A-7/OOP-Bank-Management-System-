#include "currentaccount.h"
#include "transactionsfile.h"
#include "accountsfile.h"
#include<cstdlib>
#include<time.h>
#include <string>
#include<iostream>
#include "string.h"
#include<ctime>
using namespace std;
void currentAccount::createAccount()
{
    stringstream ss;
    srand (time (NULL));
    long int randNum, randMax=30000000, randMin=1000000;
    ss << rand () % (randMax - randMin) + randMin;
    accNumber = ss.str();
    cout<<"\n"<<"\t\t Enter the name of the account holder :\t\t";
    cin.ignore();
    getline(cin,name);
    //cin>>name;
    cout<<"\n"<<"\t\t Enter the residential address [ Format : doorNo,streetName,City]\t\t";
    getline(cin,residentialAddress);
label:
    cout<<"\n"<<"\t\t Enter the initial balance amount :";
    cin>>balance;
    if(balance < minimumBalance)
    {
        cout<<"\n"<<"\t\t Initial balance amount cannot be less than the minimum balance for current account :";
        cout<<"\n Minimum Balance is :"<<minimumBalance;
        goto label;
    }
    strcpy(accType,"Current");
    af->addAccount(accNumber,name,residentialAddress,balance,accType);
    cout<<"\n"<<"\t\t ACCOUNT SUCCESSFULLY CREATED \t\t";
}




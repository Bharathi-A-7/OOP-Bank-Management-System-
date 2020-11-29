#include "savingsaccount.h"
#include "accountsfile.h"
#include "transactionsfile.h"
#include<cstdlib>
#include<time.h>
#include <string>
#include<iostream>
#include "string.h"
#include<sstream>


using namespace std;
void savingsAccount::createAccount()
{
    stringstream ss;

    srand (time (NULL));
    static long int randNum, randMax=30000000, randMin=1000000;
    ss << rand () % (randMax - randMin) + randMin;
    accNumber = ss.str();
    cout<<"\n"<<"\t\t Enter the name of the account holder :\t\t";
    cin.ignore();
    getline(cin,name);
    //cin>>name;
    cout<<"\n"<<"\t\t Enter the residential address [ Format : doorNo,streetName,City]\t\t";
    getline(cin,residentialAddress);
    cout<<"\n"<<"\t\t Enter the initial balance amount :";
    cin>>balance;
    strcpy(accType,"Savings");
    af->addAccount(accNumber,name,residentialAddress,balance,accType);
    cout<<"\n"<<"\t\t ACCOUNT SUCCESSFULLY CREATED \t\t";

}



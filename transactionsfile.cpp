#include "transactionsfile.h"
#include<iostream>
#include "accountsfile.h"
using namespace std;

void transactionsFile::addTransaction(string accNum,char transactionType[],float transactAmt,float bal, string transDescription)
{


    outfile.open("Transactions.txt",ios_base::app);
    outfile << accNum << "\t" << f->date() << "\t" <<transDescription << "\t" << transactionType << "\t" <<std:: fixed <<std::setprecision(2) << transactAmt << "\t" <<bal  <<endl;
    outfile.close();
}
int  transactionsFile::numberOfWithdrawals(string accNum)
{
    vector<string> data;
    data=getAllTransactions(accNum);
    int nowithdraw=0;
    int looper;
    string sline;
    string record[6];
    for (looper = 0; looper < (int) data.size(); looper++)
    {
        istringstream sline(data[looper]);

        for(int i=0; i<6; i++)
            getline(sline,record[i],'\t');
        if(record[3]=="Debit")
            nowithdraw++;
    }

    return nowithdraw;
}
int  transactionsFile::numberOfTransactions(string accNum)
{
    vector<string> data;
    data=getAllTransactions(accNum);

    return data.size();
}

void transactionsFile::printMiniStatement(string accNum)
{
    printStatement(accNum,10);
}

void transactionsFile::displayAllTransactions(string accNum)
{
    printStatement(accNum,0);

}

void transactionsFile::printStatement(string accNum,int nrecords)
{
    cout<<"\n\n";

    if(nrecords==0)
        cout<<"\t\t\t\t\t\tAccount Statement";
    else
        cout<<"\t\t\t\t\t\tMini Statement";

    cout<<endl;
    cout<<endl;

    accountsFile *af=new accountsFile;

    af->displayAccDetails(accNum);

    for(int i=0; i<110; i++)
        cout<<"-";
    cout<<endl;

    cout<<"Date" <<"\t\t" << "Description"  <<std::setw(32) << "Deposit Amt"  <<std::setw(22) << "Withdrawal Amt"  <<std::setw(22) << "Closing Balance" << "\n";
    for(int i=0; i<110; i++)
        cout<<"-";
    cout<<endl;

    vector<string> data;
    data=getAllTransactions(accNum);
    int looper;
    string sline;
    string record[6];
    int stval=0;
    if(nrecords>0 && (int) data.size()>nrecords)
        stval=(int) data.size()-nrecords;

    for (looper = stval; looper < (int) data.size(); looper++)
    {
        istringstream sline(data[looper]);

        for(int i=0; i<6; i++)
            getline(sline,record[i],'\t');

        float amt,bamt;
        stringstream ss,ss1;
        ss<<record[4];
        ss>>amt;

        ss1<<record[5];
        ss1>>bamt;
        int descwidth;
        if(record[3]=="Credit")
        {

            descwidth=record[2].length();
            descwidth=44-descwidth;

            cout<<record[1] <<"\t" << record[2] << std::fixed << std::setprecision(2) <<std::setw(descwidth) << amt  <<std::setw(40) << bamt << "\n";
        }
        else
        {

            descwidth=record[2].length();
            descwidth=64-descwidth;

            cout<<record[1] <<"\t" << record[2] << std::fixed << std::setprecision(2) <<std::setw(descwidth) << amt <<std::setw(20) << bamt <<"\n";
        }

    }
}

vector<string> transactionsFile::getAllTransactions(string accNum)
{
    fstream fin;
    fin.open("Transactions.txt");
    string line;
    string acNumber;
    vector<string> data;
    while(getline(fin,line))
    {
        istringstream sline(line);
        getline(sline,acNumber,'\t');
        if(acNumber==accNum)
        {
            data.push_back(line);
        }

    }
    fin.close();
    return data;
}

#include "accountsfile.h"
#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>

using namespace std;

void accountsFile::addAccount(string accNum,string name,string residentialAddress,float balance,char accType[])
{


    outfile.open("Accounts.txt",ios_base::app);
    outfile << accNum << "\t" << name << "\t" << residentialAddress << "\t" <<std::fixed << std::setprecision(2)<< balance << "\t" <<accType << "\t" << f->date() <<endl;
    outfile.close();

    tf->addTransaction(accNum,"Credit",balance,balance,"Initial Amount");
}
void accountsFile::removeRecord(string accNum)
{

    fstream fin;
    fin.open("Accounts.txt");
    string line;
    string acNumber;
    vector<string> data;
    bool exist=false;
    while(getline(fin,line))
    {
        istringstream sline(line);
        getline(sline,acNumber,'\t');
        if(acNumber==accNum)
        {
            exist=true;
        }
        else
        {
            data.push_back(line);
        }

    }
    fin.close();
    if(exist==false)
    {
        cout<<"Account Number Not Available";
        return;
    }

    ofstream myFile;
    myFile.open("Accounts.txt");
    int looper;
    for (looper = 0; looper < (int) data.size(); looper++)
    {
        myFile << data[looper] << endl;
    }
    myFile.close();
}
float accountsFile::checkBalance(string accNum)
{
    string acNumber;
    string line=getAccoutDetail(accNum);
    if(line!="")
    {
        istringstream sline(line);
        for(int i=0; i<4; i++)
            getline(sline,acNumber,'\t');

        stringstream ss;
        float balance;
        ss<<acNumber;
        ss>>balance;
        return  balance;

    }

    cout<<"Account Not Exist";
    return -1;
}
char accountsFile::checkType(string accNum)
{
    string acNumber;
    string line=getAccoutDetail(accNum);
    if(line!="")
    {
        istringstream sline(line);
        for(int i=0; i<5; i++)
            getline(sline,acNumber,'\t');

        if(acNumber=="Savings")
            return  's';
        else
            return 'c';
    }
    cout<<"Account Not Exist";
    return ' ';
}

void accountsFile::editDetails(string accNum)
{
    editUpdate(accNum,"Name");
}
void accountsFile::editAccType(string accNum)
{
    editUpdate(accNum,"AccType");
}
void accountsFile::editAddress(string accNum)
{
    editUpdate(accNum,"Address");
}

void accountsFile::editUpdate(string accNum, string field)
{

    fstream fin;
    fin.open("Accounts.txt");
    string line;
    string acNumber;
    vector<string> data;
    string newval;
    string record[6];
    while(getline(fin,line))
    {
        istringstream sline(line);
        getline(sline,acNumber,'\t');
        if(acNumber==accNum)
        {
            record[0]=acNumber;
            for(int i=1; i<6; i++)
                getline(sline,record[i],'\t');

            if(field=="Name")
                cout<<"Enter the New Name:\t";
            else if(field=="Address")
                cout<<"Enter the New Address:\t";
            else if(field=="AccType")
                cout<<"Enter the Account Type(Savings/Current):\t";
label:
            //cin.ignore();

            getline(cin,newval);
            if(newval=="")
                goto label;

            if(field=="AccType")
            {
                if(newval!="Savings" && newval!="Current")
                {
                    cout<<"Invalid Account Type\n Please Re-enter the Account Type(Savings/Current):\t";
                    goto label;
                }
                record[4]=newval;
            }
            else if(field=="Name")
                record[1]=newval;
            else if(field=="Address")
                record[2]=newval;

            data.push_back(record[0]+"\t"+record[1]+"\t"+record[2]+"\t"+record[3]+"\t"+record[4]+"\t"+record[5]);
        }
        else
        {
            data.push_back(line);
        }

    }
    fin.close();

    ofstream myFile;
    myFile.open("Accounts.txt");
    int looper;
    for (looper = 0; looper < (int) data.size(); looper++)
    {
        myFile << data[looper] << endl;
    }
    myFile.close();


}

void accountsFile::editBalance(string accNum,float amount,char transactionType[])
{

    string ttype=transactionType;

    fstream fin;
    fin.open("Accounts.txt");
    string line;
    string acNumber;
    vector<string> data;
    bool exist=false;
    while(getline(fin,line))
    {
        istringstream sline(line);
        getline(sline,acNumber,'\t');
        if(acNumber==accNum)
        {
            string record[10];
            record[0]=acNumber;

            for(int i=1; i<6; i++)
                getline(sline,record[i],'\t');

            stringstream ss;
            float balance;
            ss<<record[3];
            ss>>balance;
            if(ttype=="Credit")
                balance+=amount;
            else
                balance-=amount;


            ostringstream ss1;
            ss1<<std::fixed << std::setprecision(2)<< balance;
            record[3]=ss1.str();

            data.push_back(record[0]+"\t"+record[1]+"\t"+record[2]+"\t"+record[3]+"\t"+record[4]+"\t"+record[5]);
        }
        else
        {
            data.push_back(line);
        }

    }
    fin.close();

    ofstream myFile;
    myFile.open("Accounts.txt");
    int looper;
    for (looper = 0; looper < (int) data.size(); looper++)
    {
        myFile << data[looper] << endl;
    }
    myFile.close();


}

void accountsFile::displayAccDetails(string accNum)
{

    string line=getAccoutDetail(accNum);
    string record[6];
    if(line!="")
    {
        istringstream sline(line);
        for(int i=0; i<6; i++)
            getline(sline,record[i],'\t');

        cout<<"\nAccount Number \t\t: "<<record[0] << endl;
        cout<<"Name  \t\t\t: "<<record[1] << endl;
        cout<<"Residential Address \t: "<<record[2] << endl;
        cout<<"Account Type \t\t: "<<record[4] << endl;
        cout << "Account Opening Date \t: "<<record[5] << endl;
        cout << "Account Balance \t: "<<record[3] << endl << endl;

        return;
    }

    cout<<"Account Not Exist";

}
string accountsFile::getAccoutDetail(string accNum)
{
    fstream fin;
    fin.open("Accounts.txt");
    string line;
    string acNumber;
    while(getline(fin,line))
    {
        istringstream sline(line);
        getline(sline,acNumber,'\t');
        if(acNumber==accNum)
        {
            fin.close();
            return line;

        }

    }
    fin.close();
    return "";
}

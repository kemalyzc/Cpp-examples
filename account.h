#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#define MIN_BALANCE 250

using namespace std;

//class InsufficientFunds{};

class Account
{
private:
        long accountNumber;
        string firstName;
        string lastName;
        float balance;
        static long NextAccountNumber;
    public:
        Account(){}
        Account(string fname,string lname,float balance);
        long getAccNo(){return accountNumber;}
        string getFirstName(){return firstName;}
        string getLastName(){return lastName;}
        float getBalance(){return balance;}
        void Deposit(float amount);
        void Withdraw(float amount);
        static void setLastAccountNumber(long accountNumber);
        static long getLastAccountNumber();
    friend ofstream & operator<<(ofstream &ofs,Account &acc);
    friend ifstream & operator>>(ifstream &ifs,Account &acc);
    friend ostream & operator<<(ostream &os,Account &acc);
};

#endif // ACCOUNT_H

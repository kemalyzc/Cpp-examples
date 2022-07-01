#include "bank.h"
#include "account.h"

Bank::Bank() {
    Account account;
    ifstream infile;
    infile.open("Bank.data");
    if(!infile) {
    return;
}

while(!infile.eof()) {
    infile>>account;
    accounts.insert(pair<long,Account>(account.getAccNo(),account));
    }
    Account::setLastAccountNumber(account.getAccNo());
    infile.close();
}

Account Bank::OpenAccount(string fname,string lname,float balance) {
    ofstream outfile;
    Account account(fname,lname,balance);
    accounts.insert(pair<long,Account>(account.getAccNo(),account));
    outfile.open("Bank.data", ios::trunc);
    map<long,Account>::iterator itr;
    for(itr=accounts.begin();itr!=accounts.end();itr++)
    {
    outfile<<itr->second;
    }
    outfile.close();
    return account;
}

Account Bank::BalanceEnquiry(long accountNumber) {
    map<long,Account>::iterator itr=accounts.find(accountNumber);
    return itr->second;
}
Account Bank::Deposit(long accountNumber,float amount) {
    map<long,Account>::iterator itr=accounts.find(accountNumber);
    itr->second.Deposit(amount);
    return itr->second;
}

Account Bank::Withdraw(long accountNumber,float amount) {
    map<long,Account>::iterator itr=accounts.find(accountNumber);
    itr->second.Withdraw(amount);
    return itr->second;
}

void Bank::CloseAccount(long accountNumber) {
    map<long,Account>::iterator itr=accounts.find(accountNumber);
    cout<<"Account Deleted"<<itr->second;
    accounts.erase(accountNumber);
}

void Bank::ShowAllAccounts() {
    map<long,Account>::iterator itr;
    for(itr=accounts.begin();itr!=accounts.end();itr++)
{
cout<<"Account "<<itr->first<<endl<<itr->second<<endl;
}
}

Bank::~Bank() {
    ofstream outfile;
    outfile.open("Bank.data", ios::trunc);
    map<long,Account>::iterator itr;
    for(itr=accounts.begin();itr!=accounts.end();itr++) {
    outfile<<itr->second;
    }
    outfile.close();
}

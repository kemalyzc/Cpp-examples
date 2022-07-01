#include <iostream>
#include "account.h"
#include "bank.h"


using namespace std;

int main()
{
    Bank b;
        Account acc;
        int choice;
        string fname,lname;
        long accountNumber;
        float balance;
        float amount;
        cout<<"***Banking System***"<<endl;
    do {
        cout<<"\n\tSelect one option below ";
        cout<<"\n\t1 Open an Account";
        cout<<"\n\t2 Balance Enquiry";
        cout<<"\n\t3 Deposit";
        cout<<"\n\t4 Withdrawal";
        cout<<"\n\t5 Close an Account";
        cout<<"\n\t6 Show All Accounts";
        cout<<"\n\t7 Quit";
        cout<<"\nEnter your choice: ";
        cin>>choice;

    switch(choice)
    {
        case 1:
            cout<<"Enter First Name: ";
            cin>>fname;
            cout<<"Enter Last Name: ";
            cin>>lname;
            cout<<"Enter initil Balance: ";
            cin>>balance;
            acc=b.OpenAccount(fname,lname,balance);
            cout<<endl<<"Congratulations Account is Created"<<endl;
            cout<<acc;
            break;
        case 2:
            cout<<"Enter Account Number:";
            cin>>accountNumber;
            acc=b.BalanceEnquiry(accountNumber);
            cout<<endl<<"Your Account Details"<<endl;
            cout<<acc;
            break;
        case 3:
            cout<<"Enter Account Number:";
            cin>>accountNumber;
            cout<<"Enter Balance:";
            cin>>amount;
            acc=b.Deposit(accountNumber, amount);
            cout<<endl<<"Amount is Deposited"<<endl;
            cout<<acc;
            break;
        case 4:
            cout<<"Enter Account Number:";
            cin>>accountNumber;
            cout<<"Enter Balance:";
            cin>>amount;
            acc=b.Withdraw(accountNumber, amount);
            cout<<endl<<"Amount Withdrawn"<<endl;
            cout<<acc;
            break;
        case 5:
            cout<<"Enter Account Number:";
            cin>>accountNumber;
            b.CloseAccount(accountNumber);
            cout<<endl<<"Account is Closed"<<endl;
            cout<<acc;
        case 6:
            b.ShowAllAccounts();
            break;
        case 7: break;
                default:
            cout<<"\nEnter correct choice";
            exit(0);
    }
    }

        while(choice!=7);
        return 0;
}

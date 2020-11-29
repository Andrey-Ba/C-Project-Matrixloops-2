#include <stdio.h>
#include "myBank.h"

#define n 50

float accounts[n]={0};
char open_accounts[n]={0};

void openaccount(float amount)
{
    int i = 0;
    while (open_accounts[i]=='o')
    {
        i++;
    }
    if(i==50)
    {
        printf("Sorry, can't create an account because we are full!\n\n");
        return;
    }
    open_accounts[i]='o';
    accounts[i]=amount;
    printf("Your account number is: %d\n\n", 901+i);
}

void checkbalance(int account)
{
    if(open_accounts[account-901]!='o')
    {
        printf("Account number %d is closed!\n\n",account);
        return;
    }
    printf("The balance of account number %d is: %0.2f\n\n",account,accounts[account-901]);
}

void deposite(int account, float amount)
{
    if(open_accounts[account-901]!='o')
    {
        printf("Account number %d is closed!\n\n",account);
        return;
    }
    accounts[account-901] +=amount;
    printf("Your new balance is: %0.2f\n\n", accounts[account-901]);
}

void withdrawal(int account, float amount)
{
    if(open_accounts[account-901]!='o')
    {
        printf("Account number %d is closed!\n\n",account);
        return;
    }
    if(accounts[account-901]-amount<0)
    {
        printf("You don't have enough in your balance!\n\n");
        return;
    }
    accounts[account-901]-=amount;
    printf("Your new balance is: %0.2f\n\n",accounts[account-901]);
}

void closeaccount(int account)
{
    if(open_accounts[account-901]!='o')
    {
        printf("Account number %d is already closed!\n\n",account);
        return;
    }
    open_accounts[account-901]=0;
    printf("Your account has been closed\n\n");
}

void interest(int interest)
{
    for(int i=0;i<n;i++)
    {
        if(open_accounts[i]=='o')
        {
            accounts[i]=accounts[i]+(interest/100.0)*accounts[i];
        }
    }
    printf("Interest rate applied successfuly\n\n");
}

void print()
{
    for(int i=0;i<n;i++)
    {
        if(open_accounts[i]=='o')
        {
            printf("Account number %d with balance of: %0.2f\n",i+901,accounts[i]);
        }
    }
    printf(" \n");
}
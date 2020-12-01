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
    printf("New account number is: %d\n", 901+i);
}

void checkbalance(int account)
{
    if(open_accounts[account-901]!='o')
    {
        printf("This account is closed\n");
        return;
    }
    printf("The balance of account number %d is: %0.2f\n",account,accounts[account-901]);
}

void deposit(int account, float amount)
{
    if(open_accounts[account-901]!='o')
    {
        printf("This account is closed\n");
        return;
    }
    accounts[account-901] +=amount;
    printf("The new balance is: %0.2f\n", accounts[account-901]);
}

void withdrawal(int account, float amount)
{
    if(open_accounts[account-901]!='o')
    {
        printf("This account is closed\n");
        return;
    }
    if(accounts[account-901]-amount<0)
    {
        printf("Cannot withdraw more than the balance\n");
        return;
    }
    accounts[account-901]-=amount;
    printf("The new balance is: %0.2f\n",accounts[account-901]);
}

void closeaccount(int account)
{
    if(open_accounts[account-901]!='o')
    {
        printf("This account is already closed\n");
        return;
    }
    open_accounts[account-901]=0;
    printf("Closed account number %d\n",account);
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
}

void print()
{
    for(int i=0;i<n;i++)
    {
        if(open_accounts[i]=='o')
        {
            printf("The balance of account number %d is: %0.2f\n",i+901,accounts[i]);
        }
    }
}

int isclosed(int account)
{
    return open_accounts[account-901]!='o';
}
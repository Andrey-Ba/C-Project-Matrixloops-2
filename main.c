#include <stdio.h>
#include "myBank.h"

int main()
{
    char command;
    do
    {
        printf("Please choose a transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposit\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");
        scanf(" %c",&command);
        switch (command)
        {
        case 'O':
        {
            float amount;
            printf("Please insert amount to diposite:\n");
            if(scanf(" %f",&amount)<1)
            {
                printf("Failed to read ammount!\n\n");
                continue;
            }
            openaccount(amount);
        }
            break;
        case 'B':
        {
            printf("Please insert account number\n");
            int account=0;
            if(scanf(" %d",&account)<1)
            {
                printf("Failed to read account number\n\n");
                continue;
            }
            if(account<901 || account>950)
            {
                printf("False account number!\n\n");
                continue;
            }
            checkbalance(account);
        }
            break;
        case 'D':
        {
            printf("Please insert account number\n");
            int account=0;
            if(scanf(" %d",&account)<1)
            {
                printf("Failed to read account number\n\n");
                continue;
            }
            if(account<901 || account>950)
            {
                printf("False account number!\n\n");
                continue;
            }
            float amount;
            printf("Please insert amount to diposite:\n");
            if(scanf(" %f",&amount)<1)
            {
                printf("Failed to read ammount!\n\n");
                continue;
            }
            deposite(account,amount);
        }
            break;
        
        case 'W':
        {
            printf("Please insert account number\n");
            int account=0;
            if(scanf(" %d",&account)<1)
            {
                printf("Failed to read account number\n\n");
                continue;
            }
            if(account<901 || account>950)
            {
                printf("False account number!\n\n");
                continue;
            }
            float amount;
            printf("Please insert amount to diposite:\n");
            if(scanf(" %f",&amount)<1)
            {
                printf("Failed to read ammount!\n\n");
                continue;
            }
            withdrawal(account,amount);
        }
        break;
        
        case 'C':
        {
            printf("Please insert account number\n");
            int account=0;
            if(scanf(" %d",&account)<1)
            {
                printf("Failed to read account number\n\n");
                continue;
            }
            if(account<901 || account>950)
            {
                printf("False account number!\n\n");
                continue;
            }
            closeaccount(account);
        }
        break;

        case 'I':
        {
            int intr;
            if(scanf(" %d",&intr)<1)
            {
                printf("False interest rate!\n\n");
                continue;
            }
            interest(intr);
        }
        break;

        case 'P':
        {
            print();
        }
        break;
        case 'E':
        break;
        default:
        {
            printf("Invalid command!\n\n");
        }
            break;
        }
    } while (command!='E');
    return 0;
}
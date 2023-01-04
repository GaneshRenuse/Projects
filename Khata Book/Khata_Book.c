#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float currentsavings()
{
    int crrnt;
    FILE *fptr;
    fptr = fopen("crrntsave.txt", "r");

    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    fscanf(fptr, "%d", &crrnt);

    fclose(fptr);
    return crrnt;
}

void addmoney(int crrnt)
{
    FILE *fptr;
    fptr = fopen("crrntsave.txt", "w");

    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    int amount;
    printf("\n\t\tEnter amount : ");
    scanf("%d", &amount);
    amount += crrnt;

    fprintf(fptr, "%d", amount);
    fclose(fptr);
}

void wrt_expences(int crrnt)
{
    int n, amount;
    char str[10];
    FILE *fp;
    fp = fopen("expenses.txt", "a");

    if (fp == NULL)
    {
        printf("Error!");
        exit(1);
    }

    printf("\n\t\t--> Enter no. of Expenses : ");
    scanf("%d", &n);
    printf("\n\t\t--> Enter Expenses : ");

    for (int i = 0; i < n; i++)
    {
        printf("\n\t\t--> Amount : ");
        scanf("%d", &amount);
        printf("\t\t--> Enter reason : ");
        scanf("%s", str);

        fprintf(fp, "%d\t%s\n", amount, str);
        deduct_money(amount);
    }

    fclose(fp);
}

void show_expenses()
{
    int amount;
    char str[10];

    FILE *fp2;
    fp2 = fopen("expenses.txt", "r");

    if (fp2 == NULL)
    {
        printf("Error!");
        exit(1);
    }

    printf("\n\t\tAMOUNT\tNOTE\n");
    for (int i = 0; i < 3; i++)
    {
        fscanf(fp2, "%d%s", &amount, str);
        printf("\t\t%d\t%s\n", amount, str);
    }

    fclose(fp2);
}

void deduct_money(int x)
{
    int dec_amt = 0;
    FILE *fp3;

    dec_amt = currentsavings();
    dec_amt = dec_amt - x;
    
    fp3 = fopen("crrntsave.txt", "w");
    fprintf(fp3, "%d", dec_amt);

    fclose(fp3);
}

int main()
{
    int crrntsave;

    while (1)
    {
        crrntsave = currentsavings();
        int choice;

        printf("\n\t\t - - - - - - - - - - - - - \n");
        printf("\t\t        KHATA BOOK         \n");
        printf("\t\t - - - - - - - - - - - - - \n");
        printf("\t\t      1)Check Savings      \n");
        printf("\t\t      2)Add Money          \n");
        printf("\t\t      3)Write Expences     \n");
        printf("\t\t      4)Show Expences      \n");
        printf("\t\t      5)Exit               \n");
        printf("\t\t - - - - - - - - - - - - - \n");
        printf("\t\t Enter --> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n\t\t Your Current Savings are : %d\n", crrntsave);
            break;
        case 2:
            addmoney(crrntsave);
            break;
        case 3:
            wrt_expences(crrntsave);
            break;
        case 4:
            show_expenses();
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("\n\t\t Choose right option !!\n");
            break;
        }
    }

    return 0;
}

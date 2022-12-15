#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// create a structure to save books data
struct books
{
    int id;
    char *name;
} b[9];

void bookdetails(struct books[]);
void save_tofile(struct books[]);
void admin_login();
void student_login();

int main()
{
    // call bookdetails funtion to set book details
    bookdetails(b);

    int choice;

    while (1)
    {
        system("clr");
        printf("\n- - - - - AG LIBRARY - - - - -\n");
        printf("\t\t1] Admin Login\n");
        printf("\t\t2] Student Login\n");
        printf("\t\t3] Exit\n");
        printf("\t\tEnter --> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            admin_login();
            break;
        case 2:
            //student_login();
            break;
        case 3:
            exit(1);
            break;
        default:
            printf("\n\n");
            break;
        }
    }

    return 0;
}

void admin_login()
{
    int chk = 0;
    char pass[8] = "ad2022li";
    char chkpass[8];

    printf("Enter password : ");
    scanf("%s", chkpass);

    if (strcmp(chkpass, pass))
    {
        printf("access granted.\n");
        chk = 1;
    }
    else
    {
        printf("access denied.\n");
        chk = 0;
    }
}

void bookdetails(struct books b[9])
{
    // set book details
    for (int i = 0; i <= 9; i++)
    {
        b[i].id = i + 101;
    }

    b[0].name = "c++";
    b[1].name = "programming";
    b[2].name = "database";
    b[3].name = "softwareengg";
    b[4].name = "subtleart";
    b[5].name = "dsa";
    b[6].name = "algorithms";
    b[7].name = "java";
    b[8].name = "python";
    b[9].name = "javascript";
}

void save_tofile(struct books b[9])
{
    // open file using file pointer
    FILE *fptr;
    fptr = fopen("program.txt", "w");

    // if there is error in file opening it returns null
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    for (int i = 0; i < 10; i++)
    {
        // print book details to file
        fprintf(fptr, "%d\t%s\n", b[i].id, b[i].name);
    }

    // close file pointer.
    fclose(fptr);
}
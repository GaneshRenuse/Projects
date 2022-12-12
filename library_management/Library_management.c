#include <stdio.h>
#include <stdlib.h>

// store book data in file 

struct books
{
    int id;
    char* name;
}b[9];

void bookdetails(struct books[]);

int main()  
{
    FILE *fptr;
    fptr = fopen("C:\\program1\\program.txt","w");

    if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }

    bookdetails(b);

    for (int i = 0; i < 10; i++)
    {
        fprintf(fptr,"%d\t%s\n", b[i].id, b[i].name);
    }
    

    return 0;
}

void bookdetails(struct books b[9])
{
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
#include <stdio.h>
#include <stdlib.h>

// create a structure to save books data
struct books
{
    int id;
    char* name;
}b[9];

void bookdetails(struct books[]);

int main()  
{
    // open file using file pointer
    FILE *fptr;
    fptr = fopen("program.txt","w");

    //if there is error in file opening it returns null 
    if(fptr == NULL)
    {
      printf("Error!");   
      exit(1);             
    }

    // call bookdetails funtion to set book details
    bookdetails(b);

    for (int i = 0; i < 10; i++)
    {
        //print book details to file
        fprintf(fptr,"%d\t%s\n", b[i].id, b[i].name);
    }
    
    // close file pointer.
    fclose(fptr);

    return 0;
}

void bookdetails(struct books b[9])
{
    //set book details
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
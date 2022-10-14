#include<stdio.h>
#include<stdlib.h>

/*
Name: lab9-load-binary.c
Function: Main, getdata, printdata
Struct: Student
Parameters: argv, pointer to variable of type Student, pointer to file
Returns: Struct
Description:
- Opens file "studentBinary.bin"
- Reads data
- Prints data
Author: Martin Derwin
*/

typedef struct Student Student;

struct Student{
    char name[50];
    char college[50];
    int age;
    float grade;
};

void getdata(Student *pstudent, FILE *pfile); // reads data from file
void printdata(Student *pstudent); // displays data

int main()
{

    Student student;
    Student *pstudent = &student;

    FILE *pfile = NULL;  // file pointer
    char *fname = "studentBinary.bin"; // set file name to studnetBinary.bin

    pfile = fopen(fname, "rb"); //open the file with a binary mode
    if(!pfile) // check if it opened correctly
    {
        printf("Error opening %s. Program terminated.\n", fname);
        exit(1);
    }

    getdata(pstudent, pfile); // get the data from the file
    fclose(pfile); //close the file

    printdata(pstudent); // display the data

    return 0;
}

void getdata(Student *pstudent, FILE *pfile)
{
    int namelength; // length of student name
    int *pnl = &namelength;

    int collegelength; // length of college name
    int *pcl = &collegelength;

    //Read the data from binary file
    fread(pnl, sizeof(int), 1, pfile);
    fread(pstudent->name, sizeof(char), namelength, pfile);


    fread(pcl, sizeof(int), 1, pfile);
    fread(pstudent->college, sizeof(char), collegelength, pfile);

    fread(&pstudent->age, sizeof(int), 1, pfile);
    fread(&pstudent->grade, sizeof(float), 1, pfile);
}

void printdata(Student *pstudent)
{
    printf("Name: %s\n", pstudent->name);
    printf("College: %s\n", pstudent->college);
    printf("Age: %d\n", pstudent->age);
    printf("Grade: %.2f\n", pstudent->grade);
}
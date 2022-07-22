#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: lab7-student.c
Function: Main, add_student, print_student
Struct: Student
Parameters: arrays of strings and floats
Returns: struct
Description:
- Takes in arguments from command line, creates struct Student and adds two students to array of type Student
- If there are more than 2 students we reallocate memory for the number of students and add them to the array
- We print the student info line by line
Author: Martin Derwin
*/

typedef struct Student Student; //Define Student as a type name

struct Student //Structure type definition
{
    char name[20];
    char programme[20];
    float grade;
};

void add_student(Student *student, char *name, char *programme, float grade); //adds student info to array using struct
void print_student(Student *student); //prints student info

int main(int argc, char *argv[])
{
    Student *pStudent;
    pStudent = (Student*)malloc(2*sizeof(Student)); //memory allocate for 2 * type Student
    int count = (argc - 1)/3; // count of students
    int scount = 0; //count of students in array

    if(!pStudent)
    {
        printf("Not enough memory. Exiting...\n");
        free(pStudent);
        pStudent = NULL;
        exit(0);
    }

    if(count > 2) //check if there are more than 2 students
    {
        pStudent = (Student*)realloc(pStudent, count*sizeof(Student)); //reallocate for number of students
    }

    for(int i = 1; i < count*3;) //add students to array of type Student
    {
        add_student(&pStudent[scount], argv[i], argv[i + 1], atof(argv[i + 2]));
        i = i + 3;
        scount++;
    }

    for(int j = 0; j < scount; j++) //prints all students info
    {
        print_student(&pStudent[j]);
    }

    free(pStudent); //we are finished with pStudent so we free the memory allocated
    return 0;
}

void add_student(Student *student, char *name, char *programme, float grade) //add student info to array
{
    strcpy(student->name, name);
    strcpy(student->programme, programme);
    student->grade = grade;
}

void print_student(Student *student) //prints student info
{
    printf("%s, %s, %.2f\n", student->name, student->programme, student->grade);
}
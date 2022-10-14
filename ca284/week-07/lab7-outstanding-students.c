#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: lab7-
Function: Main, add_student, get_average print_outstanding_student
Struct: Student
Parameters: array of string and floats
Returns: struct, float
Description:
- Takes in arguments from command line, creates struct Student and adds two students to array of type Student
- If there are more than 2 students we reallocate memory for the number of students and add them to the array
- We send the array to a function that gets the average and then we print out all students whose grade is higher than the average
- Students printed must also be in the progamme CSCE
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
void print_outstanding_student(Student *student, float average); //prints student info
float get_average(Student *student, int scount); // finds the average

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
    float average = get_average(pStudent, scount);

    for(int j = 0; j < scount; j++) //prints all students info
    {
        print_outstanding_student(&pStudent[j], average);
    }

    printf("Average grade: %.2f\n", average);

    free(pStudent); //we are finished with pStudent so we free the memory allocated
    return 0;
}

void add_student(Student *student, char *name, char *programme, float grade) //add student info to array
{
    strcpy(student->name, name);
    strcpy(student->programme, programme);
    student->grade = grade;
}

float get_average(Student *student, int scount) //get average of grades
{
    float sum = 0;
    float average = 0;
    for(int j = 0; j < scount; j++) // get sum of grades
    {
        sum += student[j].grade;
    }
    average = sum / scount;
    return average;
}


void print_outstanding_student(Student *student, float average) //prints student info
{
    if(student->grade > average && strcmp(student->programme, "CSCE") == 0) // if grade is higher than average and student is in CSCE
    {
        printf("%s, %.2f\n", student->name, student->grade);
    }
}
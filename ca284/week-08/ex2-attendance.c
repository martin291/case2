#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
Name: ex2-attendance.c
Function: Main, count_A, print_status
Parameters: an array of strings
Returns: ints
Description:
- Creates an array of the strings taken from the command line
- Count the number of 'A's in the student record
- Send this count to a function that computes the student's attendance status
Author: Martin Derwin
Date: 11/11/21
*/


// P = Present
// A = Absent
// If there are more than 2 As student attendance is status 0
// else 1

int count_A(char* student); // counts the number of 'A's
int get_status(int count); // returns the status of the student's attendance by checking the count of 'A's
void print_attendance_status(int *statuses, int length); //outputs status of each student

int main(int argc, char*argv[])
{
    int length = argc - 1; // number of arguments
    char* students[length]; // array of strings/ pointer to chars
    int statuses[length]; // array of 1s and 0s, the student's attendance status
    for(int i = 0; i < length; i++)
    {
        students[i] = argv[i + 1];
        int count = count_A(students[i]); // this gets the count of 'A's in the record
        int status = get_status(count); // this outputs the status of the student's attendance
        statuses[i] = status; // add to array containing statuses
    }
    print_attendance_status(statuses, length);
    return 0;
}

int count_A(char* student) // counts number of 'A's in attendance record
{
    int count = 0; // this the the count of 'A's
    for(int i = 0; i < strlen(student); i++)
    {
        if(student[i] == 'A')
        {
            count += 1;
        }
    }
    return count;

}

int get_status(int count) // get student attendance status
{
    if(count > 2) // if there are more than 2 'A's
    {
        return(0);
    }
    else
    {
        return(1);
    }
}

void print_attendance_status(int *statuses, int length) //displays statuses
{
    for(int i = 0; i < length; i++)
    {
        printf("%d\n", statuses[i]);
    }
}
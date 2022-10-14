#include<stdio.h>
#include<stdlib.h>
#include<string.h> // for strlen()

/*
Name: ex4-attendance.c
Function: Main, count_A, convert_LLL, get_status
- Main: holds the arguments in an array called report, sends the elements of the array to other the functions
- count_A: goes through the report array and counts the number of 'A's that appear
- convert_LLL: LLL is equal to A, so we count the appearances of three consecutive 'L's
- get_status: the sum of these counts is then sent to this function which checks if the number of 'A's is >= 3 and returns the status of the student's attendance report (1 or 0)
Parameters: char*, int
Returns: int
Description:
- Takes in numbers from command line
- Creates char* to contain reports from command line
- Sends each element in the array to functions which count the number of absents
- Count_A counts the appearances of A, convert_LLL counts the appearances of 3 consecutive 'L's (lates)
- Add these counts together to get the count of absents
- Check if the number of absents is equal to or more than 3 and output the student's status
Author: Martin Derwin
Date: 09-12-21
*/

int count_A(char* report); // counts the number of 'A's
int convert_LLL(char* report); // convert LLL to A and count conversions
int get_status(int count); // returns the status of the report's attendance by checking the count of 'A's and 'LLL's (Absents)

int main(int argc, char *argv[]) // our main function, initialises variables and arrays, and passes elements to functions
{
    int length = argc - 1; // the number of arguments from the command line
    char* report[50]; // an array to contain the arguments (attendance reports)

    for(int i = 0; i < length; i++)
    {
        report[i] = argv[i + 1];

        int count = count_A(report[i]); // this gets the count of 'A's in the report
        int LLL_count = convert_LLL(report[i]); // checks for 'LLL's and adds to count

        count = count + LLL_count; // add the LLL_count to our absents counter to get the final count of 'A's

        int status = get_status(count); // this checks the status of the student's attendance

        printf("%d\n", status); // outputs status
    }

    return 0;
}

int count_A(char* report) // counts number of 'A's in attendance record
{
    int count = 0; // this the the count of 'A's

    for(int i = 0; i < strlen(report); i++)
    {
        if(report[i] == 'A')
        {
            count += 1;
        }
    }
    return count;
}

int convert_LLL(char* report) // Three consecutive 'L's is equal to one 'A'
{
    int count = 0; // this the the count of "3 consecutive 'L's"
    for(int i = 0; i < strlen(report); i++)
    {
        if(report[i] == 'L' && report[i + 1] == 'L' && report[i + 2] == 'L') // check for 3 consecutive 'L's
        {
            count += 1;
        }
    }
    return count;
}

int get_status(int count) // get student attendance status
{
    if(count >= 3) // if there are 3 or more 'A's
    {
        return(1);
    }
    else
    {
        return(0);
    }
}
#include<stdio.h>
#include<stdlib.h>

/*
Name: ex1-leap-year.c
Function: Main, leap_years
Parameters: integers from command line, start year and end year
Returns: ints, (leapyears from first argument to last argument)
Description: Takes in integers (years) from command line and prints leap years from first argument (start year) to last argument (end year)
Author: Martin Derwin
*/

/* My approach is to:
    set the command line arguments to the start and end year
    send them to a function that finds all the leap years
    leap years are divisible by 400
    or leap years are not divisible by 100 but (and) divisible by 4ei
*/
void leap_years(int start, int end); //prints leap years from start year to end year

int main(int argc, char *argv[])
{
    int start_year = atoi(argv[1]); //sets first argument as start year
    int end_year = atoi(argv[2]); //sets second argument as end year

    leap_years(start_year, end_year); //calls start year and end year to leap years function

    return 0;
}

void leap_years(int start, int end) //this function finds all leapyears from start year to end year
{
    for(int year = start; year <= end; year++)
    {
        if (year % 400 == 0) //a year is a leap year if it divisible by 400
        {
            printf("%d\n", year);
        }
        if (year % 100 != 0 && year % 4 == 0) //a year is a leap year if it is not divisible by 100 but (and) divisible by 4
        {
            printf("%d\n", year);
        }
    }
}
//once all leap years are found the loop ends

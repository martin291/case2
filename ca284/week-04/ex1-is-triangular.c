#include<stdio.h>
#include<stdlib.h>

/*
Name: ex1-is-triangular.c
Function: Main, is_triangular
Parameters: integer from command line
Returns: string
Description: Takes in integer from command line and determines if it is a triangular number
Author: Martin Derwin
*/

//Formula for triangular numbers: nth number = n(n+1)/2

//The first triangle has just one dot.
//The second triangle has another row with 2 extra dots, making 1 + 2 = 3
//The third triangle has another row with 3 extra dots, making 1 + 2 + 3 = 6
//The fourth has 1 + 2 + 3 + 4 = 10

/* My approach is to:
    send the integer argument to a function to check for triangular numbers
    if i in the loop becomes greater than the integer argument it is not a triangular number
    use the formula to check for a triangular number
    for example if n = 6, (3 * (3 + 1) / 2) = 6 would mean 6 is a triangular number
*/

int is_triangular(int num); //determines if num is a triangular number

int main(int argc, char *argv[])
{
    int num = atoi(argv[1]); //set num as the integer from the command line argument

    is_triangular(num); //we send num to the function is_triangular()

    return 0;
}

int is_triangular(int num)
{
    for(int i = 0; i <= num; i++) //if i > num, we know num is not a triangular number
    {
        if(num == (i * (i + 1) /2 )) //checks if num is a triangular number using the formula
        {
            printf("%d is a triangular number\n", num);
            return 0;
        }
    }
    printf("%d is not a triangular number\n", num); //if there is no triangular number we print this
    return 0;
}

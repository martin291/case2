#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Name: ex1-is-symmetric.c
Function: Main, symmetrical
Parameters: string, pointer to command line argument
Returns: string, "yes" or "no"
Description: Takes in string from command line argument and checks if it is symmetrical, prints "yes" or "no"
Author: Martin Derwin
*/

/* My approach is to:
    send argv[1] to a function that checks if the argument is symmetrical
    we do this by using a pointer (*string) as a parameter
    we go from the sides of string in argv[1] to the middle
    we check if every character in the string matches the character at the other end
    if not we print "no" and exit
*/
int symmetrical(char *string); //checks if string is symmetrical, checks if characters in string match

int main(int argc, char *argv[])
{
    symmetrical(argv[1]); //We send the argument to the function that checks it is symmetrical
    return 0;
}

int symmetrical(char *string) //pointer to string as parameter
{
    int length = strlen(string); //we find the length of the string
    int i, j;

    for(i = 0, j = length - 1; i < length/2; i++, j--) //we go from the start and end of the string to the middle
    {
        if (string[i] != string[j]) //if any character in the string does not match the program will print "no" and exit
        {
            printf("no\n");
            return(1);
        }

    }
    printf("yes\n"); //if the for loop has completed without printing "no", the string must be symmetrical
}

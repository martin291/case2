#include<stdio.h>
#include<stdlib.h>

/*
Name: ex4-duplicate-remover.c
Function: Main, createArray, removeDuplicates
- Main: initalise and allocate memory to int* numbers, calls functions
- createArray: creates array in seperate function to main
- removeDuplicates: checks for duplicates
Parameters: int*, char*, int
Returns: ints
Description:
- Takes in numbers from command line
- Creates an array to hold the numbers
- Sends the array of numbers to a function to check for duplicates
- Non-duplicates are then outputted
Author: Martin Derwin
Date: 09-12-21
*/

int* createArray(int *numbers, char *argv[], int length); // create array of numbers from command line
void removeDuplicates(int *numbers, int length); // checks for duplicates, outputs non-duplicates

int main(int argc, char* argv[])
{
    int length = argc - 1; // numbers of arguments
    int* numbers; // array to hold n arguments from command line
    numbers = (int*)malloc(length*sizeof(int)); // allocate memory

    if(!numbers) // error check
    {
        printf("Not enough memory. Exiting...\n");
        free(numbers);
        numbers = NULL;
        exit(0);
    }

    numbers = createArray(numbers, argv, length); // create the array

    removeDuplicates(numbers, length); // remove duplicate numbers from array

    free(numbers); // we are finished with this array so we free the memory allocated

    return 0;
}

int* createArray(int *numbers, char *argv[], int length) // creates array
{
    for(int i = 0; i < length; i++)
    {
        numbers[i] = atoi(argv[i + 1]);
    }

    return numbers; // return array
}

void removeDuplicates(int *numbers, int length)
{
    for(int i = 0; i < length; i++)
    {
        int count = 0;
        for(int j = 0; j < length; j++)
        {
            if(numbers[i] == numbers[j]) // if duplicate
            {
                ++count; // add to count
            }
        }
        if(count == 1) // non duplicate numbers should only have a count of 1 because numbers[i] shows up once in the second loop through the array
        {
            printf("%d\n", numbers[i]); // output non duplicates
        }
    }
}
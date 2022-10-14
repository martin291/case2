#include <stdio.h>
#include <stdlib.h>

/*
Name: lab7-largest-twice.c
Function: Main, largest_twice
Parameters: ints, array of ints
Returns: int
Description:
- Takes in arguments from command line, create an array of ints
- Find the biggest number
- Print biggest if biggest divided by 2 is larger than any of the other ints in the array
Author: Martin Derwin
*/

int largest_twice(int *numbers, int length); //prints biggest if biggest divided by 2 is greater than any of the ints in the array

int main(int argc, char *argv[])
{
    int length = argc - 1; // length of array

    int *numbers = NULL;
    numbers = (int*)calloc(length, sizeof(int)); // array of int numbers

    if(!numbers)
    {
        //Do something if failed to allocate memory, e.g.:
        printf("Not enough memory!");
        exit(0);
    }

    for(int i = 0; i < length; i++) //insert numbers into array
    {
        numbers[i] = atoi(argv[i + 1]); // i + 1 because of the executable
    }

    largest_twice(numbers, length);

    free(numbers); // we are finished we numbers so we free the memory allocated

    return 0;
}

int largest_twice(int *numbers, int length)
{
    int biggest = numbers[1];

    for(int i = 0; i < length; i++) //finds biggest
    {
        if(numbers[i] >= biggest)
        {
            biggest = numbers[i];
        }
    }

    for(int i = 0; i < length; i++) //if biggest divided by 2 is greater than any of the ints in the array print biggest
    {
        if(numbers[i] <= biggest / 2)
        {
            printf("%d\n", biggest);
            return 0;
        }
    }

    printf("%d\n", 0); //prints 0 if biggest divided by 2 is not greater than any of the ints in the array
    return 0;
}
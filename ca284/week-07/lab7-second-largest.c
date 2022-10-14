#include <stdio.h>
#include <stdlib.h>

/*
Name: lab7-second-largest.c
Function: Main, second_largest
Parameters: ints, array of floats
Returns: float
Description:
- Takes in arguments from command line, create an array of floats
- Find the second largest float and print it
Author: Martin Derwin
*/

void second_largest(float *floats, int length); // finds second largest float

int main(int argc, char *argv[])
{
    int length = argc - 1; // length of array

    float *floatarray = NULL;
    floatarray = (float*)calloc(length, sizeof(float)); // array of float numbers

    if(!floatarray)
    {
        //Do something if failed to allocate memory, e.g.:
        printf("Not enough memory!");
        exit(0);
    }

    for(int i = 0; i < length; i++) //insert floats into array
    {
        floatarray[i] = atof(argv[i + 1]); // i + 1 because of the executable
    }

    second_largest(floatarray, length);

    free(floatarray); //we are finished with floatarray so we free the memory

    return 0;
}

void second_largest(float *floats, int length) // finds second largest
{
    float biggest = floats[1];
    float second_biggest = floats[1];

    for(int i = 0; i < length; i++) //finds biggest
    {
        if(floats[i] >= biggest)
        {
            biggest = floats[i];
        }
    }

    for(int i = 0; i < length; i++) //finds second biggest
    {
        if((floats[i] >= second_biggest) && (floats[i] != biggest)) //makes sure number is not biggest
        {
            second_biggest = floats[i];
        }
    }

    printf("%.1f\n", second_biggest);
}

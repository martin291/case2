#include<stdio.h>
#include<stdlib.h>
/*
Name: ex2-degree-array.c
Function: Main, count_appearances, print
Parameters: an array of integers
Returns: int
Description:
- Creates an array of the integers taken from the command line
- Our function finds the integer with the most appearances in our array
- Return this to main and print the resulting count
Author: Martin Derwin
Date: 11/11/21
*/

int count_appearances(int *array, int length); // counts the number of appearances of each integer and returns the count of the integer with the most appearances
void print(int result); // prints the count of the integer with the most appearances

int main(int argc, char*argv[])
{
    int length = argc - 1; // the amount of integers/ command line arguments
    int array[length]; // an array to hold our integers
    int appeared_most = 0; // this will be the count of the integer with the most appearances

    for(int i = 0; i < length; i++)
    {
        array[i] = atoi(argv[i + 1]); // we convert the arguments into integers before adding them to the array
    }

    appeared_most = count_appearances(array, length); // counts the integers and returns the count of the int with the most appearances
    print(appeared_most); // prints the result
    return 0;
}

int count_appearances(int *array, int length)
{
    int count = 0; // counts the appearances
    int most_appearances = 0; // the int with the most appearances

    for(int i = 0; i < length; i++)
    {
        count = 1; // we count the element we are checking
        for(int j = 0; j < length; j++)
        {
            if(array[i] == array[j] && i != j) // make sure i is not equal to j so we dont something twice
            {
                count += 1;
            }
        }
        if(count > most_appearances) // if the count is bigger than the current most appearances we make count the new most appearances
        {
            most_appearances = count;
        }
        count = 0; // make count equal to 0 again
    }
    return most_appearances;
}

void print(int result) // prints the count of the int with the most appearances in our array
{
    printf("%d\n", result);
}
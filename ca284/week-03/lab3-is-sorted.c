#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
Name: is-sorted.c
Function: Main, bubble_sort
Parameters: an array of numbers
Returns: ints, line by line, followed by \n
Description: Takes in array of numbers, prints out line by line the sorted array and ends with a newline character.
Author: Martin Derwin
*/
void bubble_sort(int array[], int n);

int main(int argc, char*argv[])
{
    int length = argc - 1;
    int array[length];

    for(int i = 0; i < length; ++i)
    {
        array[i] = atoi(argv[i + 1]);
    }
    bubble_sort(array, length);
    for(int i = 0; i < length; ++i)
    {
        printf("%d\n", array[i]);
    }
    return(0);
}

void bubble_sort(int array[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
Name: duplicated-numbers.c
Function: Main, find_dupe
Parameters: an array of numbers
Returns: int
Description: Takes in an array and finds first duplicate if any exist.
Author: Martin Derwin
*/
int find_dupe(int arr1, int arr2, int i, int j);

int main(int argc, char*argv[])
{
    int length = argc - 1;
    char array[length];
    int duplicate = 0;
    int found = 0;
    for(int i = 0; i < length; ++i)
    {
        array[i] = atoi(argv[i + 1]);
    }
    for(int i = 0; i < length; ++i)
    {
        for(int j = i; j < length; ++j)
        {
            duplicate = find_dupe(array[i], array[j], i, j);

            if(duplicate != -1)
            {
                printf("%d\n", duplicate);
                break;
            }
        }
        if(duplicate != -1)
        {
            break;
        }
        else if(i == length - 1)
        {
            printf("no duplicated number\n");
        }
    }
    return(0);
}


int find_dupe(int arr1, int arr2, int i, int j)
{

    if((arr1 == arr2) && (i != j))
    {
        int found = 1;
        return arr2;
    }
    else
    {
        return -1;
    }
}
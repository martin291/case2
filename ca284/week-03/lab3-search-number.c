#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
Name: search-number.c
Functions: Main, searchx
Parameters: numbers from command line argument
Returns: int
Description: Takes in numbers, finds the number that matches argv[1].
Author: Martin Derwin
*/
int searchx(int x, int array[], int i);

int main(int argc, char *argv[])
{

    int array[50];
    /* If argc is greater than 50 + 2, only 50 elements in array allowed */
    if(argc > 52)
    {
        printf("Error, max 50 elements allowed\n");
        return 1;
    }
    int i = 0;
    int found = 0;
    int x = atoi(argv[1]);

    for(i = 0; (i < argc - 2) && (i < 50); i++)
    {
        array[i] = atoi(argv[i + 2]);
    }
    found = searchx(x, array, i);
    if( found != -1)
    {
        printf("Found %d at %d\n", x, found);
    }
    else
    {
        printf("%d not found\n", x);
    }
    return 0;
}

int searchx(int x, int array[], int i)
{
    int position = -1;
    for(int j = 0; j < i; j++)
    {
        if(x == array[j])
        {
            position = j;
        }
    }
    return position;
}

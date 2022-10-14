#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
Name: findMax.c
Functions: Main, maxnum
Parameters: array of numbers
Returns: int
Description: Takes in an array of numbers and finds the max/biggest number
Author: Martin Derwin
*/
int maxnum(int num, int big);

int main(int argc, char*argv[])
{
    int length = argc - 1;
    char array[length];
    int biggest = 0;
    for(int i = 0; i < length; ++i)
    {
        array[i] = atoi(argv[i + 1]);
    }
    for(int i = 0; i < length; ++i)
    {
        biggest = maxnum(array[i], biggest);
    }
    printf("%d\n", biggest);
    return 0;
}

int maxnum(int num, int big)
{
    if(num > big)
    {
        return num;
    }
    else
    {
        return big;
    }
}
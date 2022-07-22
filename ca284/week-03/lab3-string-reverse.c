#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
Name: string-reverse.c
Functions: Main, reverse
Parameters: string from command line argument
Returns: string
Description: Takes in string and reverses it.
Author: Martin Derwin
*/
void reverse(char *string);

int main(int argc, char*argv[])
{
    reverse(argv[1]);
    return 0;
}

void reverse(char *string)
{
    int length = strlen(string);

    for(int i = length - 1; i >= 0; i--)
    {
        printf("%c", string[i]);
    }
    printf("\n");
}

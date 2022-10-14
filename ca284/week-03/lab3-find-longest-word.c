#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
Name: lab3-find-longest-word.c
Functions: Main, ___
Parameters:  _____
Returns: string
Description: _____
Author: Martin Derwin
*/
char longest_word(char words);

int main(int argc, char*argv[])
{
    char longest[];
    char a[];
    int space;
    for(int i = 0; i < strlen(argv[1]); i++)
    {
        a[i] = argv[1][i];
        if a[i] == " "
        {
            space = i
            longest_word(a[:i]);
        }
        printf("%c\n", a[i]);
    }

    longest_word(argv[1]);
}

char longest_word(char words)
{
    printf("%s\n", words);


    return 0;
}
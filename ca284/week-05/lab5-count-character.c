#include<stdio.h>
#include<stdlib.h>
#include<string.h> //we need this to perform strlen() and strchr()

/*
Name: lab5-count-character.c
Function: Main, count_char
Parameters: character and string from command line
Returns: int
Description: Takes in character and string from command line, argv[1] and argv[2] respectfully, counts number of times character appears in the string
Author: Martin Derwin
*/

void count_char(char ch, char *str); //takes in character and string (pointer to argv[1])

int main(int argc, char * argv[])
{
    char ch = *argv[1]; // we assign the pointer to argv[1] to variable 'ch'

    count_char(ch, argv[2]);

    return 0;
}

void count_char(char ch, char *str) //counts number of character ch in string str
{
    int length = strlen(str);
    int count = 0;

    while(str = strchr(str, ch))
    {
        count += 1;
        str += 1;
    }

    printf("%d\n", count); // example: ./lab5-count-character a "aaaa" -> prints 4
}

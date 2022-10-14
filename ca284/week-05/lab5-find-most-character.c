#include<stdio.h>
#include<stdlib.h>
#include<string.h> //we need this to perform strlen()
/*
Name: lab5-find-most-character.c
Function: Main, find_most_ch
Parameters: String (pointer) from command line
Returns: char
Description: Takes in string from command line and prints the character that appears most often in the string
Author: Martin Derwin
*/
void find_most_ch(char *str); //Takes in pointer to string from command line

int main(int argc, char * argv[])
{
    find_most_ch(argv[1]);
    return 0;
}

void find_most_ch(char *str) //searches for character that appears the most in the sentence
{
    int biggest = 0; //This will be the count of the most repeated character in the string
    int count = 0;   // This will count the appearances of a character in the string
    int pos = 0; //This keeps track of the current most repeated character

    for(int i = 0; i < strlen(str); ++i) //search through string
    {
        for(int j = 0; j < strlen(str); ++j) //search through string again and add to count when str[i] appears
        {
            if(str[j] == str[i] && str[i] != ' ')
            {
                count += 1;
            }
        }
        if(count > biggest) //if count is greater than biggest, set count as biggest
        {
            biggest = count;
            pos = i; //this is the index of the current biggest character
        }
        count = 0;
    }
    printf("%c\n", str[pos]); //print character that appears most often
    //example: "abcxyzbcc" will print 'c'
}

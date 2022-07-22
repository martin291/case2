#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: lab7-longest-sentence.c
Function: Main, longestString
Parameters: ints, array of strings
Returns: string(s)
Description:
- Takes in arguments from command line, create an array of strings (char *)
- Sends this array to a function that finds the longest string
- The function contains indexlist which saves the position of the longest string(s)
- The function reallocates the memory for the list of indexes if there are multiple strings of the same length
Author: Martin Derwin
*/

void longestString(char **stringArray, int length);

int main(int argc, char *argv[])
{
    int length = argc - 1; // length of array

    char** stringArray = malloc(length*sizeof(char*)); // array of char pointers

    if(!stringArray)
    {
        //Do something if failed to allocate memory, e.g.:
        printf("Not enough memory!");
        exit(0);
    }

    for(int i = 0; i < length; i++) //insert strings into array
    {
        stringArray[i] = argv[i + 1]; // i + 1 to ignore the zeroth element in argv
    }

    longestString(stringArray, length); // send to function
    // could also use: longestString(&argv[1], length)

    free(stringArray); // we are finished with stringArray so we free the memory allocated to it

    return 0;
}

void longestString(char **stringArray, int length)
{

    int longest = strlen(stringArray[0]); // we initalise the length of the longest string as the length of the first string
    int count = 1; // this keeps track of the number of indexes in indexlist
    int *indexlist = (int*)malloc(sizeof(int)); // our array of indexes
    indexlist[0] = 0; //we set the first element in our array to 0 as this should be the biggest string's index

    for(int i = 1; i < length; i++)
    {
        if(strlen(stringArray[i]) == longest) //if the string is the same length as the current longest
        {
            count++;

            indexlist = (int*)realloc(indexlist, count*sizeof(int)); //reallocate memory to indexlist
            indexlist[count - 1] = i; //add index to array
        }
        else if(strlen(stringArray[i]) > longest) //if the string is the bigger than the current longest
        {
            count = 1; //set count back to 1

            free(indexlist); // free the memory allocated to indexlist
            indexlist = (int*)malloc(sizeof(int)); // allocate the memory for indexlist to 1
            indexlist[0] = i; // set the first element in indexlist to the index of the new biggest string
            longest = strlen(stringArray[i]); //make the new biggest string the longest

        }
    }

    for(int i = 0; i < count; i++) //prints longest strings
    {
        printf("%s\n", stringArray[indexlist[i]]);
    }

    free(indexlist); // we are finished with indexlist so we free the memory allocated to it
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h> //this lets us use strncmp() and strlen()

/*
Name: lab5-search-sub-string.c
Function: Main, search_sub_str
Parameters: two strings, the first is a sentence, the second is a potential word in the sentence
Returns: ints
Description:
Author: Martin Derwin
*/

void search_sub_str(char *string, char *substr); //takes in string and possible subset of the string

int main(int argc, char *argv[])
{
    search_sub_str(argv[1], argv[2]);
    return 0;
}

void search_sub_str(char *string, char *substr) //tests if word (argv[2]) is in the sentence (argv[1])
{
    int start_word = 0; //index for start of word
    int end_word = 0; //index for end of word
    int word_length = strlen(substr) - 1; //length of the word
    int sentence_length = strlen(string); //length of sentence

    for(int i = 0; i < sentence_length; ++i) //we go through the sentence
    {
        if(strncmp(substr, &string[i], strlen(substr)) == 0) //strncmp lets us compare a window or piece of the sentence, we set the number of characters it checks to the length of the word
        {
            start_word = i; //i is the when the word starts

            //we use strncmp to check all of the word is in the sentence before we set the index for the end of the word

            end_word = i + word_length; //word_length + i is when the word ends
        }
    }

    printf("%d %d\n", start_word, end_word);
    //example: "This is a word" "word" prints 10 13
}

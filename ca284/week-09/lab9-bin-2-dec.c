#include<stdio.h>
#include<stdlib.h>
#include<string.h> // we need this for strcmp()
#include<math.h> // we need this for pow()

/*
Name: lab9-bin-2-dec.c
Function: Main, binarytodecimal
Parameters: pointer to decimal, argv, length
Returns: int
Description:
- Creates pointer to decimal (*decimal)
- Sends arguments from command line and *decimal to function that converts binary to decimal
- Function converts binary to decimal
- We convert our binary number from left to right
- Multiply each digit of the binary number with its base, (which is 2), raised to the power based on its position in the binary number.
- *decimal is updated to be the decimal number calculated by our function
- we print this in main without returning it from our function
Author: Martin Derwin
*/

void binarytodecimal(int *decimal, char *argv[], int length); // converts binary to decimal


int main(int argc, char *argv[])
{
    int *decimal = NULL;
    decimal = (int*)malloc(sizeof(int)); // allocate memory for our decimal number

    int length = argc - 1;
    if(length > 8) // error detection
    {
        printf("Too many binary digits entered.\n");
        exit(0);
    }

    binarytodecimal(decimal, argv, length);

    printf("%d\n", *decimal); // we used a pointer to decimal so we don't need to return anything to main

    return 0;
}

void binarytodecimal(int *decimal, char *argv[], int length)
{
    for(int i = 0; i < length; i++) // decimal is updated every loop
    {
        if (strcmp(argv[i + 1], "1") == 0 || strcmp(argv[i + 1], "0") == 0) // check the string argv[i + 1] is "1" or "0"
        {
            if(atoi(argv[i + 1]) == 1) // if the number is 0 we can discard it and move on
            {
                // we are converting from left to right
                // decimal += (2 * base)^(position)
                *decimal += (int)pow(2 * atoi(argv[i + 1]), length - 1 - i); // length - 1 because we end at 0
            }
        }
        else
        {
            printf("Only digits 1 and 0 are permitted.\n"); // error detection
            exit(0);
        }
    }
}

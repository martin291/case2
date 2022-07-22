#include <stdio.h>
#include <stdlib.h>

/*
Name: lab7-dot-product-two-vector.c
Function: Main, dotproduct
Parameters: ints, size of vectors followed by elements inside vectors
Returns: int
Description:
- Takes in arguments from command line, fisrt argument denotes n, the size of two vectors
- Creates two vectors and finds the dot product of these vectors
Author: Martin Derwin
*/

void dotproduct(int *vector1, int *vector2, int size); // calculates dot product

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]); // size of the two vectors

    int *vector1 = calloc(n, sizeof(int)); // first vector/array
    if(!vector1)
    {
    //Do something if failed to allocate memory, e.g.:
    printf("Not enough memory!");
    exit(0);
    }

    int *vector2 = calloc(n, sizeof(int)); // second vector/array
    if(!vector2)
    {
    //Do something if failed to allocate memory, e.g.:
    printf("Not enough memory!");
    exit(0);
    }

    int j = 0;

    for(int i = 0; i < n; i++) // i + 2 because of n and executable name in command line
    {
        vector1[i] = atoi(argv[i + 2]);
        //printf("%d\n", vector1[i]);
        ++j;
    }
    for(int i = 0; i < n; i++)
    {
        vector2[i] = atoi(argv[2 + j]); // 2 + j because of n and executable name and vector1
        //printf("%d\n", vector2[i]);
        ++j;
    }

    dotproduct(vector1, vector2, n);

    free(vector1); // we are finished with using our vectors so we free the memory
    free(vector2);

    return 0;
}

void dotproduct(int *vector1, int *vector2, int size) // calculates dot product
{
    int dp = 0; //dot product

    for(int i = 0; i < size; i++)
    {
        dp += (vector1[i] * vector2[i]);
    }

    printf("%d\n", dp);
}
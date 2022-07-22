#include<stdio.h>
#include<stdlib.h>

/*
Name: lab5-matrix-diagonal-sum.c
Function: Main, diagonal_sum
Parameters: int representing the number of dimensions in a matrix, ints from command line which are inside of the matrix
Returns: int
Description: Takes in ints from command line, first int is the number of dimensions and the following make a matrix, we use a function to find the sum of this matrix's diagonal
Author: Martin Derwin
*/

void diagonal_sum(int *matrix, int n, int length); //Takes in matrix (array), number of dimensions, length of matrix

int main(int argc, char * argv[])
{
    int length = argc - 2;
    int matrix[length]; //initialise the matrix array

    int n = atoi(argv[1]); //number of dimensions

    for(int i = 0; i < length; ++i) //we create our matrix
    {
        matrix[i] = atoi(argv[i + 2]);
    }

    diagonal_sum(matrix, n, length);

    return 0;
}

void diagonal_sum(int *matrix, int n, int length) //returns sum of the matrix diagonal
{
    int sum = 0;

    for(int i = 0; i < length;) //we get the sum by skipping along by n + 1 until the we reach the end of the matrix
    {
        sum += matrix[i];
        i += n + 1;
    }

    printf("%d\n", sum); //example: 3 1 2 3 4 5 6 7 8 9, prints 15
}

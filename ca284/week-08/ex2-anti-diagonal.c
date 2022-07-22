#include<stdio.h>
#include<stdlib.h>

/*
Name: ex2-anti-diagonal.c
Function: Main, anti_diagonal_sum
Parameters:
- int representing the dimensions in a square matrix
- ints from command line which are inside of the square matrix
Returns: int
Description:
- Create 2D array of ints from command line
- Call our function anti_diagonal_sum()
- We start at the last element of the first row
- We increment i + the size of dimensions (n) - 1
- We get the sum of each of element at these positions and print the result
Author: Martin Derwin
Date: 11/11/21
*/

int anti_diagonal_sum(int *matrix, int n, int length); //Takes in matrix (array), number of dimensions, length of matrix

int main(int argc, char * argv[])
{
    int length = argc - 2;
    int matrix[length]; //initialise the matrix array

    int n = atoi(argv[1]); //number of dimensions

    for(int i = 0; i < length; ++i) //we create our matrix
    {
        matrix[i] = atoi(argv[i + 2]);
    }

    int result = anti_diagonal_sum(matrix, n, length);
    printf("%d\n", result);

    return 0;
}

int anti_diagonal_sum(int *matrix, int n, int length) //returns sum of the matrix diagonal
{
    int sum = 0; // sum of the diagonal
    int last = n - 1; // index of last element of each row

    for(int i = last; i < length - last;) //we get the sum by skipping along by i + last until the we reach the end of the matrix
    {
        sum += matrix[i];
        i += last;
    }

    return sum;
}
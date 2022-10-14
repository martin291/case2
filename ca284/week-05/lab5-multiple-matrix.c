#include<stdio.h>
#include<stdlib.h>
/*
Name: lab5-multiple-matrix.c
Function: Main, matrix_multiply
Parameters: two 2d arrays, the first 2 numbers representing their number of rows and columns and the following being the items in the array
Returns: A matrix of ints
Description: Takes in two 2d arrays, the function 'matrix_multiply' multipies them and prints the resulting matrix
Author: Martin Derwin
*/

void matrix_multiply(int m, int n, int p, int matrix1[][n], int matrix2[][p]);

int main(int argc, char * argv[])
{
    int m1 = atoi(argv[1]);
    int n1 = atoi(argv[2]);

    int m2 = atoi(argv[(m1 * n1) + 3]); // + 3 because of the executable, m1 and n1
    int n2 = atoi(argv[(m1 * n1) + 4]); // + 4 because of the executable, m1, n1 and m2

    int matrix1[m1][n1]; //our first matrix
    int matrix2[m2][n2]; //our second matrix

    int m = m1; // rows of first matrix
    int n = n1; // columns of first matrix
    int p = n2; // columns of second matrix

    int i = 3; //position of parameter with start element of first matrix, as the first two arguments indicate the first two dimensions of the first matrix m1 rows, n1 columns

    for(int nRows = 0; nRows < m1; nRows++) //creates first matrix
    {
        for(int nCols = 0; nCols < n1; nCols++, i++)
        {
            matrix1[nRows][nCols] = atoi(argv[i]);
        }
    }

    i = 3 + (m1 * n1) + 2; //position of parameter with start element of second matrix

    for(int nRows = 0; nRows < m2; nRows++) //creates second matrix
    {
        for(int nCols = 0; nCols < n2; nCols++, i++)
        {
            matrix2[nRows][nCols] = atoi(argv[i]);
        }
    }

    matrix_multiply(m, n, p, matrix1, matrix2); //sends matrixes and dimensions needed for matrix mulitplication algorithm to function

    return 0;
}

void matrix_multiply(int m, int n, int p, int matrix1[][n], int matrix2[][p])
{
    int result_matrix[m][p]; //this will be our resulting matrix
    int sum; //the sum of the dot product
    int i, j, k;

    for(i = 0; i < n; i++) //mulitplies matrices
    {
        for(j = 0; j < p; j++)
        {
            sum = 0;
            for(k = 0; k < m; k++)
            {
                sum = sum + (matrix1[i][k] * matrix2[k][j]); //dot product
            }
            result_matrix[i][j] = sum; //we add our sum to the resulting matrix
        }
    }

    for(i = 0; i < n; i++) //prints resulting matrix
    {
        for(j = 0; j < p; j++)
        {
            printf("%d",result_matrix[i][j]);
            if(j < p - 1) //when j is one less than p we stop printing a blank space
            {
                printf(" ");
            }
        }
        printf("\n");
    }

}

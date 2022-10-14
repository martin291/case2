#include<stdio.h>
#include<stdlib.h>
/*
Name: ex1-odd-even-array.c
Function: Main, odd_or_even
Parameters: integers from command line arguments
Returns: ints
Description: Takes in integers from command line, checks if they are even or odd, finds difference of evens from first even element in array and sums odds
Author: Martin Derwin
*/

/* My approach is to:
    create an array holding the odd and even numbers
    seperate the evens and odds
    sum the odds
    find the first even number and then find the total difference from it using subtraction
    print the sum of odds and difference of evens
*/

void odd_or_even(int a[], int length); //checks for odds and evens, sums odds, finds difference of evens from first even int

int main(int argc, char*argv[])
{
    int length = argc - 1;
    int array[length]; //creates array to store integers

    for(int i = 0; i < length; i++)
    {
        array[i] = atoi(argv[i + 1]); //add integers from command line to array
    }

    odd_or_even(array, length); //we send the array and length of the array to the function odd_or_even()

    return 0;
}

void odd_or_even(int a[], int length)
{
    int sum = 0; //sum of odds
    int diff = 0; //difference of evens from first even
    for(int i = 0; i < length; i++)
    {
        if(a[i] % 2 == 0) //check if even
        {
            if(diff == 0) //if even is first even element
            {
                diff = a[i]; //set diff as the first even element
            }
            else
            {
                diff = diff - a[i]; //subtract next even number from difference
            }
        }
        else
        {
            sum = sum + a[i]; //odd numbers are added to the sum
        }
    }
    printf("%d\n", sum); //prints the sum of odds
    printf("%d\n", diff); //prints the difference of evens from first even element in the array
}
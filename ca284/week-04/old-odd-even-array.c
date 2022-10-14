#include<stdio.h>
#include<stdlib.h>

/*
Name: ex1-odd-even-array.c
Function: Main, sum_odds, difference_evens
Parameters: integers from command line argument
Returns: int
Description: Takes in integers from command line and prints the sum of all odds and difference of evens from first even number
Author: Martin Derwin
*/
int sum_odds(int array[], int length); //returns sum of odd numbers

int difference_evens(int array[], int length); //returns difference from first even number

int main(int argc, char *argv[])
{
    int length = argc - 1;  //find length of arguments

    int odd_array[length]; //create array for odd numbers
    int even_array[length]; //create array for even numbers

    int sum; //sum of odd numbers
    int difference; //difference of even numbers

    int len_odd_array = 0; //length of odd array
    int len_even_array = 0;//length of even array

    for(int i = 0; i < length; ++i) //for loop adds elements  to odd and even arrays
    {   if(atoi(argv[i + 1]) % 2 == 0)  //if a number is even, add it to the even numbers array
        {
            even_array[i] = atoi(argv[i + 1]);
            len_even_array = (i + 1);
        }
        else if(atoi(argv[i + 1]) % 2 != 0) //if a number is odd, add it to the odd numbers array
        {
            odd_array[i] = atoi(argv[i + 1]);
            len_even_array = (i + 1);
        }
    }
    sum = sum_odds(odd_array, len_even_array); //returns the sum of the odd numbers
    difference = difference_evens(even_array, len_even_array); //returns the difference of evens from first even element
    printf("%d\n", sum);
    printf("%d\n", difference);
    return 0;
}

int sum_odds(int array[], int length)
{
    int total = 0;
    for(int i = 0; i < length; ++i)
    {
        total = total + array[i];
    }
    return total; //return sum
}

int difference_evens(int array[], int length)
{
    int first_even = array[0]; //gets first even number in the array, we are subtracting from this
    int total = first_even;
    for(int i = 3; i < length; ++i) //we initially set i to 3 so the first even number is not subtracted from itself
    {
        total = total - array[i];
    }
    return total; //return difference
}

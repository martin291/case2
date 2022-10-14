#include<stdio.h>
#include<stdlib.h>
/*
Name: ex2-median.c
Function: Main, bubble_sort, print_median, getcentre1, getcentre2
Parameters: an array of integers
Returns: ints
Description:
- Create an array of the integers taken from the command line
- Get the length of arguments and find the index for the centre of the array
- Use bubblesort to sort the array from smallest to biggest
- Print the 2 middle integers inside the array
Author: Martin Derwin
Date: 11/11/21
*/

void bubble_sort(int *array, int n); // this sorts the array from smallest to biggest
int getcentre1(int n); // returns the first middle integer index
int getcentre2(int n); // returns the second middle integer index
void print_median(int *array, int index1, int index2); // this prints the middle numbers/ median


int main(int argc, char*argv[])
{
    int length = argc - 1; // the amount of integers/ command line arguments
    int centre1 = getcentre1(length); // the index of the first middle integer
    int centre2 = getcentre2(length); // the index of the second middle integer
    int array[length]; // an array to hold our integers

    for(int i = 0; i < length; ++i)
    {
        array[i] = atoi(argv[i + 1]); // we convert the arguments into integers before adding them to the array
    }

    bubble_sort(array, length); // sorts the array
    print_median(array, centre1, centre2); // prints the median

    return(0);
}

int getcentre1(int n) // returns index for the first middle integer
{
    int index = 0;
    int middle = n / 2;
    index = middle - 1;
    return index;
}

int getcentre2(int n) // returns index for the second middle integer
{
    int index = 0;
    int middle = n / 2;
    index = middle;
    return index;
}

void bubble_sort(int *array, int n)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(array[i] > array[j]) // we compare if array[i] is bigger than array[j] (or array[i + 1])
            {
                // the code below swaps them
                int temp = array[i]; // if array[i] is bigger we make temp = array[i]
                array[i] = array[j]; // we make array[i] = array[j]
                array[j] = temp;  // finally, we make array[j] = temp
            }
        }
    }
}

void print_median(int *array, int index1, int index2)
{
    printf("%d\n", array[index1]); //prints the two middle values
    printf("%d\n", array[index2]);
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h> //we need this to perform string compare (strcmp)

/*
Name: ex1-largest-smallest.c
Function: Main, search_largest, search_smallest
Parameters: floats from command line
Returns: float with %.2f format
Description: Takes in floats from command line and returns the largest or smallest number after reading what argv[1] specifies (largest or smallest)
Author: Martin Derwin
*/

/* My approach is:
    we use the string compare function to check if argv[1] is "largest" or "smallest"
    we hold the floats in an array
    depending on the answer we send the array to the search_largest() function or search_smallest() function
    these functions compare the sizes of ints to find the largest/smallest
    once the largest/smallest is found, we return it to main and print it,
    making sure the float rounds up to 2 decimal points
*/


float search_largest(float a[], int length); //searches for largest float, takes in array of floats
float search_smallest(float a[], int length); //searches for smallest float, takes in array of floats

int main(int argc, char*argv[])
{
    int length = argc - 1; //find the length of the arguments
    float array[length]; //create an array of floats

    for(int i = 1; i < length; ++i)
    {
        array[i] = atof(argv[i + 1]); //add numbers to the array of floats
    }

    if(strcmp(argv[1], "largest") == 0) // if the first argument is "largest" we search for the largest number
    {
        printf("%.2f\n",search_largest(array, length)); //we send the array of floats to a function that searches for the largest float and returns the largest float
    }
    else if (strcmp(argv[1], "smallest") == 0) // if the first argument is "smallest" we search for the smallest number
    {
        printf("%.2f\n",search_smallest(array, length)); //we send the array of floats to a function that searches for the smallest float and returns it
    }
    else
    {
        printf("invalid\n"); //print "invalid" if argv[1] is not "smallest" or "largest"
    }

    return 0;
}

float search_largest(float a[], int length)
{
    int i = 1;
    float largest = a[1];
    while(i < length)
    {
         if(largest < a[i]) //checks if a[i] is larger than previous float
         {
             largest = a[i];
         }
         i++;
    }
    return largest;
}

float search_smallest(float a[], int length)
{
    int i = 1;
    float smallest = a[1];
    while(i < length)
    {
         if(smallest > a[i]) //checks if a[i] is smaller than previous float
         {
             smallest = a[i];
         }
         i++;
    }
    return smallest;
}

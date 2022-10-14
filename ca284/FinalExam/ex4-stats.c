#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
Name: ex4-stats.c
Function: Main, createArray, max, mode, SD
- Main: intialise int* array and call functions, function pointer and contains switch case
- createArray: creates the array 'numbers' in a seperate function to main
- max: find the biggest number in the array
- mode: find the most frequent number
- SD: find the standard deviation
Parameters: int*, int
Returns: int/ float
Description:
- Takes in numbers from command line
- Creates an int* array of these numbers
- Last argument determines what we do with these numbers
- Use switch case to check what we do
- Use function pointers to max, mode and SD
- Return either max number, mode or SD
Author: Martin Derwin
Date: 09-12-21
*/

/*
- 1 = Max: Find the maximum value of the data
- 2 = Mode: Find the most frequent value, you can assume there is only one most frequent value.
- 3 = Standard Deviation: Calculate the Population standard deviation of the data. You can display the SD value with two digits after the decimal point.
- Default option will be finding maximum value (if the last argument is none of above, e.g. 4, 5, 6 etc.).
*/

int* createArray(int *numbers, char *argv[], int length); // create array of n numbers from command line
float max(int* numbers, int length); // returns the max (biggest) number in the array
float mode(int *numbers, int length); // returns the most frequent number in the array
float SD(int *numbers, int length); // returns the Standard Deviation of the array

int main(int argc, char *argv[])
{
    int length = argc - 2; // the number of arguments in the command line minus the last argument
    int n = atoi(argv[argc - 1]); // the last argument, refers to the statistical indicator

    int* numbers; // array to hold n arguments from command line
    numbers = (int*)malloc(length*sizeof(int));

    if(!numbers) // error check
    {
        printf("Not enough memory. Exiting...\n");
        free(numbers);
        numbers = NULL;
        exit(0);
    }

    numbers = createArray(numbers, argv, length); // create the array

    float (*func[])(int*, int) = {max, mode, SD};	// our array of function pointers

    switch(n)
    {
        case 1: // n == 1
            printf("%.f\n", func[0](numbers, length)); // function 1
            break;
        case 2: // n == 2
            printf("%.f\n", func[1](numbers, length)); // function 2
            break;
        case 3: // n == 3
            printf("%.2f\n", func[2](numbers, length)); // function 3
            break;
        default: // n does not equal 1, 2 or 3
            printf("%.f\n", func[0](numbers, length)); // default: function 1
    }

    free(numbers); // we are finished with this array so we free the memory

    return 0;
}

int* createArray(int *numbers, char *argv[], int length) // creates array
{
    for(int i = 0; i < length; i++)
    {
        numbers[i] = atoi(argv[i + 1]);
    }
    return numbers; // return array
}

float max(int* numbers, int length) // returns the max (biggest) number in the array
{
    int maxnum = numbers[0];
    int tmp = numbers[0];

    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < length; j++)
        {
            if(numbers[i] > numbers[j]) // compare size
            {
                tmp = numbers[i];
            }
        }
        if(maxnum < tmp) // check if tmp is bigger than the current biggest number
        {
            maxnum = tmp; // if tmp is bigger, make it maxnum
        }
    }
    return maxnum;
}

float mode(int *numbers, int length) // returns the most frequent number in the array
{
    int mode = numbers[0];
    int maxcount = 1;

    for(int i = 0; i < length; i++)
    {
        int count = 0; // reset count each iteration of i
        for(int j = 0; j < length; j++)
        {
            if(numbers[i] == numbers[j]) // if number is spotted in numbers
            {
                ++count; // add to count
            }
        }
        if(maxcount < count) // check if current biggest count is smaller than the last count
        {
            maxcount = count;
            mode = numbers[i]; // mode will be the number with the maxcount
        }
    }
    return mode;
}

float SD(int *numbers, int length) // returns the Standard Deviation of the array
{
    int sum = 0; // we need the sum of the numbers and the mean
    float SD = 0.0;

    for(int i = 0; i < length; i++) // get sum
    {
        sum += numbers[i];
    }

    float mean = sum / length; // get mean

    for(int i = 0; i < length; i++)
    {
        SD += pow(numbers[i] - mean, 2); // SD formula, sum of variances
    }

    return sqrt(SD / length); // sum of variances divided by number of integers in the data
}

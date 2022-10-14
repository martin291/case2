#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
/*
Name: calculator.c
Functions: Main, mulitply, divide
Parameters: numbers from command line argument
Returns: int
Description: Takes in numbers and divides or multiplies them.
Author: Martin Derwin
*/

float multiply(float param1, float param2);
float divide(float param1, float param2);

int main(int argc, char * argv[])
{
    float answer = 0.0;
    float num1 = atof(argv[2]);
    float num2 = atof(argv[3]);
    if(num2 != 0)
    {
        if(strcmp(argv[1], "multiply") == 0)
        {
            answer = multiply(num1, num2);
            printf("%f\n", answer);
        }
        else if(strcmp(argv[1], "divide") == 0)
        {
            answer = divide(num1, num2);
            printf("%f\n", answer);
        }
        else
        {
            printf("invalid\n");
        }
    }
    else
    {
        printf("invalid\n");
    }

	return 0;
}

float multiply(float param1, float param2)
{
    return param1 * param2;
}

float divide(float param1, float param2)
{
    return param1 / param2;
}
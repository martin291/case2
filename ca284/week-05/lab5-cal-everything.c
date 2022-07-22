#include<stdio.h>
#include<stdlib.h>
#include<math.h> //this lets us use log()

/*
Name: lab5-cal-everything.c
Function: Main, any_function, pfunction, cal_everything, sum, difference, product, division, power, natural_log
Parameters: two floats from command line
Returns: float
Description:
    Takes in floats from command line, we then use functions to find the sum, difference, product, division, power
    and natural log of these floats. We do this by creating a pointer that will point to each function when we are calculating.
    We create a function called any_function() that will allow us to accomplish this. any_function will take in the pointer to a function,
    as well as the command line arguments. It returns the result which we will then print.
Author: Martin Derwin
*/

float sum(float a, float b); // a + b
float difference(float a, float b); // a - b
float product(float a, float b); // a * b

float division(float a, float b); // a/b
float power(float a, float b); // a^b
float natural_log(float a, float b); // log(a) + log(b)

float any_function(float(*pfunction)(float, float), float a, float b); //this lets us call any function

void cal_everything(float a, float b); //this is where we will house our print statements and function calls

int main(int argc, char * argv[])
{
    float first_num = atoi(argv[1]); //we set the numbers from command line to floats
    float second_num = atoi(argv[2]);
    cal_everything(first_num, second_num); //we then send them to the calculate everything function
    return 0;
}

void cal_everything(float a, float b)
{
    float (*pfunction)(float, float) = NULL; //we declare out function pointer here

    printf("%.2f\n", any_function(sum, a, b)); //returns sum of floats a and b

    printf("%.2f\n", any_function(difference, a, b)); //returns result of subtraction of b from a

    printf("%.2f\n", any_function(product, a, b)); //returns product of a and b

    printf("%.2f\n", any_function(division, a, b)); //returns division of b from a

    printf("%.2f\n", any_function(power, a, b)); //returns a to the power of b

    printf("%.2f\n", any_function(natural_log, a, b)); //returns sum of the natural logs of a and b
}

float any_function(float(*pfunction)(float, float), float a, float b) //this sets the pfunction pointer to whatever function we call in our print statement
{
  return pfunction(a, b); //example: any_function(sum, a , b) will return the sum of a and b
}

float sum(float a, float b) //returns a + b
{
  return a + b;
}

float difference(float a, float b) //returns a - b
{
    return a - b;
}

float product(float a, float b) //returns a * b or (a)(b)
{
    return a * b;
}

float division(float a, float b) //returns a / b
{
    return a / b;
}

float power(float a, float b) //returns a^b
{
    float result = 0;

    for(int i = 0; i < b; ++i) //while i is less than b we multiply a by itself
    {
         result = a * a;
    }

    return result;
}

float natural_log(float a, float b) //finds natural log of a and b and then adds them together
{
    float x, y;
    x = log(a);
    y = log(b);
    return x + y;
}

/*example:
./lab5-cal-everything 10 2 prints:
    12.00
    8.00
    20.00
    5.00
    100.00
    3.00
*/



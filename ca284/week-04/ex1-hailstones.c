#include<stdio.h>
#include<stdlib.h>

/*
Name: ex1-hailstones.c
Function: Main, hailstones
Parameters: integer from command line argument
Returns: ints (hailstone sequence)
Description: Takes in integer n and prints hailstone sequence starting at n until sequence element is 1
Author: Martin Derwin
*/

/* My approach is to:
    send the command line argument to the function as an integer
    the function will create a sequence of numbers
    it will end when the number in the sequence is 1
    if n is even, divide it by 2 to get n/2
    if n is even, multpily it by 3 and add 1 to get 3n + 1
    once we detect a 1, we print "1" and a newline
*/

int hailstones(int n); //paramater n points to atoi(argv[1]), the integer taken from the command line

int main(int argc, char*argv[])
{
    hailstones(atoi(argv[1])); //send argument taken from command line to hailstone function
    return 0;
}

int hailstones(int n)
{
    int num = n; //we use n as the length and the first number in the hailstones sequence
    int length = n;
    for(int i = 0; num != 1; ++i) //while i < (n + 1) e.g (5 + 1 = 6)
    {
        printf("%d ", num);
        if(num % 2 == 0) //if n is even, divide it by 2 to get n/2
        {
            num = num / 2;
        }
        else //if n is even, multpily it by 3 and add 1 to get 3n + 1
        {
            num = (num * 3) + 1;
        }
    }
    printf("%d\n", 1); //once num == 1, print 1 + a new line
}

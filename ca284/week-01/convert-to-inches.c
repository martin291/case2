/* Include standard input and output */
#include <stdio.h>
#include <stdlib.h>
/*
Function: Main
Parameters: none
returns: int
*/

int main(int argc, char*argv[])

{

   float cm;

   printf("Enter an Amount in Centimetres: ");
   scanf("%f", &cm);

   printf("The Amount in Inches is: %f\n", cm/2.54);

   return 0;
}
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
   cm = 30;
   while (cm < 50) {
    printf("%f %f %f %f %f \n", cm/2.54, (cm + 1)/2.54, (cm + 2)/2.54, (cm + 3)/2.54, (cm + 4)/2.54);
    cm += 5;
   }
   return 0;
}
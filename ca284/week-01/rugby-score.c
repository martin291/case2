/*A try (worth 5 points)*/

/*A conversion (worth 2 points)*/

/*A penalty (worth 3 points) */


/*A drop-goal (worth 3 points). */
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

   int try=0, cnv=0, pen=0, dg=0;

   printf("Number of Trys: ");
   scanf("%d", &try);
   if (try <= -1) {
        printf("Negative number detected\n");
        return 0;
   }
   printf("Number of Conversions: ");
   scanf("%d", &cnv);
    if (cnv <= -1) {
        printf("Negative number detected\n");
        return 0;
    }
   printf("Number of Penalties: ");
   scanf("%d", &pen);
     if (pen <= -1) {
        printf("Negative number detected\n");
        return 0;
    }
   printf("Number of Drop-Goals: ");
   scanf("%d", &dg);
    if (dg <= -1) {
        printf("Negative number detected\n");
        return 0;
    }

   printf("%d \n", (try * 5) + (cnv * 2) + (pen * 3) + (dg * 3));

   return 0;
}
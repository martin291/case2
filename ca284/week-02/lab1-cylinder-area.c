#include <stdio.h>
#include <stdlib.h> /* contains functions we may need*/

#define PI 3.1415

int main(int argc, char *argv[1])
{
/* variable initialisation */
	int radius = 0;
    int height = 0;
/* all command-line arguments come in as character strings, so atoi turns them into ints*/
	radius = atoi(argv[1]);
    height = atoi(argv[2]);
    /* 2πrh + 2πr2 */

	int sqrrad = radius*radius; /* radius squared */

    float area =  (2*PI*sqrrad) + (2*height*radius*PI);

    if (argc < 0) {
        printf("Two arguments needed!");
    }
    else if (argc == 0) {
        printf("No input given!");
    }
    else if (atoi(argv[1]) < 0 || atoi(argv[2]) < 0) {
        printf("The radious or height cannot be negative!");
    }
    else {
        printf ("%.2f\n",area);
    }
    /*printf ("%9.2f\n",area); /* We want to set the width of the shown number = 9. If the total number of digits < 9, spaces will be shown before the number*/
    return (0); /* exit correctly*/
} /* end program*/
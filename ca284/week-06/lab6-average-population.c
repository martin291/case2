#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: lab6-average-population.c
Function: Main, get_average
Struct: Country
Parameters: two chars, one float, one int from command line
Returns: struct Country, float
Description: Takes in arguments from command line, places them in struct Country and returns struct Country and the average of the populations
Author: Martin Derwin
*/

void get_average(float sum, int count); //Returns average

typedef struct Country Country; //Define Country as a type name

struct Country //Structure type definition
{
  char country[50];
  char capital[50];
  float population;
  int size;
};

int main(int argc, char*argv[])
{
    Country c;
    float sum = 0; //sum of populations
    int count = 0; //number of populations

    printf("Country\t\t\t");
    printf("Capital\t\t\t");
    printf("Size\t\t\t");
    printf("Population");
    printf("\n");

    for(int i = 1; i < argc - 1;) //prints struct Country until there are no more arguments (no more information)
    {
        strcpy(c.country, argv[i]);
        printf("%s\t\t\t", c.country);

        strcpy(c.capital, argv[i + 1]);
        printf("%s\t\t\t", c.capital);

        c.size = atoi(argv[i + 3]);
        printf("%d\t\t\t", c.size);

        c.population = atof(argv[i + 2]);
        printf("%.2f", c.population);

        printf("\n");
        sum = sum + c.population;
        count = count + 1;
        i = i + 4;
    }

    get_average(sum, count); //returns average

  return 0;
}

void get_average(float sum, int count) //returns average
{
    float average = sum / count;

    printf("Population average: %.2f\n", average);
}
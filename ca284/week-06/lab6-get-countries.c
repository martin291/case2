#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: lab6-get-countries.c
Function: Main
Struct: Country
Parameters: (repeated arguments of) two chars, one float, one int
Returns: struct Country
Description: Takes in arguments from command line, places them in struct Country and returns struct Country multiple times
Author: Martin Derwin
*/

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

    i = i + 4;
  }

  return 0;
}
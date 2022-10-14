#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: lab6-get-a-country.c
Function: Main
Struct: Country
Parameters: two chars, one float, one int from command line
Returns: struct Country
Description: Takes in arguments from command line, places them in struct Country and returns struct Country
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

  strcpy(c.country, argv[1]);
  printf("%s\n", c.country);

  strcpy(c.capital, argv[2]);
  printf("%s\n", c.capital);

  c.population = atof(argv[3]);
  printf("%.2f million people\n", c.population);

  c.size = atoi(argv[4]);
  printf("%d km2\n", c.size);

  return 0;
}

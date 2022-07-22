#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: lab6-find-country.c
Function: Main, add_country, check_size
Struct: Country
Parameters: (repeated arguments of) two chars, one float, one int
Returns: struct Country
Description: Takes in arguments from command line, places them in struct Country and returns struct Country if its size is smaller than 100,000km2
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

void add_country(Country *c, char *country, char *capital, float population, int size);
void check_size(Country *c);

int main(int argc, char * argv[])
{
    Country c[50];
    int count = 0; //count of countries

    printf("Country\t\t\t"); //header
    printf("Capital\t\t\t");
    printf("Size\t\t\t");
    printf("Population");
    printf("\n");

    for(int i = 1; i < argc; i = i + 4)
    {
      add_country(&c[count], argv[i], argv[i + 1], atof(argv[i + 2]), atoi(argv[i + 3])); //adds a country
      count++;
    }

    for(int j = 0; j < count; j++) // for each country in array
    {
      check_size(&c[j]); //send to print
    }
    return 0;
}

void add_country(Country *c, char *country, char *capital, float population, int size) //adds to c array
{
  strcpy(c->country, country);
  strcpy(c->capital, capital);
  c->population = population;
  c->size = size;
}

void check_size(Country *c) //checks if size is smaller than 100,000km2, prints country info if True
{
  if(c->size < 100000)
  {
    printf("%s\t\t\t", c->country);
    printf("%s\t\t\t", c->capital);
    printf("%d\t\t\t", c->size);
    printf("%.2f\n", c->population);
  }
}

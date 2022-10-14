#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: lab6-sort-countries.c
Function: Main, add_country, print_country
Struct: Country
Parameters: two chars, one float, one int from command line
Returns: struct Country
Description: Takes in arguments from command line, places them in struct Country and returns struct Country in order from biggest population to smallest
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
void print_country(Country *c);

int main(int argc, char * argv[])
{
    Country c[50]; //array of countries (structs)
    int count = 0; //count of countries

    printf("Country\t\t\t"); //header
    printf("Capital\t\t\t");
    printf("Size\t\t\t");
    printf("Population");
    printf("\n");

    for(int i = 1; i < argc;)
    {
      add_country(&c[count], argv[i], argv[i + 1], atof(argv[i + 2]), atoi(argv[i + 3]));

      i = i + 4;
      count++;
    }

    for(int i = 0; i < count; i++) //bubble sort
    {

      for(int j = 0; j < count; j++)
      {

        if(c[j + 1].population > c[j].population) //compares populations, if next country has a bigger population swap them
        {
          Country tmp = c[j]; //swap them
          c[j] = c[j+1];
          c[j+1] = tmp;
        }

      }

    }

    for(int j = 0; j < count; j++) //prints all countries
    {
      print_country(&c[j]);
    }
    return 0;
}

void add_country(Country *c, char *country, char *capital, float population, int size) //adds a country using simple function
{
  strcpy(c->country, country);
  strcpy(c->capital, capital);
  c->population = population;
  c->size = size;
}

void print_country(Country *c) //prints country info, storted by biggest population to smallest
{
  printf("%s\t\t\t", c->country);
  printf("%s\t\t\t", c->capital);
  printf("%d\t\t\t", c->size);
  printf("%.2f\n", c->population);
}
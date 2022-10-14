#include<stdio.h>
#include<stdlib.h>
#include<string.h> // for strcpy(), strncmp()

/*
Name: ex4-label-product.c
Function: Main, push, getAverageSales, setStatus, printReverse, printCountry
- Main: this function initialises the array and calls several functions
- push: this function pushes elements to the linked list, creating nodes. The linked list can then be traversed through
- getAverageSales: traverses through the linked list and calculates the average sales of all products
- setStatus: check if sales of a product is greater than the average, return status
- printReverse: prints the outputs, traversing through the linked list backwards, sends product codes to printCountry
- printCountry: uses strncmp to determine the country the product code refers to
Struct: Node
Parameters: Node **, Node *, char *, int, float
Returns: int, string
Description:
- Takes in numbers from command line
- Pushes data to linked list, status is set to 0 as default
- Get the average sales, using recursion
- Check if a product's sales are bigger than average, if product's sales are bigger set status to 1
- Determine the country each product code refers to
- Print the status and country for each product
Author: Martin Derwin
Date: 09-12-21
*/

/*Declare a structure of Node */

typedef struct Node Node;

struct Node // doubly linked list
{
    char code[20];
    float price;
    int nSold;
    int status;

    Node *next;
};

void push(Node ** head, char* code, float price, int nSold); // pushes struct elements into linked list
float getAverageSales(struct Node* current, int length); // get the average sales
void setStatus(struct Node* current, float averageSales); // compare sales for each node to average, set status to 1 if equal to or more than average
void printReverse(struct Node* current); // print desired output
void printCountry(char* countryCode); // determine country

int main(int argc, char *argv[])
{
    Node* first = NULL; // initalise pointer to Node which will be the first element of the linked list

    int length = argc - 1; // number of arguments from command line
    for(int i = 1; i < length; i = i + 3) // push code, price, nSold to linked list
    {
		push(&first, argv[i], atof(argv[i + 1]), atoi(argv[i + 2]));
	}

    float averageSales = getAverageSales(first, length);

    setStatus(first, averageSales);

    printReverse(first); // We print in reverse because we've loaded the nodes into our list in a reverse order of the desired output
    free(first); // we are finished with our linked list so we free the memory
    return 0;
}

void push(Node ** head, char* code, float price, int nSold)
{
    Node * newNode;
    newNode = (Node *)malloc(sizeof(Node)); // create new node

    strcpy(newNode->code, code); // give node its values
    newNode->price = price;
    newNode->nSold = nSold;
    newNode->status = 0; // default for status is zero
    newNode->next = *head; // make the old head the node that came before (next node)
    *head = newNode; // make the new node head
}

float getAverageSales(struct Node* current, int length)
{
    static float sales = 0.0; // assume no sales at first, we use a static variable so the variable does not lose its set value when we recurse to the next node

    if (current == NULL) // we are pointing beyond the linked list
        return sales / (length / 3); // return average

    sales += current->price * current->nSold; // sum of sales

    getAverageSales(current->next, length); // recurse to the next node in the linked list
}

void setStatus(struct Node* current, float averageSales)
{
    if (current == NULL) // we are pointing beyond the linked list
       return;

    float sales = 0.0;
    sales = current->price * current->nSold;

    if(sales >= averageSales)
    {
        current->status = 1;
    }

    setStatus(current->next, averageSales); // recurse to the next node in the linked list
}

void printReverse(struct Node* current) // recursively print the elements in reverse
{
    if (current == NULL) // we are pointing beyond the end of the linked list, so return
       return;


    printReverse(current->next); // recurse to the next node in the linked list

    printf("%d\n", current->status); // output status
    printCountry(current->code); // function outputs country, first two letters refer to one of five countries
}

void printCountry(char* countryCode)
{
    /*
    IE = Ireland
    FR = France
    SP = Spain
    US = USA
    RU = Russia
    */

    if(strncmp(countryCode, "IE", 2) == 0)
    {
        printf("Ireland\n"); // IE
    }
    else if(strncmp(countryCode, "FR", 2) == 0)
    {
        printf("France\n"); // FR
    }
    else if(strncmp(countryCode, "SP", 2) == 0)
    {
        printf("Spain\n"); // SP
    }
    else if(strncmp(countryCode, "US", 2) == 0)
    {
        printf("USA\n"); // US
    }
    else if(strncmp(countryCode, "RU", 2) == 0)
    {
        printf("Russia\n"); // RU
    }
}
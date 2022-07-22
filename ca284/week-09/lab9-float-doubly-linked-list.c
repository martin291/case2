#include<stdio.h>
#include<stdlib.h>

/*
Name: lab9-float-doubly-linked-list.c
Function: Main, get_numbers, printNumbersReversed
Struct: Node
Parameters: argv, Node* to last
Returns: floats
Description:
- Takes in numbers from command line
- Creates a linked list containing these numbers
- Prints the data inside the linked list in reverse
Author: Martin Derwin
*/

/*Declare a structure of Nodes */
typedef struct Node Node;

struct Node
{
    float value;
    Node *next;
    Node *prev; // doubly linked list allows us to traverse the list in both directions
};

Node* get_numbers(char *argv[]); // creates linked list
void printNumbersReversed(Node *last); // prints data in reverse


int main(int argc, char *argv[])
{
    Node *start = NULL;
	start = get_numbers(argv); // we send the arguments from command line to the function get_numbers
    printNumbersReversed(start);

	return 0;
}

Node* get_numbers(char *argv[])
{
    Node *current, *first, *prev;

    first = (Node*)calloc(1, sizeof(Node)); // create first node
    current = first;
    current->value = atoi(argv[2]);

    for(int i = 0; i < atoi(argv[1]) - 1; i++)
    {
        // allocate node and change the current point
        current->next = (Node*)calloc(1, sizeof(Node));

        // get the previous node before move the current pointer to the next
        prev = current;
        current = current->next;
        current->value = atof(argv[i + 3]);
        current->prev = prev;
    }

    current->next = NULL;
    return current; // return address of the last node
}


void printNumbersReversed(Node *last) // traverse the list in reverse, print values
{
	Node* p = NULL;
	for(p = last; p != NULL; p = p->prev)
	{
		printf("%.2f\n", p->value);
	}
}

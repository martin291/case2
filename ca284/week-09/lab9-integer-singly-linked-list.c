#include<stdio.h>
#include<stdlib.h>

/*
Name: lab9-integer-singly-linked-list.c
Function: Main, get_numbers, printNumbers
Struct: Node
Parameters: argv, Node* to start
Returns: ints
Description:
- Takes in numbers from command line
- Creates a linked list containing these numbers
- Prints the data inside the linked list
Author: Martin Derwin
*/

/*Declare a structure of Nodes */
typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
};

Node* get_numbers(char *argv[]); // creates linked list
void printNumbers(Node *start); // prints data inside linked list


int main(int argc, char *argv[])
{
    Node *start = NULL;
	start = get_numbers(argv); // we send our arguments from command line to the function getnumbers
    printNumbers(start); // print data starting at the head of the linked list

	return 0;
}

Node* get_numbers(char *argv[])
{
    Node *current, *first;

    first = (Node*)calloc(1, sizeof(Node)); // create first node
    current = first;
    current->value = atoi(argv[2]);

    for(int i = 0; i < atoi(argv[1]) - 1; i++) // build nodes in linked list
    {
        // allocate node and change the current point
        current->next = (Node*)calloc(1, sizeof(Node));
        current = current->next;
        current->value = atoi(argv[i + 3]);
    }

    current->next = NULL;
    return first; // return address of the first node
}


void printNumbers(Node *start) // print data
{
	Node* p = NULL;
	for(p = start; p != NULL; p = p->next)
	{
		printf("%d\n", p->value);
	}
}


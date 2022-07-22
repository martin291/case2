#include<stdio.h>
#include<stdlib.h>

/*
Name: lab9-push-pop.c
Function: Main, push, pop, printReverse
Struct: Node
Parameters: argv, pointer to Node* to head (start)
Returns: ints
Description:
- Takes in numbers from command line
- Pushes first n numbers to linked list
- Pops first 2 Nodes and Pushes the 2 remaining arguments from the command line
- Prints the data inside the linked list in reverse
Author: Martin Derwin
*/

/*Declare a structure of Nodes */
typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
    Node *prev;
};


void push(Node ** head, int value); // Node** allows us to change head without needed to return it to main
void pop(Node ** head);
void printReverse(struct Node* current);


int main(int argc, char *argv[])
{
    Node *start = NULL;

	int n = atoi(argv[1]); // get n, the number of elements in the original linked list
	for(int i = 0; i < n; i++)
    {
		push(&start, atoi(argv[i + 2])); // push n numbers to the linked list

	}

	pop(&start); // pop head
	pop(&start); // pop again
	push(&start, atoi(argv[n + 2])); // push second last argument from command line
	push(&start, atoi(argv[n + 3])); // push last argument from command line

	printReverse(start); // print in reverse, we want our first node displayed at the top

	return 0;
}

void push(Node ** head, int value)
{
    Node * newNode;
    newNode = (Node *)malloc(sizeof(Node)); // create new node

    newNode->value = value; // give node its value
    newNode->next = *head; // make the old head the node that came before (next node)
    *head = newNode; // make the new node head
}

void pop(Node **head)
{
	Node * nextNode = NULL;

    if (*head != NULL)
	{
    	nextNode = (*head)->next;
    	free(*head); // we free (pop) the node at head and make head the next node
    	*head = nextNode;
	}
}

void printReverse(struct Node* current) // recursively print the elements in reverse
{
    if (current == NULL) // we are pointing beyond the end of the linked list, so return
       return;


    printReverse(current->next); // recurse to the next node in the linked list

    printf("%d\n", current->value);
}









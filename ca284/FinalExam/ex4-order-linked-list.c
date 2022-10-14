#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Name: ex4-order-linked-list.c
Function: Main, push, checkDescendingOrder
- Main: initialises linked list and calls push and checkDescendingOrder functions
- push: pushes elements from command line to linked list
- checkDescendingOrder: check if the linked list is descending by comparing the current node value to the next node value
Struct: Node
Parameters: Node**, Node*, int
Returns: int
Description:
- Takes in numbers from command line
- Pushes numbers to linked list
- Checks if linked list is descending using recursive function that exits the function if the next node value is not less than the current
- Status is 1 if the linked list is in descending order, else it is 0
- Return status to main and output status
Author: Martin Derwin
Date: 09-12-21
*/

/*Declare a structure of Nodes */
typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
    Node *prev; // doubly linked, this means we can travel in both directions
};

void push(struct Node** head, int value);
int checkDescendingOrder(struct Node* current);

int main(int argc, char* argv[])
{
    Node *first = NULL;
    int length = argc - 1; // number of arguments from command line

    for(int i = 0; i < length; i++) // creates our linked list
    {
		push(&first, atoi(argv[i + 1]));
	}

    int status = checkDescendingOrder(first);
    printf("%d\n", status);

    free(first); // we are finished with out linked list so we free all the memory allocated
    return 0;
}

void push(struct Node** head, int value)
{
    Node * newNode;
    newNode = (Node *)malloc(sizeof(Node)); // create new node

    newNode->value = value;

    newNode->next = (*head); // make next node point to former head
    newNode->prev = NULL; // no previous, new node is at the start of the linked list

    if ((*head) != NULL) // if the linked list already exists, make former start point to the new node
    {
        (*head)->prev = newNode;
    }

    (*head) = newNode; // make the newNode the new start (head)
}

int checkDescendingOrder(struct Node* current)
{
    if (current->next == NULL) // we are pointing beyond the end of the linked list, so return
        return 1;

    if(current->value > current->next->value) // if list isn't descending we exit the function
    {
        return 0;
    }

    checkDescendingOrder(current->next); // recurse to the next node in the linked list

}

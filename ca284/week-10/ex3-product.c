#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Name: ex3-product.c
Function: Main, createLinkedList, printLinkedList,
Struct: Node
Parameters: Node*, char*[]
Returns: Struct
Description:
- Takes in numbers from command line
- Push code, country and price for each product to a linked list
- Uses recursion to traverse list, function runs until it reaches the end of the linked list
- Update the price by 20% if the country is Ireland
- Display the resulting linked list using recursion to print it in reverse
- The recursion functions are a simple yet effecient way to create this program
Author: Martin Derwin
*/

/*Declare a structure of Node */

typedef struct Node Node;

struct Node // doubly linked list
{
    char code[50];
    char country[50];
    int price;

    Node *next;
    Node *prev;
};

void push(Node ** head, char* code, char* country, int price); // pushes struct elements into linked list
void updateprice(struct Node* current); // updates price by 20% if the country is ireland
void printReverse(struct Node* current);

int main(int argc, char *argv[])
{
    Node* first = NULL; // initalise pointer to Node which will be the first element of the linked list

    int length = argc - 1; // number of arguments from command line
    for(int i = 1; i < length; i = i + 3) // push code, country, price to linked list
    {
		push(&first, argv[i], argv[i + 1], atoi(argv[i + 2]));

	}

    updateprice(first);

    printReverse(first); // We print in reverse because we've loaded the nodes into our list in a reverse order of the desired output

    return 0;
}

void push(Node ** head, char* code, char* country, int price)
{
    Node * newNode;
    newNode = (Node *)malloc(sizeof(Node)); // create new node

    strcpy(newNode->code, code); // give node its values
    strcpy(newNode->country, country);
    newNode->price = price;
    newNode->next = *head; // make the old head the node that came before (next node)
    *head = newNode; // make the new node head
}

void updateprice(struct Node* current)
{
    if (current == NULL) // we are pointing beyond the linked list
        return;

    if (strcmp(current->country, "Ireland") == 0) // we have found a node with Ireland as its country value
    {
        current->price = current->price * 1.2; // update price
    }

    updateprice(current->next); // recurse to the next node in the linked list
}

void printReverse(struct Node* current) // recursively print the elements in reverse
{
    if (current == NULL) // we are pointing beyond the end of the linked list, so return
       return;


    printReverse(current->next); // recurse to the next node in the linked list

    printf("%s\n", current->code); // print each node in the struct
    printf("%s\n", current->country);
    printf("%d\n", current->price);
}


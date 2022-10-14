#include<stdio.h>
#include<stdlib.h>

/*
Name: lab9-inside-the-queue.c
Function: Main, push, insertNextTo, printReverse
Struct: Node
Parameters: argv, pointer to Node* to current node, searchValue, newValue
Returns: ints
Description:
- Takes in numbers from command line
- Creates linked list of given numbers
- First command line argument represents the value of a node we search for in the linked list
- Second command line argument represents the value of a new node we insert after the above
- Recursively search for node and insert new node, changing pointers of next node and prev node when found
- If new node is to be inserted at the head of the linked list we push it
- Recursively prints the data inside the linked list in reverse
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


void push(int value);
void printReverse(struct Node* current);
void insertNextTo(struct Node* current, int searchValue, int newNode);

Node *start = NULL; // pointer to our linked list

int main(int argc, char *argv[])
{
    int list_of_elements[] = {8, 7, 3, 4, 5, 6, 9, 2, 14, 12};

    int search = atoi(argv[1]); // value in the node we are searching for
    int insert = atoi(argv[2]); // we will insert a new node with this value

	for(int i = 0; i < 10; i++) // creates our linked list
    {
		push(list_of_elements[i]);
	}

    insertNextTo(start, search, insert);

	printReverse(start);

	return 0;
}

void push(int value)
{
    Node * newNode;
    newNode = (Node *)malloc(sizeof(Node)); // create new node

    newNode->value = value;
    newNode->next = start; // make next node point to former start
    newNode->prev = NULL;  // no previous, new node is at the start of the linked list

    if (start != NULL) // if the linked list already exists, make former start point to the new node
    {
        start->prev = newNode;
    }

    start = newNode; // make the newNode the new start (head)
}

void insertNextTo(struct Node* current, int searchValue, int newValue) // uses recursion
{
    Node * InsertNode;

    if (current == NULL) // we are pointing beyond the linked list
        return;

    if (current->value == searchValue) // we have found the searched for node
    {
        InsertNode = (Node*)malloc(sizeof(Node)); // allocate memory for the new node to be inserted

        InsertNode->value = newValue;
        InsertNode->next = current; // the next node to the new node is the current node

        if (current->prev != NULL) // we are not inserting at the head node
        {
            InsertNode->prev = current->prev; //  the previous node to the new node is the previous node of the current node

            // now insert the new node into the linked list by changing pointers
            current->prev->next = InsertNode;
            current->prev = InsertNode;
        }
        else // we are inserting at the head node
        {
            push(newValue); // this creates a new head
            return;
        }
    }

    insertNextTo(current->next, searchValue, newValue); // recurse to the next node in the linked list


}

void printReverse(struct Node* current) // recursively print the elements in reverse
{
    if (current == NULL) // we are pointing beyond the end of the linked list, so return
       return;


    printReverse(current->next); // recurse to the next node in the linked list

    printf("%d\n", current->value);
}

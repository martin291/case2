#include<stdio.h>
#include<stdlib.h>
#include<math.h> // we need this for fmod

/*
Name: ex3-delete-even.c
Function: Main, createLinkedList, printLinkedList, deleteEvens, sumofodds, push
Struct: Node
Parameters: Node*, int*, char*[], int
Returns: ints
Description:
- Takes in numbers from command line
- Creates a linked list containing these numbers as its elements
- We check if a node's value in the linked list is even, if it is even we delete it from the linked list
- We do this by freeing up its memory and then repositioning the pointers for the previous and next node
- We then get the sum of the remaining nodes in the list which are all odd
- We push this to the end of the list and display our resulting list
Author: Martin Derwin
*/

/*Declare a structure of Nodes */

typedef struct Node Node;

struct Node // doubly linked list
{
    int value;
    Node *next;
    Node *prev;
};

Node* createLinkedList(char *argv[], int length); // this function creates our linked list and loads the data from command line into it
void printLinkedList(Node *first); // this function will display the content of our linked list
Node* deleteEvens(Node* first); // this function checks for and deletes any nodes with an even value
int sumofodds(Node *first); // this function gets the sum of the remaining odd numbers in our linked list
Node* push(Node* first, int addedValue); // we use this function to push the sum to our linked list


int toggle = 0; // we toggle this to 1 if the start of our linked list is even

int main(int argc, char *argv[])
{
    Node* first = NULL; // initalise pointer to Node which will be the first element of the linked list
    int sum = 0; // sum of odds

    int length = argc - 1; // number of arguments from command line
    first = createLinkedList(argv, length); // create linked list and load arguments from command line

    deleteEvens(first); // first we delete all the even numbers
    sum = sumofodds(first); // then we get the sum of all odd numbers
    push(first, sum); // we push the sum to our linked list
    printLinkedList(first); // we print the resulting linked list
}


Node* createLinkedList(char* argv[], int length) // create doubly linked list
{
    Node* first = NULL;
    Node* current = NULL;
    Node* prev = NULL;

    first = (Node*)calloc(1, sizeof(Node)); // allocate memory to first node in the list
    current = first;

    for(int i = 0; i < length; ++i)
    {
        current->value = atoi(argv[i + 1]);

        if(i == length - 1) // check if we've reached the end of our linked list
        {
            current->next = NULL;
        }
        else if (i == 0) // check if we are at the head of our linked list
        {
            current->prev = NULL;
            current->next = (Node*)calloc(1, sizeof(Node));
            prev = current;
            current = current->next;
            current->prev = prev;

        }
        else
        {
            current->next = (Node*)calloc(1, sizeof(Node));
            prev = current;
            current = current->next;
            current->prev = prev;
        }
    }

    return first;
}

Node* deleteEvens(Node* first)
{
   	Node* curr = first;
	Node *temp = NULL;

    for(curr = first; curr != NULL; curr = curr->next)
    {
        if(fmod(curr->value, 2) == 0)
        {
            if(curr->next == NULL) // if we are at the end of our linked list
            {
                curr->prev->next = curr->next;
                free(curr);
                curr = temp;
            }
            else if(curr->prev == NULL) // if we are at the start of our linked list (and it is even) we should free it
            {
                //printf("tail %d\n", curr->value);
                //printf("tail %d\n", curr->next->prev->value);
                //printf("next %d\n", curr->next->value);

                //curr->next->prev = NULL;
                //printf("test 1\n");
                //free(curr);
                //printf("test 2\n");
                //curr = NULL;
            }
        	else // otherwise...
            {
                curr->prev->next = curr->next;
			    curr->next->prev = curr->prev;
			    temp = curr->prev; // this is used for marking the new position of p after delete the found item
			    free(curr); // delete the item
			    curr = temp;
            }
        }
    }
}

int sumofodds(Node *first) // sum of all the remaining odd elements
{
    Node* p = NULL;
    int sum = 0;

    for(p = first; p != NULL; p = p->next) // traverse the list
    {
        if(fmod(p->value, 2) != 0)
        {
            sum = sum + p->value; // add each odd element
        }
    }

    return sum;
}

Node* push(Node* first, int addedValue) // push our sum to the linked list
{
    Node* p = NULL;
    for(p = first; p != NULL; p = p->next)
    {
        if(p->next == NULL)
        {
            p->next = (Node*)calloc(1, sizeof(Node)); // allocate memory for the new node
            p = p->next;
            p->value = addedValue;
            p->next = NULL;
            break;
        }
    }

    return first;
}

void printLinkedList(Node *first) // display our resulting linked list
{
    Node* p = NULL;
    for(p = first; p != NULL; p = p->next)
    {
        if(fmod(p->value, 2) != 0) // skip start if even
        {
            printf("%d\n", p->value);
        }
    }
}
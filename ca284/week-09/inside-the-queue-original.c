#include<stdio.h>
#include<stdlib.h>

/*Declare a structure of Nodes */
typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
    Node *prev;
};


void push(Node ** head, int value);
void pop(Node ** head);
void printReverse(struct Node* current);
void insertNextTo(struct Node* current, int searchValue, int newNode);

int main(int argc, char *argv[])
{
    Node *start = NULL;

    int list_of_elements[] = {8, 7, 3, 4, 5, 6, 9, 2, 14, 12};

    int search = atoi(argv[1]);
    int insert = atoi(argv[2]);

	for(int i = 0; i < 10; i++)
    {
		push(&start, list_of_elements[i]);
	}

    insertNextTo(start, search, insert);

	printReverse(start);

	return 0;
}

void push(Node ** head, int value)
{
    Node * newNode;
    newNode = (Node *)malloc(sizeof(Node));

    //(*head)->prev = newNode;

    newNode->value = value;
    newNode->next = *head;

    /* this seems to work */
    newNode->prev = NULL;
    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }

    *head = newNode;
    //if(newNode->value == 17)
    //{
    //    printf("next value %d\n", newNode->next->value);
    //}
    //printf("value %d\n", newNode->value);
    //printf("prev %d\n", newNode->prev->value);
    //printf("next %d\n", newNode->next->value);
}

void insertNextTo(struct Node* current, int searchValue, int newValue)
{
    Node * InsertNode;

    if (current == NULL)
        return;

    if (current->value == searchValue)
    {
        //printf("CURRENT VALUE: %d\n", current->value);
        //printf("PREV VALUE: %d\n", current->prev->value);
        //printf("NEXT VALUE: %d\n", current->next->value);
        //Node *tmp = current->next;

        InsertNode = (Node*)malloc(sizeof(Node));
        InsertNode->value = newValue;

        //InsertNode->prev = current;
        InsertNode->next = current;
        //InsertNode->next = current->next;
        if (current->prev != NULL)
        {
            InsertNode->prev = current->prev;
            current->prev->next = InsertNode;
            current->prev = InsertNode;
        }
        else
        {
            printf("works\n");
            push(&current, newValue);
            return;
        }
        //InsertNode->prev = current->prev;

        //current->next = InsertNode;
        //current->next->prev = InsertNode;

        //current->prev->next = InsertNode;

        //current->prev = InsertNode;
        //current->prev->next = InsertNode;

    }

    insertNextTo(current->next, searchValue, newValue);


}

void printReverse(struct Node* current)
{
    if (current == NULL) // base case
       return;


    printReverse(current->next); // recursively print the elements in reverse

    printf("%d\n", current->value); // after everything else is printed, print head
}
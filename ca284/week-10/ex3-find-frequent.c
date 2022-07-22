#include<stdio.h>
#include<stdlib.h>

/*
Name: ex3-find-frequent.c
Function: Main, createLinkedList, createArray, bubblesort, findFrequentNums
Struct: Node
Parameters: Node*, int*, char*[], int
Returns: ints
Description:
- Takes in numbers from command line
- Creates an array containing these numbers
- Sorts the array using bubblesort
- Sends the sorted elements in the array to a linked list
- We count the appearances of each element by adding to count for each distinct element until the next distinct element appears
- We check if the number is frequent (appears more than 3 times)
- We print the number
Author: Martin Derwin
*/

/*Declare a structure of Nodes */

typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
};

Node* createLinkedList(int* nums, int length); // creates linked list, returns pointer to Node

int* createArray(int *nums, char *argv[], int length); // create array of numbers from command line to send to linked list
int* bubblesort(int* array, int n); // sorts array
int* findFrequentNums(Node *first); // finds elements that appear 4 or more times in the linked list

int main(int argc, char *argv[])
{
    Node* first = NULL; // initalise pointer to Node which will be the first element of the linked list

    int* nums; // this will be our array of numbers from the command line, we will send the content of this to a linked list later
    nums = (int*)malloc(5*sizeof(int)); // we initially only allocate for 5 numbers

    if(!nums) // error check
    {
        printf("Not enough memory. Exiting...\n");
        free(nums);
        nums = NULL;
        exit(0);
    }

    int length = argc - 1; // number of arguments from command line
    if(length > 5) // if number of arguments is more than 5
    {
        nums = (int*)realloc(nums, length*sizeof(int)); //reallocate for actual number of arguments
    }

    nums = createArray(nums, argv, length); // first we create our array

    int* sorted_nums = bubblesort(nums, length); // then we sort it

    first = createLinkedList(sorted_nums, length); // we send the sorted numbers to our function to create a sorted linked list

    findFrequentNums(first);
    int* resultArray = NULL;
    resultArray = build(array, first);
    //findFrequentNums(first); // we find the frequent numbers

    return 0;
}

int* createArray(int *nums, char *argv[], int length) // creates array
{
    for(int i = 0; i < length; i++)
    {
        nums[i] = atoi(argv[i + 1]);
    }
    return nums; // return array
}

int* bubblesort(int* array, int n) // sort array
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(array[i] > array[j]) // check if left is bigger than right
            {
                int temp = array[i]; // swap them
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return array;
}

Node* createLinkedList(int* nums, int length) // create linked list
{
    Node* first = NULL;
    Node* current = NULL;

    first = (Node*)calloc(1, sizeof(Node));
    current = first;

    for(int i = 0; i < length; i++)
    {
        current->value = nums[i];

        //Check if we've reach the end of the linked list
        if(i == length - 1)
        {
            current->next = NULL;
        }
        else
        {
            current->next = (Node*)calloc(1, sizeof(Node));
            current = current->next;
        }
    }

    return first;
}

void findFrequentNums(Node *first)
{
    Node* p = NULL;

    int prev = first->value; // we start previous at the first value so it counts the first element in our linked list
    int count = 0; // counts appearances of elements in linked list

    for(p = first; p != NULL; p = p->next) // traverse linked list
    {

        if(p->value == prev) // if number in linked list is equal to the previous number
        {
            ++count; // add to count
        }
        else
        {
            // the value has changed, so print the count of the previous value if the count is greater than 3
            if (count > 3)
            {
                for(int i = 0; i != count; i++)
                {
                    printf("%d\n", prev);
                }
            }

            // note the current value for the next iteration
            prev = p->value;

            count = 1; // set count back to 1
        }

        if (p->next == NULL) // if we've reached the end of the linked list
        {
            if (count > 3) // check if the current count is greater than 3
            {
                printf("%d\n", p->value);
            }
        }
    }
}

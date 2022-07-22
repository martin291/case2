#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Name: ex2-receipt.c
Function: Main, add_item, items_amount, calculate_total_amount
Struct: Cart
Parameters: char, int, float, int
Returns: float
Description:
- Add item infortmation to our struct Cart
- Send to function to print the item, amount, price of each grocery in the cart
- send to function to get price of an item by its amount, check if its on sale
- If the item is on sale the customer pays three for the price of two
- Meaning the customer will pay for twice the number of groups of 3, plus the number of items remaining
- We add these prices to an array and sum all the elements in the array to get the total amount paid
- Print the total amount
- Add newline
Author: Martin Derwin
Date: 11/11/21
*/

// if promtion value = 1, print On Sale, otherwise print No Sale

typedef struct Cart Cart; //Define Cart as a type name

struct Cart //Structure type definition
{
    char item[20];
    unsigned int amount;
    float price;
    int promotion; // 1 = the item is on sale, 0 = no promotion
};

void add_item(Cart *cart, char *item, unsigned int amount, float price, int promotion); // add item, price, etc. to cart

float items_amount(Cart *cart); // returns cost of all items
void calculate_total(float* total_array, int length); // outputs total amount paid by customer

int main(int argc, char * argv[])
{
    int length = (argc - 1) / 4;
    Cart cart[length]; // array of type Cart, the size of the number of arguments divided by 4
    int count = 0; //count of items

    for(int i = 1; i < argc; i = i + 4)
    {
      add_item(&cart[count], argv[i], atoi(argv[i + 1]), atof(argv[i + 2]), atoi(argv[i + 3])); // we add item, price etc. to the cart
      count++;
    }

    float total_array[length];
    for(int j = 0; j < count; j++)
    {
        float result = items_amount(&cart[j]);
        total_array[j] = result; // add to array of amounts paid for each item(s)
    }

    calculate_total(total_array, length); // sum the amounts together

    return 0;
}

void add_item(Cart *cart, char *item, unsigned int amount, float price, int promotion)
{
  strcpy(cart->item, item); // string copy
  cart->amount = amount;
  cart->price = price;
  cart->promotion = promotion;
}

float items_amount(Cart *cart)
{
    float total = 0; // price per item

    if(cart->promotion == 0)
    {
        total = (cart->amount * cart->price);
    }
    else if(cart->promotion == 1) // customer pays three for the price of two
    {
        total = ((((cart->amount / 3) * 2) + (cart->amount % 3)) * cart->price);
        // pay for twice number of groups of 3, plus the number of items remaining
    }
    return total;
}

void calculate_total(float* total_array, int length)
{
    float sum_price = 0; // add all the prices together to get the total
    for(int i = 0; i < length; i++)
    {
        sum_price += total_array[i];
    }
    printf("%.2f\n", sum_price); // print to two decimal points
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Name: ex2-cart.c
Function: Main, add_item, print_info, check_sale
Struct: Cart
Parameters: char, int, float, int
Returns: struct (info about items in cart)
Description:
- Add item infortmation to our struct Cart
- Send to function to print the item, amount, price of each grocery in the cart
- send to function to print the sale status of each grocery
- This is all seperated by a comma
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
void print_info(Cart *cart);  // print the item info
void check_sale(Cart *cart); // check if the item is on sale

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

    for(int j = 0; j < count; j++) // these functions print our output
    {
        print_info(&cart[j]);
        check_sale(&cart[j]); //check if item is on sale or not on sale
    }
    return 0;
}

void add_item(Cart *cart, char *item, unsigned int amount, float price, int promotion)
{
  strcpy(cart->item, item); // string copy
  cart->amount = amount;
  cart->price = price;
  cart->promotion = promotion;
}

void print_info(Cart *cart) //prints cart info
{
    printf("%s,", cart->item);
    printf("%d,", cart->amount);
    printf("%.2f,", cart->price);
}

void check_sale(Cart *cart) // checks the sale status
{
  if(cart->promotion == 1)
  {
    printf("On Sale\n"); // add newline
  }
  else if (cart->promotion == 0)
  {
    printf("No Sale\n"); // add newline
  }

}

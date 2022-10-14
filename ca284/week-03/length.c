#include<stdio.h>
#include<string.h>

int main(int argc, char *argv)
{
	char str[] = "the brown fox jumped over the lazy dog";
	unsigned int length;
	length = strlen(str);
	printf("The length of the string \"%s\" is %d characters.\n", str, length);
	return (0);
}
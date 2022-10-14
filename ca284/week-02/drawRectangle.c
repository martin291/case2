#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])

{
    int width = atoi(argv[1]);
    int length = atoi(argv[2]);
    for(int i = 0; i < length; ++i)
    {
        for(int j = 0; j < width; ++j)
        {
            printf("*");
        }
        printf("\n");
    }

    return(0);
}

/*
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])

{
    int width = atoi(argv[1]);
    int length = atoi(argv[2]);

    for(int i = 0; i < width; ++i)
    {
        printf("*");
    }

    for(int i = 0; i < length - 2; ++i)
    {
        for(int j = 0; j < width; ++j)
        {
            if((j == 0)) || (j == width - 1));
            {
                printf("\n");
                printf("*");
            }
        }
    }

    for(int i = 0; i < width; ++i)
    {
        printf("*");
    }
    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){

    int width = atoi(argv[1]);
    int length = atoi(argv[2]);

    for(int i = 0; i < length; ++i){
        if(i == 0 || i + 1 == length){
            for(int j = 0; j < width; j++){
                printf("*");
            }
        }
        else{
            for(int j = 0; j < width; j++){
                if(j == 0 || j + 1 == width){
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    return(0);
}





    /*for(int i = 0; i < length; ++i)
    {
        if (i == 0) or (i == length){
            for(int j = 0; j < width; ++j)
            {
                printf("*");
            }
        }
        else {
            for (int j = 0; j < width; ++j)
            {
                if (i == 0) or (j == width){
                    printf("*");
                }
            }
        }
            printf("\n");




    }

    return(0);
} */
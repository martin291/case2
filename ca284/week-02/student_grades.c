#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
    int length = 10;
    int grades[length];
    int sum = 0;
    float average = 0;
    for(unsigned int i = 0; i < length; ++i){
        grades[i] = atoi(argv[i + 1]);
        printf("%d \n", grades[i]);
    }
    return(0);
}

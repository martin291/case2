#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
    int length = argc - 1;
    int grades[length];
    int sum = 0;
    float average = 0;
    for(unsigned int i = 0; i < length; ++i){
        grades[i] = atoi(argv[i + 1]);
        sum += grades[i];
    }
    average = (float)sum/length;
    for(unsigned int i = 0; i < length; i++){
        printf("Student %d: %d\n", i + 1, grades[i]);
    }
    printf("Sum: %d\nAverage: %f\n", sum, average );
    return(0);
}
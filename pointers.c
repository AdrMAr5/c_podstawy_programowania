#include <stdlib.h>
#include <stdio.h>


int main(){
    int arr1[10];
    int* pointer1 = arr1;
    double arr2[10];
    double* pointer2 = arr2;
    for(int i=0; i<10; i++){
        arr1[i] = 2*i;
        double num = i*3.14;
        arr2[i] = num;
    }
    printf("array1:\n");
    for(int i=0; i<10; i++){
        printf("%d\n", *pointer1);
        pointer1++;
    }

    printf("array2:\n");
    for(int i=0; i<10; i++) {
        printf("%f\n", *pointer2);
        pointer2++;
    }
    return 0;
}
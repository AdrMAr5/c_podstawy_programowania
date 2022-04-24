#include <stdlib.h>
#include <stdio.h>


int main(){
    int arr1[10];

    double arr2[10];

    // filling the arrays with numbers
    for(int i=0; i<10; i++){
        arr1[i] = 2*i;
        double num = i*3.14;
        arr2[i] = num;
    }
    printf("array1 address, value\n");
    for(int i=0; i<10; i++){
        printf("%d, ", &arr1[i]);
        printf("%d\n",arr1[i]);
    }
    printf("\narray2 address, value\n");
    for(int i=0; i<10; i++){
        printf("%d, ", &arr2[i]);
        printf("%f\n",arr2[i]);
    }

    // printing array1 using pointer
    int* pointer1 = arr1;
    printf("\narray1 using pointer:\n");
    printf("address, value\n");
    for(int i=0; i<10; i++){
        printf("%d, ", pointer1);
        printf("%d\n", *pointer1);
        pointer1++;
    }

    // printing array2 using pointer
    double* pointer2 = arr2;
    printf("\narray2 using pointer:\n");
    printf("address, value\n");
    for(int i=0; i<10; i++) {
        printf("%d, ", pointer2);
        printf("%f\n", *pointer2);
        pointer2++;
    }
    return 0;
}
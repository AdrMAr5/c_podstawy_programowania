#include <stdio.h>
#include<time.h>
#include<stdlib.h>

void sort(int *arr, int len);
void print_array(int *arr, int len);
int * merge(int *arr1, int len1, int *arr2, int len2, int *new_array);

int main(){
    int arr_len1 = 10;
    int arr_len2 = 10;
    int arr1[arr_len1];
    int arr2[arr_len2];
    srand(time(NULL));
    for(int i=0; i<arr_len1; i++){
        arr1[i] = rand()%11;
        // printf("%d\n",arr1[i]);
    }
    for(int i=0; i<arr_len2; i++){
        arr2[i] = rand()%11;
    }

    sort(arr1, arr_len1);
    sort(arr2, arr_len2);
    int new_array[arr_len1 + arr_len2];
    int new_array_len = merge(arr1, arr_len1, arr2, arr_len2, new_array);
    print_array(new_array, new_array_len);


    return 0;
}

void sort(int *arr, int len){
    for(int i=0; i<len; i++){
        int change = 0;
        for(int j=0; j<len-i-1; j++){
            if (arr[j+1] < arr[j]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                change++;
            }
        }
        if(change == 0){
            return;
        }

    }
}

int * merge(int *arr1, int len1, int *arr2, int len2, int *new_array){
    int i=0, j = 0, k = 0;
    while(i<len1 && j<len2){
        if (arr1[i] < arr2[j]){
            if(arr1[i] != new_array[k-1]){
                new_array[k] = arr1[i];
                k++;
            }
            i++;
        }
        else{
            if(arr2[j] != new_array[k-1]){
                new_array[k] = arr2[j];
                k++;
            }
            j++;
        }
    }
    while(i < len1){
        if(arr1[i] != new_array[k-1]){
            new_array[k] = arr1[i];
            k++;
        }
        i++;
    }
    while(j < len2){
        if(arr2[j] != new_array[k-1]){
            new_array[k] = arr2[j];
            k++;
        }
        j++;
    }
    return k;
}
void print_array(int *arr, int len){
    for(int i=0; i<len; i++){
        printf("%d, ", arr[i]);
    }
}

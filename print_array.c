#include <stdio.h>

enum direction{
    left_to_right,
    right_to_left,
};

void print_array(int const *arr, int size, int k, enum direction direction){
    if(direction == left_to_right){
        for(int i=k; i<size+k; i++){
            printf("%d ", arr[i%10]);
        }
    }
    else if(direction == right_to_left){
        for(int i=k; i>=0; i--){
            printf("%d ", arr[i]);
        }
        for(int i=size-1; i>k; i--){
            printf("%d ", arr[i]);
        }
    }
}

int main(){
    int arr[10];
    for(int i=0; i<10; i++){
        arr[i] = i+1;
    }
    print_array(arr, 10, 4, right_to_left);

    return 0;
}
#include <stdio.h>

#define arr_size 5

int sum_neighbors(int array[arr_size][arr_size], int x, int y);
void fill_array(int *A, size_t width, size_t height);
void print_2d_array(int *A, size_t size);

int main(){
    // exemplary array
//    int arr[arr_size][arr_size] = {{1,0,0,0,1},
//                     {1,1,1,0,0},
//                     {1,0,0,0,0},
//                     {0,0,0,1,1},
//                     {0,1,0,0,0}};
    int arr[arr_size][arr_size];
    fill_array(arr, arr_size, arr_size);
    int new_arr[arr_size][arr_size];

    for(int y=0; y<arr_size; y++){
        for(int x=0; x<arr_size; x++){
            new_arr[y][x] = sum_neighbors(arr, x, y);
        }
    }

    print_2d_array(new_arr, arr_size);
    return 0;
}

int sum_neighbors(int array[arr_size][arr_size], int pos_x, int pos_y){
    int sum = array[pos_y][pos_x];
    int x = pos_x-1;
    int y = pos_y-1;

    for(int i=0; i<2; i++){
        if(x>=0 && y>=0){
            sum += array[y][x];
        }
        x++;
    }
    for(int i=0; i<2; i++){
        if(x<=arr_size-1 && y>=0){
            sum += array[y][x];
        }
        y++;
    }
    for(int i=0; i<2; i++){
        if(x<=arr_size-1 && y<=arr_size-1){
            sum += array[y][x];
        }
        x--;
    }
    for(int i=0; i<2; i++){
        if(x>=0 && y<=arr_size-1){
            sum += array[y][x];
        }
        y--;
    }
    return sum;
}
void fill_array(int *A, size_t width, size_t height)
{
    int input;
    for(size_t i = 0; i < height; ++i)
    {
        for(size_t j = 0; j < width; ++j) {
            printf("Element[%d][%d]: ",i, j);
            scanf("%d",&input);
            A[i * width + j] = input;
        }
    }
}

// just prints 2d array
void print_2d_array(int *A, size_t size){
    for(int y=0; y<size; y++){
        for(int x=0; x<size; x++){
            printf("%d ", A[y * size + x]);
        }
        printf("\n");
    }
}
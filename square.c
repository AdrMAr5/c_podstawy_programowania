#include <stdio.h>
#include <stdbool.h>

#define arr_size 5

void fill_array(int *A, size_t width, size_t height);
void print_2d_array(int *A, size_t size);
bool is_square(int *A, size_t A_size, int x, int y, int radius, int sum);
void fill_with_zeros(int *A, size_t A_size);

int main(){
//    int arr[arr_size][arr_size];
//    fill_array(arr, arr_size, arr_size);
    int k;
    int rect_counter = 0;
    scanf("%d", &k);
    int arr[arr_size][arr_size] = {{1,1,1,1,0},
                                   {1,0,1,5,0},
                                   {1,1,1,1,1},
                                   {1,5,1,0,1},
                                   {0,2,1,1,1}};
    int squares[arr_size-2][arr_size-2];
    fill_with_zeros(squares, arr_size-2);

    for(int y=1; y<arr_size-1; y++){
        for(int x=1; x<arr_size-1; x++){
            int min_radius = y;
            if(x < min_radius) min_radius = x;
            if(arr_size-x-1 < min_radius) min_radius = arr_size-x-1;
            if(arr_size-y-1 < min_radius) min_radius = arr_size-y-1;

            for(int cur_radius=1; cur_radius<=min_radius; cur_radius++){
                if(is_square(arr,arr_size, x, y, cur_radius, k)){
                    rect_counter++;
                    squares[y-1][x-1]++;
                }
            }
        }
    }
    printf("%d\n", rect_counter);
    for(int y=0; y<arr_size-2; y++){
        for(int x=0; x<arr_size-2; x++){
            for(int i=squares[y][x]; i>0; i--){
                printf("%d %d\n", x+1, y+1);
            }
        }
    }
    return 0;
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

// enables user to fill the array with own values
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
bool is_square(int *A, size_t A_size, int x, int y, int radius, int sum){
    int cur_sum = 0;
    int pos_x = x-radius;
    int pos_y = y-radius;
    int side_len = radius*2 + 1;
    for(int i=1; i<side_len; i++){
        cur_sum += A[pos_y * A_size + pos_x];
        pos_x++;
    }
    for(int i=1; i<side_len; i++){
        cur_sum += A[pos_y * A_size + pos_x];
        pos_y++;
    }
    for(int i=1; i<side_len; i++){
        cur_sum += A[pos_y * A_size + pos_x];
        pos_x--;
    }
    for(int i=1; i<side_len; i++){
        cur_sum += A[pos_y * A_size + pos_x];
        pos_y--;
    }
    return (cur_sum == sum);
}

void fill_with_zeros(int *A, size_t A_size){
    for(int i=0; i<A_size; i++){
        for(int j=0; j<A_size; j++){
            A[i * A_size + j] = 0;
        }
    }
}

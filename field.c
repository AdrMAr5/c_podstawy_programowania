#include <stdio.h>
#include <stdbool.h>
#define arr_size 6

void fill_array(int *A, size_t width, size_t height);
bool is_field(int *A, size_t size, int max_x, int max_y, int start_x, int start_y);

int main(){
    // exemplary array
    int arr[arr_size][arr_size] = {{0,0,0,0,0,0},
                                   {0,0,0,0,0,0},
                                   {0,0,0,0,0,0},
                                   {0,0,0,0,0,0},
                                   {0,0,0,0,1,0},
                                   {0,0,0,0,0,1}};
//    int arr[arr_size][arr_size];
//    fill_array(arr, arr_size, arr_size);

    int max_field = 0;
    for(int y=0; y<arr_size; y++){
        for(int x=0; x<arr_size; x++){
            if(arr[y][x] == 1){
                continue;
            }
            // determining the maximal range to look for field in
            int max_right = x, max_down = y;
            while(max_right < arr_size && arr[y][max_right] == 0){
                max_right++;
            }
            while(max_down < arr_size && arr[max_down][x] == 0){
                max_down++;
            }
            // looking for the biggest field
            for(int new_y=y; new_y<=max_down; new_y++){
                for(int new_x=x; new_x<=max_right; new_x++){

                    if(is_field(arr, arr_size, new_x-1, new_y-1, x, y)){
                        int cur_field = (new_y-y) * (new_x-x);
                        if(cur_field > max_field){
                            max_field = cur_field;

                        }
                    }
                }
            }

        }
    }
    printf("%d", max_field);

    return 0;
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

// checks if given part of an array doesn't contain any unusable areas
bool is_field(int *A, size_t size, int max_x, int max_y, int start_x, int start_y){
    for(int y=start_y; y<=max_y; y++){
        for(int x=start_x; x<=max_x; x++){

            if(A[y * (size) + x] == 1){
                return false;
            }
        }
    }
    return true;
}

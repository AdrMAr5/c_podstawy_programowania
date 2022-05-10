#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int count_digits();

int main(){
    int N;
    printf("size of spiral: ");
    scanf("%d", &N);
    int arr[N][N];
    int n = 1;
    int x_st = 0, y_st = 0;
    int size = N-1;
    int max = N-1;
    // creating a spiral
    for(int i=0; i<N; i+=2){
        for (int x=size-max; x<max; x++){
            arr[y_st][x] = n;
            n++;
        }

        for (int y=size-max; y<max; y++){
            arr[y][max] = n;
            n++;
        }

        for (int x=max; x>x_st; x--){
            arr[max][x] = n;
            n++;
        }

        for (int y=max; y>y_st; y--){
            arr[y][x_st] = n;
            n++;
        }
        x_st++;
        y_st++;
        max--;

    }
    // insert a center number if N is odd
    if (N%2 == 1){
        arr[y_st-1][x_st-1] = n;
    }
    // max length of number is length of biggest number in spiral
    // which is always N*N
    int max_num_len;
    max_num_len = count_digits(N*N);

    for(int line=0; line<N; line++){
        for(int el=0; el<N; el++){
            // printing number on specified index
            printf("%d", arr[line][el]);
            int cur_num_len = count_digits(arr[line][el]);

            // filling the gaps with ' ' so that printed array
            // is nicely justified
            while(max_num_len - cur_num_len >= 0){
                printf(" ");
                cur_num_len++;
            }

        }
        printf("\n");
    }

    return 0;
}

// function counting length of number
int count_digits(n){
    int length = 1;
    while(n != 0){
        n/=10;
        length++;
    }
    return length;
}

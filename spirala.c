#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int count_digits();

int main(){
    int N;
    scanf("%d", &N);
    printf("%d\n", N);
    int arr[N][N];
    int n = 1;
    int x_st = 0, y_st = 0;
    int size = N-1;
    int max = N-1;
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
    if (N%2 == 1){
        arr[y_st-1][x_st-1] = n;
    }
    int max_num_len;
    max_num_len = count_digits(N*N);
    printf("%d\n", max_num_len);

    for(int line=0; line<N; line++){
        for(int el=0; el<N; el++){

            printf("%d", arr[line][el]);
            int cur_num_len = count_digits(arr[line][el]);

            while(max_num_len - cur_num_len >= 0){
                printf(" ");
                cur_num_len++;
            }

        }
        printf("\n");
    }

    return 0;
}

int count_digits(n){
    int length = 1;
    while(n != 0){
        n/=10;
        length++;
    }
    return length;
}

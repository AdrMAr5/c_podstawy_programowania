#include <stdio.h>
#define arr_size 500

void fill_with_zeros(int *A, size_t A_size);

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[arr_size][arr_size];
    fill_with_zeros(arr, n);
    for(int i=0; i<m; i++){
        int st, end;
        scanf("%d %d", &st, &end);
        arr[st-1][end-1] = 1;
        arr[end-1][st-1] = 1;
    }

    int counter = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(arr[i][j] == arr[j][k] && arr[i][j] == arr[k][i] && i != j && i != k && j != k){
                    counter++;
                }
            }
        }
    }
    printf("%d", counter/6);
    return 0;
}

void fill_with_zeros(int *A, size_t A_size){
    for(int i=0; i<A_size; i++){
        for(int j=0; j<A_size; j++){
            A[i * A_size + j] = 0;
        }
    }
}

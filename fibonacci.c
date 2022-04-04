#include <stdio.h>

int is_fibonacci_sum(n){
    int fib_1 = 0;
    int fib_2 = 1;
    do{
        int tmp = fib_1;
        fib_1 = fib_2;
        fib_2 = tmp + fib_1;
        if(fib_1 * fib_2 == n){
            return 1;
        }
    } while (fib_1 * fib_2 < n);
    return 0;
}

int main(){
#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
//nieskończona pętla celowa dla sprawdzenia wielu przypadków testowych
    for(;;) {
        int num;
        scanf("%d", &num);
        if (is_fibonacci_sum(num)) {
            printf("liczba spelnia warunek\n");
        }
        else{
            printf("liczba nie spelnia warunku\n");
        }

    }
#pragma clang diagnostic pop
    return 0;
}

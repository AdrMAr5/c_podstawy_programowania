#include <stdio.h>
#include<math.h>

int sum_divisors(num){
    int sum = 1;
    int range = sqrt(num)+1;
    for (int i=2; i<range; i++){
        if (num % i == 0){
            sum += i;
            sum += (num/i);
        }

    }
    return sum;
}

int main(){
    int range;
    int counter = 0;
    scanf("%d", &range);
    for (int i=2; i<=range; i++){
        int sum = sum_divisors(i);
        if(sum == i){
            counter++;
            printf("liczba doskonala: ");
            printf("%d\n", i);
        }

    }

    return 0;
}
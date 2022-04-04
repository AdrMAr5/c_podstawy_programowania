#include <stdio.h>

int silnia(x){
    int out=1;
    for (int i = 1; i <= x; i++){
        out *= i;
    }
    return out;
}

int main(){
    int num;
    scanf("%d", &num);
    int value=0;
    value = silnia(num);
    printf("%d", value);
    return 0;
}

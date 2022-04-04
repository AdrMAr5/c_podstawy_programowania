#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool is_prime(x){
    if(x==2){
        return true;
    }
    if(x%2 == 0 || x<2){
        return false;
    }
    int max_range = sqrt(x) + 1;
    for(int i=3; i <= max_range; i+=2){
        if(x%i == 0){
            return false;
        }
    }
    return true;
}


bool is_desc(num){
    if(num < 10){
        return true;
    }
    while(num!=0){
        int last = num%10;
        num/=10;
        int next = num%10;
        if(next < last && num != 0){
            return false;
        }
    }
    return true;
}



int main(){
    int range;
    scanf("%d", &range);
    for(int i = 11; i<range; i++){
        if(is_prime(i) && is_desc(i)){
            printf("%d\n", i);
        }
    }

    return 0;
}
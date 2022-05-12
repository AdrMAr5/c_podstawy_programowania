#include <stdio.h>
#include <math.h>

long int regular_factorial(int n);
int count_digits_of_fact(int num);
void array_factorial(int len_of_array, int n);
void multiply_array(int *num_arr, int multiplier, int len);

int main(){
    int num;
    scanf("%d", &num);

    if(num < 13){
        printf("%d", regular_factorial(num));
    }
    else{
        int len_of_fact = count_digits_of_fact(num);
        array_factorial(len_of_fact, num);
    }
    return 0;
}

// function counts how long will be factorial of a given number
// to declare an array of a proper length
int count_digits_of_fact(int num){
    double d = 0;
    for(int i=2; i<=num; i++){
        d += log10(i);
    }
    return floor(d) + 1;
}

// regular factorial for small numbers
long int regular_factorial(int n){
    int fac = 1;
    for(int i=1; i<=n; i++){
        fac *= i;
    }
    return fac;
}

// function creates an array representing 1 which is starting number
// and continuously multiplies it by numbers in range of n to get factorial of n
void array_factorial(int len_of_array, int n){
    int num_arr[len_of_array];
    for(int i=0; i<len_of_array; i++){
        num_arr[i] = -1;
    }
    num_arr[len_of_array-1] = 1;

    for(int multiplier=1; multiplier<=n; multiplier++){
        multiply_array(num_arr, multiplier, len_of_array);
    }
    for(int i=0; i<len_of_array; i++){
        printf("%d", num_arr[i]);
    }

}
// function multiplying a number represented by the array by another number
void multiply_array(int *num_arr, int multiplier, int len){
    int i = 0;
    int sum_arr[len];
    for(int ix=0; ix<len; ix++){
        sum_arr[ix] = 0;
    }
    while(multiplier != 0){
        int last = multiplier % 10;
        multiplier /= 10;
        int index_to_multiply = len-1;
        while(num_arr[index_to_multiply] !=-1){
            int product = (num_arr[index_to_multiply] * last);
            int to_next = 0;
            sum_arr[index_to_multiply - i] += product % 10;
            if (sum_arr[index_to_multiply-i] > 9){
                sum_arr[index_to_multiply-i] %= 10;
                to_next = 1;
            }
            sum_arr[index_to_multiply-1 - i] += product / 10 + to_next;
            index_to_multiply--;
        }
        i++;
    }
    // rewriting the array containing a number with newly calculated number
    for(int i=0; i<len; i++){
        num_arr[i] = sum_arr[i];
    }

}



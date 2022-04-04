#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
int main(){
    srand(time(NULL));
    int random = rand() % 20;
    printf("%d\n",random);
    bool guessed = false;
    int num_of_tries = 0;
    while(guessed != true){
        num_of_tries++;
        int user_number = scanf("%d", &user_number);
        if(user_number > random){
            printf("too big number\n");
        }
        else if(user_number < random){
            printf("too small number\n");
        }
        else{
            printf("you guessed after: ");
            printf("%d\n", num_of_tries);
        }

        guessed = true;
    }

    return 0;

}